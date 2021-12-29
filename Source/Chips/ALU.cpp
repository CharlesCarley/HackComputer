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
#include "Chips/ALU.h"
#include "Chips/BitUtils.h"
#include "Chips/Chip.h"
#include "Utils/Char.h"

#ifdef IMPLEMENT_BLACK_BOX
#include "Chips/Add16.h"
#include "Chips/And16.h"
#include "Chips/Mux16.h"
#include "Chips/Not.h"
#include "Chips/Not16.h"
#include "Chips/Or.h"
#include "Chips/Or8Way.h"
#endif


#define InsertCheckFlags       \
    if (_io.s[2] == 0)         \
        _io.b[7] = Zr;         \
    else if (_io.s[2] & Bit15) \
        _io.b[7] = Ne;         \
    else                       \
        _io.b[7] = 0

namespace Hack::Chips
{
    Alu::Alu() :
        _io{}
    {
        _io.b[7] = Bit0;
    }

    void Alu::setFlags(const uint8_t& flags)
    {
        const uint8_t ctrl = flags & 0b00111111;

        if (_io.b[6] != ctrl)
        {
            _io.b[6] = ctrl;
            _io.b[7] |= Bit0;
        }
    }

    uint8_t Alu::getFlags()
    {
        if (_io.b[7] & Bit0)
            evaluate();
        return _io.b[7];
    }

    void Alu::setX(const uint16_t& v)
    {
        if (_io.s[0] != v)
        {
            _io.s[0] = v;
            _io.b[7] |= Bit0;
        }
    }

    void Alu::setY(const uint16_t& v)
    {
        if (_io.s[1] != v)
        {
            _io.s[1] = v;
            _io.b[7] |= Bit0;
        }
    }

    bool Alu::getZr()
    {
        if (_io.b[7] & Bit0)
            evaluate();
        return (_io.b[7] & Zr) != 0;
    }

    bool Alu::getNe()
    {
        if (_io.b[7] & Bit0)
            evaluate();
        return (_io.b[7] & Ne) != 0;
    }

    uint16_t Alu::getOut()
    {
        if (_io.b[7] & Bit0)
            evaluate();
        return _io.s[2];
    }

    void Alu::evaluate()
    {
#ifdef IMPLEMENT_BLACK_BOX

        Mux16 mxA0, mxA1;
        Not16 mxAn;

        Mux16 mxB0, mxB1;
        Not16 mxBn;

        And16 xyAnd;
        Add16 xpy;
        Mux16 axy;
        Not16 axyN;
        Mux16 out;

        mxA0.setA(_io.s[0]);
        mxA0.setB((uint16_t)0b0000000000000000);
        mxA0.setSel(_io.b[6] & Zx);

        mxAn.setIn(mxA0.getOut());
        mxA1.setA(mxA0.getOut());
        mxA1.setB(mxAn.getOut());
        mxA1.setSel(_io.b[6] & Nx);

        mxB0.setA(_io.s[1]);
        mxB0.setB((uint16_t)0b0000000000000000);
        mxB0.setSel(_io.b[6] & Zy);

        mxBn.setIn(mxB0.getOut());
        mxB1.setA(mxB0.getOut());
        mxB1.setB(mxBn.getOut());
        mxB1.setSel(_io.b[6] & Ny);

        xyAnd.setA(mxA1.getOut());
        xyAnd.setB(mxB1.getOut());

        xpy.setA(mxA1.getOut());
        xpy.setB(mxB1.getOut());

        axy.setA(xyAnd.getOut());
        axy.setB(xpy.getOut());
        axy.setSel(_io.b[6] & Fn);

        axyN.setIn(axy.getOut());

        out.setA(axy.getOut());
        out.setB(axyN.getOut());
        out.setSel(_io.b[6] & No);

        _io.b[7] &= ~Bit0;
        _io.s[2] = out.getOut();

        bit16_t b16;
        b16.s = _io.s[2];

        Or8Way orh, orl;
        orh.setIn(b16.b[1]);
        orl.setIn(b16.b[0]);

        Or isZero;
        isZero.setA(orh.getOut());
        isZero.setB(orl.getOut());

        Not zr;
        zr.setIn(isZero.getOut());

        if (zr.getOut())
            _io.b[7] = Zr;
        else if (_io.s[2] & 1 << 15)
            _io.b[7] = Ne;
        else
            _io.b[7] = 0;
#else
        switch (_io.b[6])
        {
        case Zero:
            _io.s[2] = 0;
            _io.b[7] = Zr;
            break;
        case One:
            _io.s[2] = 1;
            _io.b[7] = 0;
            break;
        case XAndY:
            _io.s[2] = _io.s[0] & _io.s[1];
            InsertCheckFlags;
            break;
        case NegativeOne:
            _io.s[2] = 0xFFFF;
            _io.b[7] = Ne;
            break;
        case OutX:
            _io.s[2] = _io.s[0];
            InsertCheckFlags;
            break;
        case OutY:
            _io.s[2] = _io.s[1];
            InsertCheckFlags;
            break;
        case NotX:
            _io.s[2] = ~_io.s[0];
            InsertCheckFlags;
            break;
        case NotY:
            _io.s[2] = ~_io.s[1];
            InsertCheckFlags;
            break;
        case NegativeX:
            _io.s[2] = -_io.s[0];
            InsertCheckFlags;
            break;
        case NegativeY:
            _io.s[2] = -_io.s[1];
            InsertCheckFlags;
            break;
        case XPlusOne:
            _io.s[2] = _io.s[0] + 1;
            InsertCheckFlags;
            break;
        case YPlusOne:
            _io.s[2] = _io.s[1] + 1;
            InsertCheckFlags;
            break;
        case XMinusOne:
            _io.s[2] = _io.s[0] - 1;
            InsertCheckFlags;
            break;
        case YMinusOne:
            _io.s[2] = _io.s[1] - 1;
            InsertCheckFlags;
            break;
        case XPlusY:
            _io.s[2] = _io.s[0] + _io.s[1];
            InsertCheckFlags;
            break;
        case XMinusY:
            _io.s[2] = _io.s[0] - _io.s[1];
            InsertCheckFlags;
            break;
        case YMinusX:
            _io.s[2] = _io.s[1] - _io.s[0];
            InsertCheckFlags;
            break;
        case XOrY:
            _io.s[2] = _io.s[0] | _io.s[1];
            InsertCheckFlags;
            break;
        default:
            throw InputException("AluFunction ",
                                 Char::toBinaryString(_io.b[6]),
                                 " not found");
        }

#endif
    }

}  // namespace Hack::Chips
