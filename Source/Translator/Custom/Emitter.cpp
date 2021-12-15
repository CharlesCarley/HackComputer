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
#include "Translator/Custom/Emitter.h"
#include <iomanip>
#include "Utils/Char.h"
#include "Translator/Custom/Constants.h"

#define lft(x) std::left, std::setw(x)
#define rgt(x) std::right, std::setw(x), ' '
#define P lft(8)
#define R rgt(9)

namespace Hack::ToyVm
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

    void Emitter::getJumpLabels(String& valTrue,
                                String& valFalse,
                                String& valDone)
    {
        ++_cmp;
        String v;
        Char::toHexString(v, (uint16_t)_cmp);
        valTrue  = "L54" + v;
        valFalse = "L46" + v;
        valDone  = "L44" + v;
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

        // clang-format off
        w.write("@", P, idx, "D=A");
        w.incrementStack();
        w.write(R,           "M=D");
        // clang-format on
    }

    void Emitter::pushLocal(const String& idx)
    {
        const CodeStream w(&_stream);
        pushIntoStack(w, idx, LCL);
    }

    void Emitter::pushArgument(const String& idx)
    {
        const CodeStream w(&_stream);
        pushIntoStack(w, idx, ARG);
    }

    void Emitter::pushThis(const String& idx)
    {
        const CodeStream w(&_stream);
        pushIntoStack(w, idx, THS);
    }

    void Emitter::pushThat(const String& idx)
    {
        const CodeStream w(&_stream);
        pushIntoStack(w, idx, THT);
    }

    void Emitter::pushTemp(const String& idx)
    {
        const CodeStream w(&_stream);

        // clang-format off
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
        w.write('@', P, idx,   "D=A");
        w.write("@", P, THS,   "A=D+A");
        w.write(R,             "D=M");
        w.incrementStack();
        w.write(R,             "M=D");
        // clang-format on
    }

    void Emitter::pushStatic(const String& context, const String& idx)
    {
        const String loc = context + "." + idx;

        const CodeStream w(&_stream);

        // clang-format off
        w.write('@', P, loc);
        w.write(R,             "D=M");
        w.incrementStack();
        w.write(R,             "M=D");
        // clang-format on
    }

    void Emitter::popLocal(const String& idx)
    {
        const CodeStream w(&_stream);
        popStackInto(w, idx, LCL, SW2);
    }

    void Emitter::popArgument(const String& idx)
    {
        const CodeStream w(&_stream);
        popStackInto(w, idx, ARG, SW2);
    }

    void Emitter::popStatic(const String& context, const String& idx)
    {
        String loc = context + "." + idx;

        const CodeStream w(&_stream);

        // clang-format off
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
        const CodeStream w(&_stream);
        popStackInto(w, idx, THS, SW2);
    }

    void Emitter::popThat(const String& idx)
    {
        const CodeStream w(&_stream);
        popStackInto(w, idx, THT, SW2);
    }

    void Emitter::popTemp(const String& idx)
    {
        const CodeStream w(&_stream);

        // clang-format off
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
        const CodeStream w(&_stream);

        // clang-format off
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
        const CodeStream w(&_stream);

        // clang-format off
        w.decrementStack();
        w.write(R,            "D=M");
        w.write(R,            "A=A-1");
        w.write(R,            "M=D|M");
        // clang-format on
    }

    void Emitter::writeAnd()
    {
        const CodeStream w(&_stream);

        // clang-format off
        w.decrementStack();
        w.write(R,            "D=M");
        w.write(R,            "A=A-1");
        w.write(R,            "M=D&M");
        // clang-format on
    }

    void Emitter::writeSub()
    {
        const CodeStream w(&_stream);

        // clang-format off
        w.decrementStack();
        w.write(R,            "D=M");
        w.write(R,            "A=A-1");
        w.write(R,            "M=M-D");
        // clang-format on
    }

    void Emitter::writeAdd()
    {
        const CodeStream w(&_stream);

        // clang-format off
        w.decrementStack();
        w.write(R,            "D=M");
        w.write(R,            "A=A-1");
        w.write(R,            "M=D+M");
        // clang-format on
    }

    void Emitter::writeNot()
    {
        const CodeStream w(&_stream);

        // clang-format off
        w.write('@', P, STP,  "A=M");
        w.write(R,            "M=!M");
        // clang-format on
    }

    void Emitter::writeNeg()
    {
        const CodeStream w(&_stream);

        // clang-format off
        w.write('@', P, STP, "A=M");
        w.write(R,           "M=-M");
        // clang-format on
    }

    void Emitter::writeEq()
    {
        String t, f, d;
        getJumpLabels(t, f, d);
        const CodeStream w(&_stream);

        // clang-format off
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
        getJumpLabels(t, f, d);
        const CodeStream w(&_stream);

        // clang-format off
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
        getJumpLabels(t, f, d);

        const CodeStream w(&_stream);

        // clang-format off
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

    
    void Emitter::writeReset()
    {
        const CodeStream w(&_stream);
        w.write('@', P, 32767, "D=A;JMP");
    }

    void Emitter::writeHalt()
    {
        const String halt = "L.halt" + Char::toHexString((uint16_t)++_cmp);
        writeLabel(halt);
        writGoto(halt);
    }


    void Emitter::writGoto(const String& value)
    {
        const CodeStream w(&_stream);
        w.write('@', P, value, "D=A;JMP");
    }

    void Emitter::writIfGoto(const String& value)
    {
        const CodeStream w(&_stream);
        w.write('@', P, value, "D;JEQ");
    }

    void Emitter::writeLabel(const String& value)
    {
        const CodeStream w(&_stream);
        w.write('(', value, ')');
    }

    void Emitter::writeFunction(const String& name, const String& args)
    {
        const CodeStream w(&_stream);

        _functions.push(name);

        const uint16_t n = Char::toUint16(args);

        // clang-format off
        w.write('(', name, ')');
        for (uint16_t i=0; i<n; ++i)
        {
            w.write('@', P, LCL,  "M=M+1");
            w.write(R,            "A=M-1");
            w.write(R,            "M=0");
        }
        // clang-format on
    }

    void Emitter::writeCall(const String& name, const String& args)
    {
        const CodeStream w(&_stream);

        const String retAddr = "LR." + name;

        // clang-format off

        // ARG = SP-N-5
        w.write('@', P, STP,    "D=M");
        w.write('@', P, SW2,    "M=D");
        w.write('@', P, args,   "D=A");
        w.write('@', P, SW2,    "M=M-D");
        
        // push the return address
        

        w.write('@', P, retAddr, "D=A");
        w.incrementStack();
        w.write(R,               "M=D");

        // push LCL
        w.write('@', P, LCL,     "D=M");
        w.incrementStack();
        w.write(R,               "M=D");

        // push ARG
        w.write('@', P, ARG,     "D=M");
        w.incrementStack();
        w.write(R,               "M=D");

        // push THIS
        w.write('@', P, THS,     "D=M");
        w.incrementStack();
        w.write(R,               "M=D");


        // push THAT
        w.write('@', P, THT,     "D=M");
        w.incrementStack();
        w.write(R,               "M=D");

        w.write('@', P, SW2,     "D=M");
        w.write('@', P, ARG,     "M=D");
        w.write('@', P, STP,     "D=M");
        w.write('@', P, LCL,     "M=D");

        w.write('@', P, name,    "D=A;JMP");
        w.write('(', retAddr, ')');

        w.write('@', P, SW1,     "D=M");
        w.decrementStack();
        w.write(R,               "A=A-1");
        w.write(R,               "M=D");
        
        // clang-format on
    }

    void Emitter::writeReturn()
    {
        const CodeStream w(&_stream);

        // clang-format off
        w.write('@', P, LCL,    "D=M");
        w.write('@', P, SW2,    "M=D");
        w.decrementStack();
        w.write(R,              "D=M");
        w.write('@', P, SW1,    "M=D");
        

        w.decrementStack();
        w.write(R,              "D=M");
        w.write('@', P, THT,    "M=D");

        w.decrementStack();
        w.write(R,              "D=M");
        w.write('@', P, THS,    "M=D");

        w.decrementStack();
        w.write(R,              "D=M");
        w.write('@', P, ARG,    "M=D");

        w.decrementStack();
        w.write(R,              "D=M");
        w.write('@', P, LCL,    "M=D");

        w.decrementStack();
        w.write(R,              "D=M");
        w.write(R,              "A=D;JMP");
        // clang-format on
    }

}  // namespace Hack::VirtualMachine
