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
#include <fstream>
#include "Assembler/Parser.h"
#include "Assembler/Scanner.h"
#include "TestDirectory.h"
#include "gtest/gtest.h"

using namespace Hack::Assembler;

#include "Test2Data.inl"

GTEST_TEST(Assembler, Scanner1)
{
    const Hack::String file = GetTestFilePath("Assembler/Scanner1.asm");
    std::ifstream       fs(file);
    EXPECT_TRUE(fs.is_open());

    Scanner sc;
    sc.load(&fs);
    Token t;
    sc.scan(t);
    EXPECT_EQ(TOK_EOF, t.getType());
}

GTEST_TEST(Assembler, Scanner2)
{
    const Hack::String file =
        GetTestFilePath("Assembler/Scanner2.asm");

    std::ifstream fs(file);
    EXPECT_TRUE(fs.is_open());

    const Hack::String expected[]{
        "12",
        "123",
        "1234",
        "12345",
        "123456",
        "1234567",
        "12345678",
        "123456789",
    };

    Scanner scanner;
    scanner.load(&fs);
    Token   token;
    scanner.scan(token);
    EXPECT_EQ(TOK_AT, token.getType());
    scanner.scan(token);
    EXPECT_EQ(TOK_ZERO, token.getType());
    scanner.scan(token);
    EXPECT_EQ(TOK_AT, token.getType());
    scanner.scan(token);
    EXPECT_EQ(TOK_ONE, token.getType());

    for (const Hack::String& str : expected)
    {
        scanner.scan(token);
        EXPECT_EQ(TOK_AT, token.getType());

        scanner.scan(token);

        EXPECT_EQ(TOK_INTEGER, token.getType());

        EXPECT_EQ(str, scanner.getString(token.getIndex()));
    }

    for (int tok : Scan2Tokens)
    {
        scanner.scan(token);
        EXPECT_EQ(tok, token.getType());
    }
}

void Assembler_CompareSrc(const Hack::String& f0, const Hack::String& f1)
{
    std::ifstream if0(f0);
    std::ifstream if1(f1);

    Hack::String a, b;

    while (if1 >> b)
    {
        if0 >> a;
        EXPECT_EQ(a, b);

        a.clear();
        b.clear();
    }
}

GTEST_TEST(Assembler, Parser1)
{
    Parser psr;
    psr.parse(GetTestFilePath("Assembler/Parser1.asm"));
    psr.writeInstructions(GetOutFilePath("Parser1.out"));

    Assembler_CompareSrc(
        GetTestFilePath("Assembler/Parser1.cmp"),
        GetOutFilePath("Parser1.out"));
}

GTEST_TEST(Assembler, Parser2)
{
    Parser psr;
    psr.parse(GetTestFilePath("Assembler/Parser2.asm"));
    psr.writeInstructions(GetOutFilePath("Parser2.out"));

    Assembler_CompareSrc(
        GetTestFilePath("Assembler/Parser2.cmp"),
        GetOutFilePath("Parser2.out"));
}


GTEST_TEST(Assembler, Add)
{
    Parser psr;
    psr.parse(GetTestFilePath("Assembler/Add.asm"));
    psr.writeInstructions(GetOutFilePath("Add.out"));

    Assembler_CompareSrc(
        GetTestFilePath("Assembler/Add.cmp"),
        GetOutFilePath("Add.out"));
}


GTEST_TEST(Assembler, Parser3)
{
    Parser psr;
    psr.parse(GetTestFilePath("Assembler/Parser3.asm"));
    psr.writeInstructions(GetOutFilePath("Parser3.out"));

    Assembler_CompareSrc(
        GetTestFilePath("Assembler/Parser3.cmp"),
        GetOutFilePath("Parser3.out"));
}
