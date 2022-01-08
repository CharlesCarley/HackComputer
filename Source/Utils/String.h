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

#include <sstream>
#include <string>
#include <vector>

namespace Hack
{
    using String = std::string;
    using StringArray = std::vector<std::string>;
    using StringStream = std::stringstream;
    using InputStringStream = std::istringstream;
    using OutputStringStream = std::ostringstream;
    using IStream = std::istream;
    using OStream = std::ostream;

    class StringUtils
    {
    public:
        static void split(StringArray& dest, const String& str, char sep);

        static void split(StringArray& dest, const String& str, const String& sep);

        static void scramble(String& dest, size_t value);

        static void generate(String& dest, int& counter, void* seed);

        static void trimWhiteSpace(String& dest, const String& in);

        static void trim(String& dest, const String& in, char ch);

        static void trimL(String& dest, const String& in, char ch);

        static void trimR(String& dest, const String& in, char ch);

        static void splitLine(StringArray& dest, const String& input, char swap = '$');

        static void replaceAll(String& dest, const String& input, const String& a, const String& b);
    };

    template <typename... Args>
    void StreamMerge(OutputStringStream& dest, Args&&...args)
    {
        OutputStringStream oss;
        ((oss << std::forward<Args>(args)), ...);
        dest << oss.str() << std::endl;
    }

    template <typename... Args>
    void StringCombine(String& dest, Args&&...args)
    {
        OutputStringStream oss;
        ((oss << std::forward<Args>(args)), ...);
        dest = oss.str();
    }

    template <typename... Args>
    String StringCombine(Args&&...args)
    {
        OutputStringStream oss;
        ((oss << std::forward<Args>(args)), ...);
        return oss.str();
    }
} // namespace Hack
