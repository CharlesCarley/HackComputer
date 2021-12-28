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
    const uint16_t Memory::StackAddress  = 256;
    const uint16_t Memory::HeapAddress   = 2048;

    Memory::Memory() :
        _in(0),
        _inP(0),
        _address(0),
        _ram16(new Ram16K()),
        _screen(new Screen())
    {
    }

    Memory::~Memory()
    {
        delete _ram16;
        delete _screen;
    }

    void Memory::setIn(const uint16_t& v)
    {
        _in = v;
        markDirty();
    }

    void Memory::setAddress(const uint16_t& v)
    {
        if (v <= MaxAddress)
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
        applyBit(0, v);
        markDirty();
    }

    void Memory::setClock(const bool v)
    {
        applyBit(1, v);
        markDirty();
    }

    void Memory::lock(const bool v)
    {
        applyBit(6, v);
    }

    uint16_t Memory::getOut()
    {
        if (isDirty())
            evaluate();
        return _inP;
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
                _ram16->setLoad(getBit(0));
                _ram16->setClock(getBit(1));
                _ram16->setIn(_in);
                _inP = _ram16->getOut();
            }
            else
            {
                _screen->setAddress(_address - ScreenAddress);
                _screen->setLoad(getBit(0));
                _screen->setClock(getBit(1));
                _screen->setIn(_in);
                _inP = _screen->getOut();
            }

            clearBit(7);
        }
    }
}  // namespace Hack::Chips
