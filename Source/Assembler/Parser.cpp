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
#include "Assembler/Parser.h"
#include <bitset>
#include <fstream>
#include "Assembler/ParseError.h"
#include "Assembler/Scanner.h"
#include "Utils/Char.h"
#include "Utils/Console.h"

using namespace Hack;

namespace Hack::Assembler
{
    inline bool testCompoundExpression(const int8_t a,
                                       const int8_t b,
                                       const int8_t c,
                                       const int8_t d,
                                       const int8_t e,
                                       const int8_t f)
    {
        return a == d && b == e && c == f;
    }

    inline bool isDestToken(const int8_t type)
    {
        return type >= TOK_M && type <= TOK_AMD;
    }

    inline bool isConstantToken(const int8_t type)
    {
        return type == TOK_ZERO || type == TOK_ONE || type == TOK_INTEGER;
    }

    inline bool isOperatorToken(const int8_t type)
    {
        return type == TOK_PLUS ||
               type == TOK_MINUS ||
               type == TOK_AND ||
               type == TOK_OR ||
               type == TOK_NOT;
    }

    inline bool isJumpToken(const int8_t type)
    {
        return type >= TOK_JGT && type <= TOK_JMP;
    }

    Parser::Parser() :
        _scanner(nullptr),
        _current(0),
        _cBits(0),
        _dBits(0),
        _aBit(0),
        _jBits(0)
    {
        _scanner = new Scanner();
    }

    Parser::~Parser()
    {
        delete _scanner;
        _scanner = nullptr;
    }

    void Parser::pushCInstruction()
    {
        uint16_t inst = 0b1110000000000000;

        if (_aBit != 0)
            inst |= 1 << 12;

        inst |= (uint16_t)(_cBits << 6);
        if (_dBits != 0)
        {
            _dBits -= TOK_D_START;
            inst |= (uint16_t)(_dBits << 3);
        }

        if (_jBits != 0)
        {
            _jBits -= TOK_J_START;
            inst |= _jBits;
        }

        _instructions.push_back(inst);

        // clear the working set.
        _cBits = 0;
        _aBit = _dBits = _jBits = 0;
    }

    void Parser::readToken(int32_t n)
    {
        do
        {
            Token tok;
            _scanner->scan(tok);

            _tokens.push_back(tok);
        } while (--n > 0);
    }

    Token Parser::getToken(const int32_t offs)
    {
        const int32_t next = offs + _current;

        while (next + 1 > (int32_t)_tokens.size())
            readToken();

        if (next < (int32_t)_tokens.size() && next >= 0)
            return _tokens.at(next);

        throw ParseError("Failed to read token");
    }

    void Parser::advanceToken(const int32_t n)
    {
        _current += n;
    }

    void Parser::expressionA()
    {
        const Token& tok = getToken(1);

        uint16_t dest = 0;

        switch (tok.getType())
        {
        case TOK_ONE:
            dest = 1;
            [[fallthrough]];
        case TOK_ZERO:
        case TOK_INTEGER:
        case TOK_LABEL:
            break;
        default:
            throw ParseError("Expected a decimal to follow @");
        }

        if (tok.getType() == TOK_INTEGER)
            dest = Char::toUint16(_scanner->getString(tok.getIndex()));
        if (tok.getType() == TOK_LABEL)
        {
            const String label = _scanner->getString(tok.getIndex());

            const Labels::iterator it = _labels.find(label);
            if (it == _labels.end())
            {
                dest = (uint16_t)tok.getIndex();
                _labels.insert(std::make_pair(label, dest));
            }
            else
                dest = (uint16_t)it->second;
        }

        _instructions.push_back(dest & 0b0111111111111111);
        advanceToken(2);
    }

    void Parser::identityExpression()
    {
        const int8_t t0 = getToken(0).getType();
        const int8_t t1 = getToken(1).getType();

        switch (t0)
        {
        case TOK_ONE:
            _cBits = 63;
            break;
        case TOK_ZERO:
            _cBits = 42;
            break;
        case TOK_MINUS:

            if (t1 == TOK_ONE)
            {
                _cBits = 58;
                advanceToken();
                break;
            }

            [[fallthrough]];
        default:
            throw ParseError("Expected a constant 1, -1, or 0");
        }

        advanceToken();
    }

