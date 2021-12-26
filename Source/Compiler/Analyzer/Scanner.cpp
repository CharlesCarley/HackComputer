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

namespace Hack::Compiler::Analyzer
{
    Scanner::Scanner() = default;

    struct KeywordTable
    {
        const char* str;
        int8_t      tok;
    };

    // clang-format off

    constexpr KeywordTable Reserved[] = {
        {"class",       TokKwClass},
        {"constructor", TokKwConstructor},
        {"function",    TokKwFunction},
        {"method",      TokKwMethod},
        {"field",       TokKwField},
        {"static",      TokKwStatic},
        {"var",         TokKwVar},
        {"int",         TokKwInt},
        {"char",        TokKwChar},
        {"bool",        TokKwBool},
        {"void",        TokKwVoid},
        {"let",         TokKwLet},
        {"do",          TokKwDo},
        {"if",          TokKwIf},
        {"else",        TokKwElse},
        {"while",       TokKwWhile},
        {"return",      TokKwReturn},
        {"true",        TokKwTrue},
        {"false",       TokKwFalse},
        {"null",        TokKwNull},
        {"this",        TokKwThis},
    };
    // clang-format on

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

            tok.setType(TokId);
            tok.setIndex(save(cmp));
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

        _stream->putback((char)ch);

        tok.setType(TokInt);
        tok.setIndex(save(v));
    }

    void Scanner::scanString(Token& tok)
    {
        int ch = _stream->get();

        if (ch != '"')
            syntaxError("Invalid string starting character. (", ch, ')');

        ch = _stream->peek();

        String v;
        while (ch > 0 && ch != '"')
        {
            ch = _stream->get();
            if (ch == '\\')
            {
                ch = _stream->get();
                switch (ch)
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
                    syntaxError("invalid escape sequence");
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

        tok.setType(TokString);
        tok.setIndex(save(v));
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
            case '/':
                if (_stream->peek() == '/')
                    scanLineComment();
                else if (_stream->peek() == '*')
                    scanMultiLineComment();
                else
                {
                    tok.setType(TokOpDivide);
                    return;
                }
                break;
            case Digits09:
                _stream->putback((char)ch);
                scanDigit(tok);
                return;
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
            case '"':
                _stream->putback((char)ch);
                scanString(tok);
                return;
            case '+':
                tok.setType(TokOpPlus);
                return;
            case '-':
                tok.setType(TokOpMinus);
                return;
            case '*':
                tok.setType(TokOpMultiply);
                return;
            case '&':
                tok.setType(TokOpAnd);
                return;
            case '|':
                tok.setType(TokOpOr);
                return;
            case '!':
            case '~':
                tok.setType(TokOpNot);
                return;
            case '=':
                tok.setType(TokOpEq);
                return;
            case '<':
                tok.setType(TokOpLt);
                return;
            case '>':
                tok.setType(TokOpGt);
                return;
            case '.':
                tok.setType(TokSymPeriod);
                return;
            case '{':
                tok.setType(TokSymLBrace);
                return;
            case '}':
                tok.setType(TokSymRBrace);
                return;
            case '[':
                tok.setType(TokSymLBracket);
                return;
            case ']':
                tok.setType(TokSymRBracket);
                return;
            case '(':
                tok.setType(TokSymLPar);
                return;
            case ')':
                tok.setType(TokSymRPar);
                return;
            case ',':
                tok.setType(TokSymComma);
                return;
            case ';':
                tok.setType(TokSymSemicolon);
                return;
            default:
                syntaxError("Unknown character parsed '", (char)ch, "'");
            }
        }

        tok.setType(TokEof);
    }

}  // namespace Hack::Compiler::Analyzer
