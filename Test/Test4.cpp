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
#include "FileCmp.h"
#include "TestDirectory.h"
#include "VirtualMachine/Constants.h"
#include "VirtualMachine/Parser.h"
#include "VirtualMachine/Scanner.h"
#include "gtest/gtest.h"

using namespace Hack;

void VirtualMachineTestStack(Chips::Computer& comp, const String& baseName)
{
    const String fNameSrc = GetTestFilePath("VM/" + baseName + ".vm");
    const String fNameOut = GetOutFilePath("" + baseName + ".asm");

    VirtualMachine::Parser psr;

    psr.parse(fNameSrc);
    psr.write(fNameOut);

    Assembler::Parser loader;
    loader.parse(fNameOut);

    const Assembler::Parser::Instructions& inst = loader.instructions();

    comp.load(inst.data(), inst.size());

    comp.reset();
    comp.runToEnd();
}

GTEST_TEST(VirtualMachine, AddStackLocal)
{
    Chips::Computer comp;
    VirtualMachineTestStack(comp, "Test01");

    Chips::Memory* mem = comp.memory();

    // assert the ram
    uint16_t code = mem->get(VirtualMachine::LCL);
    code          = mem->get(code);
    EXPECT_EQ(code, 4);
}

GTEST_TEST(VirtualMachine, SubStackLocal)
{
    Chips::Computer comp;
    VirtualMachineTestStack(comp, "Test02");

    Chips::Memory* mem = comp.memory();

    // assert the ram
    uint16_t code = mem->get(VirtualMachine::LCL);
    code          = mem->get(code);
    EXPECT_EQ(code, (uint16_t)-2);
}

GTEST_TEST(VirtualMachine, OrStackLocal)
{
    Chips::Computer comp;
    VirtualMachineTestStack(comp, "Test03");

    Chips::Memory* mem = comp.memory();

    // assert the ram
    uint16_t code = mem->get(VirtualMachine::LCL);
    code          = mem->get(code);
    EXPECT_EQ(code, 63);
}

GTEST_TEST(VirtualMachine, AndStackLocal)
{
    Chips::Computer comp;
    VirtualMachineTestStack(comp, "Test04");

    Chips::Memory* mem = comp.memory();

    // assert the ram
    uint16_t code = mem->get(VirtualMachine::LCL);
    code          = mem->get(code);
    EXPECT_EQ(code, 9);
}

GTEST_TEST(VirtualMachine, AddStackArg)
{
    Chips::Computer comp;
    VirtualMachineTestStack(comp, "Test05");

    Chips::Memory* mem = comp.memory();

    // assert the ram
    const uint16_t code = mem->get(VirtualMachine::ARG);

    const uint16_t val = mem->get(code);
    EXPECT_EQ(val, 4);
}

GTEST_TEST(VirtualMachine, SubStackArg)
{
    Chips::Computer comp;
    VirtualMachineTestStack(comp, "Test06");

    Chips::Memory* mem = comp.memory();

    // assert the ram
    uint16_t code = mem->get(VirtualMachine::ARG);
    code          = mem->get(code);
    EXPECT_EQ(code, (uint16_t)-2);
}

GTEST_TEST(VirtualMachine, OrStackArg)
{
    Chips::Computer comp;
    VirtualMachineTestStack(comp, "Test07");

    Chips::Memory* mem = comp.memory();

    // assert the ram
    uint16_t code = mem->get(VirtualMachine::ARG);

    // assert the pop destination
    code = mem->get(code);
    EXPECT_EQ(code, 63);
}

GTEST_TEST(VirtualMachine, AndStackArg)
{
    Chips::Computer comp;
    VirtualMachineTestStack(comp, "Test08");

    Chips::Memory* mem = comp.memory();

    // assert the ram
    uint16_t code = mem->get(VirtualMachine::ARG);
    code          = mem->get(code);
    EXPECT_EQ(code, 9);
}

GTEST_TEST(VirtualMachine, BasicTest)
{
    Chips::Computer comp;

    VirtualMachineTestStack(comp, "Test09");

    Chips::Memory* mem = comp.memory();

    const uint16_t stp = mem->get(VirtualMachine::STP);
    const uint16_t lcl = mem->get(VirtualMachine::LCL);
    const uint16_t arg = mem->get(VirtualMachine::ARG);
    const uint16_t ths = mem->get(VirtualMachine::THS);
    const uint16_t tht = mem->get(VirtualMachine::THT);
    const uint16_t tmp = VirtualMachine::TMP;

    uint16_t code = mem->get(lcl);
    EXPECT_EQ(code, 10);
    code = mem->get(lcl + 1);
    EXPECT_EQ(code, 472);

    code = mem->get(arg + 1);
    EXPECT_EQ(code, 21);

    code = mem->get(arg + 2);
    EXPECT_EQ(code, 22);

    code = mem->get(ths + 6);
    EXPECT_EQ(code, 36);

    code = mem->get(tht + 2);
    EXPECT_EQ(code, 42);
    code = mem->get(tht + 5);
    EXPECT_EQ(code, 45);

#ifdef ZERO_M
    code = mem->get(tmp + 6);
    EXPECT_EQ(code, 0);
    code = mem->get(stp);
    EXPECT_EQ(code, 0);
#endif
}

