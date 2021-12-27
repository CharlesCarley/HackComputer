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
#include "FileCmp.h"
#include <gtest/gtest.h>
#include <fstream>

void CompareFiles(const Hack::String& a, const Hack::String& b)
{
    std::ifstream if0(a);
    std::ifstream if1(b);

    char r0, r1;
    while (if1 >> r1)
    {
        if0 >> r0;
        EXPECT_EQ((int)r0, (int)r1);
        EXPECT_EQ(if0.tellg(), if1.tellg());
    }
}
