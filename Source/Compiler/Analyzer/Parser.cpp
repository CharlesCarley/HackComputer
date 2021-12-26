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
#include "Compiler/Common/Node.h"
#include "Utils/Char.h"

namespace Hack::Compiler::Analyzer
{
    Parser::Parser()
    {
        _tree    = new Tree();
        _scanner = new Scanner();
    }

    Parser::~Parser()
    {
        delete _tree;
        _tree = nullptr;

        delete _scanner;
        _scanner = nullptr;
    }

    void Parser::reduceRule(Node* node)
    {
        if (_stack.empty())
            parseError("no rules on the stack");

        if (_stack.top() != node)
        {
            Node* resolved = _stack.top();
            if (resolved->isRule())
                node->insert(resolved);
            else
                parseError("expected a rule to reduce");

            _stack.pop();
        }
        else
            parseError("no rule was reduced");
    }

    Node* Parser::createRule(const int8_t& name)
    {
        Node* rule = new Node(name);
        _stack.push(rule);
        return rule;
    }

    bool Parser::isOperator(const int8_t id)
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

    bool Parser::isTerm(const int8_t t0)
    {
        switch (t0)
        {
        case TOK_IDENTIFIER:
        case TOK_INTEGER:
        case TOK_STRING:
        case TOK_CONST_FALSE:
        case TOK_CONST_TRUE:
        case TOK_CONST_NULL:
        case TOK_CONST_THIS:
        case TOK_L_PAR:
            return true;
        default:
            return false;
        }
    }

    bool Parser::isExpressionExitTerm(const int8_t t0)
    {
        switch (t0)
        {
        case TOK_R_BRACKET:
        case TOK_SEMICOLON:
        case TOK_R_PAR:
        case TOK_COMMA:
            return true;
        default:
            return false;
        }
    }

    bool Parser::isCallTerm(const int8_t t0, const int8_t t1, const int8_t t2, const int8_t t3)
    {
        if ((t0 == TOK_IDENTIFIER || t0 == TOK_CONST_THIS) && t1 == TOK_L_PAR)
            return true;
        if ((t0 == TOK_IDENTIFIER || t0 == TOK_CONST_THIS) && t1 == TOK_PERIOD && t2 == TOK_IDENTIFIER && t3 == TOK_L_PAR)
            return true;
        return false;
    }

    bool Parser::isComplexTerm(const int8_t t0, const int8_t t1, const int8_t t2, const int8_t t3)
    {
        if (t0 == TOK_L_PAR)
            return true;
        if (t0 == TOK_IDENTIFIER && t1 == TOK_L_BRACKET)
            return true;
        return isCallTerm(t0, t1, t2, t3);
    }

    void Parser::checkEof()
    {
        if (getToken(0).getType() == TOK_EOF)
            parseError("end of file reached while reducing rules");
    }

    void Parser::identifier(Node* rule)
    {
        const int8_t t0 = getToken(0).getType();
        if (t0 != TOK_IDENTIFIER)
            parseError("expected an identifier");

        const size_t id = getToken(0).getIndex();

        rule->insert(ConstantIdentifier, _scanner->getString(id));
    }

    void Parser::identifier(Node*        rule,
                            const int8_t symbolId,
                            const int    token)
    {
        const int8_t t0 = getToken(0).getType();
        if (t0 != token)
        {
            parseError(
                "expected an constant integer, string, "
                "boolean, pointer or identifier");
        }

        switch (token)
        {
        case TOK_CONST_FALSE:
        case TOK_CONST_TRUE:
        case TOK_CONST_NULL:
        case TOK_CONST_THIS:
            rule->insert(symbolId);
            break;
        default:
        {
            const size_t id = getToken(0).getIndex();

            if (_scanner->hasString(id))
                rule->insert(symbolId, _scanner->getString(id));
            else
                parseError("no data is associated with the supplied token");
        }
        break;
        }

        advanceCursor();
    }

    void Parser::constant(const int8_t symbolId)
    {
        Node* rule = _stack.top();
        switch (symbolId)
        {
        case ConstantIdentifier:
            identifier(rule, ConstantIdentifier, TOK_IDENTIFIER);
            break;
        case ConstantInteger:
            identifier(rule, ConstantInteger, TOK_INTEGER);
            break;
        case ConstantString:
            identifier(rule, ConstantString, TOK_STRING);
            break;
        case ConstantTrue:
            identifier(rule, ConstantTrue, TOK_CONST_TRUE);
            break;
        case ConstantFalse:
            identifier(rule, ConstantFalse, TOK_CONST_FALSE);
            break;
        case ConstantNull:
            identifier(rule, ConstantNull, TOK_CONST_NULL);
            break;
        case ConstantThis:
            identifier(rule, ConstantThis, TOK_CONST_THIS);
            break;
        default:
            parseError("unknown constant");
        }
    }

