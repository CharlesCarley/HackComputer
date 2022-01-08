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

namespace Hack::Chips
{
    class Rom32 final : public Chip<uint8_t, 8>
    {
    private:
        void evaluate();
        bool isDirty() override;

        uint16_t  _in, _out, _size;
        uint16_t* _r;

    public:
        Rom32();
        ~Rom32() override;

        void setIn(const uint16_t& v);

        uint16_t getOut();

        uint16_t get(const int& i) const;

        uint16_t size() const;

        void lock(bool v);

        void load(String& file);

        void load(const uint16_t* data, size_t size);
    };

    inline uint16_t Rom32::size() const
    {
        return _size;
    }
} // namespace Hack::Chips
