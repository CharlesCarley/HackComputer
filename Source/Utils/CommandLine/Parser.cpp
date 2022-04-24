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
#include "Parser.h"
#include <filesystem>
#include <iostream>
#include <sstream>
#include "Utils/Console.h"

#define pad(w) setw((w)) << ' '

namespace Hack::CommandLine
{
    using namespace std;

    Parser::Parser() :
        _maxLongSwitch(4),
        _required(0),
        _used(0)
    {
    }

    Parser::~Parser()
    {
        for (ParseOption* op : _options)
            delete op;
    }

    bool Parser::hasSwitch(const String& sw) const
    {
        return _switches.find(sw) != _switches.end();
    }

    int Parser::parse(int           argc,
                      char**        argv,
                      const Switch* switches,
                      uint32_t      count)
    {
        if (!_programName.empty())  // using as a check for multiple calls
            return 0;

        if (!initializeSwitches(switches, count))
            return -1;

        _programName = argv[0];
        _used        = 0;
        _scanner.clear();

        for (int i = 1; i < argc; ++i)
            _scanner.append(argv[i]);

        String curSwitch;
        curSwitch.reserve(16);

        Token a;
        while (a.getType() != TOK_EOS)
        {
            _scanner.lex(a);
            const int type = a.getType();

            if (a.getType() == TOK_ERROR)
            {
                cerr << a.getValue() << endl;
                usage();
                return -1;
            }

            if (type == TOK_SWITCH_SHORT || type == TOK_SWITCH_LONG)
            {
                // grab the next token
                _scanner.lex(a);

                if (a.getType() == TOK_NEXT || a.getType() == TOK_EOS)
                {
                    OutputStringStream os;
                    os << "expected a switch value to follow '-'" << endl;
                    return writeError(os);
                }

                if (a.getValue() == "help" || a.getValue() == "h")
                {
                    usage();
                    return -1;
                }

                Switches::iterator it = _switches.find(a.getValue());
                if (it == _switches.end())
                {
                    OutputStringStream os;
                    os << "unknown option " << a.getValue() << endl;
                    return writeError(os);
                }

                curSwitch.assign(a.getValue());

                ParseOption* opt = it->second;
                opt->makePresent();

                if (!opt->isOptional())
                    _used++;

                const size_t nArgs = opt->getArgCount();
                if (nArgs > 0)
                {
                    size_t i;
                    for (i = 0; i < nArgs; ++i)
                    {
                        _scanner.lex(a);

                        if (a.getType() != TOK_IDENTIFIER)
                        {
                            OutputStringStream os;
                            os << "invalid argument for option " << curSwitch
                               << endl;
                            return writeError(os);
                        }

                        if (a.getValue().empty())
                        {
                            OutputStringStream os;
                            os << "missing argument for option " << curSwitch
                               << endl;
                            return writeError(os);
                        }

                        opt->setValue(i, a.getValue());
                    }

                    if (i != nArgs)
                    {
                        OutputStringStream os;
                        os << "not all arguments converted when parsing switch "
                           << curSwitch << endl;
                        return writeError(os);
                    }
                }
            }
            else if (type >= TOK_OPTION && type < TOK_EOS)
                _argumentList.push_back(a.getValue());
            else
            {
                if (type != TOK_EOS)
                {
                    OutputStringStream os;
                    os << "unknown option " << a.getValue().c_str() << endl;
                    return writeError(os);
                }
            }
        }

        if (_used != _required)
        {
            OutputStringStream os;
            os << "missing required options" << endl;
            return writeError(os);
        }
        return 0;
    }

    void Parser::setHelpText(const String& help)
    {
        _helpText = help;
    }

    void Parser::logInput() const
    {
        const String& curInp = _scanner.getValue();
        if (!curInp.empty())
            Console::writeLine(curInp);
    }

    String Parser::programName() const
    {
        return _programName.stem().string();
    }

    String Parser::programDirectory() const
    {
        return _programName.root_directory().string();
    }

    String Parser::currentDirectory()
    {
        return std::filesystem::current_path().string();
    }

    bool Parser::isPresent(const uint32_t& enumId) const
    {
        if (enumId < _options.size())
            return _options[enumId]->isPresent();
        return false;
    }

    ParseOption* Parser::option(const uint32_t& enumId)
    {
        if (enumId < _options.size())
            return _options[enumId];
        return nullptr;
    }

