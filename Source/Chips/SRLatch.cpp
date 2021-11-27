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
#include "Chips/SRLatch.h"

namespace Hack::Chips
{
    constexpr uint8_t SrLatchMask = 0b01101111;

    SRLatch::SRLatch()
    {
        assignBit(7);
        setBit(4);
    }

    void SRLatch::setS(bool v)
    {
        applyBit(0, v);
        setBit(7);
    }

    void SRLatch::setR(bool v)
    {
        applyBit(1, v);
        setBit(7);
    }

    void SRLatch::setQn(bool v)
    {
        setBit(4);
        setBit(7);
    }

    bool SRLatch::getQ()
    {
        if (getBit(7))
            evaluate();
        return getBit(2);
    }

    bool SRLatch::getQPlus()
    {
        if (getBit(7))
            evaluate();
        return getBit(3);
    }

    void SRLatch::evaluate()
    {
        _bits &= SrLatchMask;

        const bool s = getBit(0);
        const bool r = getBit(1);

        const bool na  = Gates::NOr(s, getBit(3));
        const bool nb  = Gates::NOr(getBit(2), r);

        const bool sr  = Gates::And(s, r);
        const bool nsr = Gates::Not(sr);

        applyBit(2, Gates::Mux(Gates::Mux(na, Gates::Not(s), sr), na, nsr));
        applyBit(3, Gates::Mux(Gates::Mux(nb, s, sr), nb, nsr));
    }

}  // namespace Hack::Chips
