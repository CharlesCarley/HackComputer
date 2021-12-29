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
#include <cstring>


namespace Hack::Chips
{
    template <uint16_t High, uint16_t ElementCount>
    class IMemorySegment : public Chip<uint8_t, 8>
    {
    public:
        static const uint16_t HighAddress = High;
        static const uint16_t WriteAddress= High+1;
        static const uint16_t Max         = (High << 1) + 1;

    protected:
        uint16_t _in;
        uint16_t _out;
        uint16_t _address;

    public:
        IMemorySegment();

        void setIn(const uint16_t& value);

        void setAddress(const uint16_t& value);

        void setLoad(bool load);

        void setClock(bool clock);

        void lock(bool lockIt);

        uint16_t getOut();

        virtual uint16_t get(const size_t& i) const = 0;

        virtual uint16_t* pointer(const size_t& address) const = 0;

        virtual void setValue(const size_t& address, const uint16_t& v) const = 0;

        virtual void zero() const = 0;

        virtual void lockScreen();

        virtual void sync(){}

        virtual void unlockScreen();

    protected:
        bool isDirty() override;

        void markDirty();
    };

    template <uint16_t High, uint16_t ElementCount>
    IMemorySegment<High, ElementCount>::IMemorySegment() :
        _in(0), _out(0), _address(0)
    {
        markDirty();
    }

    template <uint16_t High, uint16_t ElementCount>
    void IMemorySegment<High, ElementCount>::setIn(const uint16_t& value)
    {
        _in = value;
        markDirty();
    }

    template <uint16_t High, uint16_t ElementCount>
    void IMemorySegment<High, ElementCount>::setAddress(const uint16_t& value)
    {
#ifdef CHECK_INT_BOUNDS
        if (value >= High)
            throw IndexOutOfBounds();
#endif
        if (value < High)
            _address = value;
    }

    template <uint16_t High, uint16_t ElementCount>
    void IMemorySegment<High, ElementCount>::setLoad(const bool load)
    {
        applyBit(0, load);
        markDirty();
    }

    template <uint16_t High, uint16_t ElementCount>
    void IMemorySegment<High, ElementCount>::setClock(const bool clock)
    {
        applyBit(1, clock);
        markDirty();
    }

    template <uint16_t High, uint16_t ElementCount>
    void IMemorySegment<High, ElementCount>::lock(const bool lockIt)
    {
        applyBit(6, lockIt);
    }

    template <uint16_t High, uint16_t ElementCount>
    uint16_t IMemorySegment<High, ElementCount>::getOut()
    {
        if ((_bits & Bit7) != 0 && (_bits & Bit6) == 0)
            evaluate();
        return _out;
    }

    template <uint16_t High, uint16_t ElementCount>
    void IMemorySegment<High, ElementCount>::lockScreen()
    {
    }

    template <uint16_t High, uint16_t ElementCount>
    void IMemorySegment<High, ElementCount>::unlockScreen()
    {
    }

    template <uint16_t High, uint16_t ElementCount>
    bool IMemorySegment<High, ElementCount>::isDirty()
    {
        return getBit(7) && !getBit(6);
    }

    template <uint16_t High, uint16_t ElementCount>
    void IMemorySegment<High, ElementCount>::markDirty()
    {
        setBit(7);
    }
}  // namespace Hack::Chips
