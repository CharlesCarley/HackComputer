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
#include "Compiler/Generator/SymbolTable.h"

namespace Hack::Compiler::CodeGenerator
{
    SymbolTable::SymbolTable() :
        _local(0),
        _argument(0),
        _pointer(0),
        _static(0),
        _field(0)
    {
    }

    SymbolTable::~SymbolTable() = default;

    void SymbolTable::insert(const String& name, const int8_t type, const int8_t kind)
    {
        if (!_symbols.contains(name))
        {
            switch (kind)
            {
            case Local:
                _symbols.insert(name, {name, type, kind, _local++});
                break;
            case Argument:
                _symbols.insert(name, {name, type, kind, _argument++});
                break;
            case Pointer:
                _symbols.insert(name, {name, type, kind, _pointer++});
                break;
            case Static:
                _symbols.insert(name, {name, type, kind, _static++});
                break;
            case Field:
                _symbols.insert(name, {name, type, kind, _field++});
                break;
            default:
                throw InputException("unknown symbol kind", (int)kind);
            }
        }
    }

    bool SymbolTable::contains(const String& name) const
    {
        return _symbols.contains(name);
    }

    const Symbol& SymbolTable::get(const String& name) const
    {
        const size_t idx = _symbols.find(name);
        if (idx != (size_t)-1)
            return _symbols.at(idx);

        throw NotFound();
    }

    const Symbol& SymbolTable::get(const size_t& idx) const
    {
        if (_symbols.contains(idx))
            return _symbols.at(idx);

        throw IndexOutOfBounds();
    }

    void SymbolTable::clear()
    {
        _symbols.clear();
    }

}  // namespace Hack::Compiler::CodeGenerator
