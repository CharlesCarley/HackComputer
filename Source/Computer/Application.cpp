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
#include "Computer/Application.h"
#include <filesystem>
#include <iostream>
#include "Assembler/Parser.h"
#include "Chips/Computer.h"
#include "Compiler/Analyzer/Parser.h"
#include "Compiler/Generator/Generator.h"
#include "Computer/CommandRuntime.h"
#include "Computer/DebugRuntime.h"
#include "Computer/ScreenSDL.h"
#include "Utils/CommandLine/Parser.h"
#include "Utils/Exception.h"
#include "Utils/FileSystem.h"
#include "VirtualMachine/Parser.h"

#ifdef USE_SDL
#include "Computer/RuntimeSDL.h"
#endif

namespace Hack::Computer
{
    using Clock = std::chrono::high_resolution_clock;
    using Time  = std::chrono::time_point<Clock, Clock::duration>;

    using Instructions = Assembler::Parser::Instructions;
    using Cmd          = CommandLine::Parser;
    using CmdSwitch    = CommandLine::Switch;
    using AsmParser    = Assembler::Parser;
    using VmParser     = VirtualMachine::Parser;
    using CodeGen      = Compiler::CodeGenerator::Generator;

    enum Options
    {
        OP_CMD,
        OP_DEBUG,
        OP_RUN_END,
        OP_TRACE_MEM,
        OP_SHOW_PT,
        OP_SHOW_VM,
        OP_SHOW_ASM,
        OP_SHOW_MC,
        OP_MAX,
    };

    constexpr CmdSwitch Switches[OP_MAX] = {
        {
            OP_CMD,
            'c',
            nullptr,
            "Use the command line runtime",
            true,
            0,
        },
        {
            OP_DEBUG,
            'd',
            nullptr,
            "Debug the supplied file",
            true,
            0,
        },
        {
            OP_RUN_END,
            'r',
            "run-end",
            "Run the supplied file until it exits",
            true,
            0,
        },
        {
            OP_TRACE_MEM,
            't',
            "trace",
            "Output a dump of the non-zero portions of ram",
            true,
            0,
        },
        {
            OP_SHOW_PT,
            0,
            "show-pt",
            "Output the parse tree from the supplied file",
            true,
            0,
        },
        {
            OP_SHOW_VM,
            0,
            "show-vm",
            "Output the emitted VM code from the supplied file",
            true,
            0,
        },
        {
            OP_SHOW_ASM,
            0,
            "show-asm",
            "Output the emitted assembly code from the supplied file",
            true,
            0,
        },
        {
            OP_SHOW_MC,
            0,
            "show-mc",
            "Output the emitted machine code from the supplied file",
            true,
            0,
        },
    };

    class Application
    {
    private:
        Chips::Computer*  _computer;
        Chips::Screen*    _screen;
        RuntimeInterface* _runtime;
        String            _input;
        bool              _trace;
        bool              _showVm;
        bool              _showAsm;
        bool              _showMc;
        bool              _showPt;

        void load() const;

        static void trace(Chips::Computer* computer);

        void assemble(AsmParser& assembler) const;

        void generate(VmParser& emitter) const;

        void compile(CodeGen& compiler) const;

        void setupScreen();

    public:
        Application();
        ~Application();

        bool parse(int argc, char** argv);

        int go();
    };

    Application::Application() :
        _computer(new Chips::Computer()),
        _screen(nullptr),
        _runtime(nullptr),
        _trace(false),
        _showVm(false),
        _showAsm(false),
        _showMc(false),
        _showPt(false)
    {
    }

    Application::~Application()
    {
        delete _computer;
        _computer = nullptr;

        delete _runtime;
        _runtime = nullptr;
    }

