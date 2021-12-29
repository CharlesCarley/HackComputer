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
#include "Chips/ALU.h"
#include "Chips/Add16.h"
#include "Chips/And.h"
#include "Chips/And16.h"
#include "Chips/Bit.h"
#include "Chips/BitUtils.h"
#include "Chips/CPU.h"
#include "Chips/Clock.h"
#include "Chips/DFlipFlop.h"
#include "Chips/DMux.h"
#include "Chips/DMux4Way.h"
#include "Chips/DMux8Way.h"
#include "Chips/FullAdder.h"
#include "Chips/HalfAdder.h"
#include "Chips/Inc16.h"
#include "Chips/Mux.h"
#include "Chips/Mux16.h"
#include "Chips/Mux4Way16.h"
#include "Chips/Mux8Way16.h"
#include "Chips/NAnd.h"
#include "Chips/NOr.h"
#include "Chips/Not.h"
#include "Chips/Not16.h"
#include "Chips/Or.h"
#include "Chips/Or16.h"
#include "Chips/Or8Way.h"
#include "Chips/ProgramCounter.h"
#include "Chips/Ram16k.h"
#include "Chips/Ram4k.h"
#include "Chips/Ram512.h"
#include "Chips/Ram64.h"
#include "Chips/Ram8.h"
#include "Chips/Register.h"
#include "Chips/SRLatch.h"
#include "Chips/Timer.h"
#include "Chips/XOr.h"
#include "Test1Data.inl"
#include "gtest/gtest.h"

using namespace Hack::Chips;

GTEST_TEST(Hack, Nand)
{
    NAnd n;
    n.setA(false);
    n.setB(false);
    n.print();
    EXPECT_TRUE(n.getOut());

    n.setA(false);
    n.setB(true);
    n.print();
    EXPECT_TRUE(n.getOut());

    n.setA(true);
    n.setB(false);
    n.print();
    EXPECT_TRUE(n.getOut());

    n.setA(true);
    n.setB(true);
    n.print();
    EXPECT_FALSE(n.getOut());
}

GTEST_TEST(Hack, Not)
{
    Not n;
    n.setIn(false);
    n.print();
    EXPECT_TRUE(n.getOut());

    n.setIn(true);
    n.print();
    EXPECT_FALSE(n.getOut());
}

GTEST_TEST(Hack, Not16)
{
    Not16 n;
    n.setIn((uint16_t)0);
    EXPECT_EQ(0xFFFF, n.getOut());
    EXPECT_EQ(0, n.getOut());
    EXPECT_EQ(0xFFFF, n.getOut());
    EXPECT_EQ(0, n.getOut());
}

GTEST_TEST(Hack, Or)
{
    Or n;
    n.setA(false);
    n.setB(false);
    n.print();
    EXPECT_FALSE(n.getOut());

    n.setA(false);
    n.setB(true);
    n.print();
    EXPECT_TRUE(n.getOut());

    n.setA(true);
    n.setB(false);
    n.print();
    EXPECT_TRUE(n.getOut());

    n.setA(true);
    n.setB(true);
    n.print();
    EXPECT_TRUE(n.getOut());
}

GTEST_TEST(Hack, NOr)
{
    NOr n;
    n.setA(false);
    n.setB(false);
    n.print();
    EXPECT_TRUE(n.getOut());

    n.setA(false);
    n.setB(true);
    n.print();
    EXPECT_FALSE(n.getOut());

    n.setA(true);
    n.setB(false);
    n.print();
    EXPECT_FALSE(n.getOut());

    n.setA(true);
    n.setB(true);
    n.print();
    EXPECT_FALSE(n.getOut());
}

GTEST_TEST(Hack, XOr)
{
    XOr n;
    n.setA(false);
    n.setB(false);
    n.print();
    EXPECT_FALSE(n.getOut());

    n.setA(false);
    n.setB(true);
    n.print();
    EXPECT_TRUE(n.getOut());

    n.setA(true);
    n.setB(false);
    n.print();
    EXPECT_TRUE(n.getOut());

    n.setA(true);
    n.setB(true);
    n.print();
    EXPECT_FALSE(n.getOut());
}

