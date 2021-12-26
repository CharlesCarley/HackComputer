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
#include "Compiler/Common/NodeUtils.h"
#include "Node.h"

#define BEGIN_ENUM_TO_STR(x, d) \
    switch (x)               \
    {                        \
    default:                 \
        dest = d;    \
        break

#define CASE_TO_STR_F(x) \
    case x:

#define CASE_TO_STR_A(x) \
    case x:              \
        dest = #x;       \
        break
#define CASE_TO_STR_V(x, v) \
    case x:                 \
        dest = v;           \
        break

#define END_ENUM_TO_STR() }

namespace Hack::Compiler
{
    void NodeUtils::nodeTypeString(String& dest, Node* node)
    {
        BEGIN_ENUM_TO_STR(node->type(), "Unknown");
        CASE_TO_STR_A(Rule);
        CASE_TO_STR_A(RuleClass);
        CASE_TO_STR_A(RuleClassDescription);
        CASE_TO_STR_A(RuleField);
        CASE_TO_STR_A(RuleDataType);
        CASE_TO_STR_A(RuleFieldSpecification);
        CASE_TO_STR_A(RuleIdentifierList);
        CASE_TO_STR_A(RuleMethod);
        CASE_TO_STR_A(RuleMethodSpecification);
        CASE_TO_STR_A(RuleMethodReturnType);
        CASE_TO_STR_A(RuleMethodBody);
        CASE_TO_STR_A(RuleBody);
        CASE_TO_STR_A(RuleVariable);
        CASE_TO_STR_A(RuleStatement);
        CASE_TO_STR_A(RuleLetStatement);
        CASE_TO_STR_A(RuleIfStatement);
        CASE_TO_STR_A(RuleElseStatement);
        CASE_TO_STR_A(RuleWhileStatement);
        CASE_TO_STR_A(RuleDoStatement);
        CASE_TO_STR_A(RuleReturnStatement);
        CASE_TO_STR_A(RuleStatementList);
        CASE_TO_STR_A(RuleExpression);
        CASE_TO_STR_A(RuleSingleExpression);
        CASE_TO_STR_A(RuleTerm);
        CASE_TO_STR_A(RuleSimpleTerm);
        CASE_TO_STR_A(RuleComplexTerm);
        CASE_TO_STR_A(RuleOperator);
        CASE_TO_STR_A(RuleUnaryOperator);
        CASE_TO_STR_A(RuleExpressionList);
        CASE_TO_STR_A(RuleCallMethod);
        CASE_TO_STR_A(RuleParameterList);
        CASE_TO_STR_A(RuleParameter);
        CASE_TO_STR_A(RuleEnd);
        CASE_TO_STR_A(Keyword);
        CASE_TO_STR_A(KeywordClass);
        CASE_TO_STR_A(KeywordConstructor);
        CASE_TO_STR_A(KeywordFunction);
        CASE_TO_STR_A(KeywordMethod);
        CASE_TO_STR_A(KeywordField);
        CASE_TO_STR_A(KeywordStatic);
        CASE_TO_STR_A(KeywordInt);
        CASE_TO_STR_A(KeywordChar);
        CASE_TO_STR_A(KeywordBool);
        CASE_TO_STR_A(KeywordVoid);
        CASE_TO_STR_A(KeywordVar);
        CASE_TO_STR_A(KeywordLet);
        CASE_TO_STR_A(KeywordIf);
        CASE_TO_STR_A(KeywordElse);
        CASE_TO_STR_A(KeywordDo);
        CASE_TO_STR_A(KeywordWhile);
        CASE_TO_STR_A(KeywordReturn);
        CASE_TO_STR_A(KeywordEnd);
        CASE_TO_STR_A(Symbol);
        CASE_TO_STR_A(SymbolOpenBrace);
        CASE_TO_STR_A(SymbolCloseBrace);
        CASE_TO_STR_A(SymbolSemiColon);
        CASE_TO_STR_A(SymbolLeftParenthesis);
        CASE_TO_STR_A(SymbolRightParenthesis);
        CASE_TO_STR_A(SymbolLeftBracket);
        CASE_TO_STR_A(SymbolRightBracket);
        CASE_TO_STR_A(SymbolComma);
        CASE_TO_STR_A(SymbolEquals);
        CASE_TO_STR_A(SymbolPlus);
        CASE_TO_STR_A(SymbolMinus);
        CASE_TO_STR_A(SymbolMultiply);
        CASE_TO_STR_A(SymbolDivide);
        CASE_TO_STR_A(SymbolAnd);
        CASE_TO_STR_A(SymbolOr);
        CASE_TO_STR_A(SymbolGreater);
        CASE_TO_STR_A(SymbolLess);
        CASE_TO_STR_A(SymbolNot);
        CASE_TO_STR_A(SymbolPeriod);
        CASE_TO_STR_A(SymbolEnd);
        CASE_TO_STR_A(Constant);
        CASE_TO_STR_A(ConstantIdentifier);
        CASE_TO_STR_A(ConstantInteger);
        CASE_TO_STR_A(ConstantString);
        CASE_TO_STR_A(ConstantTrue);
        CASE_TO_STR_A(ConstantFalse);
        CASE_TO_STR_A(ConstantNull);
        CASE_TO_STR_A(ConstantThis);
        CASE_TO_STR_A(ConstantEnd);
        CASE_TO_STR_A(SubtypeNone);
        CASE_TO_STR_A(SubtypeExpressionGroup);
        CASE_TO_STR_A(SubtypeCall);
        CASE_TO_STR_A(SubtypeCallFunction);
        CASE_TO_STR_A(SubtypeCallMethod);
        CASE_TO_STR_A(SubtypeArrayIndex);
        CASE_TO_STR_A(SubtypeIfElseCombo);
        CASE_TO_STR_A(SubtypeTerm);
        CASE_TO_STR_A(SubtypeOpTerm);
        CASE_TO_STR_A(SubtypeLetEqual);
        CASE_TO_STR_A(SubtypeLetArrayEqual);
        END_ENUM_TO_STR()
    }

    void NodeUtils::nodeTypeXmlString(String& dest, Node* node)
    {
        BEGIN_ENUM_TO_STR(node->type(), "Unknown");
        CASE_TO_STR_A(Rule);
        CASE_TO_STR_A(RuleClass);
        CASE_TO_STR_A(RuleClassDescription);
        CASE_TO_STR_A(RuleField);
        CASE_TO_STR_A(RuleDataType);
        CASE_TO_STR_A(RuleFieldSpecification);
        CASE_TO_STR_A(RuleIdentifierList);
        CASE_TO_STR_A(RuleMethod);
        CASE_TO_STR_A(RuleMethodSpecification);
        CASE_TO_STR_A(RuleMethodReturnType);
        CASE_TO_STR_A(RuleMethodBody);
        CASE_TO_STR_A(RuleBody);
        CASE_TO_STR_A(RuleVariable);
        CASE_TO_STR_A(RuleStatement);
        CASE_TO_STR_A(RuleLetStatement);
        CASE_TO_STR_A(RuleIfStatement);
        CASE_TO_STR_A(RuleElseStatement);
        CASE_TO_STR_A(RuleWhileStatement);
        CASE_TO_STR_A(RuleDoStatement);
        CASE_TO_STR_A(RuleReturnStatement);
        CASE_TO_STR_A(RuleStatementList);
        CASE_TO_STR_A(RuleExpression);
        CASE_TO_STR_A(RuleSingleExpression);
        CASE_TO_STR_A(RuleTerm);
        CASE_TO_STR_A(RuleSimpleTerm);
        CASE_TO_STR_A(RuleComplexTerm);
        CASE_TO_STR_A(RuleOperator);
        CASE_TO_STR_A(RuleUnaryOperator);
        CASE_TO_STR_A(RuleExpressionList);
        CASE_TO_STR_A(RuleCallMethod);
        CASE_TO_STR_A(RuleParameterList);
        CASE_TO_STR_A(RuleParameter);
        CASE_TO_STR_A(RuleEnd);
        CASE_TO_STR_A(Keyword);
        CASE_TO_STR_V(KeywordClass, "class");
        CASE_TO_STR_V(KeywordConstructor, "constructor");
        CASE_TO_STR_V(KeywordFunction, "function");
        CASE_TO_STR_V(KeywordMethod, "method");
        CASE_TO_STR_V(KeywordField, "field");
        CASE_TO_STR_V(KeywordStatic, "static");
        CASE_TO_STR_V(KeywordInt, "int");
        CASE_TO_STR_V(KeywordChar, "char");
        CASE_TO_STR_V(KeywordBool, "boolean");
        CASE_TO_STR_V(KeywordVoid, "void");
        CASE_TO_STR_V(KeywordVar, "var");
        CASE_TO_STR_V(KeywordLet, "let");
        CASE_TO_STR_V(KeywordIf, "if");
        CASE_TO_STR_V(KeywordElse, "else");
        CASE_TO_STR_V(KeywordDo, "do");
        CASE_TO_STR_V(KeywordWhile, "while");
        CASE_TO_STR_V(KeywordReturn, "return");
        CASE_TO_STR_A(KeywordEnd);
        CASE_TO_STR_A(Symbol);
        CASE_TO_STR_V(SymbolOpenBrace, "{");
        CASE_TO_STR_V(SymbolCloseBrace, "}");
        CASE_TO_STR_V(SymbolSemiColon, ";");
        CASE_TO_STR_V(SymbolLeftParenthesis, "(");
        CASE_TO_STR_V(SymbolRightParenthesis, ")");
        CASE_TO_STR_V(SymbolLeftBracket, "[");
        CASE_TO_STR_V(SymbolRightBracket, "]");
        CASE_TO_STR_V(SymbolComma, ",");
        CASE_TO_STR_V(SymbolEquals, "=");
        CASE_TO_STR_V(SymbolPlus, "+");
        CASE_TO_STR_V(SymbolMinus, "-");
        CASE_TO_STR_V(SymbolMultiply, "*");
        CASE_TO_STR_V(SymbolDivide, "/");
        CASE_TO_STR_V(SymbolAnd, "&amp;");
        CASE_TO_STR_V(SymbolOr, "|");
        CASE_TO_STR_V(SymbolGreater, "&gt;");
        CASE_TO_STR_V(SymbolLess, "&lt;");
        CASE_TO_STR_V(SymbolNot, "!");
        CASE_TO_STR_V(SymbolPeriod, ".");
        CASE_TO_STR_A(SymbolEnd);
        CASE_TO_STR_A(Constant);
        CASE_TO_STR_F(ConstantIdentifier);
        CASE_TO_STR_F(ConstantInteger);
        CASE_TO_STR_V(ConstantString, node->value());
        CASE_TO_STR_V(ConstantTrue, "true");
        CASE_TO_STR_V(ConstantFalse, "false");
        CASE_TO_STR_V(ConstantNull, "null");
        CASE_TO_STR_V(ConstantThis, "this");
        CASE_TO_STR_A(ConstantEnd);
        CASE_TO_STR_A(SubtypeNone);
        CASE_TO_STR_A(SubtypeExpressionGroup);
        CASE_TO_STR_A(SubtypeCall);
        CASE_TO_STR_A(SubtypeCallFunction);
        CASE_TO_STR_A(SubtypeCallMethod);
        CASE_TO_STR_A(SubtypeArrayIndex);
        CASE_TO_STR_A(SubtypeIfElseCombo);
        CASE_TO_STR_A(SubtypeTerm);
        CASE_TO_STR_A(SubtypeOpTerm);
        CASE_TO_STR_A(SubtypeLetEqual);
        CASE_TO_STR_A(SubtypeLetArrayEqual);
        END_ENUM_TO_STR()
    }

    /// <summary>
    /// Returns a exact string representation of the Subtype_ name
    /// </summary>
    /// <param name="dest"></param>
    /// <param name="node"></param>
    void NodeUtils::nodeSubtypeString(String& dest, Node* node)
    {
        BEGIN_ENUM_TO_STR(node->subtype(), "Unknown");
        CASE_TO_STR_A(SubtypeNone);
        CASE_TO_STR_A(SubtypeExpressionGroup);
        CASE_TO_STR_A(SubtypeCall);
        CASE_TO_STR_A(SubtypeCallFunction);
        CASE_TO_STR_A(SubtypeCallMethod);
        CASE_TO_STR_A(SubtypeArrayIndex);
        CASE_TO_STR_A(SubtypeIfElseCombo);
        CASE_TO_STR_A(SubtypeTerm);
        CASE_TO_STR_A(SubtypeOpTerm);
        CASE_TO_STR_A(SubtypeLetEqual);
        CASE_TO_STR_A(SubtypeLetArrayEqual);
        END_ENUM_TO_STR()
    }

}  // namespace Hack::Compiler
