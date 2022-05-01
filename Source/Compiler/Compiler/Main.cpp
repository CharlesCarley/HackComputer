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
#include "Compiler/Analyzer/Parser.h"
#include "Compiler/Common/DotWriter.h"
#include "Compiler/Common/XmlWriter.h"
#include "Compiler/Generator/Generator.h"
#include "Utils/CommandLine/Parser.h"
#include "Utils/Console.h"
#include "Utils/Exception.h"
#include "VirtualMachine/Parser.h"

using namespace std;
using namespace Hack;

enum InputFormat
{
    IN_FMT_JACK,
    IN_FMT_VM,
    IN_FMT_ASM,
};

enum OutputFormat
{
    OUT_FMT_VM,
    OUT_FMT_XML,
    OUT_FMT_DOT,
    OUT_FMT_ASM,
    OUT_FMT_MC,
    OUT_FMT_DBG,
};

enum Options
{
    OP_OUTPUT,
    OP_OUT_FMT_ARG,
    OP_IN_FMT_ARG,
    OP_MAX,
};

constexpr CommandLine::Switch Switches[OP_MAX] = {
    {
        OP_OUTPUT,
        'o',
        "output",
        "Specify an output file\n"
        " -- If one is not supplied the program's output will be sent to stdout",
        true,
        1,
    },

    {
        OP_OUT_FMT_ARG,
        'f',
        "format",
        "Specify the output file format\n"
        " - Where format is one of vm, asm, mc, xml, dot, dbg",
        true,
        1,
    },
    {
        OP_IN_FMT_ARG,
        '\0',
        "input-format",
        "Specify the input file format explicitly\n"
        " - Where format is one of jack, vm, or asm",
        true,
        1,
    },

};
using AsmParser = Assembler::Parser;
using VmParser  = VirtualMachine::Parser;
using CodeGen   = Compiler::CodeGenerator::Generator;

class HackCompiler
{
private:
    InputFileStream _input;
    bool            _deleteStream{false};
    OStream*        _output;
    int             _outFormat{OUT_FMT_MC};
    int             _inFormat{IN_FMT_JACK};

    void setInputFormat(const String& format)
    {
        if (format == "jack")
            _inFormat = IN_FMT_JACK;
        else if (format == "vm")
            _inFormat = IN_FMT_VM;
        else if (format == "asm")
            _inFormat = IN_FMT_ASM;
        else
            throw InputException("Unknown input format option ", format);
    }

    void setOutputFormat(const String& format)
    {
        if (format == "vm")
            _outFormat = OUT_FMT_VM;
        else if (format == "asm")
            _outFormat = OUT_FMT_ASM;
        else if (format == "mc")
            _outFormat = OUT_FMT_MC;
        else if (format == "xml")
            _outFormat = OUT_FMT_XML;
        else if (format == "dot")
            _outFormat = OUT_FMT_DOT;
        else if (format == "dbg")
            _outFormat = OUT_FMT_DBG;
    }

    [[noreturn]] void unknownOutput() const
    {
        String message = "Unknown output format";
        switch (_outFormat)
        {
        case OUT_FMT_VM:
            StringCombine(message, message, " 'vm'");
            break;
        case OUT_FMT_ASM:
            StringCombine(message, message, " 'asm'");
            break;
        case OUT_FMT_MC:
            StringCombine(message, message, " 'mc'");
            break;
        case OUT_FMT_XML:
            StringCombine(message, message, " 'xml'");
            break;
        case OUT_FMT_DOT:
            StringCombine(message, message, " 'dot'");
            break;
        default:
            StringCombine(message, message, " '?'");
            break;
        }
        StringCombine(message, message, " for input format ");

        switch (_inFormat)
        {
        case IN_FMT_JACK:
            StringCombine(message, message, " 'jack'");
            break;
        case IN_FMT_VM:
            StringCombine(message, message, " 'vm'");
            break;
        case IN_FMT_ASM:
            StringCombine(message, message, " 'asm'");
            break;
        default:
            StringCombine(message, message, " '?'");
            break;
        }

        throw MessageException(message);
    }

