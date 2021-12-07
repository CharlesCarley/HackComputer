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
#include "VirtualMachine/Parser.h"
#include <fstream>
#include "Utils/Exceptions/Exception.h"
#include "VirtualMachine/Scanner.h"

namespace Hack::VirtualMachine
{
    Parser::Parser()
    {
        _scanner = new Scanner();
    }

    Parser::~Parser()
    {
        delete _scanner;
        _scanner = nullptr;
    }

    void Parser::pushExpression()
    {
        const int8_t t0 = getToken(1).getType();
        const int8_t t1 = getToken(2).getType();

        switch (t0)
        {
        case TOK_ARGUMENT:
            break;
        case TOK_LOCAL:
            break;
        case TOK_STATIC:
            break;
        case TOK_CONSTANT:
            break;
        case TOK_THIS:
            break;
        case TOK_THAT:
            break;
        case TOK_POINTER:
            break;
        case TOK_TEMP:
            break;
        default:
            throw Exception(
                "Unknown token parsed, expected "
                "argument, local, static, constant, "
                "this, that, pointer or temp");
        }

        if (t1 == TOK_INTEGER)
        {
            const String v = _scanner->getString(getToken(2).getIndex());

            _writer.pushConstant(v);
            // move the index into the D register on the CPU
            advanceCursor(3);
        }
        else
        {
            throw Exception("expected an integer");
        }
    }

    void Parser::popExpression()
    {
        const int8_t t0 = getToken(1).getType();
        const int8_t t1 = getToken(2).getType();
        switch (t0)
        {
        case TOK_ARGUMENT:
        case TOK_LOCAL:
        case TOK_STATIC:
        case TOK_CONSTANT:
        case TOK_THIS:
        case TOK_THAT:
        case TOK_POINTER:
        case TOK_TEMP:
            if (t1 == TOK_INTEGER)
            {
                advanceCursor(3);
                break;
            }
            [[fallthrough]];
        default:
            throw Exception(
                "Unknown token parsed, expected "
                "argument, local, static, constant, "
                "this, that, pointer or temp");
        }
    }

    void Parser::expression()
    {
        const int8_t t0 = getToken(0).getType();
        if (t0 == TOK_PUSH)
            pushExpression();
        else if (t0 == TOK_POP)
            popExpression();
        else
            throw Exception("Unknown token parsed, expected push or pop");
    }

    void Parser::parseImpl(IStream& is)
    {
        // make sure the token cursor is at zero
        // initially and attach the input stream
        // to the scanner
        _cursor = 0;
        _scanner->attach(&is);

        // clear the stream
        _writer.clear();
        // load values into the correct
        // ram addresses

        _writer.setRam(0, 256);
        _writer.setRam(1, 300);
        _writer.setRam(2, 400);
        _writer.setRam(3, 3000);
        _writer.setRam(4, 3010);

        while (_cursor <= (int32_t)_tokens.size())
        {
            const int8_t tok = getToken(0).getType();
            if (tok == TOK_EOF)
                break;

            const int32_t op = _cursor;
            expression();

            // if the cursor did not
            // advance force it to.
            if (op == _cursor)
                advanceCursor();
        }


    }

    void Parser::writeImpl(OStream& os)
    {


        os << _writer.toString();
    }

}  // namespace Hack::VirtualMachine
