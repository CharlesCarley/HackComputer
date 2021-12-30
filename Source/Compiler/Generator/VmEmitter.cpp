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
#include <chrono>
#include "Utils/Char.h"

#define NOW std::chrono::high_resolution_clock::now().time_since_epoch().count()

namespace Hack::Compiler::CodeGenerator
{
    VmEmitter::VmEmitter() :
        _uid(0)
    {
    }

    void VmEmitter::initialize()
    {
        _eof = generateLabel();
        write("call Main.main 0");
        write("goto ", _eof);
    }

    void VmEmitter::finalize()
    {
        write("label ", _eof);
    }

    void VmEmitter::clear()
    {
        _stream.str("");
    }

    String VmEmitter::generateLabel()
    {
        String label;
        StringUtils::generate(label, _uid, this);
        return label;
    }

    void VmEmitter::writeStatic(const Symbol& sym)
    {
        write("push constant 32767");
        write("pop static ", sym.entry());
    }

    void VmEmitter::writeField(const Symbol& sym)
    {
        write("push constant 32767");
        write("pop this ", sym.entry());
    }

    void VmEmitter::writeFunction(const String& name, uint16_t numParams)
    {
        write("function ", name, ' ', numParams);
    }

    void VmEmitter::writeMethod(const String& className,
                                const String& methodName,
                                uint16_t      numParams)
    {
        write("function ", className, '.', methodName, ' ', numParams);
    }

    void VmEmitter::pushConstant(const String& value)
    {
        write("push constant ", (uint16_t)Char::toInt16(value));
    }

    void VmEmitter::pushConstant(const size_t& value)
    {
        write("push constant ", (uint16_t)(int16_t)value);
    }

    void VmEmitter::popLocal(const size_t& idx)
    {
        write("pop local ", idx);
    }

    void VmEmitter::popArgument(const size_t& idx)
    {
        write("pop argument ", idx);
    }

    void VmEmitter::popTemp(const size_t& idx)
    {
        write("pop temp ", idx);
    }

    void VmEmitter::popThis(const size_t& idx)
    {
        write("pop this ", idx);
    }

    void VmEmitter::popThat(const size_t& idx)
    {
        write("pop that ", idx);
    }

    void VmEmitter::popPointer(const size_t& idx)
    {
        if (idx > 2)
            throw Exception("pop pointer can be 0 or 1");
        write("pop pointer ", idx);
    }

    void VmEmitter::popStatic(const size_t& idx)
    {
        write("pop static ", idx);
    }

    void VmEmitter::pushLocal(const size_t& idx)
    {
        write("push local ", idx);
    }

    void VmEmitter::pushArgument(const size_t& idx)
    {
        write("push argument ", idx);
    }
    void VmEmitter::pushThis(const size_t& idx)
    {
        write("push this ", idx);
    }

    void VmEmitter::pushThat(const size_t& idx)
    {
        write("push that ", idx);
    }

    void VmEmitter::pushPointer(const size_t& idx)
    {
        if (idx > 2)
            throw Exception("push pointer can be 0 or 1");

        write("push pointer ", idx);
    }

    void VmEmitter::pushStatic(const size_t& idx)
    {
        write("push static ", idx);
    }

    void VmEmitter::pushTemp(const size_t& idx)
    {
        write("push temp ", idx);
    }
    
    void VmEmitter::writeReturn()
    {
        write("return");
    }

    void VmEmitter::symbolAdd()
    {
        write("add");
    }

    void VmEmitter::symbolSub()
    {
        write("sub");
    }

    void VmEmitter::symbolNeg()
    {
        write("neg");
    }

    void VmEmitter::symbolAnd()
    {
        write("and");
    }

    void VmEmitter::symbolOr()
    {
        write("or");
    }

    void VmEmitter::symbolNot()
    {
        write("not");
    }

    void VmEmitter::symbolGreater()
    {
        write("gt");
    }

    void VmEmitter::symbolLess()
    {
        write("lt");
    }

    void VmEmitter::symbolEquals()
    {
        write("eq");
    }

    void VmEmitter::writeCall(const String& id, const size_t size)
    {
        write("call ", id, ' ', std::min<size_t>(size, 20));
    }

    void VmEmitter::writeIfStart(const String& label)
    {
        write("not");
        write("if-goto ", label);
    }

    void VmEmitter::writeGoto(const String& label)
    {
        write("goto ", label);
    }

    void VmEmitter::writeLabel(const String& label)
    {
        write("label ", label);
    }


    void VmEmitter::writeCode(int type, const String& code)
    {
        if (type == RuleInlineVm)
            write(code);
        else if (type == RuleInlineAsm)
            write("asm [\n", code, "\n]");
    }

}  // namespace Hack::Compiler::CodeGenerator
