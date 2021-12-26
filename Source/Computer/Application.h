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
#include "Utils/String.h"

namespace Hack
{
    namespace Compiler
    {
        namespace CodeGenerator
        {
            class Generator;
        }
    }  // namespace Compiler

    namespace Assembler
    {
        class Parser;
    }

    namespace VirtualMachine
    {
        class Parser;
    }

    namespace Chips
    {
        class Computer;
    }
}  // namespace Hack

namespace Hack::Computer
{
    class IRuntime;
    class DebugRuntime;
    class Runtime;

    class Application
    {
    private:
        Chips::Computer* _computer;
        IRuntime*        _runtime;
        String           _input;
        bool             _trace;
        bool             _showVm;
        bool             _showAsm;
        bool             _showMc;
        bool             _showPt;

        void load() const;

        static void trace(Chips::Computer* computer);

        void assemble(Assembler::Parser& assembler) const;

        void generate(VirtualMachine::Parser& emitter) const;

        void compile(Compiler::CodeGenerator::Generator& compiler) const;

    public:
        Application();
        ~Application();

        bool parse(int argc, char** argv);

        int go() const;
    };
}  // namespace Hack::Computer
