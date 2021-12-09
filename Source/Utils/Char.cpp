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
#ifndef _CRT_SECURE_NO_WARNINGS
#define _CRT_SECURE_NO_WARNINGS 1
#endif
#include "Utils/Char.h"
#include <bitset>
#include <cstdlib>
#include <cstring>
#include <limits>
#include <sstream>
#include "String.h"

namespace Hack
{
    size_t Char::length(const char* in)
    {
        return in && *in ? (size_t)strlen(in) : 0;
    }

    void Char::copy(char* dest, const char* src)
    {
        if (dest && src && *src)
            strcpy(dest, src);
    }

    void Char::copy(char* dest, const char* src, const size_t max)
    {
        if (dest && src && *src)
        {
            size_t len = length(src);

            // restrict it to max
            if (len > max)
                len = max;

            strncpy(dest, src, (size_t)len);

            if (len <= max)
                dest[len] = 0;
        }
    }

    size_t Char::equals(const char* a, const char* b)
    {
        if (!a || !b)
            return 1;
        if (*a != *b)
            return 1;
        return (size_t)strcmp(a, b);
    }

    size_t Char::equals(const char* a, const char* b, const size_t max)
    {
        if (!a || !b)
            return 1;
        if (*a != *b)
            return 1;
        return (size_t)(size_t)strncmp(a, b, (size_t)max);
    }

    int16_t Char::toInt16(const char* in, const int16_t def, const int base)
    {
        if (in && *in)
        {
            const long long v = std::strtoll(in, nullptr, base);
            if (v > std::numeric_limits<int16_t>::max())
                return std::numeric_limits<int16_t>::max();
            if (v < std::numeric_limits<int16_t>::min())
                return std::numeric_limits<int16_t>::min();
            return (int16_t)v;
        }
        return def;
    }

    int32_t Char::toInt32(const char* in, const int32_t def, const int base)
    {
        if (in && *in)
        {
            const long long v = std::strtoll(in, nullptr, base);
            if (v > std::numeric_limits<int32_t>::max())
                return std::numeric_limits<int32_t>::max();
            if (v < std::numeric_limits<int32_t>::min())
                return std::numeric_limits<int32_t>::min();
            return (int32_t)v;
        }
        return def;
    }

    int64_t Char::toInt64(const char* in, const int64_t def, const int base)
    {
        if (in && *in)
            return (int64_t)std::strtoll(in, nullptr, base);
        return def;
    }

    uint16_t Char::toUint16(const char* in, const uint16_t def, const int base)
    {
        if (in && *in)
        {
            const unsigned long long v = std::strtoull(in, nullptr, base);
            if (v > std::numeric_limits<uint16_t>::max())
                return std::numeric_limits<uint16_t>::max();
            return (uint16_t)v;
        }
        return def;
    }

    uint32_t Char::toUint32(const char* in, const uint32_t def, const int base)
    {
        if (in && *in)
        {
            const unsigned long long v = std::strtoull(in, nullptr, base);
            if (v > std::numeric_limits<uint32_t>::max())
                return std::numeric_limits<uint32_t>::max();
            return (uint32_t)v;
        }
        return def;
    }

    uint64_t Char::toUint64(const char* in, const uint64_t def, const int base)
    {
        if (in && *in)
            return (uint64_t)std::strtoull(in, nullptr, base);
        return def;
    }

    int16_t Char::toInt16(const String& in, const int16_t def, const int base)
    {
        return toInt16(in.c_str(), def, base);
    }

    int32_t Char::toInt32(const String& in, const int32_t def, const int base)
    {
        return toInt32(in.c_str(), def, base);
    }

    int64_t Char::toInt64(const String& in, const int64_t def, const int base)
    {
        return toInt64(in.c_str(), def, base);
    }

    uint16_t Char::toUint16(const String&  in,
                            const uint16_t def,
                            const int      base)
    {
        return toUint16(in.c_str(), def, base);
    }

    uint32_t Char::toUint32(const String&  in,
                            const uint32_t def,
                            const int      base)
    {
        return toUint32(in.c_str(), def, base);
    }

    uint64_t Char::toUint64(const String&  in,
                            const uint64_t def,
                            const int      base)
    {
        return toUint64(in.c_str(), def, base);
    }

