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
#include "Translator/Custom/Scanner.h"
#include "Utils/Char.h"
#include "Utils/Exceptions/Exception.h"

#define lowercase                                                         \
    'a' : case 'b' : case 'c' : case 'd' : case 'e' : case 'f' : case 'g' \
        : case 'h' : case 'i' : case 'j' : case 'k' : case 'l' : case 'm' \
        : case 'n' : case 'o' : case 'p' : case 'q' : case 'r' : case 's' \
        : case 't' : case 'u' : case 'v' : case 'w' : case 'x' : case 'y' \
        : case 'z'
#define uppercase                                                         \
    'A' : case 'B' : case 'C' : case 'D' : case 'E' : case 'F' : case 'G' \
        : case 'H' : case 'I' : case 'J' : case 'K' : case 'L' : case 'M' \
        : case 'N' : case 'O' : case 'P' : case 'Q' : case 'R' : case 'S' \
        : case 'T' : case 'U' : case 'V' : case 'W' : case 'X' : case 'Y' \
        : case 'Z'
#define digit                                                             \
    '0' : case '1' : case '2' : case '3' : case '4' : case '5' : case '6' \
        : case '7' : case '8' : case '9' : case '-'

namespace Hack::ToyVm
{
    Scanner::Scanner() = default;

    void Scanner::scanLineComment() const
    {
        int ch = _stream->peek();
        while (ch != '\r' && ch != '\n')
        {
            ch = _stream->get();
            if (ch == '\r' && _stream->peek() == '\n')
                ch = _stream->get();
        }
    }

    void Scanner::scanWhiteSpace() const
    {
        int ch = 0;
        while (ch != -1)
        {
            if (isWhiteSpace(_stream->peek()))
                ch = _stream->get();
            else
                break;
        }
    }

    struct KeywordTable
    {
        const char* str;
        int8_t      tok;
    };

    constexpr KeywordTable Reserved[] = {
        {"argument", TOK_ARGUMENT},
        {"constant", TOK_CONSTANT},
        {"function", TOK_FUNCTION},
        {"pointer", TOK_POINTER},
        {"if-goto", TOK_IF_GOTO},
        {"return", TOK_RETURN},
        {"local", TOK_LOCAL},
        {"label", TOK_LABEL},
        {"static", TOK_STATIC},
        {"call", TOK_CALL},
        {"goto", TOK_GOTO},
        {"this", TOK_THIS},
        {"that", TOK_THAT},
        {"temp", TOK_TEMP},
        {"push", TOK_PUSH},
        {"pop", TOK_POP},
        {"add", TOK_ADD},
        {"sub", TOK_SUB},
        {"not", TOK_NOT},
        {"neg", TOK_NEG},
        {"and", TOK_AND},
        {"or", TOK_OR},
        {"eq", TOK_EQ},
        {"gt", TOK_GT},
        {"lt", TOK_LT},
        {"reset", TOK_RESET},
        {"halt", TOK_HALT},
    };

    inline bool isValidCharacter(const int ch)
    {
        return isLetter(ch) || isDecimal(ch) || ch == '-' || ch == '_' || ch == '.';
    }

    void Scanner::scanSymbol(Token& tok)
    {
        int ch = _stream->get();

        if (isLetter(ch))
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
                    return;
                }
            }

            // If it's not a reserved word save it as an identifier,
            // and use it as either a label or a static variable.

            tok.setType(TOK_IDENTIFIER);
            tok.setIndex(saveString(cmp));
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
        }

        tok.setType(TOK_INTEGER);
        tok.setIndex(saveString(v));
    }

    void Scanner::scan(Token& tok)
    {
        if (_stream == nullptr)
            throw Exception("No supplied stream");

        tok.clear();

        int ch;
        while ((ch = _stream->get()) > 0)
        {
            switch (ch)
            {
            case '#':
                scanLineComment();
                break;
            case '/':
                if (_stream->peek() == '/')
                    scanLineComment();
                break;
            case digit:
                _stream->putback((char)ch);
                scanDigit(tok);
                return;
            case uppercase:
            case lowercase:
                _stream->putback((char)ch);
                scanSymbol(tok);
                return;
            case '\r':
            case '\n':
                if (ch == '\r' && _stream->peek() == '\n')
                    _stream->get();
                break;
            case ' ':
            case '\t':
                scanWhiteSpace();
                break;
            default:
                throw Exception("Unknown character parsed '", (char)ch, "'");
            }
        }

        tok.setType(TOK_EOF);
    }

}  // namespace Hack::VirtualMachine
