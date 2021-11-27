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
#include "Chips/Inc16.h"
#ifdef IMPLEMENT_BLACK_BOX
#include "Chips/HalfAdder.h"
#endif

namespace Hack::Chips
{
    Inc16::Inc16()
    {
        _bits = 0;
    }

    void Inc16::setIn(const uint16_t& v)
    {
        _bits = v;
    }

    uint16_t Inc16::getOut()
    {
        evaluate();
        return _bits;
    }

    void Inc16::evaluate()
    {
#ifdef IMPLEMENT_BLACK_BOX
        HalfAdder       n;
        const uint16_t& a0 = _bits;

        uint32_t r0 = 0;

        bool c1 = true;
        for (uint16_t i = 0; i < 16; ++i)
        {
            const uint16_t p = (uint16_t)(1 << i);
            n.setA((a0 & p) != 0);
            n.setB(c1);

            if (n.getSum())
                r0 |= p;
            c1 = n.getCary();
        }

        _bits = (uint16_t)r0;
#else
        ++_bits;
#endif
    }

}  // namespace Hack::Chips