GTEST_TEST(Hack, And)
{
    And n;
    n.setA(false);
    n.setB(false);
    n.print();
    EXPECT_FALSE(n.getOut());

    n.setA(false);
    n.setB(true);
    n.print();
    EXPECT_FALSE(n.getOut());

    n.setA(true);
    n.setB(false);
    n.print();
    EXPECT_FALSE(n.getOut());

    n.setA(true);
    n.setB(true);
    n.print();
    EXPECT_TRUE(n.getOut());
}

GTEST_TEST(Hack, BitwiseAnd)
{
    const uint8_t a = 0b00000001;
    const uint8_t b = 0b11110001;
    const uint8_t c = BitwiseGates::And(a, b);
    EXPECT_EQ(1, c);
}

GTEST_TEST(Hack, BitwiseNAnd)
{
    const uint8_t a = 0b00000001;
    const uint8_t b = 0b11110001;
    const uint8_t c = BitwiseGates::NAnd(a, b);
    EXPECT_EQ(254, c);
}

GTEST_TEST(Hack, BitwiseOr)
{
    const uint8_t a = 0b00000001;
    const uint8_t b = 0b11110001;
    const uint8_t c = BitwiseGates::Or(a, b);
    EXPECT_EQ(241, c);
}

GTEST_TEST(Hack, BitwiseNOr)
{
    const uint8_t a = 0b00000001;
    const uint8_t b = 0b11110001;
    const uint8_t c = BitwiseGates::NOr(a, b);
    EXPECT_EQ(14, c);
}

GTEST_TEST(Hack, BitwiseXOr)
{
    const uint8_t a = 0b00000001;
    const uint8_t b = 0b11110001;
    const uint8_t c = BitwiseGates::XOr(a, b);
    EXPECT_EQ(240, c);
}

GTEST_TEST(Hack, BitwiseMux)
{
    const uint8_t a = 0b00000001;
    const uint8_t b = 0b00110101;

    const uint8_t c = BitwiseGates::Mux<uint8_t>(a, b, 0);
    EXPECT_EQ(a, c);
    const uint8_t d = BitwiseGates::Mux<uint8_t>(a, b, 0xFF);
    EXPECT_EQ(b, d);
}

GTEST_TEST(Hack, And16)
{
    And16 n;

    n.setA(0b1010101010101010);
    n.setB(0b0101010101010101);
    EXPECT_EQ(0, n.getOut());

    n.setA(0b1010101010101010);
    n.setB(0b1111111100000000);
    EXPECT_EQ(0b1010101000000000, n.getOut());
}

GTEST_TEST(Hack, Inc16)
{
    Inc16 n;

    n.setIn((uint16_t)0);

    const uint32_t p = 0xFFFF + 20;
    int32_t        r = 0;
    for (uint32_t i = 0; i < p; ++i)
    {
        const int32_t j = i + 1;
        if (i > 1 && j % 0xFFFF == 1)
            r = -1;

        uint16_t vo = (uint16_t)((int32_t)n.getOut() % 0xFFFF);
        uint16_t vi = (uint16_t)((int32_t)(j + r) % 0xFFFF);
        EXPECT_EQ(vi, vo);
    }
}

GTEST_TEST(Hack, Mux)
{
    Mux n;
    n.setA(false);
    n.setB(false);
    n.setSel(false);
    n.print();
    EXPECT_FALSE(n.getOut());

    n.setA(false);
    n.setB(false);
    n.setSel(true);
    n.print();
    EXPECT_FALSE(n.getOut());

    n.setA(false);
    n.setB(true);
    n.setSel(false);
    n.print();
    EXPECT_FALSE(n.getOut());

    n.setA(false);
    n.setB(true);
    n.setSel(true);
    n.print();
    EXPECT_TRUE(n.getOut());

    n.setA(true);
    n.setB(false);
    n.setSel(false);
    n.print();
    EXPECT_TRUE(n.getOut());

    n.setA(true);
    n.setB(false);
    n.setSel(true);
    n.print();
    EXPECT_FALSE(n.getOut());

    n.setA(true);
    n.setB(true);
    n.setSel(false);
    n.print();
    EXPECT_TRUE(n.getOut());

    n.setA(true);
    n.setB(true);
    n.setSel(true);
    n.print();
    EXPECT_TRUE(n.getOut());
}

