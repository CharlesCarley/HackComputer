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
#include "Chips/Memory.h"

namespace Hack::Chips
{
    const uint16_t Memory::MaxAddress    = 0x6000;
    const uint16_t Memory::ScreenAddress = 0x4000;
    const uint16_t Memory::StackAddress  = 0x0100;
    const uint16_t Memory::HeapAddress   = 0x0800;

    Memory::Memory() :
        _in(0),
        _out(0),
        _address(0),
        _ram16(new Ram16k()),
        _screen(new ScreenSegment())
    {
    }

    Memory::~Memory()
    {
        delete _ram16;
        delete _screen;
    }

    Screen* Memory::getScreen() const
    {
        return _screen;
    }

    void Memory::initializeScreen(Screen* screen)
    {
        if (screen)
        {
            delete _screen;
            _screen = screen;
        }
        else
            throw InvalidPointer();
    }

    void Memory::setIn(const uint16_t& v)
    {
        if (_in != v)
        {
            _in = v;
            _bits |= Bit7;
        }
    }

    void Memory::setAddress(const uint16_t& v)
    {
        if (v < MaxAddress)
            _address = v;
    }

    void Memory::setValue(const size_t& index, const uint16_t& v) const
    {
        if (index < MaxAddress)
        {
            if (index < ScreenAddress)
                _ram16->setValue(index, v);
            else
                _screen->setValue(index - ScreenAddress, v);
        }
    }

    void Memory::setLoad(const bool v)
    {
        if (v)
            _bits |= Bit0;
        else
            _bits &= ~Bit0;
        _bits |= Bit7;
    }

    void Memory::setClock(const bool v)
    {
        if (v)
            _bits |= Bit1;
        else
            _bits &= ~Bit1;
        _bits |= Bit7;
    }

    void Memory::lock(const bool v)
    {
        if (v)
            _bits |= Bit6;
        else
            _bits &= ~Bit6;
    }

    uint16_t Memory::getOut()
    {
        if ((_bits & Bit7) != 0 && (_bits & Bit6) == 0)
            evaluate();
        return _out;
    }

    uint16_t Memory::get(const size_t& i) const
    {
        if (i < MaxAddress)
        {
            if (i < ScreenAddress)
                return _ram16->get(i);
            return _screen->get(i - ScreenAddress);
        }
        return 0;
    }

    uint16_t* Memory::pointer(const size_t& address) const
    {
        if (address < ScreenAddress)
            return _ram16->pointer(address);
        return _screen->pointer(address - ScreenAddress);
    }

    void Memory::zero() const
    {
        _ram16->zero();
        _screen->zero();
    }

    bool Memory::isDirty()
    {
        return getBit(7) && !getBit(6);
    }

    void Memory::markDirty()
    {
        setBit(7);
    }

    void Memory::evaluate()
    {
        if (_address < MaxAddress)
        {
            if (_address < ScreenAddress)
            {
                _ram16->setAddress(_address);
                _ram16->setLoad((_bits & Bit0) != 0);
                _ram16->setClock((_bits & Bit1) != 0);
                _ram16->setIn(_in);
                _out = _ram16->getOut();
            }
            else
            {
                _screen->setAddress(_address - ScreenAddress);
                _screen->setLoad((_bits & Bit0) != 0);
                _screen->setClock((_bits & Bit1) != 0);
                _screen->setIn(_in);
                _out = _screen->getOut();
            }

            _bits &= 0b01111100;
        }
        else
            throw IndexOutOfBounds();
    }
} // namespace Hack::Chips
