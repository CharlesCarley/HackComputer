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
#include "VirtualMachine/Emitter.h"
#include <iomanip>
#include "Utils/Char.h"
#include "VirtualMachine/Constants.h"

namespace Hack::VirtualMachine
{
    class CodeStream
    {
    private:
        OStream* _s;

    public:
        explicit CodeStream(OStream* os) :
            _s(os)
        {
        }

        template <typename... Args>
        void write(Args&&... args) const
        {
            OutputStringStream oss;
            ((oss << std::forward<Args>(args)), ...);
            *_s << oss.str() << std::endl;
        }

        void atAddressOf(const String& value) const
        {
            write('@', value);
        }

        void atAddressOf(const int& index) const
        {
            write('@', index);
        }

        void popStackFrame(const int& frame, const int& x0, const int& idx) const
        {
            atAddressOf(frame);
            copyMIntoD();
            subXFromD(idx);
            dereferenceD();
            moveMIntoD();
            moveDIntoX(x0);
        }

        void label(const String& str) const
        {
            write('(', str, ')');
        }

        void jumpToAddressIn(const int& addr) const
        {
            atAddressOf(addr);
            moveMIntoA();
        }

        void jumpToRomAddress(const String& addr) const
        {
            atAddressOf(addr);
            write("D=A;JMP");
        }

        void jumpToRomAddress(const int& addr) const
        {
            atAddressOf(addr);
            write("D=A;JMP");
        }
#ifdef ZERO_M

        void clearSwap() const
        {
            atAddressOf(SW0);
            setM(false);
            atAddressOf(SW1);
            setM(false);
            atAddressOf(SW2);
            setM(false);
        }
#endif

        void increment() const
        {
            atAddressOf(STP);
            write("M=M+1");
        }

        void decrementA() const
        {
            write("A=A-1");
        }

        void decrement() const
        {
            atAddressOf(STP);
            write("M=M-1");
#ifdef ZERO_M
            atAddressOf(STP);
            write("A=M");
            write("M=0");
#endif
        }

        void incrementAndJump() const
        {
            atAddressOf(STP);
            write("M=M+1 A=M-1");
        }

        void dereferenceOffset(int x0, int offs) const
        {
            //  A= RAM[x0] + offs
            atAddressOf(offs);
            write("D=A");
            atAddressOf(x0);
            write("A=D+M");
        }

        void offsetTo(const int x0, const int offs) const
        {
            atAddressOf(offs);
            write("D=A");
            atAddressOf(x0);
            write("AD=D+A");
        }

        void moveMIntoD() const
        {
            write("D=M");
#ifdef ZERO_M
            write("M=0");  // DEBUG
#endif
        }

        void copyMIntoD() const
        {
            write("D=M");
        }

        void moveDIntoX(const int x0) const
        {
            atAddressOf(x0);
            write("M=D");
        }

        void moveDIntoX(const String& x0) const
        {
            atAddressOf(x0);
            moveDIntoM();
        }

        void moveDIntoM() const
        {
            write("M=D");
        }

        void moveAIntoD() const
        {
            write("D=A");
        }

        void move(const int x0, const int v) const
        {
            atAddressOf(v);
            moveAIntoD();
            atAddressOf(x0);
            moveDIntoM();
        }

        void moveMIntoA() const
        {
            write("A=M");
        }

        void moveDIntoA() const
        {
            write("A=D");
        }

        void addDmIntoM() const
        {
            write("M=D+M");
        }

        void subMdIntoM() const
        {
            write("M=M-D");
        }

        void subDmIntoD() const
        {
            write("D=M-D");
        }

        void andDmIntoM() const
        {
            write("M=D&M");
        }

        void orDmIntoM() const
        {
            write("M=D|M");
        }

        void notMIntoM() const
        {
            write("M=!M");
        }

        void negMIntoM() const
        {
            write("M=-M");
        }
        void subMdIntoD() const
        {
            write("D=M-D");
        }

        void addXToD(const int& x0) const
        {
            atAddressOf(x0);
            write("D=D+A");
        }

        void subXFromD(const int& x0) const
        {
            atAddressOf(x0);
            write("D=D-A");
        }

        void push(const int v) const
        {
            atAddressOf(v);
            moveAIntoD();
            increment();
            write("A=M-1 M=D");
        }

