/*
-------------------------------------------------------------------------------
    Copyright (c) Charles Carley.

  This software is provided 'as-is', without any express or implied
  warranty. In no event will the authors be held liable for any damages
  arising from the use of this software.

  Permission is granted to anyone to use this software for any purpose,
  including commercial applications, and to alter it and redistribute it
  freely, subject to the following restrictions:

  1. The origin of this software must not be misrepresented; you must not
     claim that you wrote the original software. If you use this software
     in a product, an acknowledgment in the product documentation would be
     appreciated but is not required.
  2. Altered source versions must be plainly marked as such, and must not be
     misrepresented as being the original software.
  3. This notice may not be removed or altered from any source distribution.
-------------------------------------------------------------------------------
*/
#include "Compiler/Analyzer/Parser.h"
#include <fstream>
#include "Compiler/Analyzer/Scanner.h"
#include "Compiler/Analyzer/Token.h"
#include "Compiler/Common/ParseTreeNode.h"
#include "Utils/Char.h"

namespace Hack::Compiler::Analyzer
{
    Parser::Parser()
    {
        _tree    = new ParseTree();
        _scanner = new Scanner();
    }

    Parser::~Parser()
    {
        delete _tree;
        _tree = nullptr;

        delete _scanner;
        _scanner = nullptr;
    }

    void Parser::reduceRule(ParseTreeNode* node)
    {
        if (_stack.empty())
            parseError("No rules on the stack");

        if (_stack.top() != node)
        {
            ParseTreeNode* resolved = _stack.top();
            if (resolved->isRule())
                node->addChild(resolved);
            else
                parseError("Expected a reduced rule");

            _stack.pop();
        }
    }

    ParseTreeNode* Parser::createRule(const int8_t& name)
    {
        ParseTreeNode* rule = new ParseTreeNode(name);
        _stack.push(rule);
        return rule;
    }

    bool Parser::isOperator(int8_t id)
    {
        switch (id)
        {
        case TOK_OP_MINUS:
        case TOK_OP_PLUS:
        case TOK_OP_MULTIPLY:
        case TOK_OP_DIVIDE:
        case TOK_OP_AND:
        case TOK_OP_OR:
        case TOK_GT:
        case TOK_LT:
        case TOK_EQ:
            return true;
        default:
            return false;
        }
    }

    bool Parser::testComplexTerm(int8_t t0, int8_t t1, int8_t t2, int8_t t3)
    {
        if (t0 == TOK_L_PAR)
            return true;
        if (t0 == TOK_IDENTIFIER && t1 == TOK_L_BRACKET)
            return true;
        if (t0 == TOK_IDENTIFIER && t1 == TOK_L_PAR)
            return true;
        if (t0 == TOK_IDENTIFIER && t1 == TOK_PERIOD && t2 == TOK_IDENTIFIER && t3 == TOK_L_PAR)
            return true;
        return false;
    }

    void Parser::classRule()
    {
        // <Class> ::= Class Identifier '{' <ClassDescription> '}'
        ParseTreeNode* rule = createRule(RuleClass);

        keyword(rule, KeywordClass, TOK_KW_CLASS, "class");

        identifier(rule, ConstantIdentifier, TOK_IDENTIFIER);

        symbol(rule, SymbolOpenBrace, TOK_L_BRACE, '{');

        classDescriptionRule();
        reduceRule(rule);

        symbol(rule, SymbolCloseBrace, TOK_R_BRACE, '}');

        this->_tree->getRoot()->addChild(rule);
    }

    void Parser::classDescriptionRule()
    {
        // <ClassDescription> ::= <ClassDescription> <Field> ';'
        //                      | <ClassDescription><Method>
        //                      | !--empty--

        ParseTreeNode* rule = createRule(RuleClassDescription);

        int8_t t0 = getToken(0).getType();

        while (t0 != TOK_R_BRACE && t0 != TOK_EOF)
        {
            const int32_t curOp = _cursor;

            // flow pivots around the static and field keywords

            if (t0 == TOK_KW_STATIC || t0 == TOK_KW_FIELD)
                fieldRule();
            else
                methodRule();

            reduceRule(rule);
            t0 = getToken(0).getType();

            if (curOp == _cursor)
                parseError("no rule was reduced");
        }
    }

