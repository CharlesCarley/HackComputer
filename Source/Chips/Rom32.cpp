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
        _size(0),
        _r(nullptr)
    {
        _bits |= Bit7;
        _r = new uint16_t[0x7FFF + 1];
        memset(_r, 0, sizeof(uint16_t) * 0x7FFF + 1);
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
            _bits |= Bit7;

            _in = v;
            if (_in >= 0x7FFF)
                _in = 0;
        }
    }

    void Rom32::lock(const bool v)
    {
        if (v)
            _bits |= Bit6;
        else
            _bits &= ~Bit6;
    }

    uint16_t Rom32::getOut()
    {
        if ((_bits & Bit7) != 0 && (_bits & Bit6) == 0)
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

    void Rom32::load(String& file)
    {
        std::ifstream fp(file);
        String        s;

        for (_size = 0; _size < 0x7FFF + 1; ++_size)
        {
            if (fp >> s)
                _r[_size] = B16::pack(s.c_str());
            else
                break;
        }
    }

    void Rom32::load(const uint16_t* data, size_t size)
    {
        if (data != nullptr)
        {
            // zero any memory that is present
            memset(_r, 0, sizeof(uint16_t) * 0x7FFF);

            // force the supplied size
            // to conform to the max

            _size = std::min<uint16_t>((uint16_t)size, 0x7FFF);

            // copy the new amount
            memcpy(_r, data, _size * sizeof(uint16_t));
        }
    }

}  // namespace Hack::Chips
