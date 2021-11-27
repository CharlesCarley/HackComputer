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
#include "Chips/DMux8Way.h"
#ifdef IMPLEMENT_BLACK_BOX
#include "Chips/DMux.h"
#include "Chips/DMux4Way.h"
#endif

namespace Hack::Chips
{
    constexpr uint16_t DMux8WayMask = 0b0000111111111111;

    DMux8Way::DMux8Way()
    {
        assignBit(15);
    }

    void DMux8Way::setIn(bool v)
    {
        applyBit(0, v);
        setBit(15);
    }

    void DMux8Way::setSel(const uint8_t& v)
    {
        applyBit(1, v & 1);
        applyBit(2, v & 2);
        applyBit(3, v & 4);
        setBit(15);
    }

    bool DMux8Way::getA()
    {
        if (getBit(15))
            evaluate();
        return getBit(4);
    }

    bool DMux8Way::getB()
    {
        if (getBit(15))
            evaluate();
        return getBit(5);
    }

    bool DMux8Way::getC()
    {
        if (getBit(15))
            evaluate();
        return getBit(6);
    }

    bool DMux8Way::getD()
    {
        if (getBit(15))
            evaluate();
        return getBit(7);
    }

    bool DMux8Way::getE()
    {
        if (getBit(15))
            evaluate();
        return getBit(8);
    }

    bool DMux8Way::getF()
    {
        if (getBit(15))
            evaluate();
        return getBit(9);
    }

    bool DMux8Way::getG()
    {
        if (getBit(15))
            evaluate();
        return getBit(10);
    }

    bool DMux8Way::getH()
    {
        if (getBit(15))
            evaluate();
        return getBit(11);
    }

    uint8_t DMux8Way::getOut()
    {
        if (getBit(15))
            evaluate();

        uint8_t r = 0;
        if (getBit(4))
            r |= 1;
        if (getBit(5))
            r |= 2;
        if (getBit(6))
            r |= 4;
        if (getBit(7))
            r |= 8;
        if (getBit(8))
            r |= 16;
        if (getBit(9))
            r |= 32;
        if (getBit(10))
            r |= 64;
        if (getBit(11))
            r |= 128;
        return r;
    }


    void DMux8Way::evaluate()
    {
        _bits &= DMux8WayMask;

#ifdef IMPLEMENT_BLACK_BOX
        DMux     a;
        DMux4Way b, c;

        a.setIn(getBit(0));
        a.setSel(getBit(3));

        const bool    arr[2] = {getBit(1), getBit(2)};
        const uint8_t sel    = B8::pack<2>(arr);

        b.setIn(a.getA());
        c.setIn(a.getB());
        b.setSel(sel);
        c.setSel(sel);

        applyBit(4, b.getA());
        applyBit(5, b.getB());
        applyBit(6, b.getC());
        applyBit(7, b.getD());
        applyBit(8, c.getA());
        applyBit(9, c.getB());
        applyBit(10, c.getC());
        applyBit(11, c.getD());

#else
        _bits &= 0b0000000000001111;

        bool ar[3]{getBit(1), getBit(2), getBit(3)};
        setBit(4 + B8::pack<3>(ar));
#endif
    }

}  // namespace Hack::Chips
