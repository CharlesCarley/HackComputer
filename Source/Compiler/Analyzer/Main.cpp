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
#include <filesystem>
#include <fstream>
#include <iostream>
#include "Compiler/Analyzer/Parser.h"
#include "Utils/CommandLine/Parser.h"
#include "Utils/Console.h"
#include "Utils/Exceptions/Exception.h"
#include "Utils/FileSystem.h"

using namespace std;
using namespace Hack;

enum Options
{
    OP_FMT,
    OP_DIR,
    OP_OUTPUT,
    OP_MAX,
};

constexpr CommandLine::Switch Switches[OP_MAX] = {
    {
        OP_FMT,
        'f',
        "format",
        "Specify an output file format\n"
        " - xml, format as XML (default)\n"
        " - dot, format as DOT",
        true,
        1,
    },
    {
        OP_DIR,
        'd',
        "directory",
        "Converts all .jack files in the current directory to .xml\n",
        true,
        1,
    },
    {
        OP_OUTPUT,
        'o',
        "output",
        "Specify an output file\n"
        "  - the directory option takes precedence",
        true,
        1,
    },
};



class Application
{
private:
    string _input;
    string _output;
    bool   _dot;
    String _dir;

public:
    Application() :
        _dot(false)
    {
    }

    bool parse(const int argc, char** argv)
    {
        CommandLine::Parser cmd;
        if (cmd.parse(argc, argv, Switches, OP_MAX) < 0)
            return false;

        _output = cmd.string(OP_OUTPUT);

        if (cmd.isPresent(OP_DIR))
            _dir = cmd.string(OP_DIR);

        const StringArray& args = cmd.arguments();
        if (args.empty() && _dir.empty())
        {
            String usage;
            cmd.usage(usage);
            throw Exception(usage, "Missing input file or directory");
        }
        if (!args.empty())
            _input = args[0];

        if (cmd.isPresent(OP_FMT))
            _dot = cmd.string(OP_FMT) == "dot";

        return true;
    }

    int go() const
    {
        if (!_dir.empty())
        {
            PathArray jackFiles;
            FileSystem::glob(jackFiles, _dir, ".jack");

            for (Path& jackFile : jackFiles)
            {
                try
                {
                    String inFile  = jackFile.string();
                    String outFile = inFile
                                         .substr(0, inFile.size() - 5)
                                         .append(".xml");

                    
                    Compiler::Analyzer::Parser psr;
                    Console::write("parsing ", jackFile.filename().string());
                    psr.parse(inFile);

                    Console::writeLine(" -> ", Path(outFile).filename().string());
                    psr.write(outFile, _dot ? 1 : 0);

                }
                catch (Exception& ex)
                {
                    Console::writeLine(ex.what());
                }
            }
        }
        else
        {
            Compiler::Analyzer::Parser psr;
            psr.parse(_input);

            if (!_output.empty())
            {
                std::ofstream fs(_output);
                psr.write(fs, _dot ? 1 : 0);
            }
            else
                psr.write(cout, _dot ? 1 : 0);
        }

        return 0;
    }
};

int main(int argc, char** argv)
{
    try
    {
        Application app;
        if (app.parse(argc, argv))
            return app.go();
    }
    catch (std::exception& ex)
    {
        Console::writeError(ex.what());
    }
    return 1;
}
