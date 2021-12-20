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
#include "Utils/FileSystem.h"

namespace Hack
{
    using Directory = std::filesystem::directory_entry;
    
    void FileSystem::glob(PathArray& dest, const String& dir, const String& ext)
    {
        const Path pth = dir;

        std::filesystem::directory_iterator dirIt(pth);

        for (const Directory& element : dirIt)
        {
            if (element.is_regular_file() && element.path().extension() == ext)
                dest.push_back(std::filesystem::absolute(element.path()));
        }
    }

    Path FileSystem::absolute(const String& input)
    {
        return std::filesystem::absolute(input);
    }

}  // namespace Hack
