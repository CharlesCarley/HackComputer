/*
-------------------------------------------------------------------------------
    Copyright (c) 2020 Charles Carley.

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
#include "MemoryStream.h"
#include <memory.h>
#include <cstring>

namespace Hack
{
    MemoryStream::MemoryStream() :
        _size(0),
        _capacity(0),
        _data(nullptr)
    {
    }

    MemoryStream::~MemoryStream()
    {
        clear();
    }

    void MemoryStream::clear(void)
    {
        if (_data)
        {
            delete[] _data;
            _data = nullptr;
        }
        _size     = 0;
        _capacity = 0;
    }

    void MemoryStream::reserve(size_t nr)
    {
        if (_capacity < nr)
        {
            uint8_t* buf = new uint8_t[nr + 1];
            if (_data != nullptr)
            {
                memcpy(buf, _data, _size);
                delete[] _data;
            }
            _data     = buf;
            _capacity = nr;
        }
    }

    void MemoryStream::cloneInto(MemoryStream& dest) const
    {
        dest.clear();
        dest.reserve(_capacity);

        if (_data)
        {
            memcpy(dest.ptr(), _data, _capacity);
            dest._size = _capacity;
        }
    }

    size_t MemoryStream::addr(size_t idx) const
    {
        if (idx < _capacity)
            return (size_t)&_data[idx];
        return -1;
    }

    size_t MemoryStream::write(const void* src, size_t nr, const bool pad)
    {
        size_t al;
        if (pad)
            al = findAllocLen(nr + 1);
        else
            al = findAllocLen(nr);

        if (al > 0)
            reserve(al);

        uint8_t* ptr = &_data[_size];
        memcpy(ptr, src, nr);
        _size += nr;

        if (pad)
        {
            _data[_size] = 0;
            ++nr;
            ++_size;
        }
        return nr;
    }

    size_t MemoryStream::findAllocLen(size_t nr) const
    {
        if (_size + nr > _capacity)
        {
            const size_t size = _size + nr;
            size_t       over = size - _capacity;
            const size_t r16  = over % 16;
            if (r16 > 0)
                over += 16 - r16;

            over += _capacity;
            over += 256;
            return over;
        }
        return 0;
    }

    size_t MemoryStream::writeString(const char* src, const size_t len)
    {
        return write(src, len, true);
    }

    size_t MemoryStream::write8(uint8_t val)
    {
        return write(&val, 1, false);
    }

    size_t MemoryStream::write16(uint16_t val)
    {
        return write(&val, 2, false);
    }

    size_t MemoryStream::write32(uint32_t val)
    {
        return write(&val, 4, false);
    }

    size_t MemoryStream::write64(uint64_t val)
    {
        return write(&val, 8, false);
    }

    size_t MemoryStream::fill(const size_t nr, const uint8_t code)
    {
        const size_t al = findAllocLen(nr);
        if (al > 0)
            reserve(al);

        uint8_t* ptr = &_data[_size];
        memset(ptr, code, nr);
        _size += nr;
        return nr;
    }

}  // namespace Hack