    void Parser::object(int8_t symbolId)
    {
        Node* rule = _stack.top();
        switch (symbolId)
        {
        case TOK_IDENTIFIER:
            identifier(rule, ConstantIdentifier, TOK_IDENTIFIER);
            break;
        case TOK_CONST_THIS:
            identifier(rule, ConstantThis, TOK_CONST_THIS);
            break;
        default:
            parseError("unknown constant");
        }
    }

    void Parser::symbol(Node*        rule,
                        const int8_t symbolId,
                        const int    token,
                        char         ch)
    {
        const int8_t t0 = getToken(0).getType();
        if (t0 != token)
            parseError("expected symbol: '", ch, '\'');

        rule->insert(symbolId);
        advanceCursor();
    }

    void Parser::symbol(const int8_t symbolId)
    {
        Node* rule = _stack.top();

        switch (symbolId)
        {
        case SymbolOpenBrace:
            symbol(rule, symbolId, TOK_L_BRACE, '{');
            break;
        case SymbolCloseBrace:
            symbol(rule, symbolId, TOK_R_BRACE, '}');
            break;
        case SymbolSemiColon:
            symbol(rule, symbolId, TOK_SEMICOLON, ';');
            break;
        case SymbolLeftParenthesis:
            symbol(rule, symbolId, TOK_L_PAR, '(');
            break;
        case SymbolRightParenthesis:
            symbol(rule, symbolId, TOK_R_PAR, ')');
            break;
        case SymbolLeftBracket:
            symbol(rule, symbolId, TOK_L_BRACKET, '[');
            break;
        case SymbolRightBracket:
            symbol(rule, symbolId, TOK_R_BRACKET, ']');
            break;
        case SymbolComma:
            symbol(rule, symbolId, TOK_COMMA, ',');
            break;
        case SymbolEquals:
            symbol(rule, symbolId, TOK_EQ, '=');
            break;
        case SymbolPlus:
            symbol(rule, symbolId, TOK_OP_PLUS, '+');
            break;
        case SymbolMinus:
            symbol(rule, symbolId, TOK_OP_MINUS, '-');
            break;
        case SymbolMultiply:
            symbol(rule, symbolId, TOK_OP_MULTIPLY, '*');
            break;
        case SymbolDivide:
            symbol(rule, symbolId, TOK_OP_DIVIDE, '/');
            break;
        case SymbolAnd:
            symbol(rule, symbolId, TOK_OP_AND, '&');
            break;
        case SymbolOr:
            symbol(rule, symbolId, TOK_OP_OR, '|');
            break;
        case SymbolGreater:
            symbol(rule, symbolId, TOK_GT, '>');
            break;
        case SymbolLess:
            symbol(rule, symbolId, TOK_LT, '<');
            break;
        case SymbolNot:
            symbol(rule, symbolId, TOK_OP_NOT, '~');
            break;
        case SymbolPeriod:
            symbol(rule, symbolId, TOK_PERIOD, '.');
            break;
        default:
            parseError("unknown symbol");
        }
    }

    void Parser::keyword(Node*        rule,
                         const int8_t symbolId,
                         const int    token,
                         const char*  kw)
    {
        const int8_t t0 = getToken(0).getType();
        if (t0 != token)
            parseError("expected keyword: '", kw, '\'');

        rule->insert(symbolId);
        advanceCursor();
    }

