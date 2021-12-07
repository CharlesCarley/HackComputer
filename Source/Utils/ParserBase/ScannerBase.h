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
#include <istream>
#include <unordered_map>
#include "Utils/IndexCache.h"
#include "Utils/ParserBase/TokenBase.h"

namespace Hack::ParserBase
{
    using StringTable = IndexCache<String>;
    using IntTable    = IndexCache<int32_t>;

    class ScannerBase
    {
    protected:
        IStream*    _stream;
        StringTable _stringTable;
        IntTable    _intTable;

        size_t saveString(const String& str)
        {
            return _stringTable.save(str);
        }

        size_t saveInt(const int32_t& value)
        {
            return _intTable.save(value);
        }

    public:
        ScannerBase() : _stream(nullptr)
        {
        }

        virtual ~ScannerBase() = default;

        virtual void attach(IStream* stream)
        {
            _stream = stream;
        }

        virtual void scan(Token& tok) = 0;


        const String& getString(const size_t& i) const;

        void getString(String& dest, const size_t& i) const;

        void getInt(int32_t& dest, const size_t& i) const;

        int32_t getInt(const size_t& i) const;

    };

}  // namespace Hack::ParserBase
