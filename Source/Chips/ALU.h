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
#pragma once
#include "Chips/Chip.h"

namespace Hack::Chips
{
    enum AluFlags
    {
        No = 1 << 0,
        Fn = 1 << 1,
        Ny = 1 << 2,
        Zy = 1 << 3,
        Nx = 1 << 4,
        Zx = 1 << 5,
        Ne = 1 << 6,
        Zr = 1 << 7,
    };

    enum Control
    {
        XAndY = 0,
        Zero = Zx | Zy | Fn,
        One = Zx | Nx | Zy | Ny | Fn | No,
        NegativeOne = Zx | Nx | Zy | Fn,
        OutX = Zy | Ny,
        OutY = Zx | Nx,
        NotX = Zy | Ny | No,
        NotY = Zx | Nx | No,
        NegativeX = Zy | Ny | No | Fn,
        NegativeY = Zx | Nx | No | Fn,
        XPlusOne = Nx | Zy | Ny | Fn | No,
        YPlusOne = Zx | Nx | Ny | Fn | No,
        XMinusOne = Zy | Ny | Fn,
        YMinusOne = Zx | Nx | Fn,
        XPlusY = Fn,
        XMinusY = Nx | Fn | No,
        YMinusX = Ny | Fn | No,
        XOrY = Nx | Ny | No,
    };

    class Alu final : public Chip<uint8_t, 8>
    {
    private:
        void evaluate();

        bit64_t _io;

    public:
        Alu();

        void setFlags(const uint8_t& flags);

        uint8_t getFlags();

        void setX(const uint16_t& x);

        void setY(const uint16_t& y);

        uint16_t getOut();

        bool getZr();

        bool getNe();
    };
} // namespace Hack::Chips
