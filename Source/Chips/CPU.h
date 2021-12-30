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
#include "ALU.h"
#include "Chips/Chip.h"
#include "Chips/ProgramCounter.h"
#include "Chips/Register.h"

namespace Hack::Chips
{
    class Cpu final : public Chip<uint8_t, 8>
    {
    private:
        void evaluate() override;

        bool isDirty() override;
        void markDirty();

        Register       _a, _d;
        ProgramCounter _pc;
        uint16_t       _ins;
        uint16_t       _in;
        Alu            _alu;

    public:
        Cpu();

        void setInMemory(const uint16_t& v);

        void setClock(bool v);

        void setReset(bool v);

        void setInstruction(const uint16_t& v);

        bool getWrite();

        uint16_t getOut();

        uint16_t getAddress();

        uint16_t getNext();

        uint16_t getDRegister();

        uint16_t getAmRegister();

        void lock(bool v);

        void clear();
    };

}  // namespace Hack::Chips
