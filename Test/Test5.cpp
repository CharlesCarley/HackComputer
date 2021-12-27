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
#include "Chips/Computer.h"
#include "Compiler/Analyzer/Parser.h"
#include "Compiler/Analyzer/Scanner.h"
#include "Compiler/Generator/Generator.h"
#include "TestDirectory.h"
#include "FileCmp.h"
#include "VirtualMachine/Parser.h"
#include "gtest/gtest.h"

using namespace Hack;
using namespace Compiler::Analyzer;

constexpr size_t NullIdx = (size_t)-1;

void GeneratorTestFile(Chips::Computer& comp, const String& baseName)
{
    const String fNameSrc = GetTestFilePath("Jack/" + baseName + ".jack");

    Parser ana;
    ana.parse(fNameSrc);

    Compiler::CodeGenerator::Generator cmp;
    cmp.compile(ana.getTree().getRoot());

    StringStream vmCode, asmCode;
    cmp.write(vmCode);

    VirtualMachine::Parser vm;

    vm.parse(vmCode);
    vm.write(asmCode);

    Assembler::Parser asmPsr;
    asmPsr.parse(asmCode);
    const Assembler::Parser::Instructions& inst = asmPsr.instructions();

    comp.load(inst.data(), inst.size());

    comp.reset();

    const int       tot = (int)inst.size();
    Chips::CpuState st  = Chips::Computer::NullState;
    while (st.pc < tot)
    {
        // ticks 0, 1
        comp.update(false);
        comp.update(true);

        st = comp.state();
    }
}

GTEST_TEST(Generator, TestAdd)
{
    Chips::Computer computer;
    GeneratorTestFile(computer, "Test10");

    Chips::Memory* memory = computer.memory();
    uint16_t       code   = memory->get(VirtualMachine::STP);
    EXPECT_EQ(code, 257);

    code = memory->get(256);
    EXPECT_EQ(code, 8);
}

GTEST_TEST(Generator, While)
{
    Chips::Computer computer;
    GeneratorTestFile(computer, "Test11");

    Chips::Memory* memory = computer.memory();
    uint16_t       code   = memory->get(VirtualMachine::STP);
    EXPECT_EQ(code, 257);

    code = memory->get(256);
    EXPECT_EQ(code, 20);
}

GTEST_TEST(Generator, StaticFields)
{
    Chips::Computer computer;
    GeneratorTestFile(computer, "Test12");

    Chips::Memory* memory = computer.memory();
    uint16_t       code   = memory->get(VirtualMachine::STP);
    EXPECT_EQ(code, 257);

    code = memory->get(256);
    EXPECT_EQ(code, 40);
    code = memory->get(16);
    EXPECT_EQ(code, 40);
    code = memory->get(17);
    EXPECT_EQ(code, 10);
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

    std::ifstream fs(GetTestFilePath("Jack/Scan.in"));
    scn.attach(&fs, GetTestFilePath("Jack/Scan.in"));

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
            scn.string(cmp, offsIndex);
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
    psr.write(GetOutFilePath("Test01.xml"));


    CompareFiles(GetOutFilePath("Test01.xml"),
                 GetTestFilePath("Jack/Test01.cmp"));
}
