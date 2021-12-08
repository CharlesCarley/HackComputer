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
#include "Chips/Computer.h"
#include "TestDirectory.h"
#include "VirtualMachine/Parser.h"
#include "VirtualMachine/Scanner.h"
#include "gtest/gtest.h"

void VmCompareSrc(const Hack::String& f0, const Hack::String& f1)
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

void VirtualMachineTestStack(const Hack::String& baseName,
                             uint16_t            srcB,
                             uint16_t            exp,
                             uint16_t            destRegValue,
                             uint16_t            destRegIndex)
{
    using namespace Hack;
    const String fNameSrc = GetTestFilePath("VM/" + baseName + ".vm");
    const String fNameCmp = GetTestFilePath("VM/" + baseName + ".asm");
    const String fNameOut = GetOutFilePath("" + baseName + ".ans");

    VirtualMachine::Parser psr;

    psr.parse(fNameSrc);
    psr.write(fNameOut);

    VmCompareSrc(fNameCmp, fNameOut);

    Assembler::Parser loader;
    loader.parse(fNameOut);

    const Assembler::Parser::Instructions& inst = loader.getInstructions();

    Chips::Computer comp;
    comp.load(inst.data(), inst.size());

    comp.reset();

    int tot = (int)inst.size();
    while (tot-- >= 0)
    {
        // ticks 0, 1
        comp.update(false);
        comp.update(false);
    }

    Chips::Memory* mem = comp.getRam();

    // assert the ram
    uint16_t code = mem->get(VirtualMachine::STP);
    EXPECT_EQ(code, VirtualMachine::Stack);

    uint16_t nc = code + 1;
    code = mem->get(code);
    EXPECT_EQ(code, exp);  // srcA should be overridden

    code = mem->get(nc);
    EXPECT_EQ(code, srcB);

    // assert the pop destination
    code = mem->get(destRegIndex);
    EXPECT_EQ(code, destRegValue);

    code = mem->get(code);
    EXPECT_EQ(code, exp);
}

GTEST_TEST(VirtualMachine, AddStackLocal)
{
    VirtualMachineTestStack("Test01",
                            2,
                            2+2,
                            Hack::VirtualMachine::Local,
                            Hack::VirtualMachine::LCL);
}

GTEST_TEST(VirtualMachine, SubStackLocal)
{
    VirtualMachineTestStack("Test02",
                            2,
                            (uint16_t)(0-2),
                            Hack::VirtualMachine::Local,
                            Hack::VirtualMachine::LCL);
}

GTEST_TEST(VirtualMachine, OrStackLocal)
{
    VirtualMachineTestStack("Test03",
                            31,
                            (uint16_t)(41 | 31),
                            Hack::VirtualMachine::Local,
                            Hack::VirtualMachine::LCL);
}

GTEST_TEST(VirtualMachine, AndStackLocal)
{
    VirtualMachineTestStack("Test04",
                            31,
                            (uint16_t)(41 & 31),
                            Hack::VirtualMachine::Local,
                            Hack::VirtualMachine::LCL);
}

GTEST_TEST(VirtualMachine, AddStackArg)
{
    VirtualMachineTestStack("Test05",
                            2,
                            2 + 2,
                            Hack::VirtualMachine::Arguments,
                            Hack::VirtualMachine::ARG);
}

GTEST_TEST(VirtualMachine, SubStackArg)
{
    VirtualMachineTestStack("Test06",
                            2,
                            (uint16_t)(0 - 2),
                            Hack::VirtualMachine::Arguments,
                            Hack::VirtualMachine::ARG);
}

GTEST_TEST(VirtualMachine, OrStackArg)
{
    VirtualMachineTestStack("Test07",
                            31,
                            (uint16_t)(41 | 31),
                            Hack::VirtualMachine::Arguments,
                            Hack::VirtualMachine::ARG);
}

GTEST_TEST(VirtualMachine, AndStackArg)
{
    VirtualMachineTestStack("Test08",
                            31,
                            (uint16_t)(41 & 31),
                            Hack::VirtualMachine::Arguments,
                            Hack::VirtualMachine::ARG);
}
