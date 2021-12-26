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
#include <stack>
#include "Compiler/Common/Tree.h"
#include "Utils/Exceptions/Exception.h"
#include "Utils/ParserBase/ParserBase.h"
#include "Utils/String.h"

namespace Hack::Compiler::Analyzer
{
    class Scanner;

    class Parser final : public ParserBase
    {
    public:
        typedef std::stack<Node*> NodeStack;

    private:
        Tree*     _tree;
        NodeStack _stack;

    private:
        void parseImpl(IStream& is) override;

        void writeImpl(OStream& os, int format = 0) override;

        void reduceRule(Node* node);

        Node* createRule(const int8_t& name);

        void checkEof();

        void classRule();

        void classDescriptionRule();

        void identifier(Node* rule);

        void identifier(Node* rule, int8_t symbolId, int token);

        void constant(int8_t symbolId);

        void object(int8_t symbolId);

        void symbol(Node* rule, int8_t symbolId, int token, char ch);

        void symbol(int8_t symbolId);

        void keyword(Node* rule, int8_t symbolId, int token, const char* kw);

        void keyword(int8_t symbolId);

        void identifierListRule();

        void fieldRule();

        void fieldSpecificationRule();

        void dataTypeRule();

        void methodRule();

        void methodSpecificationRule();

        void methodReturnTypeRule();

        void methodBodyRule();

        void bodyRule();

        void variableRule();

        void statementRule();

        void letStatementRule();

        void ifStatementRule();

        void elseStatementRule();

        void whileStatementRule();

        void doStatementRule();

        void returnStatementRule();

        void statementListRule();

        void expressionRule();

        void singleExpressionRule();

        void termRule();

        void simpleTermRule();

        void complexTermRule();

        void operatorRule();

        void unaryOperatorRule();

        void expressionListRule();

        void callMethodRule();

        void parameterListRule();

        void parameterRule();

    public:
        Parser();

        ~Parser() override;

        const Tree& getTree() const;
    };

    inline const Tree& Parser::getTree() const
    {
        if (!_tree)
            throw Exception("null tree");
        return *_tree;
    }


}  // namespace Hack::Compiler::Analyzer
