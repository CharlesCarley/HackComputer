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
#include "Chips/Mux4Way16.h"
#include "Mux16.h"

namespace Hack::Chips
{
    Mux4Way16::Mux4Way16()
    {
        _out   = 0;
        _flags = 1 << 7;
    }

    void Mux4Way16::setA(const uint16_t& v)
    {
        _bits.s[0] = v;
        B8::setBit(_flags, 7);
    }

    void Mux4Way16::setB(const uint16_t& v)
    {
        _bits.s[1] = v;
        B8::setBit(_flags, 7);
    }

    void Mux4Way16::setC(const uint16_t& v)
    {
        _bits.s[2] = v;
        B8::setBit(_flags, 7);
    }

    void Mux4Way16::setD(const uint16_t& v)
    {
        _bits.s[3] = v;
        B8::setBit(_flags, 7);
    }

    void Mux4Way16::setSel(uint8_t v)
    {
        B8::applyBit(_flags, 0, v & 1);
        B8::applyBit(_flags, 1, v & 2);
        B8::setBit(_flags, 7);
    }

    uint16_t Mux4Way16::getOut()
    {
        if (_flags & 128)
            evaluate();
        return _out;
    }

    void Mux4Way16::evaluate()
    {
#ifdef IMPLEMENT_BLACK_BOX
        Mux16 a, b, c;

        const bool ba = B8::getBit(_flags, 0);
        const bool bb = B8::getBit(_flags, 1);

        a.setA(_bits.s[0]);
        a.setB(_bits.s[1]);
        a.setSel(ba);

        b.setA(_bits.s[2]);
        b.setB(_bits.s[3]);
        b.setSel(ba);

        c.setA(a.getOut());
        c.setB(b.getOut());
        c.setSel(bb);

        _out = c.getOut();

        _flags &= ~128;
#else
        uint8_t ba = 0;
        if (B8::getBit(_flags, 0))
            ba |= 1;
        if (B8::getBit(_flags, 1))
            ba |= 2;

        _out = _bits.s[ba];
        _flags &= ~128;
#endif
    }

}  // namespace Hack::Chips