GTEST_TEST(VirtualMachine, StaticTest)
{
    Chips::Computer comp;
    VirtualMachineTestStack(comp, "Test10");

    Chips::Memory* mem = comp.memory();

    uint16_t code = mem->get(VirtualMachine::STP);
    code          = mem->get(code - 1);
    EXPECT_EQ(code, 1110);
    code = mem->get(VirtualMachine::SW2 + 1);
    EXPECT_EQ(code, 888);
    code = mem->get(VirtualMachine::SW2 + 2);
    EXPECT_EQ(code, 333);
    code = mem->get(VirtualMachine::SW2 + 3);
    EXPECT_EQ(code, 111);
}

GTEST_TEST(VirtualMachine, TempOffsetTest)
{
    Chips::Computer comp;
    VirtualMachineTestStack(comp, "Test11");

    Chips::Memory* mem = comp.memory();

    uint16_t code = mem->get(5);
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
}

GTEST_TEST(VirtualMachine, PointerTest)
{
    Chips::Computer comp;
    VirtualMachineTestStack(comp, "Test12");

    Chips::Memory* mem = comp.memory();

    //|RAM[256]| RAM[3] | RAM[4] |RAM[3032|RAM[3046|
    //|   6084 |   3030 |   3040 |     32 |     46 |

    //uint16_t code = mem->get(256);
    //EXPECT_EQ(code, 6084);

    //code = mem->get(3);
    //EXPECT_EQ(code, 3030);
    //code = mem->get(4);
    //EXPECT_EQ(code, 3040);
    //code = mem->get(3032);
    //EXPECT_EQ(code, 32);
    //code = mem->get(3046);
    //EXPECT_EQ(code, 46);
}

GTEST_TEST(VirtualMachine, JumpTestLTEQ)
{
    Chips::Computer comp;
    VirtualMachineTestStack(comp, "Test13");

    Chips::Memory* mem = comp.memory();

    const uint16_t lcl = mem->get(VirtualMachine::LCL);

    uint16_t code = mem->get(lcl + 3);
    EXPECT_EQ(code, (uint16_t)-1);
    code = mem->get(lcl + 4);
    EXPECT_EQ(code, (uint16_t)-1);
    code = mem->get(lcl + 5);
    EXPECT_EQ(code, (uint16_t)-1);
    code = mem->get(lcl + 6);
    EXPECT_EQ(code, (uint16_t)-1);
}

GTEST_TEST(VirtualMachine, JumpTestGT)
{
    Chips::Computer comp;
    VirtualMachineTestStack(comp, "Test14");

    Chips::Memory* mem = comp.memory();

    const uint16_t code = mem->get(VirtualMachine::LCL);
    EXPECT_EQ(mem->get(code), 987);
}

GTEST_TEST(VirtualMachine, JumpTest)
{
    Chips::Computer comp;
    VirtualMachineTestStack(comp, "Test15");

    Chips::Memory* mem = comp.memory();

    uint16_t code = mem->get(VirtualMachine::LCL);
    code          = mem->get(code);
    EXPECT_EQ(code, 25);
}

GTEST_TEST(VirtualMachine, LoopTest)
{
    Chips::Computer comp;
    VirtualMachineTestStack(comp, "Test16");

    Chips::Memory* mem = comp.memory();

    const uint16_t code = mem->get(VirtualMachine::LCL);
    EXPECT_EQ(code, 300);
    const uint16_t val = mem->get(code);
    EXPECT_EQ(val, 55);
}

GTEST_TEST(VirtualMachine, FibonacciSeries)
{
    Chips::Computer comp;
    VirtualMachineTestStack(comp, "Test17");

    Chips::Memory* mem = comp.memory();

    uint16_t val = mem->get(3000);
    EXPECT_EQ(val, 0);
    val = mem->get(3001);
    EXPECT_EQ(val, 1);
    val = mem->get(3002);
    EXPECT_EQ(val, 1);
    val = mem->get(3003);
    EXPECT_EQ(val, 2);
    val = mem->get(3004);
    EXPECT_EQ(val, 3);
    val = mem->get(3005);
    EXPECT_EQ(val, 5);
}

GTEST_TEST(VirtualMachine, SimpleFunction)
{
    Chips::Computer comp;
    VirtualMachineTestStack(comp, "Test18");

    Chips::Memory* mem = comp.memory();

    uint16_t code = mem->get(VirtualMachine::STP);
    EXPECT_EQ(code, 257);
    code = mem->get(256);
    EXPECT_EQ(code, 28);
}

GTEST_TEST(VirtualMachine, RecursiveFunction)
{
    Chips::Computer comp;
    VirtualMachineTestStack(comp, "Test19");

    Chips::Memory* mem = comp.memory();

    uint16_t code = mem->get(VirtualMachine::STP);
    EXPECT_EQ(code, 257);
    code = mem->get(256);
    EXPECT_EQ(code, 1);
}

GTEST_TEST(VirtualMachine, FunctionLocals)
{
    // this pushes 4 and 6, adds them, then moves them into  3 locals
    // and returns the third local

    Chips::Computer comp;
    VirtualMachineTestStack(comp, "Test20");

    Chips::Memory* mem = comp.memory();

    const int locals = 256 + 2 + 5;

    uint16_t code = mem->get(VirtualMachine::STP);
    EXPECT_EQ(code, 257);         // should be one element on the stack (257-256)
    code = mem->get(256);         // 
    EXPECT_EQ(code, 10);          // should be 4+6
    code = mem->get(257);         //
    EXPECT_EQ(code, 6);          // should be lingering garbage  of 6
    code = mem->get(locals);      // The local base address 0
    EXPECT_EQ(code, 10);          // (garbage) but still present
    code = mem->get(locals + 1);  // 
    EXPECT_EQ(code, 10);          //
    code = mem->get(locals + 2);  //
    EXPECT_EQ(code, 10);          //
}
