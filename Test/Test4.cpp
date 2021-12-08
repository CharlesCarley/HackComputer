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
#include "TestDirectory.h"
#include "VirtualMachine/Constants.h"
#include "VirtualMachine/Parser.h"
#include "VirtualMachine/Scanner.h"
#include "gtest/gtest.h"

using namespace Hack;

void VmCompareSrc(const String& f0, const String& f1)
{
    std::ifstream if0(f0);
    std::ifstream if1(f1);

    String a, b;
    while (if1 >> b)
    {
        if0 >> a;
        EXPECT_EQ(a, b);

        a.clear();
        b.clear();
    }
}

void VirtualMachineTestStack(Chips::Computer& comp, const String& baseName)
{
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

    comp.load(inst.data(), inst.size());

    comp.reset();

    int tot = (int)inst.size();
    while (tot-- >= 0)
    {
        // ticks 0, 1
        comp.update(false);
        comp.update(false);
    }
}

GTEST_TEST(VirtualMachine, AddStackLocal)
{
    Chips::Computer comp;
    VirtualMachineTestStack(comp, "Test01");

    Chips::Memory* mem = comp.getRam();

    // assert the ram
    uint16_t code = mem->get(VirtualMachine::STP);
    EXPECT_EQ(code, VirtualMachine::Stack);

    const uint16_t nc = code + 1;
    code              = mem->get(code);
    EXPECT_EQ(code, 4);  // srcA should be overridden

    code = mem->get(nc);
    EXPECT_EQ(code, 2);

    // assert the pop destination
    code = mem->get(VirtualMachine::LCL);
    EXPECT_EQ(code, VirtualMachine::Local);

    code = mem->get(code);
    EXPECT_EQ(code, 4);
}

GTEST_TEST(VirtualMachine, SubStackLocal)
{
    Chips::Computer comp;
    VirtualMachineTestStack(comp, "Test02");

    Chips::Memory* mem = comp.getRam();

    // assert the ram
    uint16_t code = mem->get(VirtualMachine::STP);
    EXPECT_EQ(code, VirtualMachine::Stack);

    const uint16_t nc = code + 1;
    code              = mem->get(code);
    EXPECT_EQ(code, (uint16_t)-2);  // srcA should be overridden

    code = mem->get(nc);
    EXPECT_EQ(code, 2);

    // assert the pop destination
    code = mem->get(VirtualMachine::LCL);
    EXPECT_EQ(code, VirtualMachine::Local);

    code = mem->get(code);
    EXPECT_EQ(code, (uint16_t)-2);
}

GTEST_TEST(VirtualMachine, OrStackLocal)
{
    Chips::Computer comp;
    VirtualMachineTestStack(comp, "Test03");

    Chips::Memory* mem = comp.getRam();

    // assert the ram
    uint16_t code = mem->get(VirtualMachine::STP);
    EXPECT_EQ(code, VirtualMachine::Stack);

    const uint16_t nc = code + 1;
    code              = mem->get(code);
    EXPECT_EQ(code, 63);  // srcA should be overridden

    code = mem->get(nc);
    EXPECT_EQ(code, 31);

    // assert the pop destination
    code = mem->get(VirtualMachine::LCL);
    EXPECT_EQ(code, VirtualMachine::Local);

    code = mem->get(code);
    EXPECT_EQ(code, 63);
}

GTEST_TEST(VirtualMachine, AndStackLocal)
{
    Chips::Computer comp;
    VirtualMachineTestStack(comp, "Test04");

    Chips::Memory* mem = comp.getRam();

    // assert the ram
    uint16_t code = mem->get(VirtualMachine::STP);
    EXPECT_EQ(code, VirtualMachine::Stack);

    const uint16_t nc = code + 1;
    code              = mem->get(code);
    EXPECT_EQ(code, 9);  // srcA should be overridden

    code = mem->get(nc);
    EXPECT_EQ(code, 31);

    // assert the pop destination
    code = mem->get(VirtualMachine::LCL);
    EXPECT_EQ(code, VirtualMachine::Local);

    code = mem->get(code);
    EXPECT_EQ(code, 9);
}