    void assemble(IStream& input) const
    {
        if (!_output)
            throw InvalidPointer();

        AsmParser asmParser;
        asmParser.parse(input);
        asmParser.write(*_output);
    }

    void generate(IStream& input) const
    {
        if (!_output)
            throw InvalidPointer();

        VirtualMachine::Parser emitter;
        emitter.parse(input);

        if (_outFormat == OUT_FMT_ASM)
            emitter.write(*_output);
        else if (_outFormat == OUT_FMT_MC)
        {
            StringStream iss;
            emitter.write(iss);
            assemble(iss);
        }
    }

    void compile(IStream& input) const
    {
        if (!_output)
            throw InvalidPointer();

        Compiler::Analyzer::Parser parser;
        parser.parse(input);

        if (_outFormat == OUT_FMT_VM)
        {
            Compiler::CodeGenerator::Generator generator;
            generator.compile(parser.getTree().getRoot());

            generator.write(*_output);
        }
        else if (_outFormat == OUT_FMT_XML)
        {
            Compiler::XmlWriter writer(parser.getTree().getRoot());
            writer.write(*_output);
        }
        else if (_outFormat == OUT_FMT_DOT)
        {
            Compiler::DotWriter writer(parser.getTree().getRoot());
            writer.write(*_output);
        }
        else
        {
            Compiler::CodeGenerator::Generator generator;
            generator.compile(parser.getTree().getRoot());

            StringStream stream;
            generator.write(stream);
            generate(stream);
        }
    }

public:
    HackCompiler()
    {
        _output = nullptr;
    }

    ~HackCompiler()
    {
        if (_deleteStream)
        {
            delete _output;
            _output = nullptr;
        }
    }

    bool parse(const int argc, char** argv)
    {
        CommandLine::Parser cl;
        cl.setHelpText("where arg[0] is the input file");

        if (cl.parse(argc, argv, Switches, OP_MAX) < 0)
            return false;

        const String str = cl.string(OP_OUTPUT, 0);
        if (!str.empty())
        {
            _deleteStream = true;
            _output       = new OutputFileStream(str);
        }
        else
            _output = &std::cout;

        StringArray& args = cl.arguments();
        if (args.empty())
        {
            String usage;
            cl.usage(usage);
            throw Exception(usage, "Missing input file");
        }

        _input = InputFileStream(args[0]);

        String ext = Path(args[0]).extension().string();
        if (ext.empty())
            _inFormat = IN_FMT_JACK;
        else
        {
            StringUtils::replaceAll(ext, ext, ".", "");
            setInputFormat(ext);
        }

        if (cl.isPresent(OP_IN_FMT_ARG))
            setInputFormat(cl.string(OP_IN_FMT_ARG));

        setOutputFormat(cl.string(OP_OUT_FMT_ARG));

        return true;
    }

    void compileJackSource()
    {
        switch (_outFormat)
        {
        case OUT_FMT_VM:
        case OUT_FMT_XML:
        case OUT_FMT_DOT:
        case OUT_FMT_ASM:
        case OUT_FMT_MC:
        case OUT_FMT_DBG:
            compile(_input);
            break;
        default:
            unknownOutput();
        }
    }

    void compileVmSource()
    {
        switch (_outFormat)
        {
        case OUT_FMT_ASM:
        case OUT_FMT_MC:
            generate(_input);
            break;
        default:
            unknownOutput();
        }
    }

    void compileAssemblySource()
    {
        if (_outFormat != OUT_FMT_MC)
            unknownOutput();

        assemble(_input);
    }

    int go()
    {
        switch (_inFormat)
        {
        case IN_FMT_JACK:
            compileJackSource();
            break;
        case IN_FMT_VM:
            compileVmSource();
            break;
        case IN_FMT_ASM:
            compileAssemblySource();
            break;
        default:
            unknownOutput();
        }

        return 0;
    }
};

int main(int argc, char** argv)
{
    try
    {
        HackCompiler app;
        if (app.parse(argc, argv))
            return app.go();
    }
    catch (std::exception& ex)
    {
        Console::writeError(ex.what());
    }
    return 1;
}
