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
#include "Chips/ProgramCounter.h"

#ifdef IMPLEMENT_BLACK_BOX
#include "Chips/Inc16.h"
#include "Chips/Mux16.h"
#include "Chips/Register.h"
#endif

namespace Hack::Chips
{
    ProgramCounter::ProgramCounter()
    {
        _bits.ll   = 0;
        _bits.b[6] = Bit7;
    }

    void ProgramCounter::setIn(const uint16_t& v)
    {
        _bits.s[0] = v;
        _bits.b[6] |= Bit7;
    }

    void ProgramCounter::setFlags(const uint8_t& v)
    {
        _bits.b[6] = v & 0b00000111;
        _bits.b[6] |= Bit7;
    }

    void ProgramCounter::lock(bool v)
    {
        if (v)
            _bits.b[6] |= Bit6;
        else
            _bits.b[6] &= ~Bit6;
    }

    void ProgramCounter::setInc(bool v)
    {
        if (v)
            _bits.b[6] |= Bit0;
        else
            _bits.b[6] &= ~Bit0;

        _bits.b[6] |= Bit7;
    }

    void ProgramCounter::setReset(bool v)
    {
        if (v)
            _bits.b[6] |= Bit1;
        else
            _bits.b[6] &= ~Bit1;

        _bits.b[6] |= Bit7;
    }

    void ProgramCounter::setLoad(bool v)
    {
        if (v)
            _bits.b[6] |= Bit2;
        else
            _bits.b[6] &= ~Bit2;

        _bits.b[6] |= Bit7;
    }

    void ProgramCounter::setClock(bool v)
    {
        _bits.b[7] = v;
        _bits.b[6] |= Bit7;
    }

    uint16_t ProgramCounter::getOut()
    {
        if (_bits.b[6] & Bit7 && !(_bits.b[6] & Bit6))
            evaluate();
        return _bits.s[1];
    }

    bool ProgramCounter::isDirty()
    {
        return B8::getBit(_bits.b[6], 7);
    }

    void ProgramCounter::evaluate()
    {
#ifdef IMPLEMENT_BLACK_BOX
        Inc16 cnt;
        Mux16 a, b, c;
        cnt.setIn(_bits.s[1]);

        a.setA(_bits.s[1]);
        a.setB(cnt.getOut());
        a.setSel(_bits.b[6] & PCF_INC);

        b.setA(a.getOut());
        b.setB(_bits.s[0]);
        b.setSel(_bits.b[6] & PCF_LOAD);

        c.setA(b.getOut());
        c.setB((uint16_t)0);
        c.setSel(_bits.b[6] & PCF_RESET);

        _store.setIn(c.getOut());
        _store.setClock(_bits.b[7]);
        _store.setLoad(true);
        _bits.s[1] = _store.getOut();
#else
        uint16_t value = _bits.s[1];

        if (_bits.b[6] & PCF_INC)
            value++;
        if (_bits.b[6] & PCF_LOAD)
            value = _bits.s[0];
        if (_bits.b[6] & PCF_RESET)
            value = 0;

        if (_bits.b[7])
            _bits.s[1] = _bits.s[2] = value;
        else
        {
            _bits.s[1] = _bits.s[2];
            _bits.s[2] = value;
        }
#endif
        _bits.b[6] &= ~Bit7;
    }
} // namespace Hack::Chips
