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
#include "Assembler/Scanner.h"
#include "Utils/ParserBase/ParserBase.h"

namespace Hack::Assembler
{

    using StringIndex = std::pair<String, size_t>;


    class Parser final : public ParserBase
    {
    public:
        typedef std::vector<uint16_t>              Instructions;
        typedef std::unordered_map<String, size_t> Labels;
        typedef std::vector<StringIndex>           LabelLookup;

    private:
        Instructions _instructions;
        Labels       _labels;
        uint16_t     _cBits;
        uint8_t      _dBits;
        uint8_t      _aBit;
        uint8_t      _jBits;
        LabelLookup  _resolution;

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

        void resolveLabels();

        void parseImpl(IStream& is) override;

        void writeImpl(OStream& os) override;

    public:
        Parser();
        ~Parser() override;

        const Instructions& getInstructions() const;
    };

    inline const Parser::Instructions& Parser::getInstructions() const
    {
        return _instructions;
    }

}  // namespace Hack::Assembler
