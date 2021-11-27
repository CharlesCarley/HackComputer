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
#include "Chips/Ram8.h"

#ifdef IMPLEMENT_BLACK_BOX
#include "Chips/DMux8Way.h"
#include "Chips/Mux8Way16.h"
#endif

namespace Hack::Chips
{
    Ram8::Ram8() :
        _r()
    {
        _bits.ll = 0;
        B8::assignBit(_bits.b[6], 7);
    }

    void Ram8::setIn(const uint16_t& v)
    {
        _bits.s[0] = v;
        B8::setBit(_bits.b[6], 7);
    }

    void Ram8::setAddress(const uint8_t& v)
    {
        _bits.b[6] = v & 0b10000111;
        B8::setBit(_bits.b[6], 7);
    }

    void Ram8::setLoad(bool write)
    {
        B8::applyBit(_bits.b[7], 0, write);
        B8::setBit(_bits.b[6], 7);
    }

    void Ram8::setClock(bool tick)
    {
        B8::applyBit(_bits.b[7], 1, tick);
        B8::setBit(_bits.b[6], 7);
    }

    uint16_t Ram8::getOut()
    {
        if (B8::getBit(_bits.b[6], 7))
            evaluate();
        return _bits.s[1];
    }

    bool Ram8::isDirty()
    {
        return B8::getBit(_bits.b[6], 7);
    }

    void Ram8::evaluate()
    {
#ifdef IMPLEMENT_BLACK_BOX
        Mux8Way16 n;
        DMux8Way  d;

        const bool load  = B8::getBit(_bits.b[7], 0);
        const bool clock = B8::getBit(_bits.b[7], 1);

        d.setIn(load);
        d.setSel(_bits.b[6]);
        n.setSel(_bits.b[6]);


        bool v[8]{d.getA(), d.getB(), d.getC(), d.getD(), d.getE(), d.getF(), d.getG(), d.getH()};

        for (uint8_t i=0; i<8; ++i)
        {
            _r[i].setLoad(v[i]);
            _r[i].setClock(clock);
            _r[i].setIn(_bits.s[0]);
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
        const uint8_t index = _bits.b[6] & 0b00000111;

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