        void pushD() const
        {
            increment();
            write("A=M-1 M=D");
        }

        void setM(const bool val) const
        {
            if (val)
                write("M=-1");
            else
                write("M=0");
        }

        void setD(const bool val) const
        {
            if (val)
                write("D=-1");
            else
                write("D=0");
        }

        void jumpStackTop() const
        {
            atAddressOf(STP);
            write("A=M-1");
        }

        void jumpIfGreater(const String& label) const
        {
            write('@', label);
            write("D;JGT");
        }

        void jumpTo(const String& label) const
        {
            write('@', label);
            write("0;JMP");
        }

        void jumpIfLess(const String& label) const
        {
            write('@', label);
            write("D;JLT");
        }

        void jumpIfEquals(const String& label) const
        {
            write('@', label);
            write("D;JEQ");
        }

        void jumpIfNotEquals(const String& label) const
        {
            write('@', label);
            write("D;JNE");
        }

        void copyMIntoDAt(const int& x0) const
        {
            atAddressOf(x0);
            copyMIntoD();
        }

        void moveMIntoDAt(const int& x0) const
        {
            atAddressOf(x0);
            moveMIntoD();
        }

        void dereferenceD() const
        {
            write("A=D");
        }

        void dereferenceM() const
        {
            write("A=M");
        }

        void jumpToD() const
        {
            write("A=D;JMP");
        }

        void popSegment(const int& seg0, const int& idx) const
        {
            dereferenceOffset(seg0, idx);
            moveAIntoD();
            moveDIntoX(SW0);
            jumpStackTop();
            moveMIntoD();
            jumpToAddressIn(SW0);
            moveDIntoM();
            decrement();

            atAddressOf(SW0);
            setM(false);
        }
    };

    Emitter::Emitter() :
        _cmp(0)
    {
    }

    void Emitter::clear()
    {
        _stream.str("");
    }

    void Emitter::getJumpLabels(String& valTrue,
                                String& valDone)
    {
        ++_cmp;
        String v;
        Char::toHexString(v, (uint16_t)_cmp);
        valTrue = "L54" + v;
        valDone = "L44" + v;
    }

    void Emitter::setRam(const int index, const int value)
    {
        const CodeStream w(&_stream);
        w.move(index, value);
    }

    void Emitter::initialize()
    {
    }

    void Emitter::popStackInto(const CodeStream& w,
                               const int&        idx,
                               const int32_t&    dest,
                               const int32_t&    swap)
    {
        w.jumpStackTop();
        w.moveMIntoD();
        w.moveDIntoX(swap);
        w.dereferenceOffset(dest, idx);
        w.moveMIntoD();
        w.jumpToAddressIn(swap);
        w.moveDIntoM();
        w.decrement();
#ifdef ZERO_M
        w.clearSwap();
#endif
    }

    void Emitter::pushConstant(const int& idx)
    {
        const CodeStream w(&_stream);
        w.push(idx);
    }

    void Emitter::pushLocal(const int& idx)
    {
        const CodeStream w(&_stream);
        w.dereferenceOffset(LCL, idx);
        w.copyMIntoD();
        w.pushD();
    }

    void Emitter::pushThis(const int& idx)
    {
        const CodeStream w(&_stream);
        w.dereferenceOffset(THS, idx);
        w.copyMIntoD();
        w.pushD();
    }

    void Emitter::pushThat(const int& idx)
    {
        const CodeStream w(&_stream);
        w.dereferenceOffset(THT, idx);
        w.copyMIntoD();
        w.pushD();
    }

    void Emitter::pushTemp(const int& idx)
    {
        const CodeStream w(&_stream);
        w.offsetTo(TMP, idx);
        w.moveMIntoD();  // Note: move not copy
        w.pushD();
    }

    void Emitter::pushArgument(const int& idx)
    {
        const CodeStream w(&_stream);
        w.dereferenceOffset(ARG, idx);
        w.copyMIntoD();
        w.pushD();
    }

    void Emitter::pushPointer(const int& idx)
    {
        const CodeStream w(&_stream);
        w.offsetTo(THS, idx);
        w.copyMIntoD();
        w.pushD();
    }

