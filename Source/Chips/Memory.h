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
#include "Chips/Ram16k.h"
#include "Chips/Screen.h"
#include "VirtualMachine/Constants.h"

namespace Hack::Chips
{
    class Memory final : public Chip<uint8_t, 8>
    {
    public:
        static const int MaxAddress;
        static const int ScreenAddress;

    private:
        void evaluate() override;
        bool isDirty() override;
        void markDirty();

        uint16_t _in;
        uint16_t _inP;
        uint16_t _address;

        Ram16K* _ram16;
        Screen* _screen;

    public:
        Memory();
        ~Memory() override;

        void setIn(const uint16_t& v);

        void setAddress(const uint16_t& v);

        void setValue(const int& index, const uint16_t& v) const;

        void setLoad(bool v);

        void setClock(bool v);

        void lock(bool v);

        uint16_t getOut();

        uint16_t get(const int& i) const;

        uint16_t* pointer(const int& address) const;

        void zero() const;
    };

}  // namespace Hack::Chips
