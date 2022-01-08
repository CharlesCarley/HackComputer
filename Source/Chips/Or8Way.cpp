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
#include "Chips/Or8Way.h"

namespace Hack::Chips
{
    Or8Way::Or8Way()
    {
        assignBit(15);
    }

    void Or8Way::setIn(uint8_t v)
    {
        bit16_t r{};
        r.b[0] = v;
        r.b[1] = 0;

        _bits = r.s;
        setBit(15);
    }

    bool Or8Way::getOut()
    {
        if (getBit(15))
            evaluate();
        return getBit(14);
    }

    void Or8Way::evaluate()
    {
#ifdef IMPLEMENT_BLACK_BOX
        applyBit(9, getBit(0) || getBit(1));
        applyBit(10, getBit(2) || getBit(3));
        applyBit(11, getBit(4) || getBit(5));
        applyBit(12, getBit(6) || getBit(7));
        applyBit(0, getBit(9) || getBit(10));
        applyBit(1, getBit(11) || getBit(12));
        applyBit(14, getBit(0) || getBit(1));
        clearBit(15);
#else
        const uint16_t& mask = _bits & 0b0000000011111111;
        applyBit(14, mask != 0);
        clearBit(15);
#endif
    }
} // namespace Hack::Chips
