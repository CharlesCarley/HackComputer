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
#include "Compiler/Analyzer/Parser.h"
#include "Compiler/Generator/Generator.h"
#include "Utils/CommandLine/Parser.h"
#include "Utils/Console.h"
#include "Utils/Exception.h"
#include "Utils/FileSystem.h"

using namespace std;

namespace Hack::Programs
{
    enum Options
    {
        OP_OUTPUT,
        OP_MAX,
    };

    using CmdLine   = CommandLine::Parser;
    using CmdSwitch = CommandLine::Switch;

    constexpr CmdSwitch Switches[OP_MAX] = {
        {
            OP_OUTPUT,
            'o',
            "output",
            "Specify an output file",
            true,
            1,
        },
    };

    class VmGeneratorApplication
    {
    private:
        Path   _input;
        string _output;

    public:
        VmGeneratorApplication() :
            _input("")
        {
        }

        bool parse(const int argc, char** argv)
        {
            CmdLine parser;
            if (parser.parse(argc, argv, Switches, OP_MAX) < 0)
                return false;

            _output = parser.string(OP_OUTPUT);

            const StringArray& arguments = parser.arguments();

            if (arguments.empty())
            {
                String usage;
                parser.usage(usage);
                throw InputException(usage, "Missing file input");
            }

            _input = filesystem::absolute(arguments[0]);
            return true;
        }

        int go() const
        {
            Compiler::Analyzer::Parser parser;
            parser.parse(_input.string());

            Compiler::CodeGenerator::Generator generator;
            generator.compile(parser.getTree().getRoot());

            if (!_output.empty())
                generator.write(_output);
            else
                generator.write(std::cout);

            return 0;
        }
    };

}  // namespace Hack::Programs

int main(const int argc, char** argv)
{
    try
    {
        Hack::Programs::VmGeneratorApplication app;
        if (app.parse(argc, argv))
            return app.go();
    }
    catch (std::exception& ex)
    {
        Hack::Console::writeError(ex.what());
    }
    return 1;
}
