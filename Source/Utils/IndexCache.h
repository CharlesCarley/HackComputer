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
#include <unordered_map>
#include "Exceptions/Exception.h"

namespace Hack
{
    template <typename T>
    class IndexCache
    {
    public:
        typedef std::unordered_map<T, size_t> Table;
        typedef std::vector<T>                Array;

    private:
        Table _elements;
        Array _list;

    public:
        size_t save(const T& value)
        {
            size_t idx;

            const typename Table::iterator it = _elements.find(value);

            if (it == _elements.end())
            {
                idx = _elements.size();
                _list.push_back(value);
                _elements.insert(std::make_pair(value, idx));
            }
            else
                idx = it->second;
            return idx;
        }

        void get(T& dest, const size_t& index) const
        {
            if (index < _list.size())
                dest = _list.at(index);
        }

        const T& get(const size_t& index) const
        {
            if (index < _list.size())
                return _list.at(index);
            throw Exception("Index out of bounds");
        }

        size_t size()
        {
            return _list.size();
        }
    };

}  // namespace Hack
