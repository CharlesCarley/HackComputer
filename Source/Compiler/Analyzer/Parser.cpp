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
#include "Utils/Exceptions/Exception.h"

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

    void Parser::classDescription()
    {
    }

    void Parser::classExpression()
    {
        const int8_t t0 = getToken(0).getType();
        if (t0 != TOK_KW_CLASS)
            throw Exception("Expected the class keyword");

        const int8_t t1 = getToken(1).getType();
        if (t1 != TOK_IDENTIFIER)
            throw Exception("Expected class <identifier>");

        const int8_t t2 = getToken(2).getType();
        if (t2 != TOK_L_BRACE)
            throw Exception("Expected open brace, "
                "class <identifier> '{'");


        ParseTreeNode* root = _tree->getRoot();

        ParseTreeNode* cls = new ParseTreeNode(TOK_KW_CLASS);
        root->addChild(cls);

        ParseTreeNode* clsId = new ParseTreeNode(TOK_IDENTIFIER,
                                                 _scanner->getString(getToken(1).getIndex()));

        cls->addChild(clsId);
        cls->addChild(new ParseTreeNode(TOK_L_BRACE));

        _stack.push(cls);

        advanceCursor(3);
        classDescription();

        if (_stack.top() != cls)
            cls->addChild(_stack.top());

        _stack.pop();

        const int8_t tf = getToken(0).getType();
        if (tf != TOK_R_BRACE)
            throw Exception(
                "Expected closing brace, "
                "class <identifier> '{' <ClassDescription> '}'");

        cls->addChild(new ParseTreeNode(TOK_R_BRACE));
        advanceCursor();
    }

    void Parser::parseImpl(IStream& is)
    {
        // make sure the token cursor is at zero
        // initially and attach the input stream
        // to the scanner
        _cursor = 0;
        _scanner->attach(&is);

        while (_cursor <= (int32_t)_tokens.size())
        {
            const int8_t tok = getToken(0).getType();
            if (tok == TOK_EOF)
                break;

            const int32_t op = _cursor;
            classExpression();

            // if the cursor did not
            // advance force it to.
            if (op == _cursor)
                advanceCursor();
        }
    }

    void Parser::writeImpl(OStream& os)
    {
        if (!_tree)
            throw Exception("invalid parse tree");

        _tree->write(os);
    }

}  // namespace Hack::Compiler::Analyzer
