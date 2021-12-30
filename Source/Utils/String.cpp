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
#include "String.h"
#include <chrono>
#define NOW std::chrono::high_resolution_clock::now().time_since_epoch().count()

namespace Hack
{
    void StringUtils::split(StringArray&  dest,
                            const String& str,
                            const char    sep)
    {
        String tmp = str;

        size_t pos = tmp.find(sep);
        while (pos != String::npos)
        {
            dest.push_back(tmp.substr(0, pos));
            tmp = tmp.substr(pos + 1, tmp.size());
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
        size_t st = 0;
        size_t en = in.size();

        for (st=0; st<in.size(); ++st)
        {
            if (in[st] != ch)
                break;
        }

        for (en = in.size()-1; en != 0; --en)
        {
            if (in[en] != ch)
                break;
        }

        if (st > en)
            return;


        dest = in.substr(st, en+1);

    }

}  // namespace Hack
