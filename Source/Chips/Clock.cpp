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
#include "Chips/Clock.h"

namespace Hack::Chips
{
    constexpr uint8_t ClockMask = 0b00000011;

    Clock::Clock()
    {
        // Needs to start as false for the
        // clocked D-flip-flops to work.
        // 6 = reset
        // 1 = input
        _bits = 0b01000000;
    }

    void Clock::setIn(bool v)
    {
        applyBit(1, v);
    }

    void Clock::setReset(bool v)
    {
        applyBit(6, v);
    }

    bool Clock::getOut()
    {
        _bits &= ClockMask;
#ifdef IMPLEMENT_BLACK_BOX
        if (getBit(6))
            applyBit(0, getBit(1));
        else
            applyBit(0, Gates::Not(getBit(0)));
        return getBit(0);
#else
        if (_bits & Bit6)
        {
            if ((_bits & Bit1) != 0)
                _bits |= Bit0;
            else
                _bits &= ~Bit0;
        }
        else
        {
            if ((_bits & Bit0) == 0)
                _bits |= Bit0;
            else
                _bits &= ~Bit0;
        }
        return (_bits & Bit0) != 0;
#endif
    }

}  // namespace Hack::Chips
