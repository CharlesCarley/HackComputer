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
#include "VirtualMachine/Constants.h"
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

        if (t1 != TOK_INTEGER)
        {
            throw Exception(
                "Expected an integer to be the third argument to the push "
                "expression");
        }

        const size_t idx = getToken(2).getIndex();

        switch (t0)
        {
        case TOK_LOCAL:
            _emitter.pushLocal(_scanner->getString(idx));
            break;
        case TOK_ARGUMENT:
            _emitter.pushArgument(_scanner->getString(idx));
            break;
        case TOK_THIS:
            _emitter.pushThis(_scanner->getString(idx));
            break;
        case TOK_THAT:
            _emitter.pushThat(_scanner->getString(idx));
            break;
        case TOK_STATIC:
            _emitter.pushStatic(_file, _scanner->getString(idx));
            break;
        case TOK_TEMP:
            _emitter.pushTemp(_scanner->getString(idx));
            break;
        case TOK_POINTER:
            break;
        case TOK_CONSTANT:
            _emitter.pushConstant(_scanner->getString(idx));
            break;
        default:
            throw Exception(
                "Unknown token parsed, expected "
                "argument, local, static, constant, "
                "this, that, pointer or temp");
        }
    }

    void Parser::popExpression()
    {
        const int8_t t0 = getToken(1).getType();
        const int8_t t1 = getToken(2).getType();

        if (t1 != TOK_INTEGER)
        {
            throw Exception(
                "Expected an integer to be the third argument to the pop "
                "expression");
        }

        const size_t idx = getToken(2).getIndex();

        switch (t0)
        {
        case TOK_LOCAL:
            _emitter.popLocal(_scanner->getString(idx));
            break;
        case TOK_ARGUMENT:
            _emitter.popArgument(_scanner->getString(idx));
            break;
        case TOK_THIS:
            _emitter.popThis(_scanner->getString(idx));
            break;
        case TOK_THAT:
            _emitter.popThat(_scanner->getString(idx));
            break;
        case TOK_TEMP:
            _emitter.popTemp(_scanner->getString(idx));
            break;
        case TOK_STATIC:
            _emitter.popStatic(_file, _scanner->getString(idx));
            break;
        case TOK_CONSTANT:
        case TOK_POINTER:
            break;
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
        switch (t0)
        {
        case TOK_PUSH:
            pushExpression();
            advanceCursor(3);
            break;
        case TOK_POP:
            popExpression();
            advanceCursor(3);
            break;
        case TOK_AND:
            _emitter.writeAnd();
            advanceCursor();
            break;
        case TOK_OR:
            _emitter.writeOr();
            advanceCursor();
            break;
        case TOK_ADD:
            _emitter.writeAdd();
            advanceCursor();
            break;
        case TOK_SUB:
            _emitter.writeSub();
            advanceCursor();
            break;
        case TOK_NOT:
            _emitter.writeNot();
            advanceCursor();
            break;
        case TOK_NEG:
            _emitter.writeNeg();
            advanceCursor();
            break;
        default:
            throw Exception(
                "Unknown rule, expected push, pop, "
                "and, or, add or sub");
        }
    }

    void Parser::parseImpl(IStream& is)
    {
        // make sure the token cursor is at zero
        // initially and attach the input stream
        // to the scanner
        _cursor = 0;
        _scanner->attach(&is);

        // clear the stream
        _emitter.clear();
        // load values into the correct
        // ram addresses

        _emitter.setRam(0, Stack);
        _emitter.setRam(1, Local);
        _emitter.setRam(2, Arguments);
        _emitter.setRam(3, This);
        _emitter.setRam(4, That);
        _emitter.setRam(5, 5);

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
        os << _emitter.toString();
    }

}  // namespace Hack::VirtualMachine
