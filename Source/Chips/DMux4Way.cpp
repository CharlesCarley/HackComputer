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
#include "Chips/DMux4Way.h"
#include <cmath>
#ifdef IMPLEMENT_BLACK_BOX
#include "Chips/DMux.h"
#endif

namespace Hack::Chips
{
    DMux4Way::DMux4Way()
    {
        assignBit(7);
    }

    void DMux4Way::setIn(bool input)
    {
        applyBit(0, input);
        setBit(7);
    }

    void DMux4Way::setSel(const uint8_t& selection)
    {
        applyBit(1, selection & 1);
        applyBit(2, selection & 2);
        setBit(7);
    }

    bool DMux4Way::getA()
    {
        if (getBit(7))
            evaluate();
        return getBit(3);
    }

    bool DMux4Way::getB()
    {
        if (getBit(7))
            evaluate();
        return getBit(4);
    }

    bool DMux4Way::getC()
    {
        if (getBit(7))
            evaluate();
        return getBit(5);
    }

    bool DMux4Way::getD()
    {
        if (getBit(7))
            evaluate();
        return getBit(6);
    }

    uint8_t DMux4Way::getOut()
    {
        if (getBit(7))
            evaluate();

        uint8_t r = 0;
        if (getBit(3))
            r |= 1;
        if (getBit(4))
            r |= 2;
        if (getBit(5))
            r |= 4;
        if (getBit(6))
            r |= 8;
        return r;
    }

    uint8_t DMux4Way::getIndex()
    {
        return (uint8_t)(int)std::log2(getOut());
    }

    void DMux4Way::evaluate()
    {
#ifdef IMPLEMENT_BLACK_BOX
        DMux a, b, c;

        a.setIn(getBit(0));
        a.setSel(getBit(2));

        b.setIn(a.getA());
        b.setSel(getBit(1));
        c.setIn(a.getB());
        c.setSel(getBit(1));

        applyBit(3, b.getA());
        applyBit(4, b.getB());

        applyBit(5, c.getA());
        applyBit(6, c.getB());

        clearBit(7);
#else
        _bits &= 0b00000111;
        bool ar[2]{getBit(1), getBit(2)};

        setBit(3 + B8::pack<2>(ar));
#endif
    }
} // namespace Hack::Chips
