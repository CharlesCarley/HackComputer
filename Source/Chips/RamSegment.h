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
#include <cstring>
#include "Chips/Chip.h"

namespace Hack::Chips
{
    template <uint16_t High, uint16_t MaxElements>
    class RamSegment : public Chip<uint8_t, 8>
    {
    public:
        static const uint16_t Max         = (High << 1)+1;
        static const uint16_t HighAddress = High;

    private:
        uint16_t  _in;
        uint16_t  _outP;
        uint16_t  _address;
        uint16_t* _ram;

    public:
        RamSegment() :
            _in(0),
            _outP(0),
            _address(0),
            _ram(nullptr)
        {
            _ram = new uint16_t[Max + 1];
            memset(_ram, 0, sizeof(uint16_t) * (Max + 1));
            markDirty();
        }

        ~RamSegment() override
        {
            delete[] _ram;
        }

        void setIn(const uint16_t& v)
        {
            _in = v;
            markDirty();
        }

        void setAddress(const uint16_t& v)
        {
#ifdef CHECK_INT_BOUNDS
            if (v >= High)
                throw IndexOutOfBounds();
#endif
            if (v < High)
                _address = v;
        }

        void setLoad(const bool v)
        {
            applyBit(0, v);
            markDirty();
        }

        void setClock(const bool v)
        {
            applyBit(1, v);
            markDirty();
        }

        void lock(const bool v)
        {
            applyBit(6, v);
        }

        uint16_t getOut()
        {
            if (isDirty())
                evaluate();
            return _outP;
        }

        uint16_t get(const size_t& i) const
        {
            if (i < High)
                return _ram[i];

#ifdef CHECK_INT_BOUNDS
            throw IndexOutOfBounds();
#else
            return 0;
#endif
        }

        uint16_t* pointer(const size_t& address) const
        {
            if (address < High)
                return &_ram[address];
            return nullptr;
        }

        void setValue(const size_t& address, const uint16_t v) const
        {
            if (address < High)
                _ram[address] = _ram[address + High] = v;
        }

        void zero() const
        {
            memset(_ram, 0, sizeof(uint16_t) * (MaxElements + 1));
        }

    protected:

        bool isDirty() override
        {
            return getBit(7) && !getBit(6);
        }

        void markDirty()
        {
            setBit(7);
        }

        void evaluate() override
        {
            if (_address < High)
            {
                if (getBit(0))
                {
                    const uint16_t hiBit = _address + High;
                    if (hiBit < Max)
                    {
                        if (getBit(1))
                            _ram[_address] = _ram[hiBit] = _in;
                        else
                        {
                            _ram[_address] = _ram[hiBit];
                            _ram[hiBit]    = _in;
                        }
                    }
                    else
                        throw InputException("Array index (", hiBit, ") out of bounds ", '[', _address, ',', hiBit,']');
                }
                _outP = _ram[_address];
                clearBit(7);
            }
        }
    };

}  // namespace Hack::Chips
