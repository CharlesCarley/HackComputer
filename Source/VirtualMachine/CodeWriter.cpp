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
#include "VirtualMachine/CodeWriter.h"
#include <iomanip>
#include "Utils/Exceptions/Exception.h"

namespace Hack::VirtualMachine
{
    enum CodeStreamDest
    {
        DST_M,
        DST_D,
        DST_A,
        DST_MD,
        DST_AM,
        DST_AD,
        DST_AMD
    };

    enum CodeStreamOp
    {
        OP_NONE  = ' ',
        OP_ZERO  = '0',
        OP_ONE   = '1',
        OP_PLUS  = '+',
        OP_MINUS = '-',
        OP_AND   = '&',
        OP_OR    = '|',
        OP_NOT   = '!',
        OP_A     = 'A',
        OP_M     = 'M',
        OP_D     = 'D',
    };

    class CodeStream
    {
        OStream* _s;

    public:
        explicit CodeStream(OStream* os) : _s(os)
        {
        }

        const CodeStream& at(int v) const
        {
            *_s << '@' << v << std::endl;
            return *this;
        }

        const CodeStream& at(const String& v) const
        {
            *_s << '@' << v << std::endl;
            return *this;
        }

        const CodeStream& dest(CodeStreamDest v) const
        {
            switch (v)
            {
            case DST_M:
                *_s << "M";
                break;
            case DST_D:
                *_s << "D";
                break;
            case DST_A:
                *_s << "A";
                break;
            case DST_AM:
                *_s << "AM";
                break;
            case DST_AD:
                *_s << "AD";
                break;
            case DST_AMD:
                *_s << "AMD";
                break;
            case DST_MD:
                *_s << "MD";
                break;
            default:
                throw Exception("Invalid destination");
            }
            return *this;
        }

        void equals(const CodeStreamOp a,
                    const CodeStreamOp b = OP_NONE,
                    const CodeStreamOp c = OP_NONE) const
        {
            *_s << '=' << (char)a << (char)b << (char)c << std::endl;
        }
    };

    CodeWriter::CodeWriter() = default;

    void CodeWriter::nl(int n)
    {
        while (n-- > 0)
            _stream << std::endl;
    }

    void CodeWriter::setRam(const int index, const int v)
    {
        _stream << "// RAM[" << index << "] = " << v << std::endl;
        const CodeStream w(&_stream);
        w.at(v).dest(DST_D).equals(OP_A);
        w.at(index).dest(DST_M).equals(OP_D);
    }

    void CodeWriter::pushConstant(const String& v)
    {
        _stream << "// push constant " << v << std::endl;

        const CodeStream w(&_stream);
        w.at(v).dest(DST_D).equals(OP_A);
        w.at("SP").dest(DST_M).equals(OP_M, OP_PLUS, OP_ONE);
        w.dest(DST_A).equals(OP_M, OP_MINUS, OP_ONE);
        w.dest(DST_M).equals(OP_D);
    }

}  // namespace Hack::VirtualMachine
