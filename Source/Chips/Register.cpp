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
    Register::Register()
    {
        _bits.ll   = 0;
        _bits.b[6] = Bit7;
    }

    void Register::setIn(const uint16_t& v)
    {
        if (_bits.s[0] != v)
        {
            _bits.s[0] = v;
            _bits.b[6] |= Bit7;
        }
    }

    void Register::setLoad(const bool write)
    {
        const bool test = (_bits.b[6] & Bit0) != 0;
        if (test != write)
        {
            if (write)
                _bits.b[6] |= Bit0;
            else
                _bits.b[6] &= ~Bit0;
            _bits.b[6] |= Bit7;
        }
    }

    void Register::setClock(const bool tick)
    {
        const bool test = (_bits.b[6] & Bit1) != 0;
        if (test != tick)
        {
            if (tick)
                _bits.b[6] |= Bit1;
            else
                _bits.b[6] &= ~Bit1;

            _bits.b[6] |= Bit7;
        }
    }

    uint16_t Register::getOut()
    {
        if (_bits.b[6] & Bit7 && !(_bits.b[6] & Bit6))
            evaluate();
        return _bits.s[1];
    }

    void Register::lock(bool v)
    {
        if (v)
            _bits.b[6] |= Bit6;
        else
            _bits.b[6] &= ~Bit6;
    }

    bool Register::isDirty()
    {
        return B8::getBit(_bits.b[6], 7);
    }

    void Register::evaluate()
    {
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
        B8::clearBit(_bits.b[6], 7);

#else
        if (_bits.b[6] & Bit0)
        {
            if (_bits.b[6] & Bit1)
                _bits.s[1] = _bits.s[2] = _bits.s[0];
            else
            {
                _bits.s[1] = _bits.s[2];
                _bits.s[2] = _bits.s[0];
            }
        }

        _bits.b[6] &= ~Bit7;
#endif
    }
} // namespace Hack::Chips
