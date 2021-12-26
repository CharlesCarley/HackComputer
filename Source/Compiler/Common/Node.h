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
#include <functional>
#include <vector>
#include "Utils/IndexCache.h"
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

        SubtypeNone,
        SubtypeExpressionGroup,
        SubtypeCall,
        SubtypeCallFunction,
        SubtypeCallMethod,
        SubtypeArrayIndex,
        SubtypeIfElseCombo,

    };

    class Node
    {
    public:
        typedef IndexCache<Node*>               Children;
        typedef Children::Array                 NodeArray;
        typedef Children::Array::const_iterator Iterator;

    private:
        Node*    _parent;
        Children _children;
        int8_t   _type;
        int8_t   _subtype;
        String   _data;

        const Node& check(size_t idx, int8_t symbolId, bool generalCase) const;

    public:
        Node();

        explicit Node(int8_t type);

        Node(int8_t type, String data);

        ~Node();

        void type(int8_t type);

        int8_t type() const;

        void subtype(int8_t type);

        int8_t subtype() const;

        bool isTypeOf(int symbolId) const;

        bool isSubtypeOf(int symbolId) const;

        void filter(NodeArray& dest, int8_t symbolId) const;

        const Node& rule(size_t idx, int8_t symbolId = Rule) const;

        const Node& keyword(size_t idx, int8_t symbolId = Keyword) const;

        const Node& symbol(size_t idx, int8_t symbolId = Symbol) const;

        const Node& constant(size_t idx, int8_t symbolId = Constant) const;

        bool isRule() const;

        bool isKeyword() const;

        bool isConstant() const;

        bool isOperator() const;

        bool isSymbol() const;

        void value(const String& data);

        const String& value() const;

        size_t size() const;

        const Children& children() const;

        const Node& parent() const;

        const Node& child(size_t idx) const;

        void insert(Node* node);

        void insert(int8_t type, const String& data);

        void insert(int8_t type);

        Iterator begin() const;

        Iterator end() const;
    };

    inline void Node::type(const int8_t type)
    {
        _type = type;
    }

    inline int8_t Node::type() const
    {
        return _type;
    }

    inline void Node::subtype(int8_t type)
    {
        _subtype = type;
    }

    inline int8_t Node::subtype() const
    {
        return _subtype;
    }

    inline bool Node::isTypeOf(const int symbolId) const
    {
        return _type == symbolId;
    }

    inline bool Node::isSubtypeOf(const int symbolId) const
    {
        return _subtype == symbolId;
    }

    inline bool Node::isRule() const
    {
        return _type > Rule && _type < RuleEnd;
    }

    inline bool Node::isKeyword() const
    {
        return _type > Keyword && _type < KeywordEnd;
    }

    inline bool Node::isConstant() const
    {
        return _type > Constant && _type < ConstantEnd;
    }

    inline bool Node::isSymbol() const
    {
        return _type > Symbol && _type < SymbolEnd;
    }

    inline void Node::value(const String& data)
    {
        _data = data;
    }

    inline const String& Node::value() const
    {
        return _data;
    }

    inline size_t Node::size() const
    {
        return _children.size();
    }

    inline const Node::Children& Node::children() const
    {
        return _children;
    }

    inline const Node& Node::parent() const
    {
        if (!_parent)
            throw InvalidPointer();
        return *_parent;
    }

    inline Node::Iterator Node::begin() const
    {
        return _children.begin();
    }

    inline Node::Iterator Node::end() const
    {
        return _children.end();
    }

}  // namespace Hack::Compiler
