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
#include "Assembler/Instruction.h"
#include "Chips/BitUtils.h"

namespace Hack::Assembler
{
    Instruction::Instruction(const uint16_t inst) :
        _inst(inst)
    {
    }

    String Instruction::asString() const
    {
        String cpy;
        asString(cpy);
        return cpy;
    }

    void Instruction::asString(String& dest) const
    {
        using B = Chips::B16;
        OutputStringStream oss;

        if (!B::getBit(_inst, 15))
        {
            oss << "@" << _inst;
        }
        else
        {
            const uint16_t j = B::extract(_inst, 0, 2);
            const uint16_t d = B::extract(_inst, 3, 5);
            const uint16_t c = B::extract(_inst, 6, 11);
            const uint16_t a = B::extract(_inst, 12, 12);

            if (d != 0)
            {
                switch (d)
                {
                case 1:
                    oss << "M=";
                    break;
                case 2:
                    oss << "D=";
                    break;
                case 3:
                    oss << "MD=";
                    break;
                case 4:
                    oss << "A=";
                    break;
                case 5:
                    oss << "AM=";
                    break;
                case 6:
                    oss << "AD=";
                    break;
                case 7:
                    oss << "AMD=";
                    break;
                default:
                    oss << "?=";
                    break;
                }
            }

            if (!a)
            {
                switch (c)
                {
                case 42:
                    oss << "0";
                    break;
                case 63:
                    oss << "1";
                    break;
                case 58:
                    oss << "-1";
                    break;
                case 12:
                    oss << "D";
                    break;
                case 48:
                    oss << "A";
                    break;
                case 13:
                    oss << "!D";
                    break;
                case 49:
                    oss << "!A";
                    break;
                case 15:
                    oss << "-D";
                    break;
                case 51:
                    oss << "-A";
                    break;
                case 31:
                    oss << "D+1";
                    break;
                case 55:
                    oss << "A+1";
                    break;
                case 14:
                    oss << "D-1";
                    break;
                case 50:
                    oss << "A-1";
                    break;
                case 2:
                    oss << "D+A";
                    break;
                case 19:
                    oss << "D-A";
                    break;
                case 7:
                    oss << "A-D";
                    break;
                case 0:
                    oss << "D&A";
                    break;
                case 21:
                    oss << "D|A";
                    break;
                default:
                    oss << "?";
                    break;
                }
            }
            else
            {
                switch (c)
                {
                case 48:
                    oss << "M";
                    break;
                case 49:
                    oss << "!M";
                    break;
                case 51:
                    oss << "-M";
                    break;
                case 55:
                    oss << "M+1";
                    break;
                case 50:
                    oss << "M-1";
                    break;
                case 2:
                    oss << "D+M";
                    break;
                case 19:
                    oss << "D-M";
                    break;
                case 7:
                    oss << "M-D";
                    break;
                case 0:
                    oss << "D&M";
                    break;
                case 21:
                    oss << "D|M";
                    break;
                default:
                    oss << "?";
                    break;
                }
            }

            if (j != 0)
            {
                switch (j)
                {
                case 1:
                    oss << ";JGT";
                    break;
                case 2:
                    oss << ";JEQ";
                    break;
                case 3:
                    oss << ";JGE";
                    break;
                case 4:
                    oss << ";JLT";
                    break;
                case 5:
                    oss << ";JNE";
                    break;
                case 6:
                    oss << ";JLE";
                    break;
                case 7:
                    oss << ";JMP";
                    break;
                default:
                    oss << ";???";
                    break;
                }
            }
        }
        dest = oss.str();
    }

}  // namespace Hack::Assembler
