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
#pragma once
#include "Utils/String.h"

namespace Hack::Compiler
{
    class Node;

    enum NodeType
    {
        Rule,
        RuleClass,
        RuleClassDescription,
        RuleField,
        RuleDataType,
        RuleFieldSpecification,
        RuleIdentifierList,
        RuleMethod,
        RuleMethodSpecification,
        RuleMethodReturnType,
        RuleMethodBody,
        RuleBody,
        RuleVariable,
        RuleStatement,
        RuleLetStatement,
        RuleIfStatement,
        RuleElseStatement,
        RuleWhileStatement,
        RuleDoStatement,
        RuleReturnStatement,
        RuleStatementList,
        RuleExpression,
        RuleSingleExpression,
        RuleTerm,
        RuleSimpleTerm,
        RuleComplexTerm,
        RuleOperator,
        RuleUnaryOperator,
        RuleExpressionList,
        RuleCallMethod,
        RuleParameterList,
        RuleParameter,
        RuleEnd,

        Keyword,
        KeywordClass,
        KeywordConstructor,
        KeywordFunction,
        KeywordMethod,
        KeywordField,
        KeywordStatic,
        KeywordInt,
        KeywordChar,
        KeywordBool,
        KeywordVoid,
        KeywordVar,
        KeywordLet,
        KeywordIf,
        KeywordElse,
        KeywordDo,
        KeywordWhile,
        KeywordReturn,
        KeywordEnd,

        Symbol,
        SymbolOpenBrace,
        SymbolCloseBrace,
        SymbolSemiColon,
        SymbolLeftParenthesis,
        SymbolRightParenthesis,
        SymbolLeftBracket,
        SymbolRightBracket,
        SymbolComma,
        SymbolEquals,
        SymbolPlus,
        SymbolMinus,
        SymbolMultiply,
        SymbolDivide,
        SymbolAnd,
        SymbolOr,
        SymbolGreater,
        SymbolLess,
        SymbolNot,
        SymbolPeriod,
        SymbolEnd,

        Constant,
        ConstantIdentifier,
        ConstantInteger,
        ConstantString,
        ConstantTrue,
        ConstantFalse,
        ConstantNull,
        ConstantThis,
        ConstantEnd,

        SubtypeNone,
        SubtypeExpressionGroup,
        SubtypeCall,
        SubtypeCallFunction,
        SubtypeCallMethod,
        SubtypeArrayIndex,
        SubtypeIfElseCombo,
        SubtypeTerm,
        SubtypeOpTerm,
        SubtypeLetEqual,
        SubtypeLetArrayEqual,
    };

    class NodeUtils
    {
    public:
        /// <summary>
        /// Returns a exact string representation of the enum name
        /// </summary>
        static String string(int8_t type);

        /// <summary>
        /// Returns a exact string representation of the enum name
        /// </summary>
        /// <param name="dest"></param>
        /// <param name="node"></param>
        static void nodeTypeString(String& dest, Node* node);
        /// <summary>
        /// Returns an XML representation of the enum name
        /// </summary>
        /// <param name="dest"></param>
        /// <param name="type"></param>
        static void nodeTypeXmlString(String& dest, Node* node);

        /// <summary>
        /// Returns a exact string representation of the Subtype_ name
        /// </summary>
        /// <param name="dest"></param>
        /// <param name="node"></param>
        static void nodeSubtypeString(String& dest, Node* node);
    };

}  // namespace Hack::Compiler
