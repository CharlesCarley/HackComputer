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
#include "Document.h"
#include "Utils/CommandLine/Parser.h"
#include "Utils/Console.h"
#include "Utils/Exception.h"

using namespace std;
using namespace Hack;

namespace Hack::DocConverter
{
    enum Options
    {
        OP_OUTPUT,
        OP_MAX,
    };

    constexpr CommandLine::Switch Switches[OP_MAX] = {
        {
            OP_OUTPUT,
            'o',
            "output",
            "Specify an output directory",
            true,
            1,
        },
    };

    class Application
    {
    private:
        string _input;
        string _output;

        Document* _doc;

    public:
        Application()
        {
            _doc = new Document();
        }

        ~Application()
        {
            delete _doc;
        }

        bool parse(const int argc, char** argv)
        {
            CommandLine::Parser p;
            if (p.parse(argc, argv, Switches, OP_MAX) < 0)
                return false;

            _output = p.string(OP_OUTPUT, 0, ".");

            StringArray& args = p.arguments();
            if (args.empty())
            {
                String usage;
                p.usage(usage);
                throw Exception(usage, "Missing input directory");
            }

            _input = args[0];
            return true;
        }

        int go() const
        {
            const Path path = FileSystem::absolute(_input);

            String     outFile;
            const Path outPath = FileSystem::absolute(_output);

            StringCombine(outFile, outPath.string(), '/', path.filename().string(), ".md");
            outFile = absolute(Path(outFile)).string();

            _doc->merge(path, outFile);

            Console::writeLine(outFile);
            return 0;
        }
    };

}  // namespace Hack::DocConverter

int main(int argc, char** argv)
{
    try
    {
        DocConverter::Application app;
        if (app.parse(argc, argv))
            return app.go();
    }
    catch (std::exception& ex)
    {
        Console::writeError(ex.what());
    }
    return 1;
}