GTEST_TEST(Hack, DMux)
{
    DMux n;
    n.setIn(false);
    n.setSel(false);
    n.print();
    EXPECT_FALSE(n.getA());
    EXPECT_FALSE(n.getB());

    n.setIn(false);
    n.setSel(true);
    n.print();
    EXPECT_FALSE(n.getA());
    EXPECT_FALSE(n.getB());

    n.setIn(true);
    n.setSel(false);
    n.print();
    EXPECT_TRUE(n.getA());
    EXPECT_FALSE(n.getB());

    n.setIn(true);
    n.setSel(true);
    n.print();
    EXPECT_FALSE(n.getA());
    EXPECT_TRUE(n.getB());
}

GTEST_TEST(Hack, DMux4Way)
{
    DMux4Way n;
    n.setIn(true);
    n.setSel(0);
    EXPECT_EQ(1, n.getOut());
    n.setSel(1);
    EXPECT_EQ(2, n.getOut());

    n.setSel(2);
    EXPECT_EQ(4, n.getOut());

    n.setSel(3);
    EXPECT_EQ(8, n.getOut());
}

GTEST_TEST(Hack, DMux8Way)
{
    DMux8Way n;
    n.setIn(true);
    n.setSel(0);
    EXPECT_EQ(1, n.getOut());
    n.setSel(1);
    EXPECT_EQ(2, n.getOut());
    n.setSel(2);
    EXPECT_EQ(4, n.getOut());
    n.setSel(3);
    EXPECT_EQ(8, n.getOut());
    n.setSel(4);
    EXPECT_EQ(16, n.getOut());
    n.setSel(5);
    EXPECT_EQ(32, n.getOut());
    n.setSel(6);
    EXPECT_EQ(64, n.getOut());
    n.setSel(7);
    EXPECT_EQ(128, n.getOut());
}

GTEST_TEST(Hack, HalfAdder)
{
    HalfAdder n;
    n.setA(false);
    n.setB(false);
    n.print();
    EXPECT_FALSE(n.getSum());
    EXPECT_FALSE(n.getCary());

    n.setA(false);
    n.setB(true);
    n.print();
    EXPECT_TRUE(n.getSum());
    EXPECT_FALSE(n.getCary());

    n.setA(true);
    n.setB(false);
    n.print();
    EXPECT_TRUE(n.getSum());
    EXPECT_FALSE(n.getCary());

    n.setA(true);
    n.setB(true);
    n.print();
    EXPECT_FALSE(n.getSum());
    EXPECT_TRUE(n.getCary());
}

GTEST_TEST(Hack, FullAdder)
{
    FullAdder n;
    n.setA(false);
    n.setB(false);
    n.setCaryIn(false);
    n.print();
    EXPECT_FALSE(n.getSum());
    EXPECT_FALSE(n.getCary());

    n.setA(false);
    n.setB(false);
    n.setCaryIn(true);
    n.print();
    EXPECT_TRUE(n.getSum());
    EXPECT_FALSE(n.getCary());

    n.setA(false);
    n.setB(true);
    n.setCaryIn(false);
    n.print();
    EXPECT_TRUE(n.getSum());
    EXPECT_FALSE(n.getCary());

    n.setA(false);
    n.setB(true);
    n.setCaryIn(true);
    n.print();
    EXPECT_FALSE(n.getSum());
    EXPECT_TRUE(n.getCary());

    n.setA(true);
    n.setB(false);
    n.setCaryIn(false);
    n.print();
    EXPECT_TRUE(n.getSum());
    EXPECT_FALSE(n.getCary());

    n.setA(true);
    n.setB(false);
    n.setCaryIn(true);
    n.print();
    EXPECT_FALSE(n.getSum());
    EXPECT_TRUE(n.getCary());

    n.setA(true);
    n.setB(true);
    n.setCaryIn(false);
    n.print();
    EXPECT_FALSE(n.getSum());
    EXPECT_TRUE(n.getCary());

    n.setA(true);
    n.setB(true);
    n.setCaryIn(true);
    n.print();
    EXPECT_TRUE(n.getSum());
    EXPECT_TRUE(n.getCary());
}

