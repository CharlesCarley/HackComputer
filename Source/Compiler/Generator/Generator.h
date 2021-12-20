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

namespace Hack
{
    namespace VirtualMachine
    {
        class Emitter;
    }
}  // namespace Hack

namespace Hack::Compiler::CodeGenerator
{
    class SymbolTable;
    class Emitter;

    class Generator
    {
    private:
        SymbolTable* _globals;
        SymbolTable* _locals;
        Emitter*     _emitter;

        void buildClass(Node* node) const;

        void buildGlobals(const Node& classDescription) const;

        void buildMethods(const Node& classDescription) const;

        void buildLocals(const Node& bodyNode) const;

        void buildLetStatement(const Node& statement) const;

        void buildReturnStatement(const Node& statement) const;

        void buildStatements(const Node& method) const;


        void parseImpl(const Node *root) const;

    public:
        Generator();
        ~Generator();

        void parse(const String& file) const;

        void parse(IStream& stream) const;

        void write(const String& file) const;

        void write(OStream& stream) const;
    };

}  // namespace Hack::Compiler::CodeGenerator