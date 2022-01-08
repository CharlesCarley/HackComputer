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
#include "Chips/HalfAdder.h"

namespace Hack::Chips
{
    HalfAdder::HalfAdder()
    {
        assignBit(7);
    }

    void HalfAdder::setA(bool a)
    {
        applyBit(0, a);
        setBit(7);
    }

    void HalfAdder::setB(bool b)
    {
        applyBit(1, b);
        setBit(7);
    }

    bool HalfAdder::getSum()
    {
        if (getBit(7))
            evaluate();
        return getBit(6);
    }

    bool HalfAdder::getCary()
    {
        if (getBit(7))
            evaluate();
        return getBit(5);
    }

    void HalfAdder::evaluate()
    {
        const bool a = getBit(0);
        const bool b = getBit(1);

        applyBit(6, Gates::XOr(a, b));
        applyBit(5, Gates::And(a, b));
        clearBit(7);
    }
} // namespace Hack::Chips