    void Parser::compoundExpressionAZero()
    {
        const int8_t t0 = getToken(0).getType();
        const int8_t t1 = getToken(1).getType();
        const int8_t t2 = getToken(2).getType();

        _aBit = 0;

        if (t0 == TOK_MINUS)
        {
            if (t1 == TOK_A || t1 == TOK_D)
                _cBits = t1 == TOK_A ? 51 : 15;
            else
                throw ParseError("Expected -A or -D");

            advanceToken(2);
        }
        else if (t0 == TOK_NOT)
        {
            if (t1 == TOK_A || t1 == TOK_D)
                _cBits = t1 == TOK_A ? 49 : 13;
            else
                throw ParseError("Expected !A or !D");

            advanceToken(2);
        }
        else
        {
            if (testCompoundExpression(t0, t1, t2, TOK_D, TOK_PLUS, TOK_ONE))
                _cBits = 31;
            else if (testCompoundExpression(t0, t1, t2, TOK_D, TOK_MINUS, TOK_ONE))
                _cBits = 14;
            else if (testCompoundExpression(t0, t1, t2, TOK_A, TOK_PLUS, TOK_ONE))
                _cBits = 55;
            else if (testCompoundExpression(t0, t1, t2, TOK_A, TOK_MINUS, TOK_ONE))
                _cBits = 50;
            else if (testCompoundExpression(t0, t1, t2, TOK_D, TOK_PLUS, TOK_A))
                _cBits = 2;
            else if (testCompoundExpression(t0, t1, t2, TOK_D, TOK_MINUS, TOK_A))
                _cBits = 19;
            else if (testCompoundExpression(t0, t1, t2, TOK_A, TOK_MINUS, TOK_D))
                _cBits = 7;
            else if (testCompoundExpression(t0, t1, t2, TOK_D, TOK_AND, TOK_A))
                _cBits = 0;
            else if (testCompoundExpression(t0, t1, t2, TOK_D, TOK_OR, TOK_A))
                _cBits = 21;
            else if (t0 == TOK_A)
                _cBits = 48;
            else if (t0 == TOK_D)
                _cBits = 12;
            else
                throw ParseError("expected one of: D+1, D-1, A+1, A-1, D+A, A-D, D&A, D|A, A, or D.");

            advanceToken(_cBits == 48 || _cBits == 12 ? 1 : 3);
        }
    }

    void Parser::compoundExpressionAOne()
    {
        const int8_t t0 = getToken(0).getType();
        const int8_t t1 = getToken(1).getType();
        const int8_t t2 = getToken(2).getType();

        _aBit = 1;

        if (t0 == TOK_MINUS)
        {
            if (t1 == TOK_M)
                _cBits = 51;
            else
                throw ParseError("Expected -M");

            advanceToken(2);
        }
        else if (t0 == TOK_NOT)
        {
            if (t1 == TOK_M)
                _cBits = 49;
            else
                throw ParseError("Expected !M");

            advanceToken(2);
        }
        else
        {
            if (testCompoundExpression(t0, t1, t2, TOK_M, TOK_PLUS, TOK_ONE))
                _cBits = 55;
            else if (testCompoundExpression(t0, t1, t2, TOK_M, TOK_MINUS, TOK_ONE))
                _cBits = 50;
            else if (testCompoundExpression(t0, t1, t2, TOK_D, TOK_PLUS, TOK_M))
                _cBits = 2;
            else if (testCompoundExpression(t0, t1, t2, TOK_D, TOK_MINUS, TOK_M))
                _cBits = 19;
            else if (testCompoundExpression(t0, t1, t2, TOK_M, TOK_MINUS, TOK_D))
                _cBits = 7;
            else if (testCompoundExpression(t0, t1, t2, TOK_D, TOK_AND, TOK_M))
                _cBits = 0;
            else if (testCompoundExpression(t0, t1, t2, TOK_D, TOK_OR, TOK_M))
                _cBits = 21;
            else if (t0 == TOK_M)
                _cBits = 48;
            else
                throw ParseError("expected one of: M+1, M-1, D+M, D-M, M+D, D&M, D|M, or M.");

            advanceToken(_cBits == 48 ? 1 : 3);
        }
    }