    void Parser::keyword(const int8_t symbolId)
    {
        Node* rule = _stack.top();
        switch (symbolId)
        {
        case KeywordClass:
            keyword(rule, symbolId, TOK_KW_CLASS, "class");
            break;
        case KeywordConstructor:
            keyword(rule, symbolId, TOK_KW_CTOR, "constructor");
            break;
        case KeywordFunction:
            keyword(rule, symbolId, TOK_KW_FUNCTION, "function");
            break;
        case KeywordMethod:
            keyword(rule, symbolId, TOK_KW_METHOD, "method");
            break;
        case KeywordField:
            keyword(rule, symbolId, TOK_KW_FIELD, "field");
            break;
        case KeywordStatic:
            keyword(rule, symbolId, TOK_KW_STATIC, "static");
            break;
        case KeywordInt:
            keyword(rule, symbolId, TOK_KW_INT, "int");
            break;
        case KeywordChar:
            keyword(rule, symbolId, TOK_KW_CHAR, "char");
            break;
        case KeywordBool:
            keyword(rule, symbolId, TOK_KW_BOOL, "boolean");
            break;
        case KeywordVoid:
            keyword(rule, symbolId, TOK_KW_VOID, "void");
            break;
        case KeywordVar:
            keyword(rule, symbolId, TOK_KW_VAR, "var");
            break;
        case KeywordLet:
            keyword(rule, symbolId, TOK_KW_LET, "let");
            break;
        case KeywordIf:
            keyword(rule, symbolId, TOK_KW_IF, "if");
            break;
        case KeywordElse:
            keyword(rule, symbolId, TOK_KW_ELSE, "else");
            break;
        case KeywordDo:
            keyword(rule, symbolId, TOK_KW_DO, "do");
            break;
        case KeywordWhile:
            keyword(rule, symbolId, TOK_KW_WHILE, "while");
            break;
        case KeywordReturn:
            keyword(rule, symbolId, TOK_KW_RETURN, "return");
            break;
        default:
            parseError("unknown keyword");
        }
    }

    void Parser::classRule()
    {
        try
        {
            Node* rule = createRule(RuleClass);

            keyword(KeywordClass);

            constant(ConstantIdentifier);

            symbol(SymbolOpenBrace);

            classDescriptionRule();
            reduceRule(rule);

            symbol(SymbolCloseBrace);

            _tree->getRoot()->insert(rule);
        }
        catch (Exception& ex)
        {
            parseError("failed to parse the class\n", ex.what());
        }
    }

    void Parser::classDescriptionRule()
    {
        Node* rule = createRule(RuleClassDescription);

        int8_t t0 = getToken(0).getType();
        if (t0 != TOK_R_BRACE)  // empty
        {
            do
            {
                // flow pivots around the static and field keywords

                if (t0 == TOK_KW_STATIC || t0 == TOK_KW_FIELD)
                    fieldRule();
                else
                    methodRule();

                reduceRule(rule);
                t0 = getToken(0).getType();

                checkEof();

            } while (t0 != TOK_R_BRACE);
        }
    }

    void Parser::identifierListRule()
    {
        createRule(RuleIdentifierList);

        constant(ConstantIdentifier);

        int8_t t0 = getToken(0).getType();
        if (t0 == TOK_COMMA)
        {
            do
            {
                advanceCursor();

                constant(ConstantIdentifier);

                t0 = getToken(0).getType();

                checkEof();
            } while (t0 == TOK_COMMA);
        }
    }

    void Parser::fieldSpecificationRule()
    {
        createRule(RuleFieldSpecification);

        switch (getToken(0).getType())
        {
        case TOK_KW_FIELD:
            keyword(KeywordField);
            break;
        case TOK_KW_STATIC:
            keyword(KeywordStatic);
            break;
        default:
            parseError("undefined field specifier");
        }
    }

    void Parser::dataTypeRule()
    {
        createRule(RuleDataType);

        switch (getToken(0).getType())
        {
        case TOK_KW_INT:
            keyword(KeywordInt);
            break;
        case TOK_KW_CHAR:
            keyword(KeywordChar);
            break;
        case TOK_KW_BOOL:
            keyword(KeywordBool);
            break;
        case TOK_IDENTIFIER:
            constant(ConstantIdentifier);
            break;
        default:
            parseError("Undefined data type");
        }
    }

    void Parser::fieldRule()
    {
        try
        {
            Node* rule = createRule(RuleField);

            fieldSpecificationRule();
            reduceRule(rule);

            dataTypeRule();
            reduceRule(rule);

            identifierListRule();
            reduceRule(rule);

            symbol(SymbolSemiColon);
        }
        catch (Exception& ex)
        {
            parseError("failed to construct class field\n", ex.what());
        }
    }

