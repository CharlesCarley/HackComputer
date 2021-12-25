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
#include "Compiler/Generator/VmEmitter.h"
#include <iomanip>
#include "Utils/Char.h"

namespace Hack::Compiler::CodeGenerator
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

    VmEmitter::VmEmitter() = default;

    void VmEmitter::clear()
    {
        _stream.str("");
    }

    void VmEmitter::initialize()
    {
        const CodeStream w(&_stream);
        w.write("call Main.main 0");
        w.write("goto __sys__exit");
    }

    void VmEmitter::finalize()
    {
        const CodeStream w(&_stream);
        w.write("label __sys__exit");
    }

    void VmEmitter::writeStatic(const Symbol& sym)
    {
        const CodeStream w(&_stream);
        w.write("push constant 32767");
        w.write("pop static ", sym.entry());
    }

    void VmEmitter::writeField(const Symbol& sym)
    {
        const CodeStream w(&_stream);
        w.write("push constant 32767");
        w.write("pop this ", sym.entry());
    }

    void VmEmitter::writeFunction(const String& name, uint16_t numParams)
    {
        const CodeStream w(&_stream);

        w.write("function ", name, " ", numParams);
    }

    void VmEmitter::writeMethod(const String& className,
                                const String& methodName,
                                uint16_t      numParams)
    {
        const CodeStream w(&_stream);
        w.write("function ", className, '.', methodName, ' ', numParams);
    }

    void VmEmitter::pushConstant(const String& value)
    {
        const CodeStream w(&_stream);
        w.write("push constant ", (uint16_t)Char::toInt16(value));
    }

    void VmEmitter::pushConstant(const size_t& value)
    {
        const CodeStream w(&_stream);
        w.write("push constant ", (uint16_t)(int16_t)value);
    }

    void VmEmitter::popLocal(const size_t& idx)
    {
        const CodeStream w(&_stream);
        w.write("pop local ", idx);
    }

    void VmEmitter::pushLocal(const size_t& idx)
    {
        const CodeStream w(&_stream);
        w.write("push local ", idx);
    }

    void VmEmitter::pushArgument(const size_t& idx)
    {
        const CodeStream w(&_stream);
        w.write("push argument ", idx);
    }

    void VmEmitter::pushStatic(const size_t& idx)
    {
        const CodeStream w(&_stream);
        w.write("push argument ", idx);
    }

    void VmEmitter::pushThis(const size_t& idx)
    {
        const CodeStream w(&_stream);
        w.write("push this ", idx);
    }

    void VmEmitter::writeReturn()
    {
        const CodeStream w(&_stream);
        w.write("return");
    }

    void VmEmitter::symbolAdd()
    {
        const CodeStream w(&_stream);
        w.write("add");
    }

    void VmEmitter::symbolSub()
    {
        const CodeStream w(&_stream);
        w.write("sub");
    }

    void VmEmitter::symbolNeg()
    {
        const CodeStream w(&_stream);
        w.write("neg");
    }

    void VmEmitter::symbolAnd()
    {
        const CodeStream w(&_stream);
        w.write("and");
    }

    void VmEmitter::symbolOr()
    {
        const CodeStream w(&_stream);
        w.write("or");
    }

    void VmEmitter::symbolNot()
    {
        const CodeStream w(&_stream);
        w.write("not");
    }

    void VmEmitter::symbolGreater()
    {
        const CodeStream w(&_stream);
        w.write("gt");
    }

    void VmEmitter::symbolLess()
    {
        const CodeStream w(&_stream);
        w.write("lt");
    }

    void VmEmitter::symbolEquals()
    {
        const CodeStream w(&_stream);
        w.write("eq");
    }

    void VmEmitter::writeCall(const String& id, const size_t size)
    {
        const CodeStream w(&_stream);
        w.write("call ", id, ' ', std::min<size_t>(size, 20));
    }

}  // namespace Hack::Compiler::CodeGenerator
