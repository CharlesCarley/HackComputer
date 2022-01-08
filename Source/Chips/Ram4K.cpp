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
#include "Chips/Ram4k.h"
#include <cstring>

#ifdef IMPLEMENT_BLACK_BOX
#include "Chips/DMux8Way.h"
#include "Chips/Mux8Way16.h"
#include "Chips/Ram64.h"
#endif

namespace Hack::Chips
{
    Ram4k::Ram4k() :
        _in(0),
        _inP(0),
        _address(0),
        _r(nullptr)
    {
#ifdef IMPLEMENT_BLACK_BOX
        _r = new Ram512[8];
#else
        _r = new bit32_t[4096];
        memset(_r, 0, sizeof(bit32_t) * 4096);
#endif
        markDirty();
    }

    Ram4k::~Ram4k()
    {
        delete[] _r;
    }

    void Ram4k::setIn(const uint16_t& v)
    {
        _in = v;
        markDirty();
    }

    void Ram4k::setAddress(const uint16_t& v)
    {
        _address = v & 0b0000111111111111;
    }

    void Ram4k::setLoad(const bool v)
    {
        applyBit(0, v);
        markDirty();
    }

    void Ram4k::setClock(const bool v)
    {
        applyBit(1, v);
        markDirty();
    }

    uint16_t Ram4k::getOut()
    {
        if (isDirty())
            evaluate();
        return _inP;
    }

    bool Ram4k::isDirty()
    {
        return getBit(7);
    }

    void Ram4k::markDirty()
    {
        setBit(7);
    }

    void Ram4k::evaluate()
    {
#ifdef IMPLEMENT_BLACK_BOX
        Mux8Way16 n;
        DMux8Way  d;

        const bool load  = getBit(0);
        const bool clock = getBit(1);

        const uint8_t&  lo = B8::extract((uint8_t)_address, 0, 2);
        const uint16_t& hi = B16::extract(_address, 3, 11);

        d.setIn(load);
        d.setSel(lo);
        n.setSel(lo);

        bool index[8]{d.getA(), d.getB(), d.getC(), d.getD(), d.getE(), d.getF(), d.getG(), d.getH()};

        Ram512* ram = &_r[0];

        for (bool element : index)
        {
            (*ram).setLoad(element);
            (*ram).setIn(_in);
            (*ram).setAddress(hi);
            (*ram).setClock(clock);

            ++ram;
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
} // namespace Hack::Chips
