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
#include "Assembler/Parser.h"
#include "Utils/UserInterface/Common.h"

namespace Hack
{
    namespace Assembler
    {
        class Parser;
    }

    namespace Compiler
    {
        namespace Analyzer
        {
            class Parser;
        }
        namespace CodeGenerator
        {
            class Generator;
        }
    } 

    namespace VirtualMachine
    {
        class Parser;
    }

    namespace CommandLine
    {
        struct Switch;
        class Parser;
    }

    namespace Computer
    {
        enum Colors
        {
            Grey = Ui::CP_USER,
            Highlight,
            WireTitle,
            Action,
            Action2,
            Wire,
            Title,
            WireShadow,
            WireLight
        };

        using Instructions = Assembler::Parser::Instructions;
        using Cmd          = CommandLine::Parser;
        using CmdSwitch    = CommandLine::Switch;

        using AsmParser   = Assembler::Parser;
        using VmParser    = VirtualMachine::Parser;
        using VmGenerator = Compiler::CodeGenerator::Generator;
        using JackParser  = Compiler::Analyzer::Parser;
    }  // namespace Computer

}  // namespace Hack