GTEST_TEST(Hack, FullAdderAdd)
{
    FullAdder n;

    int r    = 0;
    int A[7] = {1, 0, 1, 0, 0, 0, 1},
        B[7] = {1, 0, 0, 1, 0, 1, 0};

    // ----------------------------
    //                  1
    //   1  0  0  0  1  0  1 |  69
    //  +0  1  0  1  0  0  1 |+ 41
    //  ---------------------|----
    //   1  1  0  1  1  1  0 | 110
    // ----------------------------
    for (int i = 0; i < 7; ++i)
    {
        n.setCaryIn(n.getCary());
        n.setA(A[i] != 0);
        n.setB(B[i] != 0);
        n.print();
        r += (1 << i) * (n.getSum() ? 1 : 0);
    }
    if (n.getCary())
        r += (1 << 7) * (n.getSum() ? 1 : 0);

    EXPECT_EQ(110, r);
}

GTEST_TEST(Hack, Or8Way)
{
    Or8Way n;

    uint8_t v = 0b11111111;
    for (int i = 0; i < 8; ++i)
    {
        n.setIn(v);
        n.print();
        EXPECT_TRUE(n.getOut());
        v &= ~(1 << i);
    }
    n.setIn(v);
    EXPECT_FALSE(n.getOut());
}

GTEST_TEST(Hack, Or16)
{
    Or16 n;

    n.setA(0b1010101010101010);
    n.setB(0b0101010101010101);

    EXPECT_EQ(0b1111111111111111, n.getOut());
}

GTEST_TEST(Hack, Add16)
{
    Add16 n;

    n.setA(5897);
    n.setB(48721);
    EXPECT_EQ(54618, n.getOut());

    n.setA(0b1010101010);
    n.setB(0b0101010101);
    EXPECT_EQ(0b1111111111, n.getOut());

    n.setA(0b1011101011);
    n.setB(0b0101010101);
    EXPECT_EQ(0b10001000000, n.getOut());
}

GTEST_TEST(Hack, AddBounds)
{
    Add16 n;

    n.setA(0xFFFB);
    n.setB(1);
    for (int i = 0; i < 8; ++i)
    {
        std::cout << n.getOut() << std::endl;
        n.setA(n.getOut());
    }
}

GTEST_TEST(Hack, AluBounds)
{
    Alu n;

    n.setFlags(XPlusY);
    n.setX(0xFFFB);
    n.setY(1);
    for (int i = 0; i < 8; ++i)
    {
        std::cout << n.getOut() << std::endl;
        n.setX(n.getOut());
    }
}

GTEST_TEST(Hack, Mux16)
{
    Mux16 n;
    n.setA(3);
    n.setB(5);
    n.setSel(true);
    EXPECT_EQ(5, n.getOut());
    n.setSel(false);
    EXPECT_EQ(3, n.getOut());
}

GTEST_TEST(Hack, Mux4Way16)
{
    Mux4Way16 n;
    n.setA(1);
    n.setB(2);
    n.setC(3);
    n.setD(4);

    for (int i = 0; i < 4; ++i)
    {
        n.setSel((uint8_t)i);
        EXPECT_EQ(i + 1, n.getOut());
    }
}

GTEST_TEST(Hack, Mux8Way16)
{
    Mux8Way16 n;
    n.setA(1001);
    n.setB(1002);
    n.setC(1003);
    n.setD(1004);
    n.setE(1005);
    n.setF(1006);
    n.setG(1007);
    n.setH(1008);

    for (int i = 0; i < 8; ++i)
    {
        n.setSel((uint8_t)i);
        EXPECT_EQ(i + 1001, n.getOut());
    }
}

GTEST_TEST(Hack, ALUXPlusY)
{
    Alu n;

    // XPlusY
    n.setFlags(XPlusY);
    n.setX(5);
    n.setY(5);

    const uint16_t out = n.getOut();
    EXPECT_EQ(10, out);
}

