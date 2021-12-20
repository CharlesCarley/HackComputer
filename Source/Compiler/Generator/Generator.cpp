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
#include "Compiler/Generator/Generator.h"
#include <fstream>
#include "Compiler/Analyzer/Parser.h"
#include "Compiler/Common/Node.h"
#include "Compiler/Generator/Emitter.h"
#include "Compiler/Generator/SymbolTable.h"
#include "Utils/Console.h"
#include "Utils/FileSystem.h"

namespace Hack::Compiler::CodeGenerator
{
    Generator::Generator() :
        _globals(new SymbolTable()),
        _locals(new SymbolTable()),
        _emitter(new Emitter())
    {
    }

    Generator::~Generator()
    {
        delete _globals;
        delete _locals;
        delete _emitter;
    }

    void Generator::buildGlobals(const Node& classDescription) const
    {
        Node::NodeArray field;
        classDescription.filter(field, RuleField);
        for (const Node* child : field)
        {
            const Node& ch = *child;

            const Node& identifierList = ch.rule(2, RuleIdentifierList);

            const int8_t fieldType = ch.rule(0).child(0).type();
            const int8_t dataType  = ch.rule(1).rule(0).type();

            for (Node* id : identifierList.children())
            {
                const int8_t kind = fieldType == KeywordStatic ? Static : Field;

                _globals->insert(id->value(), dataType, kind);
            }
        }
    }

    void Generator::buildLocals(const Node& bodyNode) const
    {
        _locals->clear();

        Node::NodeArray variables;
        bodyNode.filter(variables, RuleVariable);
        for (const Node* var : variables)
        {
            const Node& variable = *var;

            const int8_t type = variable.rule(1, RuleDataType).type();

            const Node& identifierList = variable.rule(2, RuleIdentifierList);

            for (Node* id : identifierList)
                _locals->insert(id->value(), type, Local);
        }
    }

    void Generator::buildMethods(const Node& classDescription) const
    {
        Node::NodeArray methods;
        classDescription.filter(methods, RuleMethod);

        for (const Node* child : methods)
        {
            const Node& method = *child;

            const Node& methodSpec    = method.rule(0).child(0);
            const Node& returnType    = method.rule(1).child(0);
            const Node& methodName    = method.rule(2);
            const Node& parameterList = method.rule(4);
            const Node& body          = method.rule(6).rule(1);

            _emitter->writeFunction(methodName.value(), (uint16_t)parameterList.size());

            buildLocals(body);
            buildStatements(body);
        }
    }

    void Generator::buildLetStatement(const Node& statement) const
    {
        const String& id = statement.child(1).value();

        if (_locals->contains(id))
        {
            const Symbol& sym = _locals->get(id);

            const String& value = statement.child(3).child(0).child(0).child(0).constant(0).value();

            _emitter->pushConstant(value);
            _emitter->popLocal(sym.entry());
        }
    }

    void Generator::buildReturnStatement(const Node& statement) const
    {
        const String& id = statement.child(1).child(0).child(0).child(0).constant(0).value();

        if (_locals->contains(id))
        {
            const Symbol& sym = _locals->get(id);

            _emitter->pushLocal(sym.entry());
            _emitter->writeReturn();
        }
    }

    void Generator::buildStatements(const Node& body) const
    {
        Node::NodeArray statements;
        body.filter(statements, RuleStatement);
        for (const Node* child : statements)
        {
            const Node& statement = *child;

            const Node& stmt = statement.rule(0);

            switch (stmt.type())
            {
            case RuleLetStatement:
                buildLetStatement(stmt);
                break;
            case RuleReturnStatement:
                buildReturnStatement(stmt);
                break;
            default:
                break;
            }
        }
    }

    void Generator::buildClass(Node* node) const
    {
        const Node& clsDesc = node->rule(3, RuleClassDescription);

        buildGlobals(clsDesc);

        buildMethods(clsDesc);
    }

    void Generator::parseImpl(const Node* root) const
    {
        _emitter->initialize();

        for (Node* firstChild : root->children())
        {
            if (firstChild->isTypeOf(RuleClass))
            {
                _globals->clear();
                _locals->clear();

                buildClass(firstChild);
            }
        }
    }

    void Generator::parse(const String& file) const
    {
        Analyzer::Parser parser;
        parser.parse(file);
        parseImpl(parser.getTree().getRoot());
    }

    void Generator::parse(IStream& stream) const
    {
        Analyzer::Parser parser;
        parser.parse(stream);
        parseImpl(parser.getTree().getRoot());
    }

    void Generator::write(const String& file) const
    {
        Path path = file;
        path      = absolute(path);

        std::ofstream stream(path);
        if (!stream.is_open())
            throw InputException("failed to open the output file ", path.string());

        write(stream);
    }

    void Generator::write(OStream& stream) const
    {
        const String buffer = _emitter->stream().str();
        stream.write(buffer.c_str(), buffer.size());
    }

}  // namespace Hack::Compiler::CodeGenerator
