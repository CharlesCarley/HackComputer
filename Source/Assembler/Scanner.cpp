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
#include "Assembler/Scanner.h"
#include "SyntaxError.h"
#include "Utils/Char.h"
// clang-format off

#define lowercase \
         'a' : case 'b' : case 'c' : case 'd' : case 'e' : case 'f' : \
    case 'g' : case 'h' : case 'i' : case 'j' : case 'k' : case 'l' : \
    case 'm' : case 'n' : case 'o' : case 'p' : case 'q' : case 'r' : \
    case 's' : case 't' : case 'u' : case 'v' : case 'w' : case 'x' : \
    case 'y' : case 'z'

#define uppercase \
         'A' : case 'B' : case 'C' : case 'D' : case 'E' : case 'F' : \
    case 'G' : case 'H' : case 'I' : case 'J' : case 'K' : case 'L' : \
    case 'M' : case 'N' : case 'O' : case 'P' : case 'Q' : case 'R' : \
    case 'S' : case 'T' : case 'U' : case 'V' : case 'W' : case 'X' : \
    case 'Y' : case 'Z'

#define digit \
         '0' : case '1' : case '2' : case '3' : \
    case '4' : case '5' : case '6' : case '7' : \
    case '8' : case '9'

// clang-format on

using namespace Hack;

namespace Hack::Assembler
{
    inline bool isNewLine(const int ch)
    {
        return ch == '\r' || ch == '\n';
    }

    inline bool isWhiteSpace(const int ch)
    {
        return ch == ' ' || ch == '\t' || isNewLine(ch);
    }

    inline bool isDecimal(const int ch)
    {
        return ch >= '0' && ch <= '9';
    }

    inline bool isLetter(const int ch)
    {
        return ch >= 'a' && ch <= 'z' || ch >= 'A' && ch <= 'Z';
    }

    struct KwTable
    {
        char   a, b, c;
        int8_t tok;
    };

    struct ReservedTable
    {
        const char* val;
        size_t      len;
        uint16_t    address;
    };

    constexpr KwTable DestAndJumpTable[] = {
        {'J', 'M', 'P', TOK_JMP},
        {'J', 'G', 'T', TOK_JGT},
        {'J', 'E', 'Q', TOK_JEQ},
        {'J', 'G', 'E', TOK_JGE},
        {'J', 'L', 'T', TOK_JLT},
        {'J', 'N', 'E', TOK_JNE},
        {'J', 'L', 'E', TOK_JLE},
        {'A', 'M', 'D', TOK_AMD},
        {'A', 'D', '\0', TOK_AD},
        {'A', 'M', '\0', TOK_AM},
        {'M', 'D', '\0', TOK_MD},
    };

    constexpr ReservedTable ReservedAddresses[] = {
        {"SP", 2, 0x0000},
        {"LCL", 3, 0x0001},
        {"ARG", 3, 0x0002},
        {"THIS", 4, 0x0003},
        {"THAT", 4, 0x0004},
        {"SCREEN", 5, 0x4000},
        {"KBD", 3, 0x6000},

    };

    Scanner::Scanner() :
        _stream(nullptr)
    {
        initializeTables();
    }

    void Scanner::load(IStream* stream)
    {
        _stream = stream;
    }

    size_t Scanner::saveString(const String& str)
    {
        size_t idx;

        const StringTable::iterator it = _stringTable.find(str);

        if (it == _stringTable.end())
        {
            idx = _strings.size();

            _strings.push_back(str);

            _stringTable.insert(std::make_pair(str, idx));
        }
        else
            idx = it->second;

        return idx;
    }

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

    void Scanner::scanDecimal(Token& tok)
    {
        int ch = _stream->get();
        if (ch == '1' || ch == '0')
        {
            // Check the next characters.

            const char lh = (char)_stream->peek();
            if (!(lh >= '0' && lh <= '9'))
            {
                tok.setType(ch == '1' ? TOK_ONE : TOK_ZERO);
                return;
            }
        }

        _stream->putback((char)ch);

        String v;
        while (isDecimal(ch))
        {
            ch = _stream->get();
            if (isDecimal(ch))
                v.push_back((char)ch);
        }

        tok.setType(TOK_INTEGER);
        tok.setIndex(saveString(v));

        if (ch > -1)
            _stream->putback((char)ch);
    }