GTEST_TEST(Hack, ALUXAndY)
{
    Alu n;

    n.setFlags(XAndY);
    n.setX(3);
    n.setY(9);

    const uint16_t out = n.getOut();
    EXPECT_EQ(1, out);
}

GTEST_TEST(Hack, ALUZero)
{
    Alu n;

    n.setFlags(Zero);
    n.setX(6585);
    n.setY(5554);

    const uint16_t out = n.getOut();
    EXPECT_EQ(0, out);
}

GTEST_TEST(Hack, ALUOne)
{
    Alu n;

    n.setFlags(One);
    n.setX(6585);
    n.setY(5554);

    const uint16_t out = n.getOut();
    EXPECT_EQ(1, out);
}

GTEST_TEST(Hack, ALUOutX)
{
    Alu n;

    n.setX(6585);
    n.setY(5554);
    n.setFlags(OutX);
    const uint16_t out = n.getOut();
    EXPECT_EQ(6585, out);
}

GTEST_TEST(Hack, ALUOutY)
{
    Alu n;

    n.setX(6585);
    n.setY(5554);

    n.setFlags(OutY);
    const uint16_t out = n.getOut();
    EXPECT_EQ(5554, out);
}

GTEST_TEST(Hack, ALUNot)
{
    Alu n;

    n.setX(0b1010001000000001);
    n.setY(0b0000000000001111);

    n.setFlags(NotX);
    uint16_t out = n.getOut();
    EXPECT_EQ(0b0101110111111110, out);

    n.setFlags(NotY);
    out = n.getOut();
    EXPECT_EQ(0b1111111111110000, out);
}

GTEST_TEST(Hack, ALUNegative)
{
    Alu n;

    n.setFlags(NegativeX);
    n.setX(2);
    int16_t out = (int16_t)n.getOut();
    EXPECT_EQ(-2, out);

    n.setFlags(NegativeY);
    n.setY(6);

    out = (int16_t)n.getOut();
    EXPECT_EQ(-6, out);

    n.setFlags(NegativeOne);

    n.setX(1);
    n.setY(1);
    out = (int16_t)(n.getOut());
    EXPECT_EQ(-1, out);
}

GTEST_TEST(Hack, ALUPlusMinusOne)
{
    Alu n;

    n.setFlags(XPlusOne);
    n.setX(6);
    uint16_t out = n.getOut();
    EXPECT_EQ(7, out);

    n.setFlags(XMinusOne);
    n.setX(6);
    out = n.getOut();
    EXPECT_EQ(5, out);

    n.setFlags(YPlusOne);
    n.setY(10);
    out = n.getOut();
    EXPECT_EQ(11, out);

    n.setFlags(YMinusOne);
    n.setY(10);
    out = n.getOut();
    EXPECT_EQ(9, out);
}

GTEST_TEST(Hack, ALUPlusMinusXY)
{
    Alu n;

    n.setFlags(XMinusY);
    n.setX(2);
    n.setY(2);

    uint16_t out = n.getOut();
    EXPECT_EQ(0, out);

    n.setFlags(YMinusX);
    n.setX(2);
    n.setY(4);

    out = n.getOut();
    EXPECT_EQ(2, n.getOut());
}

GTEST_TEST(Hack, ALUXOrY)
{
    Alu n;

    n.setFlags(XOrY);
    n.setX(16);
    n.setY(4);

    const uint16_t out = n.getOut();
    EXPECT_EQ(20, out);
}

GTEST_TEST(Hack, ALUCtrlOut)
{
    Alu n;

    n.setFlags(XMinusY);
    n.setX(2);
    n.setY(2);

    const uint16_t out = n.getOut();
    EXPECT_EQ(0, out);
    EXPECT_TRUE((n.getFlags() & Zr) != 0);

    n.setY(4);
    EXPECT_TRUE((n.getFlags() & Ne) != 0);
}

