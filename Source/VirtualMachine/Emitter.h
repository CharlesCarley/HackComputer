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
#include <stack>
#include "Utils/ParserBase/ScannerBase.h"
#include "Utils/String.h"

namespace Hack::VirtualMachine
{
    class CodeStream;

    class Emitter
    {
    public:
        typedef std::stack<String> StringStack;

    private:
        OutputStringStream _stream;
        int                _cmp;
        StringStack        _functions;

    
        
        void getJumpLabels(String& valTrue, String& valDone);

        void genLabel(String& val);

    public:
        Emitter();

        void clear();

        OutputStringStream& stream()
        {
            return _stream;
        }

        void setRam(int index, int value);

        void pushConstant(const int& idx);

        void pushLocal(const size_t& idx);

        void pushArgument(const size_t& idx);

        void pushThis(const size_t& idx);

        void pushThat(const size_t& idx);

        void pushStatic(const String& context, const size_t& idx);

        void pushTemp(const size_t& idx);

        void pushPointer(const size_t& idx);

        void popLocal(const size_t& idx);

        void popThis(const size_t& idx);

        void popThat(const size_t& idx);

        void popTemp(const size_t& idx);

        void popPointer(const size_t& idx);

        void popArgument(const size_t& idx);

        void popStatic(const String& context, const size_t& idx);

        void writeOr();

        void writeAnd();

        void writeSub();

        void writeAdd();

        void writeNot();

        void writeNeg();

        void writeEq();

        void writeLt();

        void writeGt();

        void writeReset();

        void writeHalt();

        void writGoto(const String& value);

        void writIfGoto(const String& value);

        void writeLabel(const String& value);

        void writeFunction(const String& name, const int& locals);

        void writeCall(const String& name, const int& args);

        void writeReturn();

        void  writeCode(const String& cs);
    };

}  // namespace Hack::VirtualMachine
