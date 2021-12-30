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
#include <fstream>
#include "Assembler/Parser.h"
#include "Assembler/Scanner.h"
#include "Chips/Computer.h"
#include "FileCmp.h"
#include "TestDirectory.h"
#include "Utils/Console.h"
#include "gtest/gtest.h"

using namespace Hack;
using namespace Assembler;

#include "Test2Data.inl"

GTEST_TEST(Assembler, Scanner1)
{
    const String file = GetTestFilePath("Assembler/Scanner1.asm");

    std::ifstream fs(file);

    EXPECT_TRUE(fs.is_open());

    Scanner sc;
    sc.attach(&fs, file);
    Token t;
    sc.scan(t);
    EXPECT_EQ(TOK_EOF, t.getType());
}

GTEST_TEST(Assembler, Scanner2)
{
    const String file = GetTestFilePath("Assembler/Scanner2.asm");

    std::ifstream fs(file);
    EXPECT_TRUE(fs.is_open());

    const String expected[]{
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

    scanner.attach(&fs, file);
    Token token;
    scanner.scan(token);
    EXPECT_EQ(TOK_AT, token.getType());
    scanner.scan(token);
    EXPECT_EQ(TOK_ZERO, token.getType());
    scanner.scan(token);
    EXPECT_EQ(TOK_AT, token.getType());
    scanner.scan(token);
    EXPECT_EQ(TOK_ONE, token.getType());

    for (const String& str : expected)
    {
        scanner.scan(token);
        EXPECT_EQ(TOK_AT, token.getType());

        scanner.scan(token);

        EXPECT_EQ(TOK_INTEGER, token.getType());

        EXPECT_EQ(str, scanner.string(token.getIndex()));
    }

    for (int tok : Scan2Tokens)
    {
        scanner.scan(token);
        EXPECT_EQ(tok, token.getType());
    }
}

GTEST_TEST(Assembler, Parser1)
{
    Parser psr;
    psr.parse(GetTestFilePath("Assembler/Parser1.asm"));
    psr.write(GetOutFilePath("Parser1.out"));

    CompareFiles(GetTestFilePath("Assembler/Parser1.cmp"),
                 GetOutFilePath("Parser1.out"));
}

GTEST_TEST(Assembler, Parser2)
{
    Parser psr;
    psr.parse(GetTestFilePath("Assembler/Parser2.asm"));
    psr.write(GetOutFilePath("Parser2.out"));

    CompareFiles(GetTestFilePath("Assembler/Parser2.cmp"),
                 GetOutFilePath("Parser2.out"));
}

GTEST_TEST(Assembler, Error)
{
    try
    {
        Parser psr;
        psr.parse(GetTestFilePath("Assembler/Error.asm"));

        EXPECT_FALSE(true);
    }
    catch (std::exception& ex)
    {
        Console::write(ex.what());
    }
}

GTEST_TEST(Assembler, Add)
{
    Parser psr;
    psr.parse(GetTestFilePath("Assembler/Add.asm"));
    psr.write(GetOutFilePath("Add.out"));

    CompareFiles(GetTestFilePath("Assembler/Add.cmp"),
                 GetOutFilePath("Add.out"));
}

GTEST_TEST(Assembler, Parser3)
{
    Parser psr;

    psr.parse(GetTestFilePath("Assembler/Parser3.asm"));
    psr.write(GetOutFilePath("Parser3.out"));

    CompareFiles(GetTestFilePath("Assembler/Parser3.cmp"),
                 GetOutFilePath("Parser3.out"));
}

void AsmTestExec(Chips::Computer& comp, const String& baseName)
{
    const String fNameSrc = GetTestFilePath("Assembler/" + baseName + ".asm");

    Parser psr;
    psr.parse(fNameSrc);

    const Parser::Instructions& inst = psr.instructions();
    comp.load(inst.data(), inst.size());
    comp.reset();
    comp.runToEnd();
}



GTEST_TEST(Assembler, Exec01)
{
    Chips::Computer c;
    AsmTestExec(c, "Test01");

    Chips::Memory *mem = c.memory();
    EXPECT_EQ(mem->get(0), (uint16_t)-1);
    EXPECT_EQ(mem->get(1), 256);
    EXPECT_EQ(mem->get(2), 123);
    EXPECT_EQ(mem->get(3), 123);
    EXPECT_EQ(mem->get(4), (uint16_t)-1);
    EXPECT_EQ(mem->get(5), (uint16_t)-1);
    EXPECT_EQ(mem->get(6), (uint16_t)-1);
    EXPECT_EQ(mem->get(7), (uint16_t)-1);
    EXPECT_EQ(mem->get(8), 0);
}