    void Parser::compoundExpression()
    {
        const int8_t t0 = getToken(0).getType();
        const int8_t t1 = getToken(1).getType();
        const int8_t t2 = getToken(2).getType();

        bool type1 = t0 == TOK_M && isOperatorToken(t1) && t2 == TOK_D;
        type1      = type1 || t0 == TOK_D && isOperatorToken(t1) && t2 == TOK_M;
        type1      = type1 || isOperatorToken(t0) && t1 == TOK_M;
        type1      = type1 || t0 == TOK_M;

        if (type1)
            compoundExpressionAOne();
        else
            compoundExpressionAZero();
    }

    void Parser::assignmentExpression()
    {
        const int8_t t0 = getToken(0).getType();
        const int8_t t1 = getToken(1).getType();
        const int8_t t2 = getToken(2).getType();
        const int8_t t3 = getToken(3).getType();

        if (t1 == TOK_EQUAL)
        {
            if (isDestToken(t0))
            {
                _dBits = t0;
                advanceToken(2);

                if (isConstantToken(t2) || t2 == TOK_MINUS && isConstantToken(t3))
                    identityExpression();
                else
                    compoundExpression();
            }
            else
                throw ParseError("Expected M, D, MD, A, AM, AD, AMD to precede '='");
        }
        else
            compoundExpression();
    }

    void Parser::expressionC()
    {
        const int8_t c = getToken(0).getType();
        const int8_t n = getToken(1).getType();

        if (isConstantToken(c) || c == TOK_MINUS && isConstantToken(n))
            identityExpression();
        else
            assignmentExpression();

        // test the optional jump statement

        const int8_t l = getToken(0).getType();
        if (l == TOK_SEMI_COLON)
        {
            const int8_t j = getToken(1).getType();

            if (isJumpToken(j))
            {
                _jBits = j;
                advanceToken(2);
            }
            else
                throw ParseError("Expected a Jump statement to follow ';'");
        }

        pushCInstruction();
    }

    void Parser::label()
    {
        // the lookup string needs to map to the address
        // of the last instruction
        size_t last = _instructions.size();

        const Token& t1 = getToken(1);
        advanceToken(3);

        const String label = _scanner->getString(t1.getIndex());

        const Labels::iterator it = _labels.find(label);

        if (it == _labels.end())
            _labels.insert(std::make_pair(label, last));
    }

    void Parser::expression()
    {
        const int8_t t0 = getToken(0).getType();
        const int8_t t2 = getToken(2).getType();

        if (t0 == TOK_AT)
            expressionA();
        else if (t0 == TOK_L_PAREN)
        {
            if (t2 != TOK_R_PAREN)
                throw ParseError("Expected a label declaration ([a-zA-Z0-9])");

            label();
        }
        else
            expressionC();
    }

    void Parser::parse(const String& file)
    {
        std::ifstream is(file);
        if (!is.is_open())
            throw Exception("Failed to open the input file '", file, "'");

        parse(is);
    }

    void Parser::parse(IStream &is)
    {
        _current = 0;
        _scanner->load(&is);

        while (_current <= (int32_t)_tokens.size())
        {
            const int8_t tok = getToken(0).getType();
            if (tok == TOK_EOF)
                break;

            const int32_t op = _current;
            expression();

            if (op == _current)
                advanceToken();
        }
    }


    void Parser::writeInstructions(OStream& os)
    {
        for (uint16_t& inst : _instructions)
        {
            std::bitset<16> v(inst);
            os << v << std::endl;
        }
    }

    void Parser::writeInstructions(const String& file)
    {
        std::ofstream os(file);
        writeInstructions(os);
    }

}  // namespace Hack::Assembler
