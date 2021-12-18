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
#include "Compiler/Common/ParseTree.h"
#include "Utils/ParserBase/ParserBase.h"
#include "Utils/String.h"

namespace Hack::Compiler::Analyzer
{
    class Scanner;

    class Parser final : public ParserBase
    {
    public:
        typedef std::stack<ParseTreeNode*> NodeStack;

    private:
        ParseTree* _tree;
        NodeStack  _stack;

    private:
        void parseImpl(IStream& is) override;

        void writeImpl(OStream& os) override;

        void reduceRule(ParseTreeNode* node);

        ParseTreeNode* createRule(const int8_t& name);

        static bool isOperator(int8_t id);

        static bool testComplexTerm(int8_t t0, int8_t t1, int8_t t2, int8_t t3);

        void classRule();

        void classDescriptionRule();

        void identifier(ParseTreeNode* rule);

        void identifier(ParseTreeNode* rule, int8_t symbolId, int token);

        void symbol(ParseTreeNode* rule, int8_t symbolId, int token, char ch);

        void keyword(ParseTreeNode* rule, int8_t symbolId, int token, const char* kw);

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
    };

}  // namespace Hack::Compiler::Analyzer
