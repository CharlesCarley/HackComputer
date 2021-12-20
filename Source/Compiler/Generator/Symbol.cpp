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
#include "Compiler/Generator/Symbol.h"

namespace Hack::Compiler::CodeGenerator
{
    Symbol::Symbol() :
        _type(-1),
        _kind(-1),
        _entry(-1)
    {
    }

    Symbol::Symbol(String name, const int8_t type, const int8_t kind, const size_t entry) :
        _name(std::move(name)),
        _type(type),
        _kind(kind),
        _entry(entry)
    {
    }

}  // namespace Hack::Compiler::CodeGenerator
