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
#include "Chips/Mux8Way16.h"
#ifdef IMPLEMENT_BLACK_BOX
#include "Chips/Mux16.h"
#include "Chips/Mux4Way16.h"
#endif

namespace Hack::Chips
{
    constexpr uint8_t Mux8Way16Mask = 0b00000111;

    Mux8Way16::Mux8Way16() :
        _in{{}, {}}
    {
        _out = 0;
        assignBit(7);
    }

    void Mux8Way16::setA(const uint16_t& a)
    {
        _in[0].s[0] = a;
        setBit(7);
    }

    void Mux8Way16::setB(const uint16_t& b)
    {
        _in[0].s[1] = b;
        setBit(7);
    }

    void Mux8Way16::setC(const uint16_t& c)
    {
        _in[0].s[2] = c;
        setBit(7);
    }

    void Mux8Way16::setD(const uint16_t& d)
    {
        _in[0].s[3] = d;
        setBit(7);
    }

    void Mux8Way16::setE(const uint16_t& e)
    {
        _in[1].s[0] = e;
        setBit(7);
    }

    void Mux8Way16::setF(const uint16_t& f)
    {
        _in[1].s[1] = f;
        setBit(7);
    }

    void Mux8Way16::setG(const uint16_t& g)
    {
        _in[1].s[2] = g;
        setBit(7);
    }

    void Mux8Way16::setH(const uint16_t& h)
    {
        _in[1].s[3] = h;
        setBit(7);
    }

    void Mux8Way16::setSel(const uint8_t& selection)
    {
        applyBit(0, selection & 1);
        applyBit(1, selection & 2);
        applyBit(2, selection & 4);
        setBit(7);
    }

    uint16_t Mux8Way16::getOut()
    {
        if (getBit(7))
            evaluate();
        return _out;
    }

    void Mux8Way16::evaluate()
    {
        _bits &= Mux8Way16Mask;

#ifdef IMPLEMENT_BLACK_BOX
        Mux16     o;
        Mux4Way16 a, b;

        const bool    v[]{getBit(0), getBit(1)};
        const uint8_t ba = B8::pack<2>(v);

        a.setA(_in[0].s[0]);
        a.setB(_in[0].s[1]);
        a.setC(_in[0].s[2]);
        a.setD(_in[0].s[3]);
        a.setSel(ba);

        b.setA(_in[1].s[0]);
        b.setB(_in[1].s[1]);
        b.setC(_in[1].s[2]);
        b.setD(_in[1].s[3]);
        b.setSel(ba);

        o.setA(a.getOut());
        o.setB(b.getOut());
        o.setSel(getBit(2));

        _out = o.getOut();
#else
        uint8_t ba = 0;

        const uint8_t bb = getBit(2) ? 1 : 0;
        if (getBit(0))
            ba |= 1;
        if (getBit(1))
            ba |= 2;

        _out = _in[bb].s[ba];
#endif
    }
} // namespace Hack::Chips
