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
#ifdef IMPLEMENT_BLACK_BOX
#include "Chips/Bit.h"
#endif
#include "Chips/Chip.h"

namespace Hack::Chips
{
    class Register final : public Chip<bit64_t, 64>
    {
    private:
        void evaluate() override;
        bool isDirty() override;

#ifdef IMPLEMENT_BLACK_BOX
        Bit _r[16];
#endif
    public:
        Register();

        void setIn(const uint16_t& v);
        void setLoad(bool write);
        void setClock(bool tick);

        uint16_t getOut();

        void lock(bool v);
    };

}  // namespace Hack::Chips
