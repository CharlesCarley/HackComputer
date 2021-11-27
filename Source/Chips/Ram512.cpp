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
#include "Chips/Ram512.h"
#include <cstring>

#ifdef IMPLEMENT_BLACK_BOX
#include "Chips/DMux8Way.h"
#include "Chips/Mux8Way16.h"
#include "Chips/Ram64.h"
#endif

namespace Hack::Chips
{
    Ram512::Ram512() :
        _in(0),
        _inP(0),
        _address(0),
        _r(nullptr)
    {
#ifdef IMPLEMENT_BLACK_BOX
        _r = new Ram64[8];
#else
        _r = new bit32_t[512];
        memset(_r, 0, sizeof(bit32_t) * 512);
#endif
        _bits = 0;
        markDirty();
    }

    Ram512::~Ram512()
    {
        delete[] _r;
    }

    void Ram512::setIn(const uint16_t& v)
    {
        _in = v;
        markDirty();
    }

    void Ram512::setAddress(const uint16_t& v)
    {
        _address = v & 0b0000000111111111;
    }

    void Ram512::setLoad(const bool v)
    {
        applyBit(0, v);
        markDirty();
    }

    void Ram512::setClock(const bool v)
    {
        applyBit(1, v);
        markDirty();
    }

    uint16_t Ram512::getOut()
    {
        if (isDirty())
            evaluate();
        return _inP;
    }

    bool Ram512::isDirty()
    {
        return getBit(7);
    }

    void Ram512::markDirty()
    {
        setBit(7);
    }

    void Ram512::evaluate()
    {
#ifdef IMPLEMENT_BLACK_BOX
        Mux8Way16 n;
        DMux8Way  d;

        const bool load  = getBit(0);
        const bool clock = getBit(1);

        const uint8_t& lo =
            B8::extract((uint8_t)_address & 0b0000000011111111, 0, 2);
        const uint8_t& hi =
            (uint8_t)B16::extract(_address & 0b0000000111111111, 3, 8);

        d.setIn(load);
        d.setSel(lo);
        n.setSel(lo);

        bool index[8]{d.getA(), d.getB(), d.getC(), d.getD(), d.getE(), d.getF(), d.getG(), d.getH()};

        Ram64* ram64 = &_r[0];

        for (bool element : index)
        {
            (*ram64).setLoad(element);
            (*ram64).setIn(_in);
            (*ram64).setAddress(hi);
            (*ram64).setClock(clock);

            ++ram64;
        }

        n.setA(_r[0].getOut());
        n.setB(_r[1].getOut());
        n.setC(_r[2].getOut());
        n.setD(_r[3].getOut());
        n.setE(_r[4].getOut());
        n.setF(_r[5].getOut());
        n.setG(_r[6].getOut());
        n.setH(_r[7].getOut());

        _inP = n.getOut();
#else

        if (getBit(0))
        {
            if (getBit(1))
                _r[_address].s[0] = _r[_address].s[1] = _in;
            else
            {
                _r[_address].s[0] = _r[_address].s[1];
                _r[_address].s[1] = _in;
            }
        }

        _inP = _r[_address].s[0];

#endif
        clearBit(7);
    }

}  // namespace Hack::Chips
