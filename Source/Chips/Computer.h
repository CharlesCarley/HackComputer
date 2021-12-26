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
#include "Chips/CPU.h"
#include "Chips/Memory.h"
#include "Chips/Rom32.h"

namespace Hack::Chips
{
    struct CpuState
    {
        uint16_t pc;      // The current program counter
        uint16_t outM;    // The CPU's output to RAM
        uint16_t addrM;   // The current index in to RAM
        uint16_t regD;    // Current contents of the D register
        uint16_t regA;    // Contents of the A register
        uint16_t clock;   // The current clock cycle
        uint16_t inst;    // The instruction in ROM at the pc index
        uint16_t writeM;  // The load bit for the CPU.
        uint16_t ram;     // The last output from RAM
        uint16_t reset;   // Reset indicator
    };

    class Computer
    {
    public:
        static CpuState NullState;

    private:
        Rom32*   _rom;
        Cpu*     _cpu;
        Memory*  _ram;
        bool     _reset;
        CpuState _cpuState;

    public:
        Computer();
        ~Computer();

        void load(const uint16_t* data, size_t size);

        void update(bool saveState);

        void reset();

        Memory* memory() const;

        Rom32* rom() const;

        const CpuState& state() const;

        bool canRead() const;

    };

    inline Memory* Computer::memory() const
    {
        return _ram;
    }

    inline Rom32* Computer::rom() const
    {
        return _rom;
    }

    inline const CpuState& Computer::state() const
    {
        return _cpuState;
    }

}  // namespace Hack::Chips