    void Parser::identifier(ParseTreeNode* rule)
    {
        const int8_t t0 = getToken(0).getType();
        if (t0 != TOK_IDENTIFIER)
            parseError("expected an identifier");

        const size_t id = getToken(0).getIndex();

        rule->addChild(ConstantIdentifier, _scanner->getString(id));
    }

    void Parser::identifier(ParseTreeNode* rule, int8_t symbolId, int token)
    {
        const int8_t t0 = getToken(0).getType();
        if (t0 != token)
            parseError("expected an constant value");

        const size_t id = getToken(0).getIndex();

        rule->addChild(symbolId, _scanner->getString(id));
        advanceCursor();
    }

    void Parser::symbol(ParseTreeNode* rule, int8_t symbolId, const int token, char ch)
    {
        const int8_t t0 = getToken(0).getType();
        if (t0 != token)
            parseError("expected the symbol, '", ch, "'");

        rule->addChild(symbolId);
        advanceCursor();
    }

    void Parser::keyword(ParseTreeNode* rule, int8_t symbolId, int token, const char* kw)
    {
        const int8_t t0 = getToken(0).getType();
        if (t0 != token)
            parseError("expected the '", kw, "' keyword");

        rule->addChild(symbolId);
        advanceCursor();
    }

    void Parser::identifierListRule()
    {
        ParseTreeNode* rule = createRule(RuleIdentifierList);

        identifier(rule);

        int8_t t1 = getToken(1).getType();

        if (t1 == TOK_COMMA)
        {
            advanceCursor(2);

            while (t1 == TOK_COMMA)
            {
                identifier(rule, ConstantIdentifier, TOK_IDENTIFIER);

                t1 = getToken(0).getType();
                if (t1 == TOK_EOF)
                    parseError("expected a comma");
                if (t1 == TOK_COMMA)
                    advanceCursor();
                else
                    break;
            }
        }
        else
            advanceCursor();
    }

    void Parser::fieldSpecificationRule()
    {
        // <FieldSpecification> ::= Static | Field

        ParseTreeNode* rule = createRule(RuleFieldSpecification);

        const int8_t t0 = getToken(0).getType();
        if (t0 == TOK_KW_FIELD)
            rule->addChild(KeywordField);
        else if (t0 == TOK_KW_STATIC)
            rule->addChild(KeywordStatic);
        else
            parseError("Undefined field specifier");

        advanceCursor();
    }

    void Parser::dataTypeRule()
    {
        // <DataType> ::= Int | Char | Boolean | Identifier

        ParseTreeNode* rule = createRule(RuleDataType);

        String val;

        const int8_t t0 = getToken(0).getType();
        switch (t0)
        {
        case TOK_KW_INT:
            rule->addChild(KeywordInt);
            break;
        case TOK_KW_CHAR:
            rule->addChild(KeywordChar);
            break;
        case TOK_KW_BOOL:
            rule->addChild(KeywordBool);
            break;
        case TOK_IDENTIFIER:
            _scanner->getString(val, getToken(0).getIndex());
            rule->addChild(ConstantIdentifier, val);
            break;
        default:
            parseError("Undefined data type");
        }
        advanceCursor();
    }

    void Parser::fieldRule()
    {
        // <Field> ::= <FieldSpecification> <DataType> <IdentifierList>

        ParseTreeNode* rule = createRule(RuleField);

        fieldSpecificationRule();
        reduceRule(rule);

        dataTypeRule();
        reduceRule(rule);

        identifierListRule();
        reduceRule(rule);

        symbol(rule, SymbolSemiColon, TOK_SEMICOLON, ';');
    }

    void Parser::methodRule()
    {
        // <Method> ::= <MethodSpecification> <MethodReturnType>
        //              Identifier '(' <ParameterList> ')' <MethodBody>
        ParseTreeNode* rule = createRule(RuleMethod);

        methodSpecificationRule();
        reduceRule(rule);

        methodReturnTypeRule();
        reduceRule(rule);

        identifier(rule, ConstantIdentifier, TOK_IDENTIFIER);
        symbol(rule, SymbolLeftParenthesis, TOK_L_PAR, '(');

        parameterListRule();
        reduceRule(rule);

        symbol(rule, SymbolRightParenthesis, TOK_R_PAR, ')');

        methodBodyRule();
        reduceRule(rule);
    }

