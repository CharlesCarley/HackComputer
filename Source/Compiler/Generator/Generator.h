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
#include "Symbol.h"
#include "Compiler/Common/Node.h"
#include "Compiler/Common/Tree.h"
#include "Utils/Exception.h"
#include "Utils/ParserBase/ParseError.h"

namespace Hack
{
    namespace VirtualMachine
    {
        class Emitter;
    }

    namespace Compiler
    {
        namespace Analyzer
        {
            class Parser;
        }
    } // namespace Compiler
}     // namespace Hack

namespace Hack::Compiler::CodeGenerator
{
    class SymbolTable;
    class VmEmitter;

    class Generator
    {
    private:
        SymbolTable*   _globals;
        SymbolTable*   _locals;
        VmEmitter*     _emitter;
        String         _fileName;
        mutable bool   _hasReturn;
        mutable String _elseEnd;

        Symbol lookup(const String& name) const;

        void popSymbol(const Symbol& symbol) const;

        void buildClass(Node* node) const;

        void buildGlobals(const Node& classDescription) const;

        void buildClassDescription(const Node& classDescription) const;

        void buildLocals(const Node& bodyNode, const Node& parameters) const;

        void pushIdentifier(const Node& constantIdentifier) const;

        void buildConstant(const Node& simpleTerm) const;

        void buildUnaryOperation(const Node& unary) const;

        void buildOperation(const Node& op) const;

        void buildSimpleTerm(const Node& simpleTerm) const;

        void buildComplexTerm(const Node& complexTerm) const;

        void buildTerm(const Node& term) const;

        void buildSingleExpression(const Node& expression) const;

        void buildExpression(const Node& expression) const;

        void buildLetStatement(const Node& statement) const;

        void buildReturnStatement(const Node& statement) const;

        void buildExpressionList(const Node& expressionList) const;

        void buildCallMethod(const Node& callMethod) const;

        void buildDoStatement(const Node& statement) const;

        void buildIfStatement(const Node& statement) const;

        void buildElseStatement(const Node& statement) const;

        void buildWhileStatement(const Node& statement) const;

        void buildStatements(const Node& methodBody) const;

        void parseImpl(const Node* root) const;

        template <typename... Args>
        [[noreturn]] void compileError(const Node& node, const String& what, Args&&...args) const
        {
            OutputStringStream oss;
            oss << what;
            ((oss << std::forward<Args>(args)), ...);
            throw ParseError(2, node.filename(), node.line(), oss.str());
        }

    public:
        Generator();
        ~Generator();

        void write(const String& file) const;

        void write(OStream& stream) const;

        void compile(const Node* tree);
    };
} // namespace Hack::Compiler::CodeGenerator
