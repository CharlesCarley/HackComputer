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
#include "Computer.h"
#include <iomanip>
#include <iostream>
#include "Chips/Timer.h"
#include "Utils/Char.h"

namespace Hack::Chips
{
    CpuState Computer::NullState = {0, 0, 0, 0, 0, 0, 0, 0, 0, 0};

    Computer::Computer() :
        _rom(new Rom32()),
        _cpu(new Cpu()),
        _ram(new Memory()),
        _reset(false),
        _cpuState(NullState)
    {
    }

    Computer::~Computer()
    {
        delete _ram;
        delete _cpu;
        delete _rom;
    }

    void Computer::load(const uint16_t* data, const size_t size)
    {
        _rom->load(data, size);
        _reset = true;
        update(false);
    }

    bool Computer::canRead() const
    {
        return _cpuState.pc < _rom->size();
    }

    void Computer::update(const bool saveState)
    {
        const bool cycle = Timer::tick();
        if (_reset)
        {
            _cpu->clear();
            _ram->zero();
            _ram->setValue(0, (uint16_t)Memory::StackAddress);
            _cpuState = NullState;
            Timer::reset();
        }

        // force a reset...
        // @32766
        // 0;JMP
        if (_cpuState.pc >= 0x7FFF)
            _reset = true;

        // Set the next instruction
        // from the previous evaluation,
        // or zero if this is the first.
        _rom->setIn(_cpu->getNext());

        // Link I/O to the CPU

        _cpu->setInstruction(_rom->getOut());
        _cpu->setClock(cycle);
        _cpu->setReset(_reset);
        _cpu->setInMemory(_ram->getOut());

        // Tie the CPU outputs to the ram

        _ram->setClock(cycle);
        _ram->setLoad(_cpu->getWrite());
        _ram->setAddress(_cpu->getAddress());
        _ram->setIn(_cpu->getOut());

        if (saveState)
        {
            // Lock to prevent evaluation when querying the state
            _cpu->lock(true);
            _ram->lock(true);
            _rom->lock(true);

            // Save the current CPU state
            _cpuState.pc     = _cpu->getNext();
            _cpuState.addrM  = _cpu->getAddress();
            _cpuState.outM   = _cpu->getOut();
            _cpuState.regD   = _cpu->getDRegister();
            _cpuState.regA   = _cpu->getAMRegister();
            _cpuState.clock  = cycle;
            _cpuState.inst   = _rom->getOut();
            _cpuState.writeM = _cpu->getWrite();
            _cpuState.ram    = _ram->getOut();
            _cpuState.reset  = _reset ? 1 : 0;

            _cpu->lock(false);
            _ram->lock(false);
            _rom->lock(false);
        }

        _reset = false;
    }

    void Computer::reset()
    {
        _reset = true;
    }

}  // namespace Hack::Chips
