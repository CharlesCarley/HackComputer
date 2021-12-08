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
#include "Utils/String.h"

namespace Hack
{
    class TokenBase
    {
    private:
        size_t _index;
        int8_t _type;

    public:
        TokenBase() : _index(), _type()
        {
            clear();
        }

        TokenBase(const TokenBase& tok) = default;

        ~TokenBase() = default;

        void clear()
        {
            _index = -1;

            // the type here should pivot around zero,
            // negative values are errors, positive values are
            // possible tokens, and 0 indicates null
            _type = 0;
        }

        size_t getIndex() const;

        int8_t getType() const;

        void setType(int8_t type);

        void setIndex(size_t i);
    };

    inline size_t TokenBase::getIndex() const
    {
        return _index;
    }

    inline int8_t TokenBase::getType() const
    {
        return _type;
    }

    inline void TokenBase::setType(const int8_t type)
    {
        _type = type;
    }

    inline void TokenBase::setIndex(const size_t i)
    {
        _index = i;
    }

}  // namespace Hack::ParseInterface