    void Parser::methodSpecificationRule()
    {
        // <MethodSpecification> ::= Constructor | Function | Method
        ParseTreeNode* rule = createRule(RuleMethodSpecification);

        const int8_t t0 = getToken(0).getType();
        switch (t0)
        {
        case TOK_KW_CTOR:
            rule->addChild(KeywordConstructor);
            break;
        case TOK_KW_FUNCTION:
            rule->addChild(KeywordFunction);
            break;
        case TOK_KW_METHOD:
            rule->addChild(KeywordMethod);
            break;
        default:
            parseError(
                "Expected a method to be declared as a "
                "constructor, function or method");
        }
        advanceCursor();
    }

    void Parser::methodReturnTypeRule()
    {
        // <MethodReturnType> ::= Void | <DataType>

        ParseTreeNode* rule = createRule(RuleMethodReturnType);

        const int8_t t0 = getToken(0).getType();
        if (t0 == TOK_KW_VOID)
        {
            rule->addChild(KeywordVoid);
            advanceCursor();
        }
        else
        {
            dataTypeRule();
            reduceRule(rule);
        }
    }

    void Parser::methodBodyRule()
    {
        // <MethodBody> ::= '{' <Body> '}'

        ParseTreeNode* rule = createRule(RuleMethodBody);

        symbol(rule, SymbolOpenBrace, TOK_L_BRACE, '{');

        bodyRule();
        reduceRule(rule);

        symbol(rule, SymbolCloseBrace, TOK_R_BRACE, '}');
    }

    void Parser::bodyRule()
    {
        // <Body> ::= <Body> <Variable>
        //          | <Body> <Statement>
        //          | !--empty--
        ParseTreeNode* rule = createRule(RuleBody);

        int8_t t0 = getToken(0).getType();
        while (t0 != TOK_EOF && t0 != TOK_R_BRACE)
        {
            const int32_t curOp = _cursor;

            // flow pivots around the var keyword
            if (t0 == TOK_KW_VAR)
            {
                variableRule();
                reduceRule(rule);
            }
            else
            {
                statementRule();
                reduceRule(rule);
            }
            // test for the exit condition
            t0 = getToken(0).getType();

            if (curOp == _cursor)
                parseError("no rule was reduced");
        }
    }

    void Parser::variableRule()
    {
        // <Variable> ::= Var <DataType> <IdentifierList> ';'

        ParseTreeNode* rule = createRule(RuleVariable);
        keyword(rule, KeywordVar, TOK_KW_VAR, "var");

        dataTypeRule();
        reduceRule(rule);

        identifierListRule();
        reduceRule(rule);

        symbol(rule, SymbolSemiColon, TOK_SEMICOLON, ';');
    }

    void Parser::statementRule()
    {
        // <Statement> ::= <LetStatement>
        //               | <IfStatement>
        //               | <WhileStatement>
        //               | <DoStatement>
        //               | <ReturnStatement>

        ParseTreeNode* rule = createRule(RuleStatement);

        // flow pivots on the let, if, else, while, do and return keywords.

        int8_t t0 = getToken(0).getType();
        switch (t0)
        {
        case TOK_KW_LET:
            letStatementRule();
            reduceRule(rule);
            break;
        case TOK_KW_IF:
            ifStatementRule();
            reduceRule(rule);
            break;
        case TOK_KW_ELSE:
            elseStatementRule();
            reduceRule(rule);
            break;
        case TOK_KW_DO:
            doStatementRule();
            reduceRule(rule);
            break;
        case TOK_KW_WHILE:
            whileStatementRule();
            reduceRule(rule);
            break;
        case TOK_KW_RETURN:
            returnStatementRule();
            reduceRule(rule);
            break;
        default:
            parseError("unknown keyword rule, '", t0, '\'');
        }
    }