    void Emitter::pushStatic(const String& context, const int& idx)
    {
        const String     loc = StringCombine(context, '.', idx);
        const CodeStream w(&_stream);

        w.atAddressOf(loc);
        w.copyMIntoD();
        w.incrementAndJump();
        w.moveDIntoM();
    }

    void Emitter::popLocal(const int& idx)
    {
        const CodeStream w(&_stream);
        w.popSegment(LCL, idx);
    }

    void Emitter::popArgument(const int& idx)
    {
        const CodeStream w(&_stream);
        w.popSegment(ARG, idx);
    }

    void Emitter::popStatic(const String& context, const int& idx)
    {
        const String staticLabel = StringCombine(context, '.', idx);

        const CodeStream w(&_stream);

        w.jumpStackTop();
        w.moveMIntoD();
        w.moveDIntoX(staticLabel);
        w.decrement();
    }

    void Emitter::popThis(const int& idx)
    {
        const CodeStream w(&_stream);
        w.popSegment(THS, idx);
    }

    void Emitter::popThat(const int& idx)
    {
        const CodeStream w(&_stream);
        w.popSegment(THT, idx);
    }

    void Emitter::popTemp(const int& idx)
    {
        if (idx > 7)
        {
            throw InputException("pop temp index (", idx,
                                 ") out of bounds. "
                                 "expected [0-7]");
        }

        const CodeStream w(&_stream);
        w.offsetTo(TMP, idx);
        w.moveDIntoX(SW0);
        w.jumpStackTop();
        w.moveMIntoD();
        w.jumpToAddressIn(SW0);
        w.moveDIntoM();
        w.decrement();
#ifdef ZERO_M
        w.clearSwap();
#endif
    }

    void Emitter::popPointer(const int& idx)
    {
        const CodeStream w(&_stream);
        w.offsetTo(THS, idx);
        w.moveDIntoX(SW0);
        w.jumpStackTop();
        w.moveMIntoD();
        w.jumpToAddressIn(SW0);
        w.moveDIntoM();
        w.decrement();
#ifdef ZERO_M
        w.clearSwap();
#endif
    }

    void Emitter::writeOr()
    {
        const CodeStream w(&_stream);
        w.jumpStackTop();
        w.moveMIntoD();
        w.decrementA();
        w.orDmIntoM();
        w.decrement();
    }

    void Emitter::writeAnd()
    {
        const CodeStream w(&_stream);
        w.jumpStackTop();
        w.moveMIntoD();
        w.decrementA();
        w.andDmIntoM();
        w.decrement();
    }

    void Emitter::writeSub()
    {
        const CodeStream w(&_stream);
        w.jumpStackTop();
        w.moveMIntoD();
        w.decrementA();
        w.subMdIntoM();
        w.decrement();
    }

    void Emitter::writeAdd()
    {
        const CodeStream w(&_stream);
        w.jumpStackTop();
        w.moveMIntoD();
        w.decrementA();
        w.addDmIntoM();
        w.decrement();
    }

    void Emitter::writeNot()
    {
        const CodeStream w(&_stream);
        w.jumpStackTop();
        w.notMIntoM();
    }

    void Emitter::writeNeg()
    {
        const CodeStream w(&_stream);
        w.jumpStackTop();
        w.negMIntoM();
    }

    void Emitter::writeEq()
    {
        String ifTrue, whenDone;
        getJumpLabels(ifTrue, whenDone);

        const CodeStream w(&_stream);

        w.jumpStackTop();
        w.copyMIntoD();
        w.decrementA();
        w.subMdIntoD();
        w.jumpIfEquals(ifTrue);
        w.setD(false);
        w.jumpTo(whenDone);
        w.label(ifTrue);
        w.setD(true);
        w.label(whenDone);
        w.incrementAndJump();
        w.moveDIntoM();
    }

    void Emitter::writeLt()
    {
        String ifTrue, whenDone;
        getJumpLabels(ifTrue, whenDone);

        const CodeStream w(&_stream);
        w.jumpStackTop();
        w.copyMIntoD();
        w.decrementA();
        w.subMdIntoD();
        w.jumpIfLess(ifTrue);
        w.setD(false);
        w.jumpTo(whenDone);
        w.label(ifTrue);
        w.setD(true);
        w.label(whenDone);
        w.incrementAndJump();
        w.moveDIntoM();
    }

