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
#include "Chips/Bit.h"

#ifdef IMPLEMENT_BLACK_BOX
#include "Chips/Mux.h"
#endif

namespace Hack::Chips
{
    constexpr uint8_t BitMask = 0b01011111;

    Bit::Bit()
    {
        _bits = 0;
    }

    void Bit::setIn(bool v)
    {
        applyBit(0, v);
    }

    void Bit::setLoad(bool v)
    {
        applyBit(6, v);
    }

    void Bit::setClock(bool v)
    {
        applyBit(4, v);
    }

    bool Bit::getOut()
    {
        evaluate();
        return getBit(1);
    }

    void Bit::evaluate()
    {
        _bits &= BitMask;

        const bool a = getBit(0);
        const bool l = getBit(6);
        const bool c = getBit(4);

        if (l)
        {
            if (c)
            {
                applyBit(1, a);
                applyBit(2, a);
            }
            else
            {
                applyBit(1, getBit(2));
                applyBit(2, a);
            }
        }
    }

}  // namespace Hack::Chips