    void Parser::letStatementRule()
    {
        // <LetStatement> ::= Let Identifier '=' <Expression> ';'
        //                  | Let Identifier '[' < Expression > ']' '=' < Expression > ';'
        ParseTreeNode* rule = createRule(RuleLetStatement);

        keyword(rule, KeywordLet, TOK_KW_LET, "let");

        identifier(rule, ConstantIdentifier, TOK_IDENTIFIER);

        const int8_t t0 = getToken(0).getType();

        if (t0 == TOK_EQ)
        {
            symbol(rule, SymbolEquals, TOK_EQ, '=');

            expressionRule();
            reduceRule(rule);

            symbol(rule, SymbolSemiColon, TOK_SEMICOLON, ';');
        }
        else if (t0 == TOK_L_BRACKET)
        {
            symbol(rule, SymbolLeftBracket, TOK_L_BRACKET, '[');

            expressionRule();
            reduceRule(rule);

            symbol(rule, SymbolLeftBracket, TOK_R_BRACKET, ']');

            symbol(rule, SymbolEquals, TOK_EQ, '=');

            expressionRule();
            reduceRule(rule);

            symbol(rule, SymbolSemiColon, TOK_SEMICOLON, ';');
        }
    }

    void Parser::ifStatementRule()
    {
        ParseTreeNode* rule = createRule(RuleIfStatement);
    }

    void Parser::elseStatementRule()
    {
        ParseTreeNode* rule = createRule(RuleElseStatement);
    }

    void Parser::whileStatementRule()
    {
        ParseTreeNode* rule = createRule(RuleWhileStatement);
    }

    void Parser::doStatementRule()
    {
        ParseTreeNode* rule = createRule(RuleDoStatement);
    }

    void Parser::returnStatementRule()
    {
        ParseTreeNode* rule = createRule(RuleReturnStatement);
    }

    void Parser::statementListRule()
    {
        ParseTreeNode* rule = createRule(RuleStatementList);
    }

    void Parser::expressionRule()
    {
        // <Expression> ::= <Term>
        //                | <Term> <Operator> <Term>
        //                | <UnaryOperator> <Term>

        ParseTreeNode* rule = createRule(RuleExpression);

        const int8_t t0 = getToken(0).getType();

        if (t0 == TOK_OP_NOT || t0 == TOK_OP_MINUS)
        {
            unaryOperatorRule();
            reduceRule(rule);

            termRule();
            reduceRule(rule);
        }
        else if (isOperator(getToken(1).getType()))
        {
            termRule();
            reduceRule(rule);

            operatorRule();
            reduceRule(rule);

            termRule();
            reduceRule(rule);
        }
        else
        {
            termRule();
            reduceRule(rule);
        }
    }

    void Parser::termRule()
    {
        // <Term> ::= <SimpleTerm> | <ComplexTerm>

        ParseTreeNode* rule = createRule(RuleTerm);

        const int8_t t0 = getToken(0).getType();
        const int8_t t1 = getToken(1).getType();
        const int8_t t2 = getToken(2).getType();
        const int8_t t3 = getToken(3).getType();

        if (testComplexTerm(t0, t1, t2, t3))
        {
            complexTermRule();
            reduceRule(rule);
        }
        else
        {
            simpleTermRule();
            reduceRule(rule);
        }
    }

    void Parser::simpleTermRule()
    {
        // <SimpleTerm>:: = Integer | String | True | False | Null | This | Identifier

        ParseTreeNode* rule = createRule(RuleSimpleTerm);

        const int8_t t0 = getToken(0).getType();
        switch (t0)
        {
        case TOK_IDENTIFIER:
            identifier(rule, ConstantIdentifier, TOK_IDENTIFIER);
            break;
        case TOK_INTEGER:
            identifier(rule, ConstantInteger, TOK_INTEGER);
            break;
        case TOK_CONST_TRUE:
            identifier(rule, ConstantTrue, TOK_CONST_TRUE);
            break;
        case TOK_CONST_FALSE:
            identifier(rule, ConstantFalse, TOK_CONST_FALSE);
            break;
        case TOK_CONST_NULL:
            identifier(rule, ConstantNull, TOK_CONST_NULL);
            break;
        case TOK_CONST_THIS:
            identifier(rule, ConstantThis, TOK_CONST_THIS);
            break;
        case TOK_STRING:
            identifier(rule, ConstantString, TOK_STRING);
            break;
        default:
            parseError("unknown constant '", (int)t0, '\'');
        }
    }

