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
#include "Chips/IMemorySegment.h"

namespace Hack::Chips
{
    template <uint16_t High, uint16_t ElementCount>
    class DefaultMemorySegment final : public IMemorySegment<High, ElementCount>
    {
    public:
        typedef IMemorySegment<High, ElementCount> BaseType;

    private:
        uint16_t* _ram;

    public:
        DefaultMemorySegment();

        ~DefaultMemorySegment() override;

        uint16_t get(const size_t& index) const override;

        uint16_t* pointer(const size_t& address) const override;

        void setValue(const size_t& address, const uint16_t& value) const override;

        void zero() const override;

        uint16_t getOut() override;

    protected:
        void evaluate();
    };

    template <uint16_t High, uint16_t ElementCount>
    DefaultMemorySegment<High, ElementCount>::DefaultMemorySegment() :
        _ram(new uint16_t[BaseType::Max + 1])
    {
        zero();
    }

    template <uint16_t High, uint16_t ElementCount>
    DefaultMemorySegment<High, ElementCount>::~DefaultMemorySegment()
    {
        delete[] _ram;
    }

    template <uint16_t High, uint16_t ElementCount>
    uint16_t DefaultMemorySegment<High, ElementCount>::get(const size_t& index) const
    {
        if (index < High)
            return _ram[index];
#ifdef CHECK_INT_BOUNDS
        throw IndexOutOfBounds();
#else
        return 0;
#endif
    }

    template <uint16_t High, uint16_t ElementCount>
    uint16_t* DefaultMemorySegment<High, ElementCount>::pointer(const size_t& address) const
    {
        if (address < High)
            return &_ram[address];
        return nullptr;
    }

    template <uint16_t High, uint16_t ElementCount>
    void DefaultMemorySegment<High, ElementCount>::setValue(const size_t&   address,
                                                            const uint16_t& value) const
    {
        if (address < High)
            _ram[address] = _ram[address + High] = value;
    }

    template <uint16_t High, uint16_t ElementCount>
    void DefaultMemorySegment<High, ElementCount>::zero() const
    {
        memset(_ram, 0, sizeof(uint16_t) * BaseType::Max);
    }

    template <uint16_t High, uint16_t ElementCount>
    void DefaultMemorySegment<High, ElementCount>::evaluate()
    {
        const uint16_t loBit = this->_address;
        if (loBit >= High)
            return;

        if (this->_bits & Bit0)
        {
            const uint16_t hiBit = loBit + High;

            if (hiBit < BaseType::Max)
            {
                if (this->_bits & Bit1)
                    _ram[loBit] = _ram[hiBit] = this->_in;
                else
                {
                    _ram[loBit] = _ram[hiBit];
                    _ram[hiBit] = this->_in;
                }
            }
            else
            {
                throw InputException("ram index (",
                                     hiBit,
                                     ") out of bounds [0, ",
                                     hiBit,
                                     ']');
            }
        }

        this->_out = _ram[loBit];
        this->_bits &= 0b01111100;
    }

    template <uint16_t High, uint16_t ElementCount>
    uint16_t DefaultMemorySegment<High, ElementCount>::getOut()
    {
        if ((this->_bits & Bit7) != 0 && !(this->_bits & Bit6))
            evaluate();
        return this->_out;
    }
} // namespace Hack::Chips