void Hack_ALU_LogFlags(uint16_t flags)
{
    Hack::Console::writeLine(flags);
    switch (flags)
    {
    case Zero:
        Hack::Console::writeLine("Zero");
        break;
    case One:
        Hack::Console::writeLine("One");
        break;
    case XAndY:
        Hack::Console::writeLine("XAndY");
        break;
    case NegativeOne:
        Hack::Console::writeLine("NegativeOne");
        break;
    case OutX:
        Hack::Console::writeLine("OutX");
        break;
    case OutY:
        Hack::Console::writeLine("OutY");
        break;
    case NotX:
        Hack::Console::writeLine("NotX");
        break;
    case NotY:
        Hack::Console::writeLine("NotY");
        break;
    case NegativeX:
        Hack::Console::writeLine("NegativeX");
        break;
    case NegativeY:
        Hack::Console::writeLine("NegativeY");
        break;
    case XPlusOne:
        Hack::Console::writeLine("XPlusOne");
        break;
    case YPlusOne:
        Hack::Console::writeLine("YPlusOne");
        break;
    case XMinusOne:
        Hack::Console::writeLine("XMinusOne");
        break;
    case YMinusOne:
        Hack::Console::writeLine("YMinusOne");
        break;
    case XPlusY:
        Hack::Console::writeLine("XPlusY");
        break;
    case XMinusY:
        Hack::Console::writeLine("XMinusY");
        break;
    case YMinusX:
        Hack::Console::writeLine("YMinusX");
        break;
    case XOrY:
        Hack::Console::writeLine("XOrY");
        break;
    default:
        Hack::Console::writeLine("Unknown");
    }
}

GTEST_TEST(Hack, ALU)
{
    Alu n;
    for (const int* al : ALUTestData)
    {
        n.setX((uint16_t)al[0]);
        n.setY((uint16_t)al[1]);

        uint8_t flags = 0;
        if (al[2])
            flags |= Zx;
        if (al[3])
            flags |= Nx;
        if (al[4])
            flags |= Zy;
        if (al[5])
            flags |= Ny;
        if (al[6])
            flags |= Fn;
        if (al[7])
            flags |= No;

        Hack_ALU_LogFlags(flags);
        n.setFlags(flags);

        const uint16_t out = n.getOut();
        EXPECT_EQ((uint16_t)al[8], out);

        int tz = 0;
        if (n.getZr())
            tz = 1;
        EXPECT_EQ(al[9], tz);

        tz = 0;
        if (n.getNe())
            tz = 1;
        EXPECT_EQ(al[10], tz);
    }
}

GTEST_TEST(Hack, SRLatch)
{
    char table[][4] = {
        {0, 0, 1, 1},  // latched
        {0, 1, 1, 0},
        {1, 0, 0, 1},
        {1, 1, 0, 1},
    };
    for (char* tab : table)
    {
        SRLatch n;

        n.setS(tab[0] != 0);
        n.setR(tab[1] != 0);
        n.print();

        EXPECT_EQ(tab[2] != 0, n.getQ());
        EXPECT_EQ(tab[3] != 0, n.getQPlus());
    }
}

GTEST_TEST(Hack, Clock)
{
    Clock n;

    n.setIn(true);
    n.setReset(true);

    n.print();
    EXPECT_TRUE(n.getOut());

    bool test = true;
    for (int i = 0; i < 17; ++i)
    {
        n.print();
        EXPECT_EQ(!test, n.getOut());
        test = !test;
    }

    n.setIn(test);
    n.setReset(true);
    n.print();
    EXPECT_EQ(test, n.getOut());
}

GTEST_TEST(Hack, DFlipFlop)
{
    DFlipFlop n;
    n.setD(false);
    n.setG(true);
    n.print();
    EXPECT_EQ(false, n.getQ());
    EXPECT_EQ(true, n.getQPlus());

    for (int i = 0; i < 100; ++i)
    {
        n.setG(false);
        n.print();
        EXPECT_EQ(false, n.getQ());
        EXPECT_EQ(true, n.getQPlus());
    }

    n.setD(true);
    n.setG(true);
    n.print();
    EXPECT_EQ(true, n.getQ());
    EXPECT_EQ(false, n.getQPlus());

    for (int i = 0; i < 100; ++i)
    {
        n.setG(false);
        n.print();
        EXPECT_EQ(true, n.getQ());
        EXPECT_EQ(false, n.getQPlus());
    }
}