    bool Char::isNullOrEmpty(const char* in)
    {
        return !in || !*in;
    }

    bool Char::toBool(const char* in)
    {
        if (in)
        {
            switch (*in)
            {
            case 't':
                return strncmp(in, "true", 4) == 0;
            case 'y':
                return strncmp(in, "yes", 3) == 0;
            case '1':
                return strncmp(in, "1", 1) == 0;
            default:
                break;
            }
        }
        return false;
    }

    float Char::toFloat(const char* in, const float& def)
    {
        if (in && *in)
            return std::strtof(in, nullptr);
        return def;
    }

    double Char::toDouble(const char* in, const double& def)
    {
        if (in && *in)
            return std::strtod(in, nullptr);
        return def;
    }

    bool Char::toBool(const String& in)
    {
        return toBool(in.c_str());
    }

    float Char::toFloat(const String& in, const float& def)
    {
        return toFloat(in.c_str(), def);
    }

    double Char::toDouble(const String& in, const double& def)
    {
        return toDouble(in.c_str(), def);
    }

    void Char::toString(String& dest, const float v)
    {
        std::stringstream stream;
        stream << v;
        dest = stream.str();
    }

    void Char::toString(String& dest, const double v)
    {
        std::stringstream stream;
        stream << v;
        dest = stream.str();
    }

    void Char::toString(String& dest, const bool v)
    {
        dest.reserve(2);
        dest.resize(0);
        if (v)
            dest.push_back('1');
        else
            dest.push_back('0');
    }

    void Char::toString(String& dest, const int16_t v)
    {
        std::stringstream stream;
        stream << v;
        dest = stream.str();
    }

    void Char::toString(String& dest, const int32_t v)
    {
        std::stringstream stream;
        stream << v;
        dest = stream.str();
    }

    void Char::toString(String& dest, const int64_t v)
    {
        std::stringstream stream;
        stream << v;
        dest = stream.str();
    }

    void Char::toString(String& dest, const uint16_t v)
    {
        std::stringstream stream;
        stream << v;
        dest = stream.str();
    }

    void Char::toString(String& dest, const uint32_t v)
    {
        std::stringstream stream;
        stream << v;
        dest = stream.str();
    }

    void Char::toString(String& dest, const uint64_t v)
    {
        std::stringstream stream;
        stream << v;
        dest = stream.str();
    }

    void Char::toHexString(String& dest, const uint16_t v)
    {
        std::stringstream stream;
        stream << std::hex << v;
        dest = stream.str();
    }

    void Char::toBinaryString(String& dest, const uint16_t v)
    {
        const std::bitset<16> bs(v);
        dest = bs.to_string();
    }

    String Char::toString(const float v)
    {
        String copyOnReturn;
        toString(copyOnReturn, v);
        return copyOnReturn;
    }

    String Char::toString(const double v)
    {
        String copyOnReturn;
        toString(copyOnReturn, v);
        return copyOnReturn;
    }

    String Char::toString(const bool v)
    {
        String copyOnReturn;
        toString(copyOnReturn, v);
        return copyOnReturn;
    }

    String Char::toString(const int16_t v)
    {
        String copyOnReturn;
        toString(copyOnReturn, v);
        return copyOnReturn;
    }

    String Char::toString(const int32_t v)
    {
        String copyOnReturn;
        toString(copyOnReturn, v);
        return copyOnReturn;
    }

    String Char::toString(const int64_t v)
    {
        String copyOnReturn;
        toString(copyOnReturn, v);
        return copyOnReturn;
    }

    String Char::toString(const uint16_t v)
    {
        String copyOnReturn;
        toString(copyOnReturn, v);
        return copyOnReturn;
    }

    String Char::toHexString(const uint16_t v)
    {
        String copyOnReturn;
        toHexString(copyOnReturn, v);
        return copyOnReturn;
    }

    String Char::toBinaryString(const uint16_t v)
    {
        String copyOnReturn;
        toBinaryString(copyOnReturn, v);
        return copyOnReturn;
    }

    String Char::toString(const uint32_t v)
    {
        String copyOnReturn;
        toString(copyOnReturn, v);
        return copyOnReturn;
    }

    String Char::toString(const uint64_t v)
    {
        String copyOnReturn;
        toString(copyOnReturn, v);
        return copyOnReturn;
    }

}  // namespace Hack
