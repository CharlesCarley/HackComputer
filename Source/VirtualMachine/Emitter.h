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
#include "Utils/ParserBase/ScannerBase.h"
#include "VirtualMachine/Token.h"

namespace Hack::VirtualMachine
{
    class CodeStream;

    class Emitter
    {
    private:
        OutputStringStream _stream;

        static void popStackInto(const CodeStream& w,
                                 const String&     idx,
                                 const int32_t&    dest,
                                 const int32_t&    swap);

    public:
        Emitter();

        void clear();

        String toString() const;

        void setRam(int index, int value);

        void pushConstant(const String& value);

        void popLocal(const String& idx);

        void popThis(const String& idx);

        void popThat(const String& idx);

        void popTemp(const String& idx);

        void popArgument(const String& idx);

        void writeOr();

        void writeAnd();

        void writeSub();

        void writeAdd();
    };

}  // namespace Hack::VirtualMachine