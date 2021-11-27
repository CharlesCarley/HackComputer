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
#include "Chips/Ram64.h"
#include "Ram8.h"
#include <cstring>
#ifdef IMPLEMENT_BLACK_BOX
#include "Chips/DMux8Way.h"
#include "Chips/Mux8Way16.h"
#endif

namespace Hack::Chips
{
    Ram64::Ram64() :
        _r(nullptr)
    {
#ifdef IMPLEMENT_BLACK_BOX
        _r = new Ram8[8];
#else
        _r = new bit32_t[64];
#endif
        memset(_r, 0, sizeof(bit32_t) * 64);

        _bits.ll = 0;
        markDirty();
    }

    Ram64::~Ram64()
    {
        delete[] _r;
    }

    void Ram64::setIn(const uint16_t& v)
    {
        _bits.s[0] = v;
        markDirty();
    }

    void Ram64::setAddress(const uint8_t& v)
    {
        _bits.b[6] = v & 0b10111111;
        markDirty();
    }

    void Ram64::setLoad(const bool v)
    {
        B8::applyBit(_bits.b[7], 0, v);
        markDirty();
    }

    void Ram64::setClock(const bool v)
    {
        B8::applyBit(_bits.b[7], 1, v);
        markDirty();
    }

    uint16_t Ram64::getOut()
    {
        if (isDirty())
            evaluate();
        return _bits.s[1];
    }

    uint16_t Ram64::getOut(const bool v)
    {
        setClock(v);
        return getOut();
    }

    bool Ram64::isDirty()
    {
        return B8::getBit(_bits.b[6], 7);
    }

    void Ram64::markDirty()
    {
        B8::setBit(_bits.b[6], 7);
    }

    void Ram64::evaluate()
    {
#ifdef IMPLEMENT_BLACK_BOX

        Mux8Way16 n;
        DMux8Way  d;

        const bool load  = B8::getBit(_bits.b[7], 0);
        const bool clock = B8::getBit(_bits.b[7], 1);

        const uint8_t& lo = B8::extract(_bits.b[6] & 0b00111111, 0, 2);
        const uint8_t& hi = B8::extract(_bits.b[6] & 0b00111111, 3, 5);

        d.setIn(load);
        d.setSel(lo);
        n.setSel(lo);

        bool index[8]{d.getA(), d.getB(), d.getC(), d.getD(), d.getE(), d.getF(), d.getG(), d.getH()};

        Ram8* ram8 = &_r[0];

        for (bool element : index)
        {
            (*ram8).setLoad(element);
            (*ram8).setIn(_bits.s[0]);
            (*ram8).setAddress(hi);
            (*ram8).setClock(clock);

            ++ram8;
        }

        n.setA(_r[0].getOut());
        n.setB(_r[1].getOut());
        n.setC(_r[2].getOut());
        n.setD(_r[3].getOut());
        n.setE(_r[4].getOut());
        n.setF(_r[5].getOut());
        n.setG(_r[6].getOut());
        n.setH(_r[7].getOut());

        _bits.s[1] = n.getOut();
#else

        const uint8_t index = _bits.s[3] & 0b00111111;

        if (B8::getBit(_bits.b[7], 0))
        {
            if (B8::getBit(_bits.b[7], 1))
                _r[index].s[0] = _r[index].s[1] = _bits.s[0];
            else
            {
                _r[index].s[0] = _r[index].s[1];
                _r[index].s[1] = _bits.s[0];
            }
        }

        _bits.s[1] = _r[index].s[0];
#endif
        B8::clearBit(_bits.b[6], 7);
    }

}  // namespace Hack::Chips