GTEST_TEST(Hack, Bit)
{
    Bit n;

    for (const int* bit : BitsTestData)
    {
        const bool    time = bit[0] != 0;
        const int16_t in   = (int16_t)bit[1];
        const bool    load = bit[2] != 0;
        const int16_t exp  = (int16_t)bit[3];

        n.setClock(time);
        n.setIn(in);
        n.setLoad(load);

        int16_t out = (int16_t)n.getOut();
        n.print();
        EXPECT_EQ(exp, out);
    }
}

GTEST_TEST(Hack, Register)
{
    Register n;

    for (const int* reg : RegisterTestData)
    {
        const bool    time = reg[0] != 0;
        const int16_t in   = (int16_t)reg[1];
        const bool    load = reg[2] != 0;
        const int16_t exp  = (int16_t)reg[3];

        n.setClock(time);
        n.setIn(in);
        n.setLoad(load);

        n.print();

        int16_t out = (int16_t)n.getOut();
        EXPECT_EQ(exp, out);
    }
}

GTEST_TEST(Hack, Register1)
{
    Register n;
    n.setClock(false);
    n.setLoad(true);
    n.setIn(2);

    EXPECT_EQ(0, n.getOut());
}

GTEST_TEST(Hack, Ram8)
{
    Ram8 n;

    for (const int* reg : Ram8TestData)
    {
        const bool    time = reg[0] != 0;
        const int16_t in   = (int16_t)reg[1];
        const bool    load = reg[2] != 0;
        const uint8_t addr = reg[3];
        const int16_t exp  = (int16_t)reg[4];

        n.setClock(time);
        n.setIn(in);
        n.setLoad(load != 0);
        n.setAddress(addr);

        n.print();

        int16_t out = (int16_t)n.getOut();
        EXPECT_EQ(exp, out);
    }
}

GTEST_TEST(Hack, Ram64)
{
    Ram64 n;

    for (const int* ram : Ram64TestData)
    {
        const bool    clock = ram[0] != 0;
        const int16_t inp   = (int16_t)ram[1];
        const bool    load  = ram[2] != 0;
        const uint8_t addr  = (uint8_t)ram[3];
        const int16_t exp   = (int16_t)ram[4];

        n.setIn(inp);
        n.setLoad(load);
        n.setAddress(addr);
        n.setClock(clock);

        n.print();

        int16_t out = (int16_t)n.getOut();
        EXPECT_EQ(exp, out);
    }
}

GTEST_TEST(Hack, Ram512)
{
    Ram512 n;

    for (const int* ram : Ram512TestData)
    {
        const bool     clock = ram[0] != 0;
        const int16_t  inp   = (int16_t)ram[1];
        const bool     load  = ram[2] != 0;
        const uint16_t addr  = (uint16_t)ram[3];
        const int16_t  exp   = (int16_t)ram[4];

        n.setIn(inp);
        n.setLoad(load);
        n.setAddress(addr);
        n.setClock(clock);

        ///n.print();

        int16_t out = (int16_t)n.getOut();
        EXPECT_EQ(exp, out);
    }
}

#if 0

GTEST_TEST(Hack, Ram4k)
{
    Ram4k n;

    for (const int* ram : Ram512TestData)
    {
        const bool     clock = ram[0] != 0;
        const int16_t  inp   = (int16_t)ram[1];
        const bool     load  = ram[2] != 0;
        const uint16_t addr  = (uint16_t)ram[3];
        const int16_t  exp   = (int16_t)ram[4];

        n.setIn(inp);
        n.setLoad(load);
        n.setAddress(addr);
        n.setClock(clock);

        n.print();

        int16_t out = (int16_t)n.getOut();
        EXPECT_EQ(exp, out);
    }
}

