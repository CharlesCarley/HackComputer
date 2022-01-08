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
#include "Chips/DFlipFlop.h"

namespace Hack::Chips
{
    DFlipFlop::DFlipFlop()
    {
        assignBit(7);
        setBit(4);
    }

    void DFlipFlop::setD(bool d)
    {
        applyBit(0, d);
        setBit(7);
    }

    void DFlipFlop::setG(bool g)
    {
        applyBit(1, g);
        setBit(7);
    }

    void DFlipFlop::setQn(bool qn)
    {
        // explicitly set the previous value
        // for testing purposes...
        applyBit(6, qn);
        clearBit(4);
        setBit(7);
    }

    bool DFlipFlop::getQ()
    {
        if (getBit(7))
            evaluate();
        return getBit(2);
    }

    bool DFlipFlop::getQPlus()
    {
        if (getBit(7))
            evaluate();
        return getBit(3);
    }

    void DFlipFlop::evaluate()
    {
        if (getBit(4))
            setQn(getBit(0));

        const bool cur = getBit(0);
        const bool clk = getBit(1);

        if (clk)
        {
            if (!cur)
            {
                applyBit(2, false);
                applyBit(3, true);
            }
            else
            {
                applyBit(2, true);
                applyBit(3, false);
            }

            applyBit(6, getBit(2));
        }
        else
        {
            applyBit(2, getBit(6));
            applyBit(3, !getBit(2));
        }

        clearBit(7);
    }
} // namespace Hack::Chips
