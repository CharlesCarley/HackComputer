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

    void Parser::reduceRule(ParseTreeNode* node)
    {
        if (_stack.empty())
            throw Exception("No rules on the stack");

        if (_stack.top() != node)
        {
            ParseTreeNode* resolved = _stack.top();

            const int8_t type = resolved->getType();
            if (type > Rule && type < RuleEnd)
                node->addChild(resolved);
            else
                throw Exception("Expected a reduced rule");

            _stack.pop();
        }
    }

    ParseTreeNode* Parser::createRule(const int8_t& name)
    {
        ParseTreeNode* rule = new ParseTreeNode(name);
        _stack.push(rule);
        return rule;
    }

    void Parser::identifier(ParseTreeNode* rule)
    {
        const int8_t t0 = getToken(0).getType();
        if (t0 != TOK_IDENTIFIER)
            throw Exception("expected an identifier");

        const size_t id = getToken(0).getIndex();
        rule->addChild(ConstantIdentifier, _scanner->getString(id));

        
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
                identifier(rule);
                advanceCursor();

                t1 = getToken(0).getType();
                if (t1 == TOK_EOF)
                    throw Exception("expected a comma");
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
        ParseTreeNode* rule = createRule(RuleFieldSpecification);

        const int8_t t0 = getToken(0).getType();
        if (t0 == TOK_KW_FIELD)
            rule->addChild(KeywordField);
        else if (t0 == TOK_KW_STATIC)
            rule->addChild(KeywordStatic);
        else
            throw Exception("Undefined field specifier");

        advanceCursor();

    }


    void Parser::dataTypeRule()
    {
        ParseTreeNode* rule = createRule(RuleDataType);
        String         val;

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
            throw Exception("Undefined data type");
        }
        advanceCursor();

    }


    void Parser::fieldRule()
    {
        ParseTreeNode* rule = createRule(RuleField);

        fieldSpecificationRule();
        reduceRule(rule);

        dataTypeRule();
        reduceRule(rule);

        identifierListRule();
        reduceRule(rule);

        const int8_t t0 = getToken(0).getType();
        if (t0 != TOK_SEMICOLON)
            throw Exception("Expected a semi colon");
        rule->addChild(SymbolSemiColon);
        advanceCursor();
    }

    void Parser::methodRule()
    {
        ParseTreeNode* rule = createRule(RuleMethod);
    }

    void Parser::classDescriptionRule()
    {
        ParseTreeNode* rule = createRule(RuleClassDescription);

        int8_t t0 = getToken(0).getType();

        //   <ClassList> <Field> | <ClassList> <Method>
        while (t0 != TOK_R_BRACE && t0 != TOK_EOF)
        {
            if (t0 == TOK_KW_STATIC || t0 == TOK_KW_FIELD)
                fieldRule();
            else
                methodRule();

            reduceRule(rule);
            t0 = getToken(0).getType();
        }
    }

    void Parser::classRule()
    {
        const int8_t t0 = getToken(0).getType();
        if (t0 != TOK_KW_CLASS)
            throw Exception("Expected the class keyword");

        const int8_t t1 = getToken(1).getType();
        if (t1 != TOK_IDENTIFIER)
            throw Exception("Expected class <identifier>");

        const int8_t t2 = getToken(2).getType();
        if (t2 != TOK_L_BRACE)
            throw Exception(
                "Expected open brace, "
                "class <identifier> '{'");

        ParseTreeNode* root = _tree->getRoot();

        ParseTreeNode* rule = createRule(RuleClass);
        root->addChild(rule);

        String val;
        _scanner->getString(val, getToken(1).getIndex());

        rule->addChild(KeywordClass);
        rule->addChild(ConstantIdentifier, val);
        rule->addChild(SymbolOpenBrace);

        advanceCursor(3);

        classDescriptionRule();
        reduceRule(rule);

        const int8_t tf = getToken(0).getType();
        if (tf != TOK_R_BRACE)
        {
            throw Exception(
                "Expected closing brace, "
                "class <identifier> '{' <ClassDescription> '}'");
        }

        rule->addChild(SymbolCloseBrace);
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
            throw Exception("invalid parse tree");

        _tree->write(os);
    }

}  // namespace Hack::Compiler::Analyzer