    void Emitter::writeGt()
    {
        String ifTrue, whenDone;
        getJumpLabels(ifTrue, whenDone);

        const CodeStream w(&_stream);
        w.jumpStackTop();
        w.copyMIntoD();
        w.decrementA();
        w.subMdIntoD();
        w.jumpIfGreater(ifTrue);
        w.setD(false);
        w.jumpTo(whenDone);
        w.label(ifTrue);
        w.setD(true);
        w.label(whenDone);
        w.incrementAndJump();
        w.moveDIntoM();
    }

    void Emitter::writeReset()
    {
        const CodeStream w(&_stream);
        w.jumpToRomAddress(32766);
    }

    void Emitter::writeHalt()
    {
        const String     halt = StringCombine("L.halt.", (size_t)this);
        const CodeStream w(&_stream);
        w.label(halt);
        w.jumpToRomAddress(halt);
    }

    void Emitter::writGoto(const String& value)
    {
        const CodeStream w(&_stream);
        w.jumpToRomAddress(value);
    }

    void Emitter::writIfGoto(const String& value)
    {
        const CodeStream w(&_stream);
        w.jumpStackTop();
        w.moveMIntoD();
        w.decrement();
        w.decrement();
        w.jumpIfNotEquals(value);
    }

    void Emitter::writeLabel(const String& value)
    {
        const CodeStream w(&_stream);
        w.label(value);
    }

    void Emitter::writeFunction(const String& name, const int& args)
    {
        const CodeStream w(&_stream);

        _functions.push(name);

        const uint16_t n = (uint16_t)args;
        w.label(name);

        for (uint16_t i = 0; i < n; ++i)
        {
            w.dereferenceOffset(LCL, i);
            w.setM(false);
        }
    }

    void Emitter::writeCall(const String& name, const int& args)
    {
        const CodeStream w(&_stream);

        const String retAddr = StringCombine("R.", name, '.', _cmp++, (size_t)this);

        w.atAddressOf(STP);
        w.copyMIntoD();
        w.pushD();  // save the stack  

        // Push the segment addresses.

        w.atAddressOf(retAddr);
        w.moveAIntoD();
        w.pushD();

        w.atAddressOf(LCL);
        w.copyMIntoD();
        w.pushD();

        w.atAddressOf(ARG);
        w.copyMIntoD();
        w.pushD();

        w.atAddressOf(THS);
        w.copyMIntoD();
        w.pushD();

        w.atAddressOf(THT);
        w.copyMIntoD();
        w.pushD();

        // update the new ARG
        w.atAddressOf(args);
        w.moveAIntoD();
        w.addXToD(5);
        w.atAddressOf(STP);
        w.subDmIntoD();
        w.atAddressOf(ARG);
        w.moveDIntoM();

        // Move the current stack address into the LCL address.
        w.copyMIntoDAt(STP);
        w.subXFromD(args);
        w.atAddressOf(LCL);
        w.moveDIntoM();
        w.jumpTo(name);

        // Write the return position.
        w.label(retAddr);
    }

    void Emitter::writeReturn()
    {
        const CodeStream w(&_stream);

        w.copyMIntoDAt(LCL);
        w.moveDIntoX(SW0);  // Save the Frame

        // extract the return code
        w.jumpStackTop();
        w.moveMIntoD();
        w.moveDIntoX(SW1);

        w.popStackFrame(SW0, THT, 1);
        w.popStackFrame(SW0, THS, 2);
        w.popStackFrame(SW0, ARG, 3);
        w.popStackFrame(SW0, LCL, 4);

        // return address
        w.copyMIntoDAt(SW0);
        w.subXFromD(5);
        w.dereferenceD();
        w.moveMIntoD();  // move the return address
        w.moveDIntoX(SW2);

        w.moveMIntoDAt(SW0);  // Final move
        w.subXFromD(6);
        w.dereferenceD();
        w.moveMIntoD();
        w.moveDIntoX(STP);

        w.atAddressOf(SW1);
        w.moveMIntoD();
        w.pushD();

        w.atAddressOf(SW2);
        w.moveMIntoD();
        w.jumpToD();
    }

}  // namespace Hack::VirtualMachine
