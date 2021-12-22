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
    using IntTable    = IndexCache<int>;

    class ScannerBase
    {
    protected:
        IStream*    _stream;
        StringTable _stringTable;
        IntTable    _intTable;
        String      _file;
        size_t      _line;

        size_t save(const String& str)
        {
            return _stringTable.insert(str);
        }

        size_t save(const int& val)
        {
            return _intTable.insert(val);
        }

        template <typename... Args>
        [[noreturn]] void syntaxError(const String& what, Args&&... args)
        {
            OutputStringStream oss;
            oss << what;
            ((oss << std::forward<Args>(args)), ...);
            syntaxErrorThrow(oss.str());
        }

        void scanWhiteSpace() const;

        void scanLineComment();

        void scanMultiLineComment();

    private:
        [[noreturn]] void syntaxErrorThrow(const String& message) const;

    public:
        ScannerBase();

        virtual ~ScannerBase() = default;

        virtual void scan(TokenBase& tok) = 0;

        void attach(IStream* stream, const String& file);

        const String& getString(const size_t& i) const;

        void getString(String& dest, const size_t& i) const;

        int getInt(const size_t& i) const;

        size_t getLine() const;

        bool hasString(size_t id) const;
    };

    inline size_t ScannerBase::getLine() const
    {
        return _line;
    }

// clang-format off
    #define LowerCaseAz                                                   \
    'a' : case 'b' : case 'c' : case 'd' : case 'e' : case 'f' : case 'g' \
        : case 'h' : case 'i' : case 'j' : case 'k' : case 'l' : case 'm' \
        : case 'n' : case 'o' : case 'p' : case 'q' : case 'r' : case 's' \
        : case 't' : case 'u' : case 'v' : case 'w' : case 'x' : case 'y' \
        : case 'z'

    #define UpperCaseAz                                                   \
    'A' : case 'B' : case 'C' : case 'D' : case 'E' : case 'F' : case 'G' \
        : case 'H' : case 'I' : case 'J' : case 'K' : case 'L' : case 'M' \
        : case 'N' : case 'O' : case 'P' : case 'Q' : case 'R' : case 'S' \
        : case 'T' : case 'U' : case 'V' : case 'W' : case 'X' : case 'Y' \
        : case 'Z'

    #define Digits09                                                      \
    '0' : case '1' : case '2' : case '3' : case '4' : case '5' : case '6' \
        : case '7' : case '8' : case '9'

    // clang-format on

}  // namespace Hack