GTEST_TEST(Hack, Ram16k)
{
    Ram16k n;

    for (const int* ram : Ram512TestData)
    {
        const bool     clock = ram[0] != 0;
        const int16_t  inp   = (int16_t)ram[1];
        const bool     load  = ram[2] != 0;
        const uint16_t addr  = (uint16_t)ram[3];
        const int16_t  exp   = (int16_t)ram[4];

        n.setIn(inp);
        n.setLoad(load);
        n.setAddress(addr);
        n.setClock(clock);

        n.print();

        int16_t out = (int16_t)n.getOut();
        EXPECT_EQ(exp, out);
    }
}

#endif

GTEST_TEST(Hack, ProgramCounter)
{
    ProgramCounter n;

    for (const int* pc : ProgramCountertTestData)
    {
        const bool    clock = pc[0] != 0;
        const int16_t inp   = (int16_t)pc[1];
        const bool    reset = pc[2] != 0;
        const bool    load  = pc[3] != 0;
        const bool    inc   = pc[4] != 0;
        const int16_t exp   = (int16_t)pc[5];

        n.setIn(inp);

        uint8_t flags = 0;
        if (reset)
            flags |= PCF_RESET;
        if (load)
            flags |= PCF_LOAD;
        if (inc)
            flags |= PCF_INC;

        n.setFlags(flags);
        n.setClock(clock);

        n.print();
        int16_t out = (int16_t)n.getOut();
        EXPECT_EQ(exp, out);
    }
}

void executeInstruction(Cpu& c, const uint16_t& inst)
{
    c.setClock(Timer::tick());
    c.setInstruction(inst);

    const uint16_t memOut           = c.getOut();
    const bool     memLoad          = c.getWrite();
    const uint16_t memAddress       = c.getAddress();
    const uint16_t fetchInstruction = c.getNext();

    Hack::OutputStringStream oss;
    oss << "memOut     : " << memOut << std::endl;
    oss << "memLoad    : " << (memLoad ? "yes" : "no") << std::endl;
    oss << "memAddress : " << memAddress << std::endl;
    oss << "fetch      : " << fetchInstruction << std::endl;

    Hack::Console::writeLine(oss);
}

GTEST_TEST(Hack, CPU_AInstruction)
{
    Cpu n;
    // ------------------------ Codes -----------------------
    //  i |  x   x |  a |  c  c  c  c c  c | d d d | j  j  j
    // 15 | 14  13 | 12 | 11 10  9  8 7  6 | 5 4 3 | 2  1  0
    // ac                 zx nx zy ny f no          gt eq lt
    // ------------------------------------------------------
    Timer::reset();
    executeInstruction(n, 0b0011000000111001);
    executeInstruction(n, 0b0011000000111001);
}

GTEST_TEST(Hack, CPU)
{
    Cpu n;
    int i = 0;

    for (const int* cpu : CpuTestData)
    {
        const bool     clock = cpu[0] != 0;
        const int16_t  in    = (int16_t)cpu[1];
        const uint16_t ins   = (uint16_t)cpu[2];
        const bool     reset = cpu[3] != 0;
        const int16_t  out   = (int16_t)cpu[4];
        const bool     write = cpu[5] != 0;
        const uint16_t addr  = (uint16_t)cpu[6];
        const uint16_t pc    = (uint16_t)cpu[7];
        const int16_t  dre   = (int16_t)cpu[8];

        n.setClock(clock);
        n.setReset(reset);
        n.setInMemory(in);
        n.setInstruction(ins);

        if (write)
        {
            EXPECT_EQ(out, (int16_t)n.getOut());
            EXPECT_EQ(addr, n.getAddress());
            EXPECT_EQ(write, n.getWrite());
        }

        EXPECT_EQ(pc, n.getNext());
        EXPECT_EQ(dre, (int16_t)n.getDRegister());

        ++i;
    }
}

GTEST_TEST(Hack, CPU_Add)
{
    Cpu n;
    executeInstruction(n, 0b0000000000000010);
    executeInstruction(n, 0b1110110000010000);
    executeInstruction(n, 0b0000000000000011);
    executeInstruction(n, 0b1110000010010000);
    executeInstruction(n, 0b0000000000000000);
    executeInstruction(n, 0b1110001100001000);
}