GTEST_TEST(VirtualMachine, AddStackArg)
{
    Chips::Computer comp;
    VirtualMachineTestStack(comp, "Test05");

    Chips::Memory* mem = comp.getRam();

    // assert the ram
    uint16_t code = mem->get(VirtualMachine::STP);
    EXPECT_EQ(code, VirtualMachine::Stack);

    const uint16_t nc = code + 1;
    code              = mem->get(code);
    EXPECT_EQ(code, 4);  // srcA should be overridden

    code = mem->get(nc);
    EXPECT_EQ(code, 2);

    code = mem->get(VirtualMachine::ARG);
    EXPECT_EQ(code, VirtualMachine::Arguments);

    code = mem->get(code);
    EXPECT_EQ(code, 4);
}

GTEST_TEST(VirtualMachine, SubStackArg)
{
    Chips::Computer comp;
    VirtualMachineTestStack(comp, "Test06");

    Chips::Memory* mem = comp.getRam();

    // assert the ram
    uint16_t code = mem->get(VirtualMachine::STP);
    EXPECT_EQ(code, VirtualMachine::Stack);

    const uint16_t nc = code + 1;
    code              = mem->get(code);
    EXPECT_EQ(code, (uint16_t)-2);  // srcA should be overridden

    code = mem->get(nc);
    EXPECT_EQ(code, 2);

    code = mem->get(VirtualMachine::ARG);
    EXPECT_EQ(code, VirtualMachine::Arguments);

    code = mem->get(code);
    EXPECT_EQ(code, (uint16_t)-2);
}

GTEST_TEST(VirtualMachine, OrStackArg)
{
    Chips::Computer comp;
    VirtualMachineTestStack(comp, "Test07");

    Chips::Memory* mem = comp.getRam();

    // assert the ram
    uint16_t code = mem->get(VirtualMachine::STP);
    EXPECT_EQ(code, VirtualMachine::Stack);

    const uint16_t nc = code + 1;
    code              = mem->get(code);
    EXPECT_EQ(code, 63);  // srcA should be overridden

    code = mem->get(nc);
    EXPECT_EQ(code, 31);

    // assert the pop destination
    code = mem->get(VirtualMachine::ARG);
    EXPECT_EQ(code, VirtualMachine::Arguments);

    code = mem->get(code);
    EXPECT_EQ(code, 63);
}

GTEST_TEST(VirtualMachine, AndStackArg)
{
    Chips::Computer comp;
    VirtualMachineTestStack(comp, "Test08");

    Chips::Memory* mem = comp.getRam();

    // assert the ram
    uint16_t code = mem->get(VirtualMachine::STP);
    EXPECT_EQ(code, VirtualMachine::Stack);

    const uint16_t nc = code + 1;
    code              = mem->get(code);
    EXPECT_EQ(code, 9);  // srcA should be overridden

    code = mem->get(nc);
    EXPECT_EQ(code, 31);

    // assert the pop destination
    code = mem->get(VirtualMachine::ARG);
    EXPECT_EQ(code, VirtualMachine::Arguments);

    code = mem->get(code);
    EXPECT_EQ(code, 9);
}

GTEST_TEST(VirtualMachine, BasicTest)
{
    Chips::Computer comp;
    VirtualMachineTestStack(comp, "Test09");

    Chips::Memory* mem = comp.getRam();

    uint16_t code = mem->get(256);
    EXPECT_EQ(code, 472);
    code = mem->get(300);
    EXPECT_EQ(code, 10);
    code = mem->get(401);
    EXPECT_EQ(code, 21);
    code = mem->get(402);
    EXPECT_EQ(code, 22);
    code = mem->get(3006);
    EXPECT_EQ(code, 36);
    code = mem->get(3012);
    EXPECT_EQ(code, 42);
    code = mem->get(3015);
    EXPECT_EQ(code, 45);
    code = mem->get(11);
    EXPECT_EQ(code, 510);
}
