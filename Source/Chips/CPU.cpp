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
#include "Chips/And16.h"
#include "Chips/ALU.h"
#include "Chips/Mux16.h"
#include "Chips/ProgramCounter.h"
#include "Chips/Register.h"

namespace Hack::Chips
{
    Cpu::Cpu() :
        _ins(0),
        _in(0)
    {
        assignBit(7);
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
        And16 and16;
        Mux16 m0, m1, mt;

        bool codes[16];
        B16::unpack(_ins, codes);

        const bool clk = getBit(1);

        const bool cIns = codes[15];

        const bool aIns = Gates::Not(cIns);
        // a
        const bool ld0 = Gates::Or(aIns, codes[5]);

        // Am
        const bool ld1 = Gates::And(cIns, codes[12]);

        // d
        const bool ld2 = Gates::And(cIns, codes[4]);

        // writeM
        const bool ld3 = Gates::And(cIns, codes[3]);

        // ------------------------ M0 ------------------------
        m0.setA(_alu.getOut());
        m0.setB(_ins);
        m0.setSel(aIns);

        // ------------------------ Ar ------------------------
        _a.setLoad(ld0);

        and16.setA(m0.getOut());
        and16.setB(0b0111111111111111);

        _a.setIn(and16.getOut());
        _a.setClock(clk);

        // ------------------------ M1 ------------------------
        m1.setA(_a.getOut());
        m1.setB(_in);
        m1.setSel(ld1);

        // ----------------------- ALU ------------------------
        bool c[6]{codes[6], codes[7], codes[8], codes[9], codes[10], codes[11]};
        _alu.setFlags(B8::pack<6>(c));
        _alu.setX(_d.getOut());
        _alu.setY(m1.getOut());

        // ------------------------ Dr ------------------------
        _d.setLoad(ld2);
        _d.setIn(_alu.getOut());
        _d.setClock(Gates::Not(clk));  // t-1

        // ------------------------ PC ------------------------
        // J-bits

        const bool Zr = _alu.getZr();
        const bool Ne = _alu.getNe();

        const bool ZrNeI = Gates::And(Gates::Not(Zr), Gates::Not(Ne));
        const bool ld4   = Gates::Or3(
            Gates::And(Gates::And(cIns, codes[0]), ZrNeI),
            Gates::And(Gates::And(cIns, codes[1]), Zr),
            Gates::And(Gates::And(cIns, codes[2]), Ne)

        );
        if (ld4)
            _pc.setLoad(ld4);
        else
            _pc.setLoad(getBit(0));

        _pc.setIn(_a.getOut());
        _pc.setInc(true);
        _pc.setReset(getBit(0));
        _pc.setClock(clk);

        applyBit(6, ld3);

        _pc.getOut();
        clearBit(7);
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

        evaluate();
    }

}  // namespace Hack::Chips
