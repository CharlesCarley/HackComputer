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
#include "Chips/Mux16.h"
#ifdef IMPLEMENT_BLACK_BOX
#include "Chips/Mux.h"
#endif

namespace Hack::Chips
{
    Mux16::Mux16()
    {
        _bits.ll   = 0;
        _bits.s[3] = 1;
    }

    void Mux16::setA(const uint16_t& v)
    {
        _bits.s[0] = v;
        _bits.s[3] |= 1;
    }

    void Mux16::setB(const uint16_t& v)
    {
        _bits.s[1] = v;
        _bits.s[3] |= 1;
    }

    void Mux16::setSel(bool v)
    {
        _bits.s[3] |= 1;
        if (v)
            _bits.s[3] |= 2;
        else
            _bits.s[3] &= ~2;
    }

    uint16_t Mux16::getOut()
    {
        if (_bits.s[3] & 1)
            evaluate();
        return _bits.s[2];
    }

    void Mux16::evaluate()
    {
#ifdef IMPLEMENT_BLACK_BOX
        Mux n;
        _bits.s[2] = 0;
        for (uint16_t i = 0; i < 16; ++i)
        {
            const uint16_t p = (uint16_t)(1 << i);
            const bool     a = (_bits.s[0] & p) != 0;
            const bool     b = (_bits.s[1] & p) != 0;

            n.setA(a);
            n.setB(b);
            n.setSel(_bits.s[3] & 2);

            if (n.getOut())
                _bits.s[2] |= p;
        }

        _bits.s[3] &= ~1;
#else
        if (_bits.s[3] & 2)
            _bits.s[2] = _bits.s[1];
        else
            _bits.s[2] = _bits.s[0];
        _bits.s[3] &= ~1;
#endif
    }
} // namespace Hack::Chips
