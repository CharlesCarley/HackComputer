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
#include "Utils/IndexCache.h"
#include "Utils/ParserBase/TokenBase.h"

namespace Hack
{
    using StringTable = IndexCache<String>;

    class ScannerBase
    {
    protected:
        IStream*    _stream;
        StringTable _stringTable;
        String      _file;
        size_t      _line;

        size_t saveString(const String& str)
        {
            return _stringTable.save(str);
        }

        [[noreturn]] void syntaxErrorThrow(const String& message) const;

        template <typename... Args>
        [[noreturn]] void syntaxError(const String& what, Args&&... args)
        {
            OutputStringStream oss;
            oss << what;
            ((oss << std::forward<Args>(args)), ...);
            syntaxErrorThrow(oss.str());
        }

    public:
        ScannerBase() :
            _stream(nullptr),
            _line(0)
        {
        }

        virtual ~ScannerBase() = default;

        virtual void attach(IStream* stream, const String& file)
        {
            _stream = stream;
            _file   = file;
            _line   = 1;
        }

        virtual void scan(TokenBase& tok) = 0;

        const String& getString(const size_t& i) const;

        void getString(String& dest, const size_t& i) const;

        size_t  getLine() const;
    };

    inline size_t ScannerBase::getLine() const
    {
        return _line;
    }

}  // namespace Hack