    void Parser::complexTermRule()
    {
        ParseTreeNode* rule = createRule(RuleComplexTerm);
    }

    void Parser::operatorRule()
    {
        ParseTreeNode* rule = createRule(RuleOperator);

        const int8_t t0 = getToken(0).getType();
        switch (t0)
        {
        case TOK_OP_PLUS:
            symbol(rule, SymbolPlus, TOK_OP_PLUS, '+');
            break;
        case TOK_OP_MINUS:
            symbol(rule, SymbolMinus, TOK_OP_MINUS, '-');
            break;
        case TOK_OP_MULTIPLY:
            symbol(rule, SymbolMultiply, TOK_OP_MULTIPLY, '*');
            break;
        case TOK_OP_DIVIDE:
            symbol(rule, SymbolDivide, TOK_OP_DIVIDE, '/');
            break;
        case TOK_OP_AND:
            symbol(rule, SymbolAnd, TOK_OP_AND, '&');
            break;
        case TOK_OP_OR:
            symbol(rule, SymbolOr, TOK_OP_OR, '|');
            break;
        case TOK_GT:
            symbol(rule, SymbolGreater, TOK_GT, '>');
            break;
        case TOK_LT:
            symbol(rule, SymbolLess, TOK_LT, '<');
            break;
        case TOK_EQ:
            symbol(rule, SymbolEquals, TOK_EQ, '=');
            break;
        default:
            parseError("unknown symbol '", (int)t0, '\'');
        }
    }

    void Parser::unaryOperatorRule()
    {
        ParseTreeNode* rule = createRule(RuleUnaryOperator);

        const int8_t t0 = getToken(0).getType();

        if (t0 == TOK_OP_MINUS)
            symbol(rule, SymbolMinus, TOK_OP_MINUS, '-');
        else if (t0 == TOK_OP_NOT)
            symbol(rule, SymbolNot, TOK_OP_NOT, '!');
        else
            parseError("expected a '-', '~', or '!' character");
    }

    void Parser::expressionListRule()
    {
        ParseTreeNode* rule = createRule(RuleExpressionList);
    }

    void Parser::callMethodRule()
    {
        ParseTreeNode* rule = createRule(RuleCallMethod);
    }

    void Parser::parameterListRule()
    {
        // <ParameterList> ::= <ParameterList> ',' <Parameter>
        //                   | <Parameter>
        //                   | !--empty--

        ParseTreeNode* rule = createRule(RuleParameterList);
        int8_t         t0   = getToken(0).getType();
        if (t0 != TOK_R_PAR)
        {
            parameterRule();
            reduceRule(rule);

            t0 = getToken(0).getType();
            if (t0 == TOK_COMMA)
            {
                advanceCursor();

                while (t0 == TOK_COMMA)
                {
                    parameterRule();
                    reduceRule(rule);

                    t0 = getToken(0).getType();
                    if (t0 == TOK_EOF)
                        parseError("expected a comma");
                    if (t0 == TOK_COMMA)
                        advanceCursor();
                    else
                        break;
                }
            }
        }
    }

    void Parser::parameterRule()
    {
        ParseTreeNode* rule = createRule(RuleParameter);

        dataTypeRule();
        reduceRule(rule);

        identifier(rule, ConstantIdentifier, TOK_IDENTIFIER);
    }

    void Parser::parseImpl(IStream& is)
    {
        // make sure the token cursor is at zero
        // initially and attach the input stream
        // to the scanner
        _cursor = 0;
        _scanner->attach(&is, _filePath);

        while (_cursor <= (int32_t)_tokens.size())
        {
            const int8_t tok = getToken(0).getType();
            if (tok == TOK_EOF)
                break;

            const int32_t op = _cursor;
            classRule();

            // if the cursor did not
            // advance force it to.
            if (op == _cursor)
                advanceCursor();
        }
    }

    void Parser::writeImpl(OStream& os)
    {
        if (!_tree)
            parseError("invalid parse tree");

        _tree->write(os);
    }

}  // namespace Hack::Compiler::Analyzer
