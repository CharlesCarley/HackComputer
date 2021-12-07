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
#define lft(x) std::left, std::setw(x)
#define rgt(x) std::right, std::setw(x), ' '
#define P lft(8)
#define R rgt(9)

namespace Hack::VirtualMachine
{
    enum Codes
    {
        STP = 0,
        LCL,
        ARG,
        THS,
        THT,
        TMP,
        SW0 = 13,
        SW1,
        SW2
    };

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
        w.write("# [ set ram ] ");
        w.write();
        w.write('@', P, value, "D=A     # CPU.D = ", value);
        w.write('@', P, index, "M=D     # RAM[", index, "] = ", value);
        w.write();
    }

    void Emitter::pushConstant(const String& value)
    {
        // clang-format off
        const CodeStream w(&_stream);
        w.write("# [ push constant ] ");
        w.write();
        w.write("@", P, value, "D=A");
        w.write('@', P, STP,   "M=M+1");
        w.write(R,             "A=M-1");
        w.write(R,             "M=D");
        w.write();
        // clang-format on
    }

    void Emitter::popStackInto(const CodeStream& w,
                               const String&     idx,
                               const int32_t&    dest,
                               const int32_t&    swap)
    {
        // assumes the the actual destination
        // index is in RAM[dest]

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

    void Emitter::popLocal(const String& idx)
    {
        // clang-format off
        const CodeStream w(&_stream);
        w.write("# [ pop local ] ");
        w.write();
        popStackInto(w, idx, LCL, SW2);
        w.write();
        // clang-format on
    }

    void Emitter::popArgument(const String& idx)
    {
        // clang-format off
        const CodeStream w(&_stream);
        w.write("# [ pop argument ] ");
        w.write();
        popStackInto(w, idx, ARG, SW2);
        w.write();
        // clang-format on
    }

    void Emitter::popThis(const String& idx)
    {
        // clang-format off
        const CodeStream w(&_stream);
        w.write("# [ pop this ] ");
        w.write();
        popStackInto(w, idx, THS, SW2);
        w.write();
        // clang-format on
    }

    void Emitter::popThat(const String& idx)
    {
        // clang-format off
        const CodeStream w(&_stream);
        w.write("# [ pop that ] ");
        w.write();
        popStackInto(w, idx, THT, SW2);
        w.write();
        // clang-format on
    }

    void Emitter::popTemp(const String& idx)
    {
        // clang-format off
        const CodeStream w(&_stream);
        w.write("# [ pop temp ] ");
        popStackInto(w, idx, TMP, SW2);
        w.write();
        // clang-format on
    }

    void Emitter::writeOr()
    {
        // clang-format off
        const CodeStream w(&_stream);
        w.write("# [ or ] ");
        w.write('@', P, STP,  "M=M-1");
        w.write(R,            "A=M");
        w.write(R,            "D=M");
        w.write(R,            "A=A-1");
        w.write(R,            "M=M|D");
        w.write();
        // clang-format on
    }

    void Emitter::writeAnd()
    {
        // clang-format off
        const CodeStream w(&_stream);
        w.write("# [ or ] ");
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
        w.write("# [ sub ] ");
        w.write('@', P, STP,  "M=M-1");
        w.write(R,            "A=M");
        w.write(R,            "D=M");
        w.write(R,            "A=A-1");
        w.write(R,            "M=M-D");
        w.write();
        // clang-format on
    }

    void Emitter::writeAdd()
    {
        // clang-format off
        const CodeStream w(&_stream);
        w.write("# [ add ] ");
        w.write('@', P, STP,  "M=M-1");
        w.write(R,            "A=M");
        w.write(R,            "D=M");
        w.write(R,            "A=A-1");
        w.write(R,            "M=D+M");
        w.write();
        // clang-format on
    }

}  // namespace Hack::VirtualMachine
