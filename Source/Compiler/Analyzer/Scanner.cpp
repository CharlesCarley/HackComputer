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
#include "Compiler/Analyzer/Scanner.h"
#include "Compiler/Analyzer/Token.h"
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
        : case '7' : case '8' : case '9'

namespace Hack::Compiler::Analyzer
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

    void Scanner::scanMultiLineComment() const
    {
        int ch = _stream->peek();
        // save doc string?
        // /** | /*!
        while (ch > 0)
        {
            ch = _stream->get();
            if (ch == '*' && _stream->peek() == '/')
                break;
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
        {"class", TOK_KW_CLASS},
        {"constructor", TOK_KW_CTOR},
        {"function", TOK_KW_FUNCTION},
        {"method", TOK_KW_METHOD},
        {"field", TOK_KW_FIELD},
        {"static", TOK_KW_STATIC},
        {"var", TOK_KW_VAR},
        {"int", TOK_KW_INT},
        {"char", TOK_KW_CHAR},
        {"bool", TOK_KW_BOOL},
        {"void", TOK_KW_VOID},
        {"let", TOK_KW_LET},
        {"do", TOK_KW_DO},
        {"if", TOK_KW_IF},
        {"else", TOK_KW_ELSE},
        {"while", TOK_KW_WHILE},
        {"return", TOK_KW_RETURN},
        {"true", TOK_CONST_TRUE},
        {"false", TOK_CONST_FALSE},
        {"null", TOK_CONST_NULL},
        {"this", TOK_CONST_THIS},
    };

    inline bool isValidCharacter(const int ch)
    {
        return isLetter(ch) || isDecimal(ch) || ch == '_';
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
        while (isDecimal(ch))
        {
            ch = _stream->get();
            if (isDecimal(ch))
                v.push_back((char)ch);
        }

        tok.setType(TOK_INTEGER);
        tok.setIndex(saveString(v));
    }

    void Scanner::scanString(Token& tok)
    {
        int ch = _stream->get();

        if (ch != '"')
            throw Exception("Invalid string starting character. (", ch, ')');

        ch = _stream->peek();

        String v;
        while (ch > 0 && ch != '"')
        {
            ch = _stream->get();
            if (ch == '\\')
            {


                ch = _stream->get();
                switch(ch)
                {
                case 'n':
                    v.push_back('\n');
                    break;
                case 'r':
                    v.push_back('\r');
                    break;
                case 't':
                    v.push_back('\t');
                    break;
                case 'b':
                    v.push_back('\b');
                    break;

                case '\'':
                case '"':
                    v.push_back((char)ch);
                    break;
                case '\\':
                    v.push_back('\\');
                    break;
                default:
                    throw Exception("invalid escape sequence");
                }

                if (ch == '"')
                    ch = _stream->get();
            }
            else
            {
                if (ch > 0 && ch != '"')
                    v.push_back((char)ch);
                
            }

        }

        tok.setType(TOK_STRING);
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
                else if (_stream->peek() == '*')
                    scanMultiLineComment();
                else
                {
                    tok.setType(TOK_OP_DIVIDE);
                    return;
                }
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
            case '"':
                _stream->putback((char)ch);
                scanString(tok);
                return;
            case '+':
                tok.setType(TOK_OP_PLUS);
                return;
            case '-':
                tok.setType(TOK_OP_MINUS);
                return;
            case '*':
                tok.setType(TOK_OP_MULTIPLY);
                return;
            case '&':
                tok.setType(TOK_OP_AND);
                return;
            case '|':
                tok.setType(TOK_OP_OR);
                return;
            case '!':
            case '~':
                tok.setType(TOK_OP_NOT);
                return;
            case '=':
                tok.setType(TOK_EQ);
                return;
            case '<':
                tok.setType(TOK_LT);
                return;
            case '>':
                tok.setType(TOK_GT);
                return;
            case '.':
                tok.setType(TOK_PERIOD);
                return;
            case '{':
                tok.setType(TOK_L_BRACE);
                return;
            case '}':
                tok.setType(TOK_R_BRACE);
                return;
            case '[':
                tok.setType(TOK_L_BRACKET);
                return;
            case ']':
                tok.setType(TOK_R_BRACKET);
                return;
            case '(':
                tok.setType(TOK_L_PAR);
                return;
            case ')':
                tok.setType(TOK_R_PAR);
                return;
            case ',':
                tok.setType(TOK_COMMA);
                return;
            case ';':
                tok.setType(TOK_SEMICOLON);
                return;
            default:
                throw Exception("Unknown character parsed '", (char)ch, "'");
            }
        }

        tok.setType(TOK_EOF);
    }

}  // namespace Hack::Compiler::Analyzer
