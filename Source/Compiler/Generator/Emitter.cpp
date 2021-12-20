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
#include "Compiler/Generator/Emitter.h"
#include <iomanip>
#include "Utils/Char.h"

namespace Hack::Compiler::CodeGenerator
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
    };

    Emitter::Emitter() :
        _cmp(0)
    {
    }

    void Emitter::clear()
    {
        _stream.str("");
    }

    void Emitter::initialize()
    {
        const CodeStream w(&_stream);
        w.write("set 0 256");
        w.write("set 1 512");
        w.write("set 2 768");
        w.write("set 4 1024");
    }

    void Emitter::writeStatic(const Symbol& sym)
    {
        const CodeStream w(&_stream);
        w.write("push constant 32767");
        w.write("pop static ", sym.entry());
    }

    void Emitter::writeField(const Symbol& sym)
    {
        const CodeStream w(&_stream);
        w.write("push constant 32767");
        w.write("pop this ", sym.entry());
    }

    void Emitter::writeFunction(const String& name, uint16_t numParams)
    {
        const CodeStream w(&_stream);

        w.write("function ", name, " ", numParams);
    }

    void Emitter::pushConstant(const String& cs)
    {
        const CodeStream w(&_stream);
        w.write("push constant ", Char::toInt16(cs));
    }

    void Emitter::popLocal(const size_t idx)
    {
        const CodeStream w(&_stream);
        w.write("pop local ", idx);
    }


    void Emitter::pushLocal(const size_t idx)
    {
        const CodeStream w(&_stream);
        w.write("push local ", idx);
    }


    void Emitter::writeReturn()
    {
        const CodeStream w(&_stream);
        w.write("return");
    }


}  // namespace Hack::Compiler::CodeGenerator
