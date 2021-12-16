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
#include "Compiler/Analyzer/Emitter.h"
#include <iomanip>
#include "Compiler/Analyzer/Constants.h"
#include "Utils/Char.h"

#define LFT(x) std::left, std::setw(x)
#define RGT(x) std::right, std::setw(x), ' '
#define P LFT(20)
#define R RGT(21)

namespace Hack::Compiler::Analyzer
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
        w.write('@', P, value, "D=A");
        w.write('@', P, index, "M=D");
    }

    void Emitter::initialize()
    {
        const CodeStream w(&_stream);
        w.write('@', P, 256, "D=A");
        w.write('@', P, STP, "M=D");
        w.write('@', P, LCL, "M=D");
        w.write('@', P, ARG, "M=D");
        w.write('@', P, THS, "M=D");
        w.write('@', P, THT, "M=D");
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
        w.write('@', P, STP,  "A=M-1");
        w.write(R,            "M=!M");
        // clang-format on
    }

    void Emitter::writeNeg()
    {
        const CodeStream w(&_stream);
        // clang-format off
        w.write('@', P, STP,  "A=M-1");
        w.write(R,            "M=-M");
        // clang-format on
    }

    void Emitter::writeEq()
    {
        String t, d;
        getJumpLabels(t, d);
        const CodeStream w(&_stream);

        // clang-format off
        w.decrementStack();
        w.write(R,           "D=M");
        w.write(R,           "A=A-1");
        w.write(R,           "D=M-D");
        w.write('@', P, t,   "D;JEQ");
        w.write(R,           "D=0");
        w.write('@', P, d,   "0;JMP");
        w.write('(', t, ')');
        w.write(R,           "D=-1");
        w.write('(', d, ')');
        w.write('@', P, STP,  "A=M-1");
        w.write(R,            "M=D");
        // clang-format on
    }

    void Emitter::writeLt()
    {
        String t, d;
        getJumpLabels(t, d);
        const CodeStream w(&_stream);

        // clang-format off
        w.decrementStack();
        w.write(R,            "D=M");
        w.write(R,            "A=A-1");
        w.write(R,            "D=M-D");
        w.write('@', P, t,    "D;JLT");
        w.write(R,            "D=0");
        w.write('@', P, d,    "0;JMP");
        w.write('(', t, ')');
        w.write(R,            "D=-1");
        w.write('(', d, ')');
        w.write('@', P, STP,  "A=M-1");
        w.write(R,            "M=D");
        // clang-format on
    }

    void Emitter::writeGt()
    {
        String t, d;
        getJumpLabels(t, d);

        const CodeStream w(&_stream);

        // clang-format off
        w.decrementStack();
        w.write(R,             "D=M");
        w.write(R,             "A=A-1");
        w.write(R,             "D=M-D");
        w.write('@', P, t,     "D;JGT");
        w.write(R,             "D=0");
        w.write('@', P, d,     "0;JMP");
        w.write('(', t, ')');
        w.write(R,             "D=-1");
        w.write('(', d, ')');
        w.write('@', P, STP,   "A=M-1");
        w.write(R,             "M=D");
        // clang-format on
    }

    void Emitter::writeReset()
    {
        const CodeStream w(&_stream);
        w.write('@', P, 32765, "D=A;JMP");
    }

    void Emitter::writeHalt()
    {
        const String halt = "L.halt" + Char::toHexString((uint16_t)++_cmp);

        const CodeStream w(&_stream);
        w.write('(', halt, ')');
        w.write('@', P, halt, "D=A;JMP");
    }

    void Emitter::writGoto(const String& value)
    {
        const CodeStream w(&_stream);
        w.write('@', P, value);
        w.write(R, "D=A");
        w.write(R, "0;JMP");
    }

    void Emitter::writIfGoto(const String& value)
    {
        const CodeStream w(&_stream);
        w.decrementStack();
        w.write(R, "D=M");
        w.write('@', P, value);
        w.write(R, "D;JNE");
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
            w.write('@', P, i,    "D=A");
            w.write('@', P, LCL,  "A=D+M");
            w.write(R,            "M=0");
        }
        // clang-format on
    }

    void Emitter::writeCall(const String& name, const String& args)
    {
        const CodeStream w(&_stream);

        const String retAddr = "LR." + name + Char::toHexString((uint16_t)++_cmp);

        // Push the return address.
        w.write('@', P, retAddr);
        w.write(R,            "D=A");
        w.incrementStack();
        w.write(R,            "M=D");

        // Push the local segment address.
        w.write('@', P, LCL,  "D=M");
        w.incrementStack();
        w.write(R,            "M=D");

        // Push the argument segment address.
        w.write('@', P, ARG,  "D=M");
        w.incrementStack();
        w.write(R,            "M=D");

        // Push the this segment address
        w.write('@', P, THS,  "D=M");
        w.incrementStack();
        w.write(R,            "M=D");

        // Push the that segment address.
        w.write('@', P, THT,  "D=M");
        w.incrementStack();
        w.write(R,            "M=D");

        // update the new Arg
        w.write('@', P, args, "D=A");
        w.write('@', P, 5,    "D=A-D");
        w.write('@', P, STP,  "D=M-D");
        w.write('@', P, ARG,  "M=D");

        // Move the current stack address into the LCL address.
        w.write('@', P, STP,  "D=M");
        w.write('@', P, LCL,  "M=D");
        w.write('@', P, name);
        w.write(R,            "D=A");
        w.write(R,            "D;JMP");

        // Write the return position.
        w.write('(', retAddr, ')');

        // clang-format on
    }

    void Emitter::writeReturn()
    {
        const CodeStream w(&_stream);

        // clang-format off
        
        w.write('@', P, LCL, "D=M"); // Local
        w.write('@', P, SW0, "M=D"); // FRAME = Local store in Swap 0

        w.write('@', P, 5,   "D=D-A"); // Frame - 5
        w.write('@', P, SW2, "M=D");   // Is the Return addr
        w.write('@', P, SW1, "M=D");   // de-reference the  
        w.write(R,           "A=D");  // vaLue at frame -5 
        w.write(R,           "D=M");   //

        w.write('@', P, SW1, "M=D");   // RET = *(frame-5)
        w.write('@', P, STP, "A=M-1");
        w.write(R,           "A=M");
        w.write(R,           "D=A");   // *ARG = return value
        w.write('@', P, SW2, "D=M");   // RET addr
        w.write('@', P, STP, "M=D+1"); // SP = ARG + 1 

        w.write('@', P, SW0, "D=M");   // FRAME
        w.write('@', P, 1,   "D=D-A"); // FRAME-1
        w.write(R,           "A=D");   // de-reference 
        w.write(R,           "D=M");   //
        w.write('@', P, THT, "M=D");   // THAT

        w.write('@', P, SW0, "D=M");   // FRAME
        w.write('@', P, 2,   "D=D-A"); // FRAME-2
        w.write(R,           "A=D");   // de-reference 
        w.write(R,           "D=M");   //
        w.write('@', P, THS, "M=D");   // THIS

        w.write('@', P, SW0, "D=M");   // FRAME
        w.write('@', P, 3,   "D=D-A"); // FRAME-3
        w.write(R,           "A=D");   // de-reference 
        w.write(R,           "D=M");   //
        w.write('@', P, ARG, "M=D");   // ARG

        w.write('@', P, SW0, "D=M");   // FRAME
        w.write('@', P, 4,   "D=D-A"); // FRAME-4
        w.write(R,           "A=D");   // de-reference 
        w.write(R,           "D=M");   //
        w.write('@', P, LCL, "M=D");   // LCL
        
        w.write('@', P, SW0, "D=M"); // Clear the Frame
        w.write(R,           "A=D"); // RET
        w.write(R,           "D=M"); // Pick up the value at the top of the frame

        w.write('@', P, SW2, "A=M");
        w.write(R,           "M=D"); // Function return, place it in RAM[Swap 2]
        w.write('@', P, SW1, "D=M"); // Pick up the return address
        w.write(R,           "A=D"); // set up the jump to the return address
        w.write(R,           "0;JMP");

        // clang-format on
    }

}  // namespace Hack::VirtualMachine
