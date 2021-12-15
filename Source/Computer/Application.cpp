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
#include "Assembler/Parser.h"
#include "Chips/Computer.h"
#include "Computer/CommandRuntime.h"
#include "Computer/DebugRuntime.h"
#include "Translator/VirtualMachine/Parser.h"
#include "Utils/CommandLine/Parser.h"
#include "Utils/Exceptions/Exception.h"

#ifdef USE_SDL
#include "Computer/Runtime.h"
#endif

namespace Hack::Computer
{
    using Instructions = Assembler::Parser::Instructions;

    enum Options
    {
        OP_CMD,
        OP_DEBUG,
        OP_RUN_END,
        OP_TRACE_MEM,
        OP_MAX,
    };

    constexpr CommandLine::Switch Switches[OP_MAX] = {
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
    };

    Application::Application() :
        _computer(new Chips::Computer()),
        _runtime(nullptr),
        _trace(false)
    {
    }

    Application::~Application()
    {
        delete _runtime;
        _runtime = nullptr;

        try
        {
            if (_trace)
                trace(_computer);
        }
        catch (Exception&)
        {
        }

        delete _computer;
        _computer = nullptr;
    }

    bool Application::parse(const int argc, char** argv)
    {
        CommandLine::Parser cmd;
        if (cmd.parse(argc, argv, Switches, OP_MAX) < 0)
            return false;

        const StringArray& al = cmd.getArgList();
        if (al.empty())
        {
            String usage;
            cmd.usage(usage);
            throw Exception(usage, "Missing input file");
        }

        _input = al[0];

#ifdef USE_SDL
        if (cmd.isPresent(OP_DEBUG))
            _runtime = new DebugRuntime();
        else if (cmd.isPresent(OP_CMD))
            _runtime = new CommandRuntime();
        else
            _runtime = new Runtime();
#else
        if (cmd.isPresent(OP_DEBUG))
            _runtime = new DebugRuntime();
        else
            _runtime = new CommandRuntime();
#endif

        _trace = cmd.isPresent(OP_TRACE_MEM);
        return true;
    }

    void Application::load() const
    {
        // parser throws an exception but, it is not being
        // caught here, so that if there is an error it will
        // be caught in the main catch statement and reported.
        std::filesystem::path path = _input;

        String ext = path.extension().string();

        if (ext == ".vm")
        {
            VirtualMachine::Parser vmp;
            vmp.parse(_input);

            StringStream ss;
            vmp.write(ss);

            Assembler::Parser psr;
            psr.parse(ss);

            const Instructions& instructions = psr.getInstructions();

            _computer->load(instructions.data(), instructions.size());
        }
        else
        {
            Assembler::Parser psr;
            psr.parse(_input);

            const Instructions& instructions = psr.getInstructions();

            _computer->load(instructions.data(), instructions.size());
        }
    }

    void Application::trace(Chips::Computer* computer)
    {
        Chips::Memory* mem = computer->getRam();

        OutputStringStream oss;

        oss << "| Index |  Value   |" << std::endl;
        oss << "|------:|---------:|" << std::endl;

        for (int i = 0; i < Chips::Memory::MaxAddress; ++i)
        {
            const uint16_t v = mem->get(i);
            if (v != 0)
            {
                oss << '|';
                oss << std::right << std::setw(7) << i;
                oss << '|';
                oss << std::setw(10) << v;
                oss << '|';
                oss << std::endl;
            }
        }
        Console::write(oss.str());
    }

    int Application::go() const
    {
        if (_runtime)
        {
            // load the supplied command line file
            load();

            _runtime->initialize(_computer);

            while (!_runtime->exitRequest())
            {
                // map keyboard events
                _runtime->processEvents(_computer);

                // update the CPU
                if (_runtime->shouldUpdate())
                    _runtime->update(_computer);

                // synchronize screen memory
                _runtime->flushMemory(_computer);
            }

            return 0;
        }

        throw Exception("No application runtime was found");
    }

}  // namespace Hack::Computer
