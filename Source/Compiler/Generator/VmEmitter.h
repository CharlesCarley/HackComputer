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
#pragma once

#include "Compiler/Common/Node.h"
#include "Compiler/Generator/Symbol.h"
#include "Utils/String.h"

namespace Hack::Compiler::CodeGenerator
{
    class CodeStream;

    class VmEmitter
    {
    private:
        OutputStringStream _stream;
        int                _uid;
        String             _eof;

        template <typename... Args>
        void write(Args&&... args)
        {
            OutputStringStream oss;
            ((oss << std::forward<Args>(args)), ...);
            _stream << oss.str() << std::endl;
        }

    public:
        VmEmitter();

        OutputStringStream& stream();

        void initialize();

        void finalize();

        void clear();

        String generateLabel();

        void writeStatic(const Symbol& sym);

        void writeField(const Symbol& sym);

        void writeFunction(const String& name, uint16_t numParams);

        void writeMethod(const String& className,
                         const String& methodName,
                         uint16_t      numParams);

        void pushConstant(const String& value);

        void pushConstant(const size_t& value);

        void popLocal(const size_t& idx);

        void popArgument(const size_t& size);

        void popThis(const size_t& idx);

        void popThat(const size_t& idx);

        void popPointer(const size_t& idx);

        void popStatic(const size_t& idx);

        void popTemp(const size_t& idx);



        void pushLocal(const size_t& idx);

        void pushArgument(const size_t& idx);


        void pushThis(const size_t& idx);

        void pushThat(const size_t& idx);

        void pushPointer(const size_t& idx);

        void pushStatic(const size_t& idx);

        void pushTemp(const size_t& idx);
        

        void writeReturn();

        void symbolAdd();

        void symbolSub();

        void symbolAnd();

        void symbolOr();

        void symbolNot();

        void symbolGreater();

        void symbolLess();

        void symbolEquals();

        void symbolNeg();

        void writeCall(const String& id, size_t size);

        void writeIfStart(const String& label);

        void writeGoto(const String& label);

        void writeLabel(const String& label);
    };

    inline OutputStringStream& VmEmitter::stream()
    {
        return _stream;
    }
}  // namespace Hack::Compiler::CodeGenerator
