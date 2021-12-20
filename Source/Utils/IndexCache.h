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
#include <unordered_set>
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

        size_t insert(const T& value)
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

        void at(T& dest, const size_t& index) const
        {
            if (index < _list.size())
                dest = _list.at(index);
            else
                IndexOutOfBounds();
        }

        const T& at(const size_t& index) const
        {
            if (index < _list.size())
                return _list.at(index);

            IndexOutOfBounds();
        }

        bool contains(const size_t& index) const
        {
            return index < _list.size();
        }

        bool contains(const T& value) const
        {
            const typename Table::const_iterator it = _elements.find(value);
            return it != _elements.end();
        }

        size_t get(const T& value) const
        {
            typename Table::const_iterator it = _elements.find(value);
            if (it != _elements.end())
                return it->second;

            NotFound();
        }

        size_t size() const
        {
            return _list.size();
        }

        void clear()
        {
            _list.clear();
            _elements.clear();
        }


        typename Array::const_iterator begin() const
        {
            return _list.begin();
        }

        typename Array::const_iterator end() const
        {
            return _list.end();
        }
    };

    template <typename T>
    class Cache
    {
    public:
        typedef std::unordered_set<T> Table;

    private:
        Table _elements;

    public:
        void save(const T& value)
        {
            const typename Table::iterator it = _elements.find(value);

            if (it == _elements.end())
                _elements.insert(value);
        }

        bool exists(const T& value) const
        {
            const typename Table::iterator it = _elements.find(value);
            return it != _elements.end();
        }
    };

    template <typename Key, typename Value>
    class KeyIndexCache
    {
    public:
        typedef std::unordered_map<Key, size_t> Table;
        typedef std::vector<Value>              Array;

    private:
        Table _elements;
        Array _list;

    public:


        size_t insert(const Key& key, const Value& value)
        {
            size_t idx;

            const typename Table::iterator it = _elements.find(key);

            if (it == _elements.end())
            {
                idx = _elements.size();
                _list.push_back(value);
                _elements.insert(std::make_pair(key, idx));
            }
            else
                idx = it->second;

            return idx;
        }

        void at(Value& dest, const size_t& index) const
        {
            if (index < _list.size())
                dest = _list.at(index);
            else
                IndexOutOfBounds();
        }

        const Value& at(const size_t& index) const
        {
            if (index < _list.size())
                return _list.at(index);
            IndexOutOfBounds();
        }

        bool contains(const size_t& index) const
        {
            if (index < _list.size())
                return true;
            return false;
        }

        bool contains(const Key& value) const
        {
            const typename Table::const_iterator it = _elements.find(value);
            return it != _elements.end();
        }

        size_t find(const Key& value) const
        {
            typename Table::const_iterator it = _elements.find(value);
            if (it != _elements.end())
                return it->second;
            return (size_t)-1;
        }

        size_t size()
        {
            return _list.size();
        }

        void clear()
        {
            _list.clear();
            _elements.clear();
        }

        typename Array::const_iterator begin() const
        {
            return _list.begin();
        }

        typename Array::const_iterator end() const
        {
            return _list.end();
        }
    };

}  // namespace Hack
