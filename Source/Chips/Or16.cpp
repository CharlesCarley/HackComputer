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
#include "Chips/Or16.h"

namespace Hack::Chips
{
    Or16::Or16()
    {
        _bits.ll   = 0;
        _bits.s[3] = 1;
    }

    void Or16::setA(const uint16_t& v)
    {
        _bits.s[0] = v;
        _bits.s[3] = 1;
    }

    void Or16::setB(const uint16_t& v)
    {
        _bits.s[1] = v;
        _bits.s[3] = 1;
    }

    uint16_t Or16::getOut()
    {
        if (_bits.s[3])
            evaluate();
        return _bits.s[2];
    }

    void Or16::evaluate()
    {
#ifdef IMPLEMENT_BLACK_BOX
        const uint16_t& a = _bits.s[0];
        const uint16_t& b = _bits.s[1];

        _bits.s[2] = 0;

        for (uint16_t i = 0; i < 16; ++i)
        {
            const bool ba = B16::getBit(a, i);
            const bool bb = B16::getBit(b, i);
            B16::applyBit(_bits.s[2], i, (ba | bb) != 0);
        }

        _bits.s[3] = 0;
#else
        _bits.s[2] = _bits.s[0] | _bits.s[1];
        _bits.s[3] = 0;
#endif
    }

}  // namespace Hack::Chips