    void Parser::methodRule()
    {
        Node* rule = createRule(RuleMethod);

        try
        {
            methodSpecificationRule();
            reduceRule(rule);

            methodReturnTypeRule();
            reduceRule(rule);

            constant(ConstantIdentifier);

            symbol(SymbolLeftParenthesis);

            parameterListRule();
            reduceRule(rule);

            symbol(SymbolRightParenthesis);

            methodBodyRule();
            reduceRule(rule);
        }
        catch (Exception& ex)
        {
            parseError("failed to build method\n", ex.what());
        }
    }

    void Parser::methodSpecificationRule()
    {
        createRule(RuleMethodSpecification);

        switch (getToken(0).getType())
        {
        case TOK_KW_CTOR:
            keyword(KeywordConstructor);
            break;
        case TOK_KW_FUNCTION:
            keyword(KeywordFunction);
            break;
        case TOK_KW_METHOD:
            keyword(KeywordMethod);
            break;
        default:
            parseError(
                "Expected a method to be declared as a "
                "constructor, function or method");
        }
    }

    void Parser::methodReturnTypeRule()
    {
        Node* rule = createRule(RuleMethodReturnType);

        if (getToken(0).getType() == TOK_KW_VOID)
            keyword(KeywordVoid);
        else
        {
            dataTypeRule();
            reduceRule(rule);
        }
    }

    void Parser::methodBodyRule()
    {
        Node* rule = createRule(RuleMethodBody);

        symbol(SymbolOpenBrace);

        const int8_t t0 = getToken(0).getType();
        if (t0 != TOK_R_BRACE)  // handle empty
        {
            bodyRule();
            reduceRule(rule);
        }

        symbol(SymbolCloseBrace);
    }

    void Parser::bodyRule()
    {
        Node* rule = createRule(RuleBody);

        int8_t t0 = getToken(0).getType();
        do
        {
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

            checkEof();

            // test for the exit condition
            t0 = getToken(0).getType();

        } while (t0 != TOK_R_BRACE);
    }

    void Parser::variableRule()
    {
        Node* rule = createRule(RuleVariable);

        keyword(KeywordVar);

        dataTypeRule();
        reduceRule(rule);

        identifierListRule();
        reduceRule(rule);

        symbol(SymbolSemiColon);
    }

