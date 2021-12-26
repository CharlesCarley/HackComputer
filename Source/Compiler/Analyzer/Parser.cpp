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
#include "Compiler/Analyzer/ParseUtils.h"
#include "Compiler/Analyzer/Scanner.h"
#include "Compiler/Analyzer/Token.h"
#include "Compiler/Common/Node.h"
#include "Utils/Char.h"

namespace Hack::Compiler::Analyzer
{
    using Pu = ParseUtils;
    using Nu = NodeUtils;

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
            {
                parseError(
                    "expected the node on the top "
                    "of the stack to be a rule");
            }
            _stack.pop();
        }
        else
            parseError(
                "the node on the top of the stack "
                "is the current node being reduced "
                "therefore, it can not be reduced.");
    }

    Node* Parser::createRule(const int8_t& name)
    {
        Node* rule = new Node(name, _filePath, _scanner->line());

        _stack.push(rule);
        return rule;
    }

    void Parser::checkEof()
    {
        if (getToken(0).getType() == TokEof)
            parseError("end of file reached while reducing rules");
    }

    void Parser::identifier(Node* rule)
    {
        const int8_t t0 = getToken(0).getType();
        if (t0 != TokId)
        {
            parseError(
                "expected to find an identifier, but found ",
                Pu::string(t0),
                " instead.");
        }

        const size_t id = getToken(0).getIndex();

        rule->insert(ConstantIdentifier,
                     _scanner->string(id),
                     _filePath,
                     _scanner->line());
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
                "boolean, pointer or identifier, but found ",
                Pu::string(t0),
                " instead.");
        }

        switch (token)
        {
        case TokKwFalse:
        case TokKwTrue:
        case TokKwNull:
        case TokKwThis:
            rule->insert(symbolId, _filePath, _scanner->line());
            break;
        default:
        {
            const size_t id = getToken(0).getIndex();
            if (_scanner->containsString(id))
                rule->insert(symbolId, _scanner->string(id), _filePath, _scanner->line());
            else
                parseError("no scan data is associated with the supplied token");
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
            identifier(rule, ConstantIdentifier, TokId);
            break;
        case ConstantInteger:
            identifier(rule, ConstantInteger, TokInt);
            break;
        case ConstantString:
            identifier(rule, ConstantString, TokString);
            break;
        case ConstantTrue:
            identifier(rule, ConstantTrue, TokKwTrue);
            break;
        case ConstantFalse:
            identifier(rule, ConstantFalse, TokKwFalse);
            break;
        case ConstantNull:
            identifier(rule, ConstantNull, TokKwNull);
            break;
        case ConstantThis:
            identifier(rule, ConstantThis, TokKwThis);
            break;
        default:
            parseError("unknown constant '",
                       Nu::string(symbolId),
                       '\'');
        }
    }

    void Parser::object(const int8_t symbolId)
    {
        Node* rule = _stack.top();
        switch (symbolId)
        {
        case TokId:
            identifier(rule, ConstantIdentifier, TokId);
            break;
        case TokKwThis:
            identifier(rule, ConstantThis, TokKwThis);
            break;
        default:
            parseError("unknown constant '",
                       Pu::string(symbolId),
                       '\'');
        }
    }

    void Parser::symbol(Node*        rule,
                        const int8_t symbolId,
                        const int    token,
                        char         ch)
    {
        const int8_t t0 = getToken(0).getType();
        if (t0 != token)
        {
            parseError("expected the symbol '",
                       ch,
                       "' but found the token ",
                       Pu::string(t0));
        }

        rule->insert(symbolId, _filePath, _scanner->line());
        advanceCursor();
    }

    void Parser::symbol(const int8_t symbolId)
    {
        Node* rule = _stack.top();

        switch (symbolId)
        {
        case SymbolOpenBrace:
            symbol(rule, symbolId, TokSymLBrace, '{');
            break;
        case SymbolCloseBrace:
            symbol(rule, symbolId, TokSymRBrace, '}');
            break;
        case SymbolSemiColon:
            symbol(rule, symbolId, TokSymSemicolon, ';');
            break;
        case SymbolLeftParenthesis:
            symbol(rule, symbolId, TokSymLPar, '(');
            break;
        case SymbolRightParenthesis:
            symbol(rule, symbolId, TokSymRPar, ')');
            break;
        case SymbolLeftBracket:
            symbol(rule, symbolId, TokSymLBracket, '[');
            break;
        case SymbolRightBracket:
            symbol(rule, symbolId, TokSymRBracket, ']');
            break;
        case SymbolComma:
            symbol(rule, symbolId, TokSymComma, ',');
            break;
        case SymbolEquals:
            symbol(rule, symbolId, TokOpEq, '=');
            break;
        case SymbolPlus:
            symbol(rule, symbolId, TokOpPlus, '+');
            break;
        case SymbolMinus:
            symbol(rule, symbolId, TokOpMinus, '-');
            break;
        case SymbolMultiply:
            symbol(rule, symbolId, TokOpMultiply, '*');
            break;
        case SymbolDivide:
            symbol(rule, symbolId, TokOpDivide, '/');
            break;
        case SymbolAnd:
            symbol(rule, symbolId, TokOpAnd, '&');
            break;
        case SymbolOr:
            symbol(rule, symbolId, TokOpOr, '|');
            break;
        case SymbolGreater:
            symbol(rule, symbolId, TokOpGt, '>');
            break;
        case SymbolLess:
            symbol(rule, symbolId, TokOpLt, '<');
            break;
        case SymbolNot:
            symbol(rule, symbolId, TokOpNot, '~');
            break;
        case SymbolPeriod:
            symbol(rule, symbolId, TokSymPeriod, '.');
            break;
        default:
            parseError("unknown symbol ", Nu::string(symbolId));
        }
    }

    void Parser::keyword(Node*        rule,
                         const int8_t symbolId,
                         const int    token,
                         const char*  kw)
    {
        const int8_t t0 = getToken(0).getType();
        if (t0 != token)
        {
            parseError("expected the keyword '",
                       kw,
                       "' but found the token ",
                       Pu::string(t0));
        }

        rule->insert(symbolId, _filePath, _scanner->line());
        advanceCursor();
    }

    void Parser::keyword(const int8_t symbolId)
    {
        Node* rule = _stack.top();
        switch (symbolId)
        {
        case KeywordClass:
            keyword(rule, symbolId, TokKwClass, "class");
            break;
        case KeywordConstructor:
            keyword(rule, symbolId, TokKwConstructor, "constructor");
            break;
        case KeywordFunction:
            keyword(rule, symbolId, TokKwFunction, "function");
            break;
        case KeywordMethod:
            keyword(rule, symbolId, TokKwMethod, "method");
            break;
        case KeywordField:
            keyword(rule, symbolId, TokKwField, "field");
            break;
        case KeywordStatic:
            keyword(rule, symbolId, TokKwStatic, "static");
            break;
        case KeywordInt:
            keyword(rule, symbolId, TokKwInt, "int");
            break;
        case KeywordChar:
            keyword(rule, symbolId, TokKwChar, "char");
            break;
        case KeywordBool:
            keyword(rule, symbolId, TokKwBool, "boolean");
            break;
        case KeywordVoid:
            keyword(rule, symbolId, TokKwVoid, "void");
            break;
        case KeywordVar:
            keyword(rule, symbolId, TokKwVar, "var");
            break;
        case KeywordLet:
            keyword(rule, symbolId, TokKwLet, "let");
            break;
        case KeywordIf:
            keyword(rule, symbolId, TokKwIf, "if");
            break;
        case KeywordElse:
            keyword(rule, symbolId, TokKwElse, "else");
            break;
        case KeywordDo:
            keyword(rule, symbolId, TokKwDo, "do");
            break;
        case KeywordWhile:
            keyword(rule, symbolId, TokKwWhile, "while");
            break;
        case KeywordReturn:
            keyword(rule, symbolId, TokKwReturn, "return");
            break;
        default:
            parseError("unknown keyword ", Nu::string(symbolId));
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
        if (t0 != TokSymRBrace)  // empty
        {
            do
            {
                // flow pivots around the static and field keywords

                if (t0 == TokKwStatic || t0 == TokKwField)
                    fieldRule();
                else
                    methodRule();

                reduceRule(rule);
                t0 = getToken(0).getType();

                checkEof();

            } while (t0 != TokSymRBrace);
        }
    }

    void Parser::identifierListRule()
    {
        createRule(RuleIdentifierList);

        constant(ConstantIdentifier);

        int8_t t0 = getToken(0).getType();
        if (t0 == TokSymComma)
        {
            do
            {
                advanceCursor();

                constant(ConstantIdentifier);

                t0 = getToken(0).getType();

                checkEof();
            } while (t0 == TokSymComma);
        }
    }

    void Parser::fieldSpecificationRule()
    {
        createRule(RuleFieldSpecification);

        switch (getToken(0).getType())
        {
        case TokKwField:
            keyword(KeywordField);
            break;
        case TokKwStatic:
            keyword(KeywordStatic);
            break;
        default:
            parseError("unknown field specifier '",
                       Pu::string(getToken(0).getType()),
                       "'. expected either field or static.");
        }
    }

    void Parser::dataTypeRule()
    {
        createRule(RuleDataType);

        switch (getToken(0).getType())
        {
        case TokKwInt:
            keyword(KeywordInt);
            break;
        case TokKwChar:
            keyword(KeywordChar);
            break;
        case TokKwBool:
            keyword(KeywordBool);
            break;
        case TokId:
            constant(ConstantIdentifier);
            break;
        default:
            parseError("unknown data type '",
                       Pu::string(getToken(0).getType()),
                       "'. expected int, char, bool or a class id");
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
        case TokKwConstructor:
            keyword(KeywordConstructor);
            break;
        case TokKwFunction:
            keyword(KeywordFunction);
            break;
        case TokKwMethod:
            keyword(KeywordMethod);
            break;
        default:
            parseError(
                "expected a method to be declared as a "
                "constructor, function or method. Found the token '",
                Pu::string(getToken(0).getType()),
                "' instead.");
        }
    }

    void Parser::methodReturnTypeRule()
    {
        Node* rule = createRule(RuleMethodReturnType);

        if (getToken(0).getType() == TokKwVoid)
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
        if (t0 != TokSymRBrace)  // handle empty
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

            if (t0 == TokKwVar)
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

        } while (t0 != TokSymRBrace);
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
        case TokKwLet:
            letStatementRule();
            reduceRule(rule);
            break;
        case TokKwIf:
            ifStatementRule();
            reduceRule(rule);
            break;
        case TokKwElse:
            elseStatementRule();
            reduceRule(rule);
            break;
        case TokKwDo:
            doStatementRule();
            reduceRule(rule);
            break;
        case TokKwWhile:
            whileStatementRule();
            reduceRule(rule);
            break;
        case TokKwReturn:
            returnStatementRule();
            reduceRule(rule);
            break;
        default:
            parseError(
                "expected a statement token "
                "let, if, else, do, while or return, but"
                " found the token ",
                Pu::string(getToken(0).getType()),
                " instead.");
        }
    }

    void Parser::letStatementRule()
    {
        Node* rule = createRule(RuleLetStatement);

        keyword(KeywordLet);

        constant(ConstantIdentifier);

        const int8_t t0 = getToken(0).getType();

        if (t0 == TokOpEq)
        {
            rule->subtype(SubtypeLetEqual);

            symbol(SymbolEquals);

            expressionRule();
            reduceRule(rule);

            symbol(SymbolSemiColon);
        }
        else if (t0 == TokSymLBracket)
        {
            rule->subtype(SubtypeLetArrayEqual);

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
        if (t0 == TokKwElse)
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
        if (t0 != TokSymSemicolon)
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

        if (t0 != TokSymRBrace)
        {
            do
            {
                statementRule();
                reduceRule(rule);

                checkEof();

                t0 = getToken(0).getType();

            } while (t0 != TokSymRBrace);
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

        } while (!Pu::isExpressionExitTerm(getToken(0).getType()));
    }

    void Parser::singleExpressionRule()
    {
        Node* rule = createRule(RuleSingleExpression);

        const int8_t tp = getToken(-1).getType();
        const int8_t t0 = getToken(0).getType();
        const int8_t t1 = getToken(1).getType();

        if (Pu::isUnary(t0, t1, tp))
        {
            rule->subtype(SubtypeOpTerm);

            unaryOperatorRule();
            reduceRule(rule);

            termRule();
            reduceRule(rule);
        }
        else if (Pu::isOperator(getToken(0).getType()) && Pu::isTerm(t1))
        {
            rule->subtype(SubtypeOpTerm);

            operatorRule();
            reduceRule(rule);

            termRule();
            reduceRule(rule);
        }
        else if (Pu::isTerm(t0))
        {
            rule->subtype(SubtypeTerm);

            termRule();
            reduceRule(rule);
        }
        else if (t0 != TokSymRBracket && t0 != TokSymSemicolon && t0 != TokSymRPar)
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

        if (Pu::isComplexTerm(t0, t1, t2, t3))
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
        case TokId:
            constant(ConstantIdentifier);
            break;
        case TokInt:
            constant(ConstantInteger);
            break;
        case TokKwTrue:
            constant(ConstantTrue);
            break;
        case TokKwFalse:
            constant(ConstantFalse);
            break;
        case TokKwNull:
            constant(ConstantNull);
            break;
        case TokKwThis:
            constant(ConstantThis);
            break;
        case TokString:
            constant(ConstantString);
            break;
        default:
            parseError("unknown token ", Pu::string(t0));
        }
    }

    void Parser::complexTermRule()
    {
        Node* rule = createRule(RuleComplexTerm);

        const int8_t t0 = getToken(0).getType();
        const int8_t t1 = getToken(1).getType();
        const int8_t t2 = getToken(2).getType();
        const int8_t t3 = getToken(3).getType();

        if (t0 == TokSymLPar)
        {
            rule->subtype(SubtypeExpressionGroup);

            symbol(SymbolLeftParenthesis);

            expressionRule();
            reduceRule(rule);

            symbol(SymbolRightParenthesis);
        }
        else if (t0 == TokId && t1 == TokSymLBracket)
        {
            rule->subtype(SubtypeArrayIndex);

            constant(ConstantIdentifier);

            symbol(SymbolLeftBracket);

            expressionRule();
            reduceRule(rule);

            symbol(SymbolRightBracket);
        }
        else if (Pu::isCallTerm(t0, t1, t2, t3))
        {
            rule->subtype(SubtypeCall);

            callMethodRule();
            reduceRule(rule);
        }
        else
        {
            parseError("Unknown complex term.",
                       "found tokens: ",
                       Pu::string(t0),
                       ' ',
                       Pu::string(t1),
                       ' ',
                       Pu::string(t2),
                       ' ',
                       Pu::string(t3));
        }
    }

    void Parser::operatorRule()
    {
        createRule(RuleOperator);

        const int8_t t0 = getToken(0).getType();

        switch (t0)
        {
        case TokOpPlus:
            symbol(SymbolPlus);
            break;
        case TokOpMinus:
            symbol(SymbolMinus);
            break;
        case TokOpMultiply:
            symbol(SymbolMultiply);
            break;
        case TokOpDivide:
            symbol(SymbolDivide);
            break;
        case TokOpAnd:
            symbol(SymbolAnd);
            break;
        case TokOpOr:
            symbol(SymbolOr);
            break;
        case TokOpGt:
            symbol(SymbolGreater);
            break;
        case TokOpLt:
            symbol(SymbolLess);
            break;
        case TokOpEq:
            symbol(SymbolEquals);
            break;
        default:
            parseError("unknown symbol ", Pu::string(t0));
        }
    }

    void Parser::unaryOperatorRule()
    {
        createRule(RuleUnaryOperator);

        const int8_t t0 = getToken(0).getType();

        if (t0 == TokOpMinus)
            symbol(SymbolMinus);
        else if (t0 == TokOpNot)
            symbol(SymbolNot);
        else
        {
            parseError(
                "expected a '-', '~', or '!' "
                "character, but found the token ",
                Pu::string(t0),
                " instead.");
        }
    }

    void Parser::expressionListRule()
    {
        Node* rule = createRule(RuleExpressionList);

        int8_t t0 = getToken(0).getType();

        if (t0 != TokSymRPar)  // empty case
        {
            do
            {
                expressionRule();
                reduceRule(rule);

                checkEof();

                t0 = getToken(0).getType();
                if (t0 == TokSymComma)
                {
                    advanceCursor();
                    t0 = getToken(0).getType();
                }
            } while (t0 != TokSymRPar);
        }
    }

    void Parser::callMethodRule()
    {
        Node* rule = createRule(RuleCallMethod);

        const int8_t t0 = getToken(0).getType();
        const int8_t t1 = getToken(1).getType();
        const int8_t t2 = getToken(2).getType();
        const int8_t t3 = getToken(3).getType();

        if (Pu::isFunctionCall(t0, t1))
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
        else if (Pu::isMethodCall(t0, t1, t2, t3))
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
        if (t0 != TokSymRPar)  // empty case
        {
            do
            {
                parameterRule();
                reduceRule(rule);

                t0 = getToken(0).getType();
                if (t0 == TokSymComma)
                    advanceCursor();

                checkEof();

            } while (t0 != TokSymRPar);
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

        _tree->filename(_filePath);

        while (_cursor <= (int32_t)_tokens.size())
        {
            const int8_t tok = getToken(0).getType();
            if (tok == TokEof)
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
