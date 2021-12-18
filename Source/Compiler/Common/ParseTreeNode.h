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
#include <vector>
#include "Utils/String.h"

namespace Hack::Compiler
{
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
    };

    class ParseTreeNode
    {
    public:
        typedef std::vector<ParseTreeNode*> Children;

    private:
        ParseTreeNode* _parent;
        Children       _children;
        int8_t         _type;
        String         _data;

    public:
        ParseTreeNode();

        explicit ParseTreeNode(int8_t type);

        ParseTreeNode(int8_t type, String data);

        ~ParseTreeNode();

        void setType(int8_t type);

        int8_t getType() const;

        bool isRule() const;

        bool isKeyword() const;

        bool isConstant() const;

        bool isSymbol() const;

        void setData(const String& data);

        const String& getData() const;

        size_t getChildCount() const;

        const Children& getChildren();

        ParseTreeNode* getParent() const;

        ParseTreeNode* getChild(size_t idx);

        void addChild(ParseTreeNode* node);

        void addChild(int8_t type, const String& data);

        void addChild(int8_t type);
    };

    inline void ParseTreeNode::setType(const int8_t type)
    {
        _type = type;
    }

    inline int8_t ParseTreeNode::getType() const
    {
        return _type;
    }

    inline bool ParseTreeNode::isRule() const
    {
        return _type > Rule && _type < RuleEnd;
    }

    inline bool ParseTreeNode::isKeyword() const
    {
        return _type > Keyword && _type < KeywordEnd;
    }

    inline bool ParseTreeNode::isConstant() const
    {
        return _type > Constant && _type < ConstantEnd;
    }

    inline bool ParseTreeNode::isSymbol() const
    {
        return _type > Symbol && _type < SymbolEnd;
    }

    inline void ParseTreeNode::setData(const String& data)
    {
        _data = data;
    }

    inline const String& ParseTreeNode::getData() const
    {
        return _data;
    }

    inline size_t ParseTreeNode::getChildCount() const
    {
        return _children.size();
    }

    inline const ParseTreeNode::Children& ParseTreeNode::getChildren()
    {
        return _children;
    }

    inline ParseTreeNode* ParseTreeNode::getParent() const
    {
        return _parent;
    }

}  // namespace Hack::Compiler
