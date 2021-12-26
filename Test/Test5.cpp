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
#include "Compiler/Analyzer/Parser.h"
#include "Compiler/Analyzer/Scanner.h"
#include "FileCmp.h"
#include "TestDirectory.h"
#include "gtest/gtest.h"

using namespace Hack;
using namespace Compiler::Analyzer;

constexpr size_t NullIdx = (size_t)-1;

GTEST_TEST(Analyzer, GrammarClass)
{
    String testFiles[] = {
        "Test02",
        "Test03",
        "Test04",
        "Test05",
        "Test06",
        "Test07",
        "Test08",
        "Test09",
        "Test10",
    };


    for (String& f : testFiles)
    {
        Parser psr;
        psr.parse(GetTestFilePath("Jack/" + f + ".jack"));
        // psr.write(GetTestFilePath("Jack/" + f + ".xml"));
        psr.write(GetOutFilePath("" + f));
        CompareFiles(GetTestFilePath("Jack/" + f + ".xml"), GetOutFilePath("" + f));
    }
}

GTEST_TEST(Analyzer, TokenTest)
{
    Scanner scn;
    Token   tok;

    constexpr int Expected[] = {
        TokKwClass,
        TokKwConstructor,
        TokKwFunction,
        TokKwMethod,
        TokKwField,
        TokKwStatic,
        TokKwVar,
        TokKwInt,
        TokKwChar,
        TokKwBool,
        TokKwVoid,
        TokKwLet,
        TokKwDo,
        TokKwIf,
        TokKwElse,
        TokKwWhile,
        TokKwReturn,
        TokKwTrue,
        TokKwFalse,
        TokKwNull,
        TokKwThis,
        TokOpPlus,
        TokOpMinus,
        TokOpMultiply,
        TokOpDivide,
        TokOpAnd,
        TokOpOr,
        TokOpNot,
        TokOpNot,
        TokSymLBracket,
        TokSymRBracket,
        TokSymLBrace,
        TokSymRBrace,
        TokSymLPar,
        TokSymRPar,
        TokSymPeriod,
        TokOpGt,
        TokOpLt,
        TokOpEq,
        TokSymComma,
        TokSymSemicolon,
        TokInt,
        TokInt,
        TokId,
        TokString,
        TokString,
        TokString,
        TokString,
        TokString,
        TokEof,
    };

    std::ifstream fs(GetTestFilePath("Jack/Scan.jack"));
    scn.attach(&fs, GetTestFilePath("Jack/Scan.jack"));

    String expString[] = {
        "0",
        "123456",
        "A_b_1_2",
        "abcdefghihjklmopqrstuvwxyz",
        "ABCDEFGHIHJKLMOPQRSTUVWXYZ",
        "0123456789",
        "~!@#$%^&*()_-+={}[]:;\"'<>,.?/\\|",
        "\n\r \t",

    };

    int offsIndex = 0;
    for (int exp : Expected)
    {
        scn.scan(tok);
        EXPECT_EQ(exp, tok.getType());

        if (exp >= 'A' && exp <= 'C')
        {
            EXPECT_EQ(offsIndex, tok.getIndex());

            String cmp;
            scn.getString(cmp, offsIndex);
            EXPECT_EQ(expString[offsIndex], cmp);
            ++offsIndex;
        }
        else
            EXPECT_EQ(NullIdx, tok.getIndex());
    }
}

GTEST_TEST(Analyzer, ParserTest)
{
    Parser psr;
    psr.parse(GetTestFilePath("Jack/Test01.jack"));
    psr.write(GetTestFilePath("Jack/Test01.xml"));
}
