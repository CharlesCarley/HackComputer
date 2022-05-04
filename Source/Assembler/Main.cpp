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
#include <iostream>
#include "Assembler/Parser.h"
#include "Utils/CommandLine/Parser.h"
#include "Utils/Console.h"
#include "Utils/Exception.h"
#include "Utils/Win32/CrtUtils.h"

using namespace std;

namespace Hack::Programs
{
    enum Asm2McOptions
    {
        OP_OUTPUT,
        OP_MAX,
    };

    constexpr CommandLine::Switch Switches[OP_MAX] = {
        {
            OP_OUTPUT,
            'o',
            "output",
            "Specify an output file",
            true,
            1,
        },
    };

    class Asm2Mc
    {
    private:
        string _input;
        string _output;

    public:
        Asm2Mc() = default;

        bool parse(const int argc, char** argv)
        {
            CommandLine::Parser p;
            p.setHelpText("where arg[0] is the input file");

            if (p.parse(argc, argv, Switches, OP_MAX) < 0)
                return false;

            _output = p.string(OP_OUTPUT, 0);

            StringArray& args = p.arguments();
            if (args.empty())
            {
                String usage;
                p.usage(usage);
                throw Exception(usage, "Missing input file");
            }

            _input = args[0];
            return true;
        }

        int go() const
        {
            Assembler::Parser psr;
            psr.parse(_input);
            if (_output.empty())
                psr.write(cout);
            else
                psr.write(_output);
            return 0;
        }
    };
}  // namespace Hack::Programs

int main(int argc, char** argv)
{
    Hack::CrtTestMemory();
    try
    {
        Hack::Programs::Asm2Mc app;
        if (app.parse(argc, argv))
            return app.go();
    }
    catch (std::exception& ex)
    {
        Hack::Console::writeError(ex.what());
    }
    Hack::CrtDump();
    return 1;
}