    int32_t Parser::int32(const uint32_t& enumId,
                          const size_t    idx,
                          const int32_t   defaultValue,
                          const int32_t   base) const
    {
        if (enumId < _options.size())
        {
            if (_options[enumId] != nullptr)
                return _options[enumId]->getInt(idx, defaultValue, base);
        }
        return defaultValue;
    }

    int64_t Parser::int64(const uint32_t& enumId,
                          const size_t    idx,
                          const int64_t   defaultValue,
                          int32_t         base) const
    {
        if (enumId < _options.size())
        {
            if (_options[enumId] != nullptr)
                return _options[enumId]->getInt64(idx, defaultValue, base);
        }
        return defaultValue;
    }

    const String& Parser::string(const uint32_t& enumId,
                                 size_t          idx,
                                 const String&   defaultValue) const
    {
        if (enumId < _options.size())
        {
            if (_options[enumId] != nullptr)
                return _options[enumId]->getValue(idx);
        }
        return defaultValue;
    }

    void Parser::usage() const
    {
        String usageString;
        usage(usageString);
        Console::writeLine(usageString);
    }

    void Parser::usage(String& dest) const
    {
        const int          w = max(_maxLongSwitch + 2, 4);
        OutputStringStream out;

        out << "Usage: " << programName() << " <options> <arg[0] .. arg[n]>" << endl
               << endl;
        if (!_helpText.empty())
        {
            out << pad(2) << _helpText << endl
                   << endl;
        }
        out << pad(4) << "-h, --help" << pad(w - 4)
               << "Display this help message" << endl;

        for (ParseOption* opt : _options)
        {
            const Switch& switchVal = opt->getSwitch();
            out << pad(4);

            if (switchVal.shortSwitch != 0)
            {
                out << '-' << switchVal.shortSwitch;
                if (switchVal.longSwitch != nullptr)
                    out << ", ";
                else
                    out << pad(4);
            }
            else
                out << pad(4);

            int space = _maxLongSwitch;
            if (switchVal.longSwitch != nullptr)
            {
                space -= (int)Char::length(switchVal.longSwitch);
                out << "--" << switchVal.longSwitch;
            }
            out << pad(space + 2);

            if (switchVal.description != nullptr)
            {
                StringArray arr;
                StringUtils::split(arr, switchVal.description, '\n');

                for (size_t i = 0; i < arr.size(); ++i)
                {
                    const String& str = arr[i];
                    out << str;
                    if (i + 1 < arr.size())
                    {
                        out << endl
                               << pad(w + 10);
                    }
                }
            }
            out << endl;
        }
        out << endl;
        dest = out.str();
    }

    bool Parser::initializeOption(ParseOption* opt, const Switch& sw)
    {
        if (sw.shortSwitch == 0 && sw.longSwitch == nullptr)
        {
            Console::writeError(
                "A switch must have at least a long or short name");
            return false;
        }

        if (sw.shortSwitch != 0)
        {
            if (hasSwitch(String(sw.shortSwitch, 1)))
            {
                OutputStringStream stream;
                stream << "Duplicate switch " << sw.shortSwitch;
                Console::writeError(stream);
                return false;
            }
        }

        if (sw.longSwitch != nullptr)
        {
            const String lsw = String(sw.longSwitch);

            _maxLongSwitch = max(_maxLongSwitch, (int)lsw.size());

            if (hasSwitch(lsw))
            {
                OutputStringStream stream;
                stream << "Duplicate switch " << sw.longSwitch;
                Console::writeError(stream);
                return false;
            }
        }

        if (sw.shortSwitch != 0)
            _switches.insert(make_pair(String(1, sw.shortSwitch), opt));
        if (sw.longSwitch != nullptr)
            _switches.insert(make_pair(sw.longSwitch, opt));

        return true;
    }

    bool Parser::initializeSwitches(const Switch* switches, uint32_t count)
    {
        if (switches == nullptr || count == 0 || count == (uint32_t)-1)
            return true;

        count = min<uint32_t>(count, 0x100);

        _options.resize(count);
        bool result = true;

        for (uint32_t i = 0; i < count && result; ++i)
        {
            if (switches[i].id != i)
            {
                Console::writeError("Misaligned switch id");
                result = false;
            }
            else
            {
                if (!switches[i].optional)
                    _required++;

                _options[i] = new ParseOption(switches[i]);

                result = initializeOption(_options[i], switches[i]);
            }
        }
        return result;
    }

    int Parser::writeError(const OutputStringStream& stream) const
    {
        Console::writeError(stream);
        usage();
        return -1;
    }
}  // namespace Hack::CommandLine
