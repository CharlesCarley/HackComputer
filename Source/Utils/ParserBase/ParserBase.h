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
#include <vector>
#include "Utils/ParserBase/TokenBase.h"

namespace Hack
{
    class ScannerBase;

    class ParserBase
    {
    public:
        typedef std::vector<TokenBase> Tokens;

    protected:
        Tokens       _tokens;
        int32_t      _cursor;
        ScannerBase* _scanner;
        String       _file;
        String       _filePath;

        virtual void parseImpl(IStream& is) = 0;

        virtual void writeImpl(OStream& is) = 0;

        TokenBase getToken(int32_t offs);

        void advanceCursor(int32_t n = 1);

        void readToken(int32_t n = 1);

        template <typename... Args>
        [[noreturn]] void parseError(const String& what, Args&&... args)
        {
            OutputStringStream oss;
            oss << what;
            ((oss << std::forward<Args>(args)), ...);
            parseErrorThrow(oss.str());
        }

    private:
        [[noreturn]] void parseErrorThrow(const String& message) const;

    public:
        ParserBase();
        virtual ~ParserBase();

        void parse(const String& file);

        void parse(IStream& is);

        void write(const String& file);

        void write(OStream& os);
    };

}  // namespace Hack
