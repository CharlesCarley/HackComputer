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
#include "VirtualMachine/Parser.h"
#include <fstream>
#include "Utils/Exceptions/Exception.h"

namespace Hack::VirtualMachine
{
    Parser::Parser()
    {
    }

    Parser::~Parser()
    {
    }

    void Parser::parse(IStream& is)
    {
    }

    void Parser::emit(OStream& dest)
    {
    }

    void Parser::parse(const String& file)
    {
        std::ifstream fs(file);
        if (!fs.is_open())
            throw Exception("Failed to open the input file '", file, "'");
        parse(fs);
    }

    void Parser::emit(const String& file)
    {
        std::ofstream fs(file);
        if (!fs.is_open())
            throw Exception("Failed to open the output file '", file, "'");

        emit(fs);
    }

}  // namespace Hack::VirtualMachine
