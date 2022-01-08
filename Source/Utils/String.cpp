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
#include "Utils/String.h"
#include <chrono>
#include "Utils/Char.h"

#define NOW std::chrono::high_resolution_clock::now().time_since_epoch().count()

namespace Hack
{
    void StringUtils::replaceAll(String&       dest,
                                 const String& input,
                                 const String& a,
                                 const String& b)
    {
        if (a.empty())
        {
            dest = input;
            return;
        }

        OutputStringStream oss;
        for (size_t i = 0; i < input.size(); ++i)
        {
            const char ch = input[i];
            if (ch != a[0])
                oss << ch;
            else
            {
                bool match = true;
                for (size_t j = 1; j < a.size() && match; ++j)
                {
                    if (i + j > input.size())
                        match = false;
                    else
                    {
                        const char aCh = input[i + j];
                        const char bCh = a[j];

                        match = aCh == bCh;
                    }
                }
                if (match)
                {
                    oss << b;
                    if (a.size() > 1)
                        i += a.size() - 1;
                }
                else
                    oss << ch;
            }
        }
        dest = oss.str();
    }

    void StringUtils::splitLine(StringArray&  dest,
                                const String& input,
                                const char    swap)
    {
        String swap1, swap2;
        swap1.push_back(swap);
        swap2.push_back(swap);
        swap2.push_back(swap);

        String temp = input;
        replaceAll(temp, temp, "\r", swap1);
        replaceAll(temp, temp, "\n", swap1);
        replaceAll(temp, temp, swap2, "\r\n");
        replaceAll(temp, temp, swap1, "\r\n");
        split(dest, temp, "\r\n");
    }

    void StringUtils::split(StringArray&  dest,
                            const String& str,
                            const char    sep)
    {
        String inp;
        inp.push_back(sep);
        split(dest, str, inp);
    }

    void StringUtils::split(StringArray& dest, const String& str, const String& sep)
    {
        String tmp = str;

        size_t pos = tmp.find(sep);
        while (pos != String::npos)
        {
            dest.push_back(tmp.substr(0, pos));
            tmp = tmp.substr(pos + sep.size(), tmp.size());
            pos = tmp.find(sep);
        }

        if (!tmp.empty())
            dest.push_back(tmp);
    }

    // clang-format off
    constexpr char BaseChars[] = {
        'D', 'c', 'U', 'y', '3', 'b', 'C', 'g',
        'p', 'J', '9', 'L', 'p', 'J', '0', 'A',
        'W', 'o', 'x', 'O', 'a', 'N', 'u', '8',
        'n', 'x', '7', 's', 'E', 'z', 'h', 'E',
        'q', 'Z', 'L', '4', 'F', '2', 'Q', 'i',
        'S', 'K', 'w', 'G', 'r', 'f', '1', 'Z',
        'd', 't', 'Y', '5', 'I', '3', 'K', 't',
        'B', '6', 'a', 'R', 'l', 'H', 'm', 'M',
    };
    // clang-format on

    constexpr size_t BaseCharsSize = sizeof BaseChars;

    void StringUtils::scramble(String& dest, size_t value)
    {
        dest.clear();
        srand(NOW % 65536);

        while (value > 0)
        {
            const size_t q  = value >> 6;
            const size_t ra = (size_t)rand();
            const size_t r  = (value + ra) % BaseCharsSize;

            dest.push_back(BaseChars[r]);
            value = q;
        }
    }

    void StringUtils::generate(String& dest, int& counter, void* seed)
    {
        // this 'should' be a GUID
        String sa, sb, sc, sd;
        scramble(sa, size_t(17) * ++counter);
        scramble(sb, NOW);
        scramble(sc, (size_t)seed);
        scramble(sd, size_t(41) * ++counter);
        StringCombine(dest, "L", sa, sb, sc, sd);
    }

    void StringUtils::trim(String& dest, const String& in, char ch)
    {
        trimL(dest, in, ch);
        trimR(dest, dest, ch);
    }

    void StringUtils::trimWhiteSpace(String& dest, const String& in)
    {
        size_t st;
        for (st = 0; st < in.size(); ++st)
        {
            if (!isWhiteSpace(in[st]))
                break;
        }

        if (st < in.size())
            dest = in.substr(st, in.size());
        else
            dest.clear();

        int en = (int)dest.size() - 1;
        for (; en >= 0; --en)
        {
            if (!isWhiteSpace(dest[en]))
            {
                ++en;
                break;
            }
        }

        if (en > 0)
            dest = dest.substr(0, en);
        else
            dest.clear();
    }

    void StringUtils::trimL(String& dest, const String& in, char ch)
    {
        size_t st;
        for (st = 0; st < in.size(); ++st)
        {
            if (in[st] != ch)
                break;
        }

        if (st < in.size())
            dest = in.substr(st, in.size());
        else
            dest.clear();
    }

    void StringUtils::trimR(String& dest, const String& in, char ch)
    {
        size_t st = 0;
        int    en = (int)in.size() - 1;

        for (; en >= 0; --en)
        {
            if (in[en] != ch)
            {
                ++en;
                break;
            }
        }

        if (en > 0)
            dest = in.substr(0, en);
        else
            dest.clear();
    }
} // namespace Hack
