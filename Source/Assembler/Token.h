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
#pragma once
#include "Utils/String.h"

namespace Hack::Assembler
{
    enum TokenType
    {
        TOK_ERROR = -2,
        TOK_EOF,
        TOK_NULL,
        // Destination
        TOK_D_START,
        TOK_M,
        TOK_D,
        TOK_MD,
        TOK_A,
        TOK_AM,
        TOK_AD,
        TOK_AMD,
        // Jump
        TOK_J_START,
        TOK_JGT,
        TOK_JEQ,
        TOK_JGE,
        TOK_JLT,
        TOK_JNE,
        TOK_JLE,
        TOK_JMP,
        // Comp
        TOK_ZERO,
        TOK_MINUS,
        TOK_NOT,
        TOK_PLUS,
        TOK_AND,
        TOK_OR,
        TOK_AT,
        TOK_SEMI_COLON,
        TOK_EQUAL,
        TOK_L_PAREN,
        TOK_R_PAREN,
        TOK_COMMA,
        TOK_ONE,
        TOK_INTEGER,
        TOK_LABEL
    };

    class Token
    {
    private:
        size_t _index;
        int8_t _type;

    public:
        Token() :
            _index(),
            _type()
        {
            clear();
        }

        Token(const Token& tok) = default;

        ~Token() = default;

        void clear()
        {
            _index = -1;
            _type  = TOK_NULL;
        }

        size_t getIndex() const;

        int8_t getType() const;

        void setType(int8_t type);

        void setIndex(size_t i);
    };

    inline size_t Token::getIndex() const
    {
        return _index;
    }

    inline int8_t Token::getType() const
    {
        return _type;
    }

    inline void Token::setType(const int8_t type)
    {
        _type = type;
    }

    inline void Token::setIndex(const size_t i)
    {
        _index = i;
    }

}  // namespace Hack::Assembler
