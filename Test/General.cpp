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
#include <cstdio>
#include "Utils/String.h"
#include "gtest/gtest.h"

using namespace Hack;

GTEST_TEST(General, StringSplitCR)
{
    String inp = "A\rB\rC\r";

    StringArray a0;
    StringUtils::splitLine(a0, inp);

    EXPECT_EQ(3, a0.size());
    EXPECT_EQ("A", a0[0]);
    EXPECT_EQ("B", a0[1]);
    EXPECT_EQ("C", a0[2]);

    inp = "A\nB\nC\n";

    StringArray a1;
    StringUtils::splitLine(a1, inp);

    EXPECT_EQ(3, a1.size());
    EXPECT_EQ("A", a1[0]);
    EXPECT_EQ("B", a1[1]);
    EXPECT_EQ("C", a1[2]);


    inp = "A\rB\nC\r";

    StringArray a2;
    StringUtils::splitLine(a2, inp);

    EXPECT_EQ(3, a2.size());
    EXPECT_EQ("A", a2[0]);
    EXPECT_EQ("B", a2[1]);
    EXPECT_EQ("C", a2[2]);

    inp = "A\r\nB\nC\r\n";

    StringArray a3;
    StringUtils::splitLine(a3, inp);

    EXPECT_EQ(3, a3.size());
    EXPECT_EQ("A", a3[0]);
    EXPECT_EQ("B", a3[1]);
    EXPECT_EQ("C", a3[2]);
}



GTEST_TEST(General, Trim)
{
    String inp = "     A B C       ";
    StringUtils::trimWhiteSpace(inp, inp);

    EXPECT_EQ("A B C", inp);

    inp = "\t\t\t\A\tB\tC\t\t\t\t\t";
    StringUtils::trimWhiteSpace(inp, inp);
    EXPECT_EQ("A\tB\tC", inp);


    inp = " \t \t \tA\tB C \t \t  \t";
    StringUtils::trimWhiteSpace(inp, inp);
    EXPECT_EQ("A\tB C", inp);
}
