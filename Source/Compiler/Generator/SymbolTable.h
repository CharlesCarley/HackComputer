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
#include "Compiler/Common/Tree.h"
#include "Utils/IndexCache.h"

namespace Hack::Compiler::CodeGenerator
{
    enum SymbolKind
    {
        Local,
        Argument,
        Pointer,
        Static,
        Field,
    };

    class Symbol
    {
    private:
        String _name;
        int8_t _type;
        int8_t _kind;
        size_t _entry;

    public:
        Symbol(String name, int8_t type, int8_t kind, size_t entry);
        Symbol(const Symbol& oth) = default;

        const String& name() const;
        const int8_t& type() const;
        const int8_t& kind() const;
        const size_t& entry() const;
    };

    class SymbolTable
    {
    public:
        typedef KeyIndexCache<String, Symbol> Symbols;

    private:
        Symbols _symbols;
        size_t  _local;
        size_t  _argument;
        size_t  _pointer;
        size_t  _static;
        size_t  _filed;


    public:
        SymbolTable();
        ~SymbolTable();

        void insert(const String& name, int8_t type, int8_t kind);

        bool contains(const String& name) const;

        const Symbol& get(const String& name) const;

        const Symbol& get(const size_t& idx) const;

        void clear();
    };

    inline const String& Symbol::name() const
    {
        return _name;
    }

    inline const int8_t& Symbol::type() const
    {
        return _type;
    }

    inline const int8_t& Symbol::kind() const
    {
        return _kind;
    }

    inline const size_t& Symbol::entry() const
    {
        return _entry;
    }

}  // namespace Hack::Compiler::CodeGenerator
