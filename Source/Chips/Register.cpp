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
#include "Chips/Register.h"

namespace Hack::Chips
{
    constexpr uint64_t RegisterMask = 0xFFFFFFFFFFFFFF;

    Register::Register()
    {
        _bits.ll = 0;
        B8::assignBit(_bits.b[6], 7);
    }

    void Register::setIn(const uint16_t& v)
    {
        _bits.s[0] = v;
        B8::setBit(_bits.b[6], 7);
    }

    void Register::setLoad(bool write)
    {
        B8::applyBit(_bits.b[6], 0, write);
        B8::setBit(_bits.b[6], 7);
    }

    void Register::setClock(bool tick)
    {
        B8::applyBit(_bits.b[6], 1, tick);
        B8::setBit(_bits.b[6], 7);
    }

    uint16_t Register::getOut()
    {
        if (B8::getBit(_bits.b[6], 7))
            evaluate();
        return _bits.s[1];
    }

    bool Register::isDirty()
    {
        return B8::getBit(_bits.b[6], 7);
    }

    void Register::evaluate()
    {
        _bits.ll &= RegisterMask;

#ifdef IMPLEMENT_BLACK_BOX

        const bool load  = B8::getBit(_bits.b[6], 0);
        const bool clock = B8::getBit(_bits.b[6], 1);

        _bits.s[1] = 0;

        for (uint16_t i = 0; i < 16; ++i)
        {
            const uint16_t& p = (uint16_t)(1 << i);

            const bool a = _bits.s[0] & p;
            _r[i].setIn(a);
            _r[i].setLoad(load);
            _r[i].setClock(clock);

            if (_r[i].getOut())
                _bits.s[1] |= p;
        }
#else
        if (B8::getBit(_bits.b[6], 0))
        {
            if (B8::getBit(_bits.b[6], 1))
                _bits.s[1] = _bits.s[2] = _bits.s[0];
            else
            {
                _bits.s[1] = _bits.s[2];
                _bits.s[2] = _bits.s[0];
            }
        }
#endif

        B8::clearBit(_bits.b[6], 7);
    }

}  // namespace Hack::Chips
