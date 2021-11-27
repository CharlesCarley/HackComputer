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
#include <unordered_map>
#include <vector>
#include "Assembler/Token.h"

namespace Hack::Assembler
{
    class Scanner;

    class Parser
    {
    public:
        typedef std::vector<uint16_t>              Instructions;
        typedef std::vector<Token>                 Tokens;
        typedef std::unordered_map<String, size_t> Labels;

    private:
        Instructions _instructions;
        Tokens       _tokens;
        Labels       _labels;
        Scanner*     _scanner;
        int32_t      _current;
        uint16_t     _cBits;
        uint8_t      _dBits;
        uint8_t      _aBit;
        uint8_t      _jBits;

        Token getToken(int32_t offs);

        void advanceToken(int32_t n = 1);

        void readToken(int32_t n = 1);

        void pushCInstruction();

        void compoundExpressionAZero();

        void compoundExpressionAOne();

        void compoundExpression();

        void assignmentExpression();

        void identityExpression();

        void expressionC();

        void expressionA();

        void label();

        void expression();

    public:
        Parser();
        ~Parser();

        void parse(const String& file);

        void parse(IStream& is);

        void writeInstructions(OStream& os);

        void writeInstructions(const String& file);

        const Instructions& getInstructions() const;
    };

    inline const Parser::Instructions& Parser::getInstructions() const
    {
        return _instructions;
    }

}  // namespace Hack::Assembler