    bool Application::parse(const int argc, char** argv)
    {
        Cmd parser;
        if (parser.parse(argc, argv, Switches, OP_MAX) < 0)
            return false;

        const StringArray& arguments = parser.arguments();
        if (arguments.empty())
        {
            String usage;
            parser.usage(usage);
            throw Exception(usage, "Missing input file");
        }

        _input = arguments[0];

#ifdef USE_SDL
        if (parser.isPresent(OP_DEBUG))
            _runtime = new DebugRuntime();
        else if (parser.isPresent(OP_CMD))
            _runtime = new CommandRuntime();
        else
            _runtime = new RuntimeSDL();
#else
        if (parser.isPresent(OP_DEBUG))
            _runtime = new DebugRuntime();
        else
            _runtime = new CommandRuntime();
#endif

        _trace   = parser.isPresent(OP_TRACE_MEM);
        _showAsm = parser.isPresent(OP_SHOW_ASM);
        _showVm  = parser.isPresent(OP_SHOW_VM);
        _showMc  = parser.isPresent(OP_SHOW_MC);
        _showPt  = parser.isPresent(OP_SHOW_PT);

        return true;
    }

    void Application::trace(Chips::Computer* computer)
    {
        Chips::Memory*     mem = computer->memory();
        OutputStringStream oss;

        oss << "| Index |  Value   |" << std::endl;
        oss << "|------:|---------:|" << std::endl;

        const int& stp = (int)mem->get(0);

        for (uint16_t i = 0; i < Chips::Memory::MaxAddress; ++i)
        {
            const uint16_t v = mem->get(i);

            bool dumpIt = v != 0 || i >= 256 && i < stp || i < 16;

            if (dumpIt && v >= 0x4000 && v <= 0x6000)
                dumpIt = false;

            if (dumpIt)
            {
                oss << '|';
                oss << std::right << std::setw(7) << i;
                oss << '|';
                oss << std::setw(10) << (int16_t)v;
                oss << '|';
                oss << std::endl;
            }
        }
        Console::write(oss.str());
    }

    void Application::assemble(AsmParser& assembler) const
    {
        const Instructions& instructions = assembler.instructions();

        if (instructions.empty())
            throw MessageException("no instructions found");

        _computer->load(instructions.data(), instructions.size());
    }

    void Application::generate(VmParser& emitter) const
    {
        StringStream input;
        emitter.write(input);

        AsmParser assembler;
        assembler.parse(input);

        if (_showMc)
            assembler.write(std::cout);

        assemble(assembler);
    }

    void Application::compile(CodeGen& compiler) const
    {
        StringStream input;
        compiler.write(input);

        if (_showVm)
            compiler.write(std::cout);

        VirtualMachine::Parser emitter;
        emitter.parse(input);

        if (_showAsm)
            emitter.write(std::cout);

        generate(emitter);
    }

    void Application::load() const
    {
        // parser throws an exception but, it is not being
        // caught here, so that if there is an error it will
        // be caught in the main catch statement and reported.
        const Path path = FileSystem::absolute(_input);

        const String extension = path.extension().string();

        if (extension == ".jack")
        {
            Compiler::Analyzer::Parser parser;
            parser.parse(path.string());

            if (_showPt)
                parser.getTree().write(std::cout, 0);

            Compiler::CodeGenerator::Generator input;
            input.compile(parser.getTree().getRoot());

            compile(input);
        }
        else if (extension == ".vm")
        {
            VirtualMachine::Parser input;
            input.parse(_input);

            if (_showAsm)
                input.write(std::cout);

            generate(input);
        }
        else
        {
            Assembler::Parser input;
            input.parse(_input);

            assemble(input);
        }
    }

    void Application::setupScreen()
    {
        Chips::Memory* mem = _computer->memory();

#ifdef USE_SDL
        _screen = new Chips::ScreenSDL();
#else
        _screen = new Chips::ScreenSegment();
#endif

        mem->initializeScreen(_screen);
    }

    int Application::go()
    {
        if (_runtime)
        {
            setupScreen();

            // load the supplied command line file
            load();

            _runtime->initialize(_computer, _screen);

            while (!_runtime->exitRequest())
            {
                // map keyboard events
                _runtime->processEvents(_computer);

                // update the CPU
                if (_runtime->shouldUpdate())
                    _runtime->update(_computer);

                _runtime->flushMemory(_computer);
            }

            if (_trace)
                trace(_computer);

            return 0;
        }

        throw Exception("No application runtime was found");
    }

}  // namespace Hack::Computer

int main(int argc, char** argv)
{
    try
    {
        Hack::Computer::Application app;
        if (app.parse(argc, argv))
            return app.go();
    }
    catch (Hack::Exception& ex)
    {
        Hack::Console::writeError(ex.what());
    }
    return 1;
}
