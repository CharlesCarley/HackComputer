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
#include "Chips/Rom32.h"
#include <cstring>
#include <fstream>

namespace Hack::Chips
{
    Rom32::Rom32() :
        _in(0),
        _out(0),
        _r(nullptr)
    {
        setBit(7);
        _r = new uint16_t[0xFFFF];

        memset(_r, 0, 0xFFFF);
    }

    Rom32::~Rom32()
    {
        delete _r;
        _r = nullptr;
    }

    void Rom32::setIn(const uint16_t& v)
    {
        if (_in != v)
        {
            setBit(7);
            _in = v;
            if (_in >= 0x7FFF)
                _in = 0;
        }
    }

    void Rom32::lock(const bool v)
    {
        applyBit(6, v);
    }

    uint16_t Rom32::getOut()
    {
        if (isDirty())
            evaluate();
        return _out;
    }

    uint16_t Rom32::get(const int& i) const
    {
        if (i < 0 || i > 0x7FFF)
            return 0;
        return _r[i];
    }

    bool Rom32::isDirty()
    {
        return getBit(7) && !getBit(6);
    }

    void Rom32::evaluate()
    {
        if (_in < 0x7FFF)
            _out = _r[_in];
    }

    void Rom32::load(String& file) const
    {
        std::ifstream fp(file);
        String        s;

        for (uint16_t i = 0; i < 0x7FFF + 1; ++i)
        {
            if (fp >> s)
                _r[i] = B16::pack(s.c_str());
            else
                break;
        }
    }

    void Rom32::load(const uint16_t* data, size_t size) const
    {
        if (data!= nullptr)
        {
            // zero any memory that is present
            memset(_r, 0, 0xFFFF);

            // force the supplied size
            // to conform to the max
            size = std::min<size_t>(size, 0x7FFF);

            // copy the new amount
            memcpy(_r, data, size * sizeof(uint16_t));
        }
    }

}  // namespace Hack::Chips