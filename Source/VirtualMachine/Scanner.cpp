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
#include "VirtualMachine/Scanner.h"
#include "Utils/Char.h"
#include "VirtualMachine/Token.h"

namespace Hack::VirtualMachine
{
    Scanner::Scanner() = default;

    struct KeywordTable
    {
        const char* str;
        int8_t      tok;
    };

    // clang-format off
    constexpr KeywordTable Reserved[] = {
        {"argument",    TOK_ARGUMENT},
        {"constant",    TOK_CONSTANT},
        {"function",    TOK_FUNCTION},
        {"pointer",     TOK_POINTER},
        {"if-goto",     TOK_IF_GOTO},
        {"return",      TOK_RETURN},
        {"local",       TOK_LOCAL},
        {"label",       TOK_LABEL},
        {"static",      TOK_STATIC},
        {"call",        TOK_CALL},
        {"goto",        TOK_GOTO},
        {"this",        TOK_THIS},
        {"that",        TOK_THAT},
        {"temp",        TOK_TEMP},
        {"push",        TOK_PUSH},
        {"pop",         TOK_POP},
        {"add",         TOK_ADD},
        {"sub",         TOK_SUB},
        {"not",         TOK_NOT},
        {"neg",         TOK_NEG},
        {"and",         TOK_AND},
        {"or",          TOK_OR},
        {"eq",          TOK_EQ},
        {"gt",          TOK_GT},
        {"lt",          TOK_LT},
        {"set",         TOK_SET},
        {"reset",       TOK_RESET},
        {"halt",        TOK_HALT},
        {"asm",         TOK_ASM},
    };
    // clang-format on

    inline bool isValidCharacter(const int ch)
    {
        return isLetter(ch) || isDecimal(ch) || ch == '-' || ch == '_' || ch == '.';
    }

    void Scanner::scanCode(Token& tok)
    {
        String block;
        extractCode(block, '[', ']');

        tok.setIndex(_code.size());
        _code.push_back(block);
    }

    void Scanner::getCode(String& dest, const size_t& idx)
    {
        if (idx < _code.size())
            dest = _code.at(idx);
        else
            syntaxError("code index out of bounds");
    }

    void Scanner::scanSymbol(Token& tok)
    {
        int ch = _stream->get();

        if (isLetter(ch) || ch == '_')
        {
            String cmp;
            while (isValidCharacter(ch))
            {
                cmp.push_back((char)ch);
                ch = _stream->get();
            }

            _stream->putback((char)ch);

            for (const KeywordTable& res : Reserved)
            {
                if (cmp == res.str)
                {
                    tok.setType(res.tok);

                    if (res.tok == TOK_ASM)
                        scanCode(tok);
                    return;
                }
            }

            // If it's not a reserved word save it as an identifier,
            // and use it as either a label or a static variable.

            tok.setType(TOK_IDENTIFIER);
            tok.setIndex(save(cmp));
        }
    }

    void Scanner::scanDigit(Token& tok)
    {
        int ch = _stream->peek();

        String v;
        while (isDecimal(ch) || ch == '-')
        {
            ch = _stream->get();
            if (isDecimal(ch) || ch == '-')
                v.push_back((char)ch);
            else
                _stream->putback((char)ch);
        }

        tok.setType(TOK_INTEGER);
        tok.setIndex(save(Char::toInt32(v)));
    }

    void Scanner::scan(Token& tok)
    {
        if (_stream == nullptr)
            syntaxError("No supplied stream");

        tok.clear();

        int ch;
        while ((ch = _stream->get()) > 0)
        {
            tok.setLine(_line);

            switch (ch)
            {
            case '#':
                scanLineComment();
                break;
            case '/':
                if (_stream->peek() == '/')
                    scanLineComment();
                if (_stream->peek() == '*')
                    scanMultiLineComment();
                break;
            case '-':
            case Digits09:
                _stream->putback((char)ch);
                scanDigit(tok);
                return;
            case '_':
            case UpperCaseAz:
            case LowerCaseAz:
                _stream->putback((char)ch);
                scanSymbol(tok);
                return;
            case '\r':
            case '\n':
                if (ch == '\r' && _stream->peek() == '\n')
                    _stream->get();
                ++_line;
                break;
            case ' ':
            case '\t':
                scanWhiteSpace();
                break;
            default:
                syntaxError("unknown character parsed '", ch, "'");
            }
        }

        tok.setType(TOK_EOF);
    }

}  // namespace Hack::VirtualMachine