    void Scanner::initializeTables()
    {
        // 0 - 15 in string format
        for (int i = 0; i < 16; ++i)
            saveString(Char::toString(i));

        saveString(Char::toString(0x4000));  // SCREEN
        saveString(Char::toString(0x6000));  // KBD
    }

    bool Scanner::extractRSymbol(Token& tok)
    {
        String str;

        int ch = _stream->get();
        while (isDecimal(ch))
        {
            str.push_back((char)ch);
            ch = _stream->get();
        }

        _stream->putback((char)ch);

        const uint64_t iv = Char::toUint64(str);

        if (iv < 16)
        {
            tok.setType(TOK_INTEGER);
            tok.setIndex(saveString(str));
            return true;
        }
        return false;
    }

    void Scanner::readSymbol(String& dest) const
    {
        int ch = _stream->get();
        dest.clear();

        // The first should be a letter prior
        // to entry into this method.

        while (isLetter(ch) || isDecimal(ch))
        {
            dest.push_back((char)ch);
            ch = _stream->get();
        }

        _stream->putback((char)ch);
    }

    bool Scanner::testSingleRegister(Token& tok)
    {
        // Check the single identifier case.

        const int ch = _stream->get();
        const int nx = _stream->peek();

        if (!isLetter(nx))
        {
            switch (ch)
            {
            case 'A':
                tok.setType(TOK_A);
                return true;
            case 'D':
                tok.setType(TOK_D);
                return true;
            case 'M':
                tok.setType(TOK_M);
                return true;
            case 'R':
                if (isDecimal(nx) && extractRSymbol(tok))
                    return true;
                [[fallthrough]];
            default:
                // just keep going
                break;
            }
        }

        _stream->putback((char)ch);
        return false;
    }

    bool Scanner::testMultipleRegisterAndJump(Token& tok) const
    {
        const int pc = _stream->get();
        const int ch = _stream->get();
        int       nx = _stream->peek();

        if (!isLetter(nx))
            nx = '\0';

        // Test the destination and jump table.

        for (const KwTable& djt : DestAndJumpTable)
        {
            if (pc == djt.a && ch == djt.b && nx == djt.c)
            {
                if (nx != 0)
                {
                    // consume the next
                    _stream->get();
                }

                tok.setType(djt.tok);
                return true;
            }
        }
        _stream->putback((char)ch);
        _stream->putback((char)pc);
        return false;
    }

    void Scanner::scanSymbol(Token& tok)
    {
        if (testSingleRegister(tok))
            return;

        if (testMultipleRegisterAndJump(tok))
            return;

        String buf;
        readSymbol(buf);

        for (const ReservedTable& ele : ReservedAddresses)
        {
            if (Char::equals(buf.c_str(), ele.val, std::min(buf.size(), ele.len)) == 0)
            {
                tok.setType(TOK_INTEGER);

                // Serialize the address.

                const size_t index = saveString(Char::toString(ele.address));

                tok.setIndex(index);
                return;
            }
        }

        // It needs looked up

        tok.setType(TOK_LABEL);
        tok.setIndex(saveString(buf));
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
            case '@':
                tok.setType(TOK_AT);
                return;
            case '-':
                tok.setType(TOK_MINUS);
                return;
            case '&':
                tok.setType(TOK_AND);
                return;
            case '|':
                tok.setType(TOK_OR);
                return;
            case '!':
                tok.setType(TOK_NOT);
                return;
            case ';':
                tok.setType(TOK_SEMI_COLON);
                return;
            case '+':
                tok.setType(TOK_PLUS);
                return;
            case '=':
                tok.setType(TOK_EQUAL);
                return;
            case '(':
                tok.setType(TOK_L_PAREN);
                return;
            case ')':
                tok.setType(TOK_R_PAREN);
                return;
            case digit:
                _stream->putback((char)ch);
                scanDecimal(tok);
                return;
            case lowercase:
            case uppercase:
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
                throw SyntaxError(String("unknown character parsed") + (char)ch);
            }
        }

        tok.setType(TOK_EOF);
    }

    String Scanner::getString(const size_t& i)
    {
        if (i < _strings.size())
            return _strings.at(i);
        return "";
    }

}  // namespace Hack::Assembler