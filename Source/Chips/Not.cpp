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
#include "Chips/Not.h"

namespace Hack::Chips
{
    Not::Not()
    {
        assignBit(7);
    }

    void Not::setIn(bool v)
    {
        applyBit(0, v);
        setBit(7);
    }

    void Not::evaluate()
    {
#ifdef IMPLEMENT_BLACK_BOX
        applyBit(6, Gates::Not(getBit(0)));
#else
        applyBit(6, !getBit(0));
#endif
        clearBit(7);
    }

    bool Not::getOut()
    {
        if (getBit(7))
            evaluate();
        return getBit(6);
    }

}  // namespace Hack::Chips
