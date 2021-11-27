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
#pragma once
#include <cstdint>
#include <cstddef>

namespace Hack
{
    class MemoryStream
    {
    private:
        size_t findAllocLen(size_t nr) const;
        size_t write(const void* src, size_t nr, bool pad);

        size_t   _size;
        size_t   _capacity;
        uint8_t* _data;

    public:
        MemoryStream();
        ~MemoryStream();

        void clear(void);

        size_t writeString(const char* src, size_t len);

        size_t write8(uint8_t val);

        size_t write16(uint16_t val);

        size_t write32(uint32_t val);

        size_t write64(uint64_t val);

        size_t fill(size_t nr, uint8_t code);

        void reserve(size_t cap);

        void cloneInto(MemoryStream& dest) const;

        size_t addr(size_t idx) const;

        size_t size(void) const;

        size_t capacity(void) const;

        uint8_t* ptr();

        const uint8_t* ptr() const;
    };

    inline size_t MemoryStream::size() const
    {
        return _size;
    }

    inline size_t MemoryStream::capacity() const
    {
        return _capacity;
    }

    inline uint8_t* MemoryStream::ptr()
    {
        return _data;
    }

    inline const uint8_t* MemoryStream::ptr() const
    {
        return _data;
    }

}  // namespace Hack
