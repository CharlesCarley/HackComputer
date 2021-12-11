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

#define lft(x) std::left, std::setw(x)
#define rgt(x) std::right, std::setw(x), ' '
#define P lft(8)
#define R rgt(9)

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

        void incrementStack() const
        {
            // clang-format off
            write('@', P, STP, "M=M+1");
            write(R,           "A=M-1");
            // clang-format on
        }

        void decrementStack() const
        {
            // clang-format off
            write('@', P, STP, "M=M-1");
            write(R,           "A=M");
            // clang-format on
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

    void Emitter::getCmpLabels(String& valTrue, String& valFalse, String& valDone)
    {
        ++_cmp;
        valTrue  = "true" + Char::toString(_cmp);
        valFalse = "false" + Char::toString(_cmp);
        valDone = "done" + Char::toString(_cmp);
    }

    void Emitter::setRam(const int index, const int value)
    {
        const CodeStream w(&_stream);
        w.write('@', P, value, "D=A");
        w.write('@', P, index, "M=D");
    }

    void Emitter::popStackInto(const CodeStream& w,
                               const String&     idx,
                               const int32_t&    dest,
                               const int32_t&    swap)
    {
        // assumes the correct destination index is in RAM[dest]
        // clang-format off
        w.write('@', P, idx,   "D=A");
        w.write('@', P, dest,  "D=D+M");
        w.write('@', P, swap,  "M=D");

        w.decrementStack();

        w.write(R,             "D=M");
        w.write('@', P, swap,  "A=M");
        w.write(R,             "M=D");
        // clang-format on
    }

    void Emitter::pushIntoStack(const CodeStream& w,
                                const String&     idx,
                                const int32_t&    dest)
    {
        // clang-format off
        w.write('@', P, idx,   "D=A");
        w.write("@", P, dest,  "A=D+M");
        w.write(R,             "D=M");
        w.incrementStack();
        w.write(R,             "M=D");
        // clang-format on
    }

    void Emitter::pushConstant(const String& idx)
    {
        const CodeStream w(&_stream);
        w.write("// push constant ", idx);
        w.write("@", P, idx, "D=A");
        w.incrementStack();
        w.write(R, "M=D");
    }

    void Emitter::pushLocal(const String& idx)
    {
        const CodeStream w(&_stream);
        w.write("// push local ", idx);
        pushIntoStack(w, idx, LCL);
    }

    void Emitter::pushArgument(const String& idx)
    {
        const CodeStream w(&_stream);
        w.write("// push argument ", idx);
        pushIntoStack(w, idx, ARG);
    }

    void Emitter::pushThis(const String& idx)
    {
        const CodeStream w(&_stream);
        w.write("// push this ", idx);
        pushIntoStack(w, idx, THS);
    }

    void Emitter::pushThat(const String& idx)
    {
        const CodeStream w(&_stream);
        w.write("// push that ", idx);
        pushIntoStack(w, idx, THT);
    }

    void Emitter::pushTemp(const String& idx)
    {
        const CodeStream w(&_stream);
        // clang-format off
        w.write("// push temp ", idx);
        w.write('@', P, idx,   "D=A");
        w.write("@", P, TMP,   "A=D+A");
        w.write(R,             "D=M");
        w.incrementStack();
        w.write(R,             "M=D");
        // clang-format on
    }

    void Emitter::pushPointer(const String& idx)
    {
        const CodeStream w(&_stream);
        // clang-format off
        w.write("// push pointer", idx);
        w.write('@', P, idx,   "D=A");
        w.write("@", P, THS,   "A=D+A");
        w.write(R,             "D=M");
        w.incrementStack();
        w.write(R,             "M=D");
        // clang-format on
    }

    void Emitter::pushStatic(const String& context, const String& idx)
    {
        String loc = context + "." + idx;

        const CodeStream w(&_stream);
        // clang-format off
        w.write("// push static", idx);
        w.write('@', P, loc);
        w.write(R,             "D=M");
        w.incrementStack();
        w.write(R,             "M=D");
        // clang-format on
    }

    void Emitter::popLocal(const String& idx)
    {
        // clang-format off
        const CodeStream w(&_stream);
        w.write("// pop local ", idx);
        popStackInto(w, idx, LCL, SW2);
        // clang-format on
    }

    void Emitter::popArgument(const String& idx)
    {
        // clang-format off
        const CodeStream w(&_stream);
        w.write("// pop argument ", idx);
        popStackInto(w, idx, ARG, SW2);
        // clang-format on
    }

    void Emitter::popStatic(const String& context, const String& idx)
    {
        String loc = context + "." + idx;

        // clang-format off
        const CodeStream w(&_stream);
        // clang-format off
        w.write("// pop static ", idx);
        w.write('@', P, loc);
        w.write(R,             "D=A");
        w.write('@', P, SW0,   "M=D");
        w.decrementStack();
        w.write(R,             "D=M");
        w.write('@', P, SW0,   "A=M");
        w.write(R,             "M=D");
        // clang-format on
    }

    void Emitter::popThis(const String& idx)
    {
        // clang-format off
        const CodeStream w(&_stream);
        w.write("// pop this ", idx);
        popStackInto(w, idx, THS, SW2);
        // clang-format on
    }

    void Emitter::popThat(const String& idx)
    {
        // clang-format off
        const CodeStream w(&_stream);
        w.write("// pop that ", idx);
        popStackInto(w, idx, THT, SW2);
        // clang-format on
    }

    void Emitter::popTemp(const String& idx)
    {
        // clang-format off
        const CodeStream w(&_stream);
        w.write("// pop temp ", idx);
        w.write('@', P, idx,   "D=A");
        w.write('@', P, TMP,   "D=D+A");
        w.write('@', P, SW2,   "M=D");
        w.decrementStack();
        w.write(R,             "D=M");
        w.write('@', P, SW2,   "A=M");
        w.write(R,             "M=D");
        // clang-format on
    }

    void Emitter::popPointer(const String& idx)
    {
        // clang-format off
        const CodeStream w(&_stream);
        w.write("// pop pointer ", idx);
        w.write('@', P, idx,   "D=A");
        w.write('@', P, THS,   "D=D+A");
        w.write('@', P, SW2,   "M=D");
        w.decrementStack();
        w.write(R,             "D=M");
        w.write('@', P, SW2,   "A=M");
        w.write(R,             "M=D");
        // clang-format on
    }

    void Emitter::writeOr()
    {
        // clang-format off
        const CodeStream w(&_stream);
        w.write("// or ");
        w.decrementStack();
        w.write(R,            "D=M");
        w.write(R,            "A=A-1");
        w.write(R,            "M=D|M");
        // clang-format on
    }

    void Emitter::writeAnd()
    {
        // clang-format off
        const CodeStream w(&_stream);
        w.write("// and ");
        w.decrementStack();
        w.write(R,            "D=M");
        w.write(R,            "A=A-1");
        w.write(R,            "M=D&M");
        // clang-format on
    }

    void Emitter::writeSub()
    {
        // clang-format off
        const CodeStream w(&_stream);
        w.write("// sub ");
        w.decrementStack();
        w.write(R,            "D=M");
        w.write(R,            "A=A-1");
        w.write(R,            "M=M-D");
        // clang-format on
    }

    void Emitter::writeAdd()
    {
        // clang-format off
        const CodeStream w(&_stream);
        w.write("// add ");
        w.decrementStack();
        w.write(R,            "D=M");
        w.write(R,            "A=A-1");
        w.write(R,            "M=D+M");
        // clang-format on
    }

    void Emitter::writeNot()
    {
        // clang-format off
        const CodeStream w(&_stream);
        w.write("// not ");
        w.write('@', P, STP, "A=M");
        w.write(R, "M=!M");
        // clang-format on
    }

    void Emitter::writeNeg()
    {
        const CodeStream w(&_stream);
        w.write("// neg ");
        w.write('@', P, STP, "A=M");
        w.write(R, "M=-M");
    }

    void Emitter::writeEq()
    {
        String t, f, d;
        getCmpLabels(t,f,d);


        // clang-format off
        const CodeStream w(&_stream);
        w.write("// eq ");
        w.decrementStack();
        w.write(R,           "D=M");
        w.write(R,           "A=A-1");
        w.write(R,           "D=M-D");
        w.write('@', P, f,   "D;JNE");
        w.write('(', t, ')');
        w.write(R,           "D=-1");
        w.write('@', P, d,   "0;JMP");
        w.write('(', f, ')');
        w.write(R,           "D=0");
        w.write('(', d, ')');
        w.write('@', P, STP, "A=M");
        w.write(R,           "M=D");
        // clang-format on
    }

    void Emitter::writeLt()
    {
        String t, f, d;
        getCmpLabels(t, f, d);
        // clang-format off
        const CodeStream w(&_stream);
        w.write("// lt ");
        w.decrementStack();
        w.write(R,            "D=M");
        w.write(R,            "A=A-1");
        w.write(R,            "D=M-D");
        w.write('@', P, f,    "D;JLT");
        w.write('(', t, ')');
        w.write(R,            "D=-1");
        w.write('@', P, d,    "0;JMP");
        w.write('(', f, ')');
        w.write(R,            "D=0");
        w.write('(', d, ')');
        w.write('@', P, STP,  "A=M");
        w.write(R,            "M=D");
        // clang-format on
    }

    void Emitter::writeGt()
    {
        String t, f, d;
        getCmpLabels(t, f, d);

        // clang-format off
        const CodeStream w(&_stream);
        w.write("// gt ");
        w.decrementStack();
        w.write(R,             "D=M");
        w.write(R,             "A=A-1");
        w.write(R,             "D=M-D");
        w.write('@', P, t,     "D;JGT");
        w.write('(', f, ')');
        w.write(R,             "D=-1");
        w.write('@', P, d,     "D;JMP");
        w.write('(', t, ')');
        w.write(R,             "D=0");
        w.write('(', d, ')');
        w.write('@', P, STP,   "A=M");
        w.write(R,             "M=D");
        // clang-format on
    }

    void Emitter::writGoto(const String& value)
    {
        const CodeStream w(&_stream);
        // clang-format off
        w.write("// goto ", value);
        w.write('@', P, value, "D=A;JMP");
        // clang-format on
    }

    void Emitter::writIfGoto(const String& value)
    {
        const CodeStream w(&_stream);
        w.write("// if-goto ", value);
        w.write('@', P, value, "D;JEQ");
    }

    void Emitter::writeLabel(const String& value)
    {
        // clang-format off
        const CodeStream w(&_stream);
        w.write('(', value, ')');
        // clang-format on
    }
}  // namespace Hack::VirtualMachine
