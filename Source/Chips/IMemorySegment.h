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
    template <uint16_t High, uint16_t ElementCount>
    class IMemorySegment : public Chip<uint8_t, 8>
    {
    public:
        static const uint16_t HighAddress = High;
        static const uint16_t Max         = (High << 1) + 1;

    protected:
        uint16_t _in;
        uint16_t _out;
        uint16_t _address;

    public:
        IMemorySegment();

        void setIn(const uint16_t& input);

        void setAddress(const uint16_t& address);

        void setLoad(bool load);

        void setClock(bool clock);

        void lock(bool state);

        virtual uint16_t getOut() = 0;

        virtual uint16_t get(const size_t& index) const = 0;

        virtual uint16_t* pointer(const size_t& address) const = 0;

        virtual void setValue(const size_t& address, const uint16_t& value) const = 0;

        virtual void zero() const = 0;

        virtual void lockScreen();

        virtual void sync()
        {
        }

        virtual void unlockScreen();

    protected:
        bool isDirty() override;

        void markDirty();
    };

    template <uint16_t High, uint16_t ElementCount>
    IMemorySegment<High, ElementCount>::IMemorySegment() :
        _in(0),
        _out(0),
        _address(0)
    {
        _bits = Bit7;
    }

    template <uint16_t High, uint16_t ElementCount>
    void IMemorySegment<High, ElementCount>::setIn(const uint16_t& input)
    {
        _in = input;
        _bits |= Bit7;
    }

    template <uint16_t High, uint16_t ElementCount>
    void IMemorySegment<High, ElementCount>::setAddress(const uint16_t& address)
    {
#ifdef CHECK_INT_BOUNDS
        if (address >= High)
            throw IndexOutOfBounds();
#endif
        if (address < High)
            _address = address;
    }

    template <uint16_t High, uint16_t ElementCount>
    void IMemorySegment<High, ElementCount>::setLoad(const bool load)
    {
        if (load)
            _bits |= Bit0;
        else
            _bits &= ~Bit0;
        _bits |= Bit7;
    }

    template <uint16_t High, uint16_t ElementCount>
    void IMemorySegment<High, ElementCount>::setClock(const bool clock)
    {
        if (clock)
            _bits |= Bit1;
        else
            _bits &= ~Bit1;
        _bits |= Bit7;
    }

    template <uint16_t High, uint16_t ElementCount>
    void IMemorySegment<High, ElementCount>::lock(const bool state)
    {
        if (state)
            _bits |= Bit6;
        else
            _bits &= ~Bit6;
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
        return (_bits & Bit7) != 0 && (_bits & Bit6) == 0;
    }

    template <uint16_t High, uint16_t ElementCount>
    void IMemorySegment<High, ElementCount>::markDirty()
    {
        _bits |= Bit7;
    }
} // namespace Hack::Chips
