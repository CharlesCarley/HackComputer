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
#include "Utils/ParserBase/ScannerBase.h"

namespace Hack::ParserBase
{
    size_t Scanner::saveString(const String& str)
    {
        size_t idx;

        const StringTable::iterator it = _stringTable.find(str);

        if (it == _stringTable.end())
        {
            idx = _strings.size();

            _strings.push_back(str);

            _stringTable.insert(std::make_pair(str, idx));
        }
        else
            idx = it->second;

        return idx;
    }

    String Scanner::getString(const size_t& i) const
    {
        if (i < _strings.size())
            return _strings.at(i);
        return "";
    }


}  // namespace Hack::ParserBase
