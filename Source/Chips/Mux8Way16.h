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
    class Mux8Way16 final : public Chip<uint8_t, 8>
    {
    private:
        void evaluate();

        bit64_t  _in[2];
        uint16_t _out;

    public:
        Mux8Way16();

        void setA(const uint16_t& a);

        void setB(const uint16_t& b);

        void setC(const uint16_t& c);

        void setD(const uint16_t& d);

        void setE(const uint16_t& e);

        void setF(const uint16_t& f);

        void setG(const uint16_t& g);

        void setH(const uint16_t& h);

        void setSel(const uint8_t& selection);

        uint16_t getOut();
    };
} // namespace Hack::Chips
