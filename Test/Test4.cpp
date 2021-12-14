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
#include "Translator/VirtualMachine/Constants.h"
#include "Translator/VirtualMachine/Parser.h"
#include "Translator/VirtualMachine/Scanner.h"
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

struct Addressing
{
    int stp;
    int lcl;
    int arg;
    int ths;
    int tht;
};
constexpr Addressing DefaultAddressing = {256, 256, 256, 256, 256};

void VirtualMachineTestStack(Chips::Computer& comp, const String& baseName, Addressing addresses = DefaultAddressing)
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



    int tot = (int)inst.size(), i=0;

    Chips::CpuState st = Chips::Computer::NullState;
    while (st.pc < tot)
    {
        if (i++ == 13)
        {
            comp.getRam()->setValue(0, addresses.stp);
            comp.getRam()->setValue(1, addresses.lcl);
            comp.getRam()->setValue(2, addresses.arg);
            comp.getRam()->setValue(3, addresses.ths);
            comp.getRam()->setValue(4, addresses.tht);
        }

        // ticks 0, 1
        comp.update(false);
        comp.update(true);

        st = comp.getState();
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

    code = mem->get(code);
    EXPECT_EQ(code, 4);  // srcA should be overridden

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

    code = mem->get(code);
    EXPECT_EQ(code, (uint16_t)-2);  // srcA should be overridden

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

    code = mem->get(code);
    EXPECT_EQ(code, 63);  // srcA should be overridden

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

    code = mem->get(code);
    EXPECT_EQ(code, 9);  // srcA should be overridden

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

    code = mem->get(code);
    EXPECT_EQ(code, 4);  // srcA should be overridden

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

    code = mem->get(code);
    EXPECT_EQ(code, (uint16_t)-2);  // srcA should be overridden

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

    code = mem->get(code);
    EXPECT_EQ(code, 63);  // srcA should be overridden

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

    code = mem->get(code);
    EXPECT_EQ(code, 9);  // srcA should be overridden

    // assert the pop destination
    code = mem->get(VirtualMachine::ARG);
    EXPECT_EQ(code, VirtualMachine::Arguments);

    code = mem->get(code);
    EXPECT_EQ(code, 9);
}

GTEST_TEST(VirtualMachine, BasicTest)
{
    Chips::Computer comp;

    Addressing addr = {256, 300, 400, 3000, 3010}; 
    VirtualMachineTestStack(comp, "Test09", addr);

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

GTEST_TEST(VirtualMachine, StaticTest)
{
    Chips::Computer comp;
    VirtualMachineTestStack(comp, "Test10");

    Chips::Memory* mem = comp.getRam();

    const uint16_t code = mem->get(256);
    EXPECT_EQ(code, 1110);
}

GTEST_TEST(VirtualMachine, TempOffsetTest)
{
    Chips::Computer comp;
    VirtualMachineTestStack(comp, "Test11");

    Chips::Memory* mem = comp.getRam();

    uint16_t code = mem->get(256);
    EXPECT_EQ(code, 555);

    code = mem->get(5);
    EXPECT_EQ(code, 555);
    code = mem->get(6);
    EXPECT_EQ(code, 555);
    code = mem->get(7);
    EXPECT_EQ(code, 555);
    code = mem->get(8);
    EXPECT_EQ(code, 555);
    code = mem->get(9);
    EXPECT_EQ(code, 555);
    code = mem->get(10);
    EXPECT_EQ(code, 555);
    code = mem->get(11);
    EXPECT_EQ(code, 555);
    code = mem->get(12);
    EXPECT_EQ(code, 555);
    code = mem->get(13);
    EXPECT_EQ(code, 0);
    code = mem->get(14);
    EXPECT_EQ(code, 0);
    code = mem->get(15);
    EXPECT_EQ(code, 12);
}

GTEST_TEST(VirtualMachine, PointerTest)
{
    Chips::Computer comp;
    VirtualMachineTestStack(comp, "Test12");

    Chips::Memory* mem = comp.getRam();

    //|RAM[256]| RAM[3] | RAM[4] |RAM[3032|RAM[3046|
    //|   6084 |   3030 |   3040 |     32 |     46 |

    uint16_t code = mem->get(256);
    EXPECT_EQ(code, 6084);

    code = mem->get(3);
    EXPECT_EQ(code, 3030);
    code = mem->get(4);
    EXPECT_EQ(code, 3040);
    code = mem->get(3032);
    EXPECT_EQ(code, 32);
    code = mem->get(3046);
    EXPECT_EQ(code, 46);
}

GTEST_TEST(VirtualMachine, JumpTestLTEQ)
{
    Chips::Computer comp;
    VirtualMachineTestStack(comp, "Test13");

    Chips::Memory* mem  = comp.getRam();
    uint16_t       code = mem->get(VirtualMachine::Local + 3);
    EXPECT_EQ(code, (uint16_t)-1);

    code = mem->get(VirtualMachine::Local + 4);
    EXPECT_EQ(code, (uint16_t)-1);
    code = mem->get(VirtualMachine::Local + 5);
    EXPECT_EQ(code, (uint16_t)-1);
    code = mem->get(VirtualMachine::Local + 6);
    EXPECT_EQ(code, (uint16_t)-1);
}

GTEST_TEST(VirtualMachine, JumpTestGT)
{
    Chips::Computer comp;
    VirtualMachineTestStack(comp, "Test14");

    Chips::Memory* mem = comp.getRam();

    const uint16_t code = mem->get(VirtualMachine::Local);
    EXPECT_EQ(code, 987);
}

GTEST_TEST(VirtualMachine, JumpTest)
{
    Chips::Computer comp;
    VirtualMachineTestStack(comp, "Test15");

    Chips::Memory* mem = comp.getRam();

    const uint16_t code = mem->get(VirtualMachine::Local);
    EXPECT_EQ(code, 25);
}

GTEST_TEST(VirtualMachine, LoopTest)
{
    Chips::Computer comp;
    VirtualMachineTestStack(comp, "Test16");

    Chips::Memory* mem = comp.getRam();

    const uint16_t code = mem->get(VirtualMachine::LCL);
    EXPECT_EQ(code, 300);
    const uint16_t val = mem->get(code);
    EXPECT_EQ(val, 55);
}
