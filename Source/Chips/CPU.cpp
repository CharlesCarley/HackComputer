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
#include "Chips/CPU.h"
#include "Chips/ALU.h"
#include "Chips/ProgramCounter.h"
#include "Chips/Register.h"
#include "Chips/Timer.h"
#ifdef IMPLEMENT_BLACK_BOX
#include "Chips/And16.h"
#include "Chips/Mux16.h"
#endif

namespace Hack::Chips
{
#ifndef IMPLEMENT_BLACK_BOX
    constexpr uint16_t RMask = 0b0111'1111'1111'1111;
    constexpr uint16_t MLoad = 0b0'00'0'000000'001'000;
    constexpr uint16_t DLoad = 0b0'00'0'000000'010'000;
    constexpr uint16_t ALoad = 0b0'00'0'000000'100'000;
    constexpr uint16_t ABits = 0b0'00'1'000000'000'000;
    constexpr uint16_t CBits = 0b0'00'0'111111'000'000;
#endif
    Cpu::Cpu() : _ins(0), _in(0)
    {
        // This should not be marked as dirty
        // initially
    }

    void Cpu::lock(bool v)
    {
        applyBit(2, v);
    }

    void Cpu::setInMemory(const uint16_t& v)
    {
        _in = v;
        markDirty();
    }

    void Cpu::setClock(bool v)
    {
        applyBit(1, v);
        markDirty();
    }

    void Cpu::setReset(bool v)
    {
        applyBit(0, v);
        markDirty();
    }

    void Cpu::setInstruction(const uint16_t& v)
    {
        _ins = v;
        markDirty();
    }

    bool Cpu::getWrite()
    {
        if (isDirty())
            evaluate();
        return getBit(6);
    }

    uint16_t Cpu::getOut()
    {
        if (isDirty())
            evaluate();
        return _alu.getOut();
    }

    uint16_t Cpu::getAddress()
    {
        if (isDirty())
            evaluate();
        return _a.getOut();
    }

    uint16_t Cpu::getDRegister()
    {
        if (isDirty())
            evaluate();
        return _d.getOut();
    }

    uint16_t Cpu::getAMRegister()
    {
        if (isDirty())
            evaluate();
        return _a.getOut();
    }

    uint16_t Cpu::getNext()
    {
        if (isDirty())
            evaluate();
        return _pc.getOut();
    }

    bool Cpu::isDirty()
    {
        return getBit(7) && !getBit(2);
    }

    void Cpu::markDirty()
    {
        setBit(7);
    }

    void Cpu::evaluate()
    {
#ifdef IMPLEMENT_BLACK_BOX
        And16 and16;
        Mux16 m0, m1;

        bool codes[16];
        B16::unpack(_ins, codes);

        const bool tick  = getBit(1);
        const bool typeC = codes[15];
        const bool typeA = Gates::Not(typeC);

        m0.setA(_alu.getOut());
        m0.setB(_ins);
        m0.setSel(typeA);

        and16.setA(m0.getOut());
        and16.setB(0b0111111111111111);

        _a.setLoad(Gates::Or(typeA, Gates::And(typeC, codes[5])));
        _a.setIn(and16.getOut());
        _a.setClock(tick);

        m1.setA(_a.getOut());
        m1.setB(_in);
        m1.setSel(Gates::And(typeC, codes[12]));

        bool c[6]{codes[6], codes[7], codes[8], codes[9], codes[10], codes[11]};

        _alu.setFlags(B8::pack<6>(c));
        _alu.setX(_d.getOut());
        _alu.setY(m1.getOut());

        _d.setLoad(Gates::And(typeC, codes[4]));
        _d.setIn(_alu.getOut());
        _d.setClock(Gates::Not(tick));  // t-1

        _pc.setLoad(Gates::Mux(
            getBit(0),
            true,
            Gates::Or3(Gates::And(Gates::And(typeC, codes[0]),
                                  Gates::And(Gates::Not(_alu.getZr()),
                                             Gates::Not(_alu.getNe()))),
                       Gates::And(Gates::And(typeC, codes[1]), _alu.getZr()),
                       Gates::And(Gates::And(typeC, codes[2]), _alu.getNe())
                           )));
        _pc.setIn(_a.getOut());
        _pc.setInc(true);
        _pc.setReset(getBit(0));
        _pc.setClock(tick);

        applyBit(6, Gates::And(typeC, codes[3]));

        _pc.getOut();
        clearBit(7);
#else

        // clock is in bit 1
        const bool tick = getBit(1);

        // if the highest bit is set, it is a c-type instruction
        const bool typeC = (_ins & 1 << 15) != 0;

        // otherwise it's an a-type instruction
        const bool typeA = !typeC;

        // load into the A register if it is an a-type
        // or if it's a c-type and the a destination
        // bit is set
        _a.setLoad(typeA || typeC && (_ins & ALoad) != 0);

        _a.setIn((typeA ? _ins : _alu.getOut()) & RMask);
        _a.setClock(tick);

        // The flags are the ALU ctrl-bits, so mask them off
        // and shift them down so that they align in the lower
        // six bits of an unsigned char.
        _alu.setFlags((_ins & CBits) >> 6);

        _alu.setX(_d.getOut());

        // A/M the a-bit (12) controls the M type commands
        // if it is set when the instruction is a c-type instruction,
        // use the CPU input (when linked to RAM its the RAM'S output (M)).
        // otherwise use the output from the internal (A) register.
        _alu.setY(typeC && (_ins & ABits) != 0 ? _in : _a.getOut());

        _d.setLoad(typeC && (_ins & DLoad) != 0);
        _d.setIn(_alu.getOut());
        _d.setClock(!tick);  // t-1

        if (typeC)
        {
            const bool isZero = _alu.getZr();
            const bool isNeg  = _alu.getNe();

            const bool jgt = _ins & 0b001;
            const bool jeq = _ins & 0b010;
            const bool jlt = _ins & 0b100;

            if (jgt && !isZero && !isNeg || jeq && isZero || jlt && isNeg)
                _pc.setLoad(true);
            else
                _pc.setLoad(false);
        }
        else
            _pc.setLoad(getBit(0));

        _pc.setIn(_a.getOut());
        _pc.setInc(true);
        _pc.setReset(getBit(0));
        _pc.setClock(tick);

        // bit 6 controls the write memory flag
        // which should be linked to the load bit on the
        // RAM.
        applyBit(6, typeC && (_ins & MLoad) != 0);

        // evaluate the program counter
        (void)_pc.getOut();

        // clear the dirty flag
        clearBit(7);
#endif
    }

    void Cpu::clear()
    {
        _d.setIn(0);
        _d.setLoad(true);
        _d.setClock(true);

        _a.setIn(0);
        _a.setLoad(true);
        _a.setClock(true);

        _pc.setIn(0);
        _pc.setInc(false);
        _pc.setLoad(true);
        _pc.setClock(true);

        _ins = 0;
        _in  = 0;
        _alu.setX(0);
        _alu.setY(0);
        _alu.setFlags(0);

        _bits = 0;
        Timer::reset();
    }

}  // namespace Hack::Chips
