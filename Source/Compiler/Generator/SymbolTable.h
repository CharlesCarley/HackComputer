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
#pragma once
#include "Compiler/Generator/Symbol.h"
#include "Utils/IndexCache.h"

namespace Hack::Compiler::CodeGenerator
{
    class SymbolTable
    {
    public:
        typedef KeyIndexCache<String, Symbol>  Symbols;
        typedef Symbols::Array::const_iterator Iterator;

    private:
        Symbols _symbols;
        size_t  _field;
        size_t  _static;
        size_t  _local;
        size_t  _argument;

    public:
        SymbolTable();
        ~SymbolTable();

        void insert(const String& name, int8_t type, int8_t kind);

        bool contains(const String& name) const;

        const Symbol& get(const String& name) const;

        const Symbol& get(const size_t& idx) const;

        size_t fieldCount() const;

        size_t staticCount() const;

        size_t localCount() const;

        size_t argumentCount() const;


        void clear();

        Iterator begin() const;

        Iterator end() const;
    };


    inline size_t SymbolTable::fieldCount() const
    {
        return _field;
    }

    inline size_t SymbolTable::staticCount() const
    {
        return _static;
    }

    inline size_t SymbolTable::localCount() const
    {
        return _local;
    }

    inline size_t SymbolTable::argumentCount() const
    {
        return _argument;
    }


    inline SymbolTable::Iterator SymbolTable::begin() const
    {
        return _symbols.begin();
    }

    inline SymbolTable::Iterator SymbolTable::end() const
    {
        return _symbols.end();
    }
} // namespace Hack::Compiler::CodeGenerator
