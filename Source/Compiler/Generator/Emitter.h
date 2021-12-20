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

#include "Compiler/Generator/Symbol.h"
#include "Utils/String.h"

namespace Hack::Compiler::CodeGenerator
{
    class CodeStream;

    class Emitter
    {
    private:
        OutputStringStream _stream;

    public:
        Emitter();

        void clear();

        OutputStringStream& stream();

        void initialize();

        void writeStatic(const Symbol& sym);

        void writeField(const Symbol& sym);

        void writeFunction(const String& name, uint16_t numParams);

        void writeMethod(const String& className, const String& methodName, uint16_t numParams);

        void pushConstant(const String& value);

        void popLocal(const size_t& idx);

        void pushLocal(const size_t& idx);

        void writeReturn();

        void add();
        void sub();
    };

    inline OutputStringStream& Emitter::stream()
    {
        return _stream;
    }
}  // namespace Hack::Compiler::CodeGenerator