    void Parser::statementRule()
    {
        Node* rule = createRule(RuleStatement);

        // flow pivots on the let, if, else, while, do and return keywords.

        switch (getToken(0).getType())
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
            parseError(
                "expected a statement token of "
                "let, if, else, do, while or return");
        }
    }

    void Parser::letStatementRule()
    {
        Node* rule = createRule(RuleLetStatement);

        keyword(KeywordLet);

        constant(ConstantIdentifier);

        const int8_t t0 = getToken(0).getType();

        if (t0 == TOK_EQ)
        {
            symbol(SymbolEquals);

            expressionRule();
            reduceRule(rule);

            symbol(SymbolSemiColon);
        }
        else if (t0 == TOK_L_BRACKET)
        {
            symbol(SymbolLeftBracket);

            expressionRule();
            reduceRule(rule);

            symbol(SymbolRightBracket);
            symbol(SymbolEquals);

            expressionRule();
            reduceRule(rule);

            symbol(SymbolSemiColon);
        }
    }

    void Parser::ifStatementRule()
    {
        Node* rule = createRule(RuleIfStatement);

        keyword(KeywordIf);

        symbol(SymbolLeftParenthesis);

        expressionRule();
        reduceRule(rule);

        symbol(SymbolRightParenthesis);
        symbol(SymbolOpenBrace);

        statementListRule();
        reduceRule(rule);

        symbol(SymbolCloseBrace);

        const int8_t t0 = getToken(0).getType();
        if (t0 == TOK_KW_ELSE)
            rule->subtype(SubtypeIfElseCombo);


    }

    void Parser::elseStatementRule()
    {
        Node* rule = createRule(RuleElseStatement);

        keyword(KeywordElse);

        symbol(SymbolOpenBrace);

        statementListRule();
        reduceRule(rule);

        symbol(SymbolCloseBrace);
    }

    void Parser::whileStatementRule()
    {
        Node* rule = createRule(RuleWhileStatement);

        keyword(KeywordWhile);
        symbol(SymbolLeftParenthesis);

        expressionRule();
        reduceRule(rule);

        symbol(SymbolRightParenthesis);
        symbol(SymbolOpenBrace);

        statementListRule();
        reduceRule(rule);

        symbol(SymbolCloseBrace);
    }

    void Parser::doStatementRule()
    {
        Node* rule = createRule(RuleDoStatement);

        keyword(KeywordDo);

        callMethodRule();
        reduceRule(rule);

        symbol(SymbolSemiColon);
    }

    void Parser::returnStatementRule()
    {
        Node* rule = createRule(RuleReturnStatement);

        keyword(KeywordReturn);

        const int8_t t0 = getToken(0).getType();
        if (t0 != TOK_SEMICOLON)
        {
            expressionRule();
            reduceRule(rule);
        }
        symbol(SymbolSemiColon);
    }

    void Parser::statementListRule()
    {
        Node* rule = createRule(RuleStatementList);

        int8_t t0 = getToken(0).getType();

        if (t0 != TOK_R_BRACE)
        {
            do
            {
                statementRule();
                reduceRule(rule);

                checkEof();

                t0 = getToken(0).getType();

            } while (t0 != TOK_R_BRACE);
        }
    }

    void Parser::expressionRule()
    {
        Node* rule = createRule(RuleExpression);

        do
        {
            singleExpressionRule();
            reduceRule(rule);

            checkEof();

        } while (!isExpressionExitTerm(getToken(0).getType()));
    }

    void Parser::singleExpressionRule()
    {
        Node* rule = createRule(RuleSingleExpression);

        const int8_t t0 = getToken(0).getType();
        const int8_t t1 = getToken(1).getType();

        if (t0 == TOK_OP_NOT || t0 == TOK_OP_MINUS && isTerm(t1))
        {
            const int8_t tp = getToken(-1).getType();

            if (isTerm(tp) && tp != TOK_L_PAR)
                operatorRule();
            else
                unaryOperatorRule();

            reduceRule(rule);

            termRule();
            reduceRule(rule);
        }
        else if (isOperator(getToken(0).getType()) && isTerm(t1))
        {
            const int8_t tp = getToken(-1).getType();

            if (isTerm(tp))
                operatorRule();
            else
                unaryOperatorRule();

            reduceRule(rule);


            termRule();
            reduceRule(rule);
        }
        else if (isTerm(t0))
        {
            termRule();
            reduceRule(rule);
        }
        else if (t0 != TOK_R_BRACKET && t0 != TOK_SEMICOLON && t0 != TOK_R_PAR)
        {
            // if it's not an exit from this rule, then it's an error.
            parseError("expected unary term, operator term or a term");
        }
    }

    void Parser::termRule()
    {
        Node* rule = createRule(RuleTerm);

        const int8_t t0 = getToken(0).getType();
        const int8_t t1 = getToken(1).getType();
        const int8_t t2 = getToken(2).getType();
        const int8_t t3 = getToken(3).getType();

        if (isComplexTerm(t0, t1, t2, t3))
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
        createRule(RuleSimpleTerm);

        const int8_t t0 = getToken(0).getType();

        switch (t0)
        {
        case TOK_IDENTIFIER:
            constant(ConstantIdentifier);
            break;
        case TOK_INTEGER:
            constant(ConstantInteger);
            break;
        case TOK_CONST_TRUE:
            constant(ConstantTrue);
            break;
        case TOK_CONST_FALSE:
            constant(ConstantFalse);
            break;
        case TOK_CONST_NULL:
            constant(ConstantNull);
            break;
        case TOK_CONST_THIS:
            constant(ConstantThis);
            break;
        case TOK_STRING:
            constant(ConstantString);
            break;
        default:
            parseError("unknown constant '", (int)t0, '\'');
        }
    }

    void Parser::complexTermRule()
    {
        Node* rule = createRule(RuleComplexTerm);

        const int8_t t0 = getToken(0).getType();
        const int8_t t1 = getToken(1).getType();
        const int8_t t2 = getToken(2).getType();
        const int8_t t3 = getToken(3).getType();

        if (t0 == TOK_L_PAR)
        {
            rule->subtype(SubtypeExpressionGroup);

            symbol(SymbolLeftParenthesis);

            expressionRule();
            reduceRule(rule);

            symbol(SymbolRightParenthesis);
        }
        else if (t0 == TOK_IDENTIFIER && t1 == TOK_L_BRACKET)
        {
            rule->subtype(SubtypeArrayIndex);

            constant(ConstantIdentifier);

            symbol(SymbolLeftBracket);

            expressionRule();
            reduceRule(rule);

            symbol(SymbolRightBracket);
        }
        else if (isCallTerm(t0, t1, t2, t3))
        {
            rule->subtype(SubtypeCall);

            callMethodRule();
            reduceRule(rule);
        }
        else
            parseError("unknown complex term");
    }

    void Parser::operatorRule()
    {
        createRule(RuleOperator);

        const int8_t t0 = getToken(0).getType();

        switch (t0)
        {
        case TOK_OP_PLUS:
            symbol(SymbolPlus);
            break;
        case TOK_OP_MINUS:
            symbol(SymbolMinus);
            break;
        case TOK_OP_MULTIPLY:
            symbol(SymbolMultiply);
            break;
        case TOK_OP_DIVIDE:
            symbol(SymbolDivide);
            break;
        case TOK_OP_AND:
            symbol(SymbolAnd);
            break;
        case TOK_OP_OR:
            symbol(SymbolOr);
            break;
        case TOK_GT:
            symbol(SymbolGreater);
            break;
        case TOK_LT:
            symbol(SymbolLess);
            break;
        case TOK_EQ:
            symbol(SymbolEquals);
            break;
        default:
            parseError("unknown symbol '", (int)t0, '\'');
        }
    }

    void Parser::unaryOperatorRule()
    {
        createRule(RuleUnaryOperator);

        const int8_t t0 = getToken(0).getType();

        if (t0 == TOK_OP_MINUS)
            symbol(SymbolMinus);
        else if (t0 == TOK_OP_NOT)
            symbol(SymbolNot);
        else
            parseError("expected a '-', '~', or '!' character");
    }

    void Parser::expressionListRule()
    {
        Node* rule = createRule(RuleExpressionList);

        int8_t t0 = getToken(0).getType();

        if (t0 != TOK_R_PAR)  // empty case
        {
            do
            {
                expressionRule();
                reduceRule(rule);

                checkEof();

                t0 = getToken(0).getType();
                if (t0 == TOK_COMMA)
                {
                    advanceCursor();
                    t0 = getToken(0).getType();
                }
            } while (t0 != TOK_R_PAR);
        }
    }

    void Parser::callMethodRule()
    {
        Node* rule = createRule(RuleCallMethod);

        const int8_t t0 = getToken(0).getType();
        const int8_t t1 = getToken(1).getType();
        const int8_t t2 = getToken(2).getType();
        const int8_t t3 = getToken(3).getType();

        if (t0 == TOK_IDENTIFIER && t1 == TOK_L_PAR)
        {
            try
            {
                rule->subtype(SubtypeCallFunction);

                constant(ConstantIdentifier);

                symbol(SymbolLeftParenthesis);

                expressionListRule();
                reduceRule(rule);

                symbol(SymbolRightParenthesis);
            }
            catch (Exception& ex)
            {
                throw InputException(ex.what(), "\n", "failed to parse method declaration");
            }
        }
        else if (t0 == TOK_IDENTIFIER || t0 == TOK_CONST_THIS &&
                                             t1 == TOK_PERIOD &&
                                             t2 == TOK_IDENTIFIER &&
                                             t3 == TOK_L_PAR)
        {
            try
            {
                rule->subtype(SubtypeCallMethod);

                object(t0);

                symbol(SymbolPeriod);

                constant(ConstantIdentifier);

                symbol(SymbolLeftParenthesis);

                expressionListRule();
                reduceRule(rule);

                symbol(SymbolRightParenthesis);
            }
            catch (Exception& ex)
            {
                throw InputException(ex.what(), "\n", "failed to parse method declaration");
            }
        }
        else
            parseError("unknown call rule");
    }

    void Parser::parameterListRule()
    {
        Node* rule = createRule(RuleParameterList);

        int8_t t0 = getToken(0).getType();
        if (t0 != TOK_R_PAR)  // empty case
        {
            do
            {
                parameterRule();
                reduceRule(rule);

                t0 = getToken(0).getType();
                if (t0 == TOK_COMMA)
                    advanceCursor();

                checkEof();

            } while (t0 != TOK_R_PAR);
        }
    }

    void Parser::parameterRule()
    {
        Node* rule = createRule(RuleParameter);

        dataTypeRule();
        reduceRule(rule);

        constant(ConstantIdentifier);
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

    void Parser::writeImpl(OStream& os, int format)
    {
        if (!_tree)
            parseError("invalid parse tree");

        _tree->write(os, format);
    }

}  // namespace Hack::Compiler::Analyzer
