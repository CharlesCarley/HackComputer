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
#include "TestDirectory.h"
#include "Assembler/Parser.h"
#include "Chips/Computer.h"
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

GTEST_TEST(VirtualMachine, Parser1)
{
    Hack::VirtualMachine::Parser psr;

    psr.parse(GetTestFilePath("VM/Test01.vm"));
    psr.write(GetOutFilePath("Test01.ans"));

    VmCompareSrc(GetTestFilePath("VM/Test01.cmp"),
                 GetOutFilePath("Test01.ans"));

    Hack::Chips::Computer comp;


    // from the output make sure that RAM[RAM[@LCL]] = (2 + 2) = 4
    Hack::Assembler::Parser loader;
    loader.parse(GetOutFilePath("Test01.ans"));

    const Hack::Assembler::Parser::Instructions& inst = loader.getInstructions();

    comp.load(inst.data(), inst.size());

    comp.reset();

    int tot = (int)inst.size();
    while (tot-- >= 0)
    {
        // ticks 0, 1
        comp.update(false);
        comp.update(false);
    }

    Hack::Chips::Memory *mem= comp.getRam();


    uint16_t code = mem->get(Hack::VirtualMachine::LCL);
    EXPECT_EQ(code, Hack::VirtualMachine::Local);

    code = mem->get(code);
    EXPECT_EQ(code, 4);
}
