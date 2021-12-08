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
        explicit CodeStream(OStream* os) : _s(os)
        {
        }

        template <typename... Args>
        void write(Args&&... args) const
        {
            OutputStringStream oss;
            ((oss << std::forward<Args>(args)), ...);
            *_s << oss.str() << std::endl;
        }
    };

    Emitter::Emitter() = default;

    void Emitter::clear()
    {
        _stream.str("");
    }

    String Emitter::toString() const
    {
        return _stream.str();
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
        w.write('@', P, STP,   "M=M-1");
        w.write(R,             "A=M");
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
        w.write('@', P, STP,   "M=M+1");
        w.write(R,             "A=M-1");
        w.write(R,             "M=D");
        // clang-format on
    }

    void Emitter::pushConstant(const String& idx)
    {
        // clang-format off
        const CodeStream w(&_stream);
        w.write("@", P, idx, "D=A");
        w.write('@', P, STP,   "M=M+1");
        w.write(R,             "A=M-1");
        w.write(R,             "M=D");
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

    void Emitter::popLocal(const String& idx)
    {
        // clang-format off
        const CodeStream w(&_stream);
        popStackInto(w, idx, LCL, SW2);
        // clang-format on
    }

    void Emitter::popArgument(const String& idx)
    {
        // clang-format off
        const CodeStream w(&_stream);
        popStackInto(w, idx, ARG, SW2);
        // clang-format on
    }

    void Emitter::popThis(const String& idx)
    {
        // clang-format off
        const CodeStream w(&_stream);
        popStackInto(w, idx, THS, SW2);
        // clang-format on
    }

    void Emitter::popThat(const String& idx)
    {
        // clang-format off
        const CodeStream w(&_stream);
        popStackInto(w, idx, THT, SW2);
        // clang-format on
    }

    void Emitter::popTemp(const String& idx)
    {
        // clang-format off
        const CodeStream w(&_stream);
        popStackInto(w, idx, TMP, SW2);
        // clang-format on
    }

    void Emitter::writeOr()
    {
        // clang-format off
        const CodeStream w(&_stream);
        w.write('@', P, STP,  "M=M-1");
        w.write(R,            "A=M");
        w.write(R,            "D=M");
        w.write(R,            "A=A-1");
        w.write(R,            "M=D|M");
        w.write();
        // clang-format on
    }

    void Emitter::writeAnd()
    {
        // clang-format off
        const CodeStream w(&_stream);
        w.write('@', P, STP,  "M=M-1");
        w.write(R,            "A=M");
        w.write(R,            "D=M");
        w.write(R,            "A=A-1");
        w.write(R,            "M=D&M");
        w.write();
        // clang-format on
    }

    void Emitter::writeSub()
    {
        // clang-format off
        const CodeStream w(&_stream);
        w.write('@', P, STP,  "M=M-1");
        w.write(R,            "A=M");
        w.write(R,            "D=M");
        w.write(R,            "A=A-1");
        w.write(R,            "M=M-D");
        // clang-format on
    }

    void Emitter::writeAdd()
    {
        // clang-format off
        const CodeStream w(&_stream);
        w.write('@', P, STP,  "M=M-1");
        w.write(R,            "A=M");
        w.write(R,            "D=M");
        w.write(R,            "A=A-1");
        w.write(R,            "M=D+M");
        // clang-format on
    }

    void Emitter::writeNot()
    {
        // clang-format off
        const CodeStream w(&_stream);
        w.write('@', P, STP,  "M=M-1");
        w.write(R,            "A=M");
        w.write(R,            "M=!M");
        // clang-format on
    }

    void Emitter::writeNeg()
    {
        // clang-format off
        const CodeStream w(&_stream);
        w.write('@', P, STP,  "M=M-1");
        w.write(R,            "A=M");
        w.write(R,            "M=-M");
        // clang-format on
    }

}  // namespace Hack::VirtualMachine
