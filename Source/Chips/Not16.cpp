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
#include "Chips/Not16.h"
#ifdef IMPLEMENT_BLACK_BOX
#include "Chips/Not.h"
#endif

namespace Hack::Chips
{
    Not16::Not16()
    {
        _bits = 0;
    }

    void Not16::setIn(const uint16_t& v)
    {
        _bits = v;
    }

    uint16_t Not16::getOut()
    {
        evaluate();
        return _bits;
    }

    void Not16::evaluate()
    {
#ifdef IMPLEMENT_BLACK_BOX
        Not n;
        for (uint8_t i=0; i<16; ++i)
        {
            n.setIn(getBit(i));
            applyBit(i, Gates::Not(getBit(i)));
        }
#else
        _bits = ~_bits;
#endif
    }
} // namespace Hack::Chips
