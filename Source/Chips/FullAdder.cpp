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
#include "Chips/FullAdder.h"
#include "Chips/And.h"
#include "Chips/Or.h"
#include "Chips/XOr.h"

namespace Hack::Chips
{
    FullAdder::FullAdder()
    {
        assignBit(7);
    }

    void FullAdder::setA(bool v)
    {
        applyBit(0, v);
        setBit(7);
    }

    void FullAdder::setB(bool v)
    {
        applyBit(1, v);
        setBit(7);
    }

    void FullAdder::setCaryIn(bool v)
    {
        applyBit(2, v);
        setBit(7);
    }

    bool FullAdder::getSum()
    {
        if (getBit(7))
            evaluate();
        return getBit(6);
    }

    bool FullAdder::getCary()
    {
        if (getBit(7))
            evaluate();
        return getBit(5);
    }

    void FullAdder::evaluate()
    {
        XOr x1, x2;
        And a1, a2;
        Or  o1;

        x1.setA(getBit(0));
        x1.setB(getBit(1));
        a1.setA(getBit(0));
        a1.setB(getBit(1));

        x2.setA(x1.getOut());
        x2.setB(getBit(2));

        a2.setA(x1.getOut());
        a2.setB(getBit(2));

        o1.setA(a2.getOut());
        o1.setB(a1.getOut());
        applyBit(6, x2.getOut());
        applyBit(5, o1.getOut());
        clearBit(7);
    }

}  // namespace Hack::Chips
