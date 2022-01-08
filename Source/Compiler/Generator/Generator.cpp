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
#include "Compiler/Generator/SymbolTable.h"
#include "Compiler/Generator/VmEmitter.h"
#include "Utils/Exception.h"
#include "Utils/FileSystem.h"

namespace Hack::Compiler::CodeGenerator
{
    Generator::Generator() :
        _globals(new SymbolTable()),
        _locals(new SymbolTable()),
        _emitter(new VmEmitter()),
        _hasReturn(false)
    {
    }

    Generator::~Generator()
    {
        delete _globals;
        delete _locals;
        delete _emitter;
    }

    void Generator::pushIdentifier(const Node& constantIdentifier) const
    {
        const String& value = constantIdentifier.value();

        if (_locals->contains(value))
        {
            const Symbol& sym = _locals->get(value);
            if (sym.kind() == Argument)
                _emitter->pushArgument(sym.entry());
            else if (sym.kind() == Local)
                _emitter->pushLocal(sym.entry());
        }
        else if (_globals->contains(value))
        {
            const Symbol& sym = _globals->get(value);
            if (sym.kind() == Field)
                _emitter->pushThis(sym.entry());
            else if (sym.kind() == Static)
                _emitter->pushStatic(sym.entry());
        }
        else
        {
            throw InputException("The value '", value, "' was not found.");
        }
    }

    void Generator::buildConstant(const Node& simpleTerm) const
    {
        switch (simpleTerm.type())
        {
        case ConstantInteger:
            _emitter->pushConstant(simpleTerm.value());
            break;
        case ConstantThis:
            _emitter->pushThis(0);
            break;
        case ConstantNull:
        case ConstantFalse:
            _emitter->pushConstant("0");
            break;
        case ConstantTrue:
            _emitter->pushConstant("65536");
            break;
        case ConstantIdentifier:
            pushIdentifier(simpleTerm);
            break;
        default:
            compileError(simpleTerm, "unhandled constant ", (int)simpleTerm.type());
        }
    }

    void Generator::buildUnaryOperation(const Node& unary) const
    {
        switch (unary.type())
        {
        case SymbolMinus:
            _emitter->symbolNeg();
            break;
        case SymbolNot:
            _emitter->symbolNot();
            break;
        default:
            compileError(unary, "unknown unary operation type ", unary.type());
        }
    }

    void Generator::buildOperation(const Node& op) const
    {
        switch (op.type())
        {
        case SymbolPlus:
            _emitter->symbolAdd();
            break;
        case SymbolMinus:
            _emitter->symbolSub();
            break;
        case SymbolAnd:
            _emitter->symbolAnd();
            break;
        case SymbolOr:
            _emitter->symbolOr();
            break;
        case SymbolGreater:
            _emitter->symbolGreater();
            break;
        case SymbolLess:
            _emitter->symbolLess();
            break;
        case SymbolEquals:
            _emitter->symbolEquals();
            break;
        default:
            compileError(op, "unknown operation type ", op.type());
        }
    }

    /// <summary>
    /// <code>
    /// <SimpleTerm> ::= Integer
    ///                | String
    ///                | True
    ///                | False
    ///                | Null
    ///                | This
    ///                | Identifier
    /// </code>
    /// </summary>
    /// <param name="simpleTerm"></param>
    void Generator::buildSimpleTerm(const Node& simpleTerm) const
    {
        const Node& term0 = simpleTerm.child(0);
        if (term0.isConstant())
            buildConstant(term0);
        else
        {
            compileError(term0,
                         "expected simple term to "
                         "reduce to a constant");
        }
    }

    /// <summary>
    /// <code>
    /// ComplexTerm ::= Identifier '[' Expression ']'
    ///               | CallMethod
    ///               | '(' Expression  ')'
    /// </code>
    /// </summary>
    /// <param name="complexTerm"></param>
    void Generator::buildComplexTerm(const Node& complexTerm) const
    {
        if (complexTerm.isSubtypeOf(SubtypeExpressionGroup))
            buildExpression(complexTerm.child(1));
        else if (complexTerm.isSubtypeOf(SubtypeCall))
            buildCallMethod(complexTerm.child(0));
        else if (complexTerm.isSubtypeOf(SubtypeArrayIndex))
        {
            buildConstant(complexTerm.child(0));
            buildExpression(complexTerm.child(2));
            _emitter->symbolAdd();
            _emitter->popPointer(1);
            _emitter->pushThat(0);
        }
    }

    /// <summary>
    /// <code>
    /// Term ::= SimpleTerm | ComplexTerm
    /// </code>
    /// </summary>
    /// <param name="term"></param>
    void Generator::buildTerm(const Node& term) const
    {
        const size_t numTerms = term.size();

        if (numTerms)
        {
            const Node& term0 = term.child(0);

            if (term0.isTypeOf(RuleSimpleTerm))
                buildSimpleTerm(term0);
            else if (term0.isTypeOf(RuleComplexTerm))
                buildComplexTerm(term0);
            else
            {
                compileError(term0,
                             "unknown terminal type, it should "
                             "be either a simple or complex type");
            }
        }
    }

    /// <summary>
    /// <code>
    /// LetStatement ::= Let Identifier '=' Expression ';'
    ///                | Let Identifier '['  Expression  ']' '='  Expression  ';'
    /// </code>
    /// </summary>
    /// <param name="statement"></param>
    void Generator::buildLetStatement(const Node& statement) const
    {
        if (statement.isSubtypeOf(SubtypeLetEqual))
        {
            // expects rule 0
            const String& id = statement.constant(1, ConstantIdentifier).value();

            const Node& expression = statement.rule(3, RuleExpression);

            const Symbol sym = lookup(id);
            if (sym.isValid())
            {
                buildExpression(expression);
                popSymbol(sym);
            }
            else
                compileError(statement, "variable '", id, "' not found");
        }
        else if (statement.isSubtypeOf(SubtypeLetArrayEqual))
        {
            const Node& id = statement.rule(1, ConstantIdentifier);
            pushIdentifier(id);

            const Node& arrayExpr = statement.rule(3, RuleExpression);
            buildExpression(arrayExpr);
            _emitter->symbolAdd();   // base address offset
            _emitter->popPointer(1); // move the base address into the current pointer

            const Node& assign = statement.rule(6, RuleExpression);
            buildExpression(assign);

            _emitter->popThat(0);
        }
        else
        {
            // compile error
        }
    }

    /// <summary>
    /// ReturnStatement ::= Return ';' | Return Expression ';'
    /// <code></code>
    /// </summary>
    /// <param name="statement"></param>
    void Generator::buildReturnStatement(const Node& statement) const
    {
        _hasReturn = true;

        const Node& term1 = statement.child(1);

        if (term1.isTypeOf(SymbolSemiColon))
            _emitter->pushConstant(0);
        else if (term1.isTypeOf(RuleExpression))
            buildExpression(term1);
        else
            compileError(statement, "invalid terminal type");

        _emitter->writeReturn();
    }

    /// <summary>
    /// <code>
    ///  SingleExpression ::= Term
    ///                        | Operator Term
    ///                        | UnaryOperator Term
    /// </code>
    /// </summary>
    /// <param name="singleExpression"></param>
    void Generator::buildSingleExpression(const Node& singleExpression) const
    {
        const size_t numTerms = singleExpression.size();
        if (numTerms > 0)
        {
            const Node& term0 = singleExpression.child(0);
            if (singleExpression.isSubtypeOf(SubtypeTerm))
            {
                if (term0.isTypeOf(RuleTerm))
                    buildTerm(term0);
            }
            else if (singleExpression.isSubtypeOf(SubtypeOpTerm))
            {
                const Node& term1 = singleExpression.child(1);

                if (term1.isTypeOf(RuleTerm))
                    buildTerm(term1);
                else
                    compileError(term1, "invalid terminal type");

                if (term0.isTypeOf(RuleOperator))
                    buildOperation(term0.child(0));
                else if (term0.isTypeOf(RuleUnaryOperator))
                    buildUnaryOperation(term0.child(0));
                else
                    compileError(term1, "invalid operator type");
            }
            else
                compileError(singleExpression, "invalid terminal expression type");
        }
        else
            compileError(singleExpression, "empty expression");
    }

    /// <summary>
    /// <code>
    /// Expression ::= ExpressionSingleExpression
    ///                | SingleExpression
    /// </code>
    /// </summary>
    /// <param name="expression"></param>
    void Generator::buildExpression(const Node& expression) const
    {
        for (const Node* exp : expression.children())
        {
            const Node& singleExpression = *exp;
            buildSingleExpression(singleExpression);
        }
    }

    /// <summary>
    /// <code>
    /// ExpressionList ::= ExpressionList ','  Expression
    ///                    | Expression
    ///                    | !--empty--
    /// </code>
    /// </summary>
    /// <param name="expressionList"></param>
    void Generator::buildExpressionList(const Node& expressionList) const
    {
        const Node::Children& expressions = expressionList.children();
        for (const Node* child : expressions)
        {
            const Node& expression = *child;

            buildExpression(expression);
        }
    }

    /// <summary>
    /// <code>
    /// CallMethod ::= Identifier '(' ExpressionList ')'
    ///                | Identifier '.' Identifier '(' ExpressionList ')'
    /// </code>
    /// </summary>
    /// <param name="callMethod"></param>
    void Generator::buildCallMethod(const Node& callMethod) const
    {
        if (callMethod.isSubtypeOf(SubtypeCallFunction))
        {
            const Node& id             = callMethod.constant(0, ConstantIdentifier);
            const Node& expressionList = callMethod.rule(2, RuleExpressionList);

            buildExpressionList(expressionList);

            _emitter->writeCall(id.value(), expressionList.size());
        }
        else if (callMethod.isSubtypeOf(SubtypeCallMethod))
        {
            const Node& classId  = callMethod.constant(0, ConstantIdentifier);
            const Node& methodId = callMethod.constant(2, ConstantIdentifier);

            const Node& expressionList = callMethod.rule(4, RuleExpressionList);

            // will need to be looked back up
            // when compiling to a binary
            const String id = StringCombine(classId.value(), '.', methodId.value());

            buildExpressionList(expressionList);

            _emitter->writeCall(id, expressionList.children().size());
        }
        else
        {
            // error
        }
    }

    /// <summary>
    /// <code>
    /// DoStatement ::= Do CallMethod ';'
    /// </code>
    /// </summary>
    /// <param name="statement"></param>
    void Generator::buildDoStatement(const Node& statement) const
    {
        const Node& callMethod = statement.rule(1, RuleCallMethod);
        buildCallMethod(callMethod);
    }

    /// <summary>
    /// <code>
    /// IfStatement ::= If '(' Expression ')' '{' StatementList '}'
    ///                 | Else '{'  StatementList  '}'
    /// </code>
    /// </summary>
    /// <param name="statement"></param>
    void Generator::buildElseStatement(const Node& statement) const
    {
        if (_elseEnd.empty())
            compileError(statement, "else statement without matching if statement");

        const Node& term2 = statement.rule(2, RuleStatementList);
        buildStatements(term2);
        _emitter->writeLabel(_elseEnd);
    }

    /// <summary>
    /// <code>
    /// IfStatement ::= If '(' Expression ')' '{' StatementList '}'
    ///                 | Else '{'  StatementList  '}'
    /// </code>
    /// </summary>
    /// <param name="statement"></param>
    void Generator::buildIfStatement(const Node& statement) const
    {
        const Node& term2 = statement.rule(2, RuleExpression);
        const Node& term5 = statement.rule(5, RuleStatementList);

        const String l0 = _emitter->generateLabel();
        buildExpression(term2);

        _emitter->writeIfStart(l0);

        buildStatements(term5);

        if (term5.isSubtypeOf(SubtypeIfElseCombo))
        {
            _elseEnd = _emitter->generateLabel();
            _emitter->writeGoto(_elseEnd);
        }

        _emitter->writeLabel(l0);
    }

    /// <summary>
    /// <code>
    /// WhileStatement ::= While '(' Expression ')' '{' StatementList '}'
    /// </code>
    /// </summary>
    /// <param name="statement"></param>
    void Generator::buildWhileStatement(const Node& statement) const
    {
        const Node& term2 = statement.rule(2, RuleExpression);
        const Node& term5 = statement.rule(5, RuleStatementList);

        const String l1 = _emitter->generateLabel();
        const String l0 = _emitter->generateLabel();

        _emitter->writeLabel(l1);
        buildExpression(term2);
        _emitter->writeIfStart(l0);

        buildStatements(term5);

        _emitter->writeGoto(l1);
        _emitter->writeLabel(l0);
    }

    /// <summary>
    /// <code>
    /// StatementList ::= StatementList Statement
    ///                   | Statement
    ///                   |
    /// </code>
    /// </summary>
    /// <param name="methodBody"></param>
    void Generator::buildStatements(const Node& methodBody) const
    {
        // extract only the statements from the method body
        const Node::Children& statements = methodBody.children();

        for (const Node* child : statements)
        {
            const Node& statement = *child;
            if (statement.isTypeOf(RuleStatement))
            {
                const Node& stmt = statement.rule(0);

                switch (stmt.type())
                {
                case RuleLetStatement:
                    buildLetStatement(stmt);
                    break;
                case RuleReturnStatement:
                    buildReturnStatement(stmt);
                    break;
                case RuleDoStatement:
                    buildDoStatement(stmt);
                    break;
                case RuleIfStatement:
                    _elseEnd.clear();
                    buildIfStatement(stmt);
                    break;
                case RuleElseStatement:
                    buildElseStatement(stmt);
                    break;
                case RuleWhileStatement:
                    buildWhileStatement(stmt);
                    break;
                default:
                    compileError(stmt, "unknown statement type ", stmt.type());
                }
            }
            else if (statement.isTypeOf(RuleInlineVm))
            {
                _emitter->writeCode(RuleInlineVm, statement.child(0).value());
            }
            else if (statement.isTypeOf(RuleInlineAsm))
            {
                _emitter->writeCode(RuleInlineAsm, statement.child(0).value());
            }
        }
    }

    Symbol Generator::lookup(const String& name) const
    {
        if (_locals->contains(name))
            return _locals->get(name);
        if (_globals->contains(name))
            return _globals->get(name);
        return Symbol();
    }

    void Generator::popSymbol(const Symbol& symbol) const
    {
        switch (symbol.kind())
        {
        case Local:
            _emitter->popLocal(symbol.entry());
            break;
        case Argument:
            _emitter->popArgument(symbol.entry());
            break;
        case Field:
            _emitter->popThis(symbol.entry());
            break;
        case Static:
            _emitter->popStatic(symbol.entry());
            break;
        default:
            break;
        }
    }

    void Generator::buildLocals(const Node& bodyNode,
                                const Node& parameters) const
    {
        _locals->clear();

        Node::NodeArray variables;
        bodyNode.filter(variables, RuleVariable);

        for (const Node* var : variables)
        {
            const Node& variable = *var;

            const int8_t type           = variable.rule(1, RuleDataType).type();
            const Node&  identifierList = variable.rule(2, RuleIdentifierList);

            for (Node* id : identifierList)
                _locals->insert(id->value(), type, Local);
        }

        for (const Node* par : parameters.children())
        {
            const Node& parameter = *par;

            const int8_t type = parameter.rule(0, RuleDataType).type();

            _locals->insert(parameter.constant(1, ConstantIdentifier).value(),
                            type,
                            Argument);
        }
    }

    /// <summary>
    /// <code>
    /// ClassDescription  ::= ClassDescription Field ';'
    ///                       | ClassDescription Method
    ///                       |
    /// </code>
    /// </summary>
    /// <param name="classDescription"></param>
    void Generator::buildClassDescription(const Node& classDescription) const
    {
        buildGlobals(classDescription);

        const String& className = classDescription.parent().child(1).value();

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

            buildLocals(body, parameterList);

            const uint16_t tot = (uint16_t)_locals->localCount();

            _emitter->writeMethod(className, methodName.value(), tot);

            _hasReturn = false;
            buildStatements(body);

            if (!_hasReturn)
            {
                _emitter->pushConstant(0);
                _emitter->writeReturn();
            }
        }
    }

    void Generator::buildGlobals(const Node& classDescription) const
    {
        _globals->clear();

        Node::NodeArray field;
        classDescription.filter(field, RuleField);

        for (const Node* child : field)
        {
            const Node& ch             = *child;
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

    /// <summary>
    /// <code>
    /// Class ::= Class Identifier '{' ClassDescription '}'
    /// </code>
    /// </summary>
    /// <param name="node"></param>
    void Generator::buildClass(Node* node) const
    {
        const Node& description = node->rule(3, RuleClassDescription);

        buildClassDescription(description);
    }

    void Generator::parseImpl(const Node* root) const
    {
        _emitter->initialize();

        try
        {
            for (Node* firstChild : root->children())
            {
                if (firstChild->isTypeOf(RuleClass))
                    buildClass(firstChild);
            }
        }
        catch (Exception& ex)
        {
            compileError(*root, "compilation failed\n", ex.what());
        }

        _emitter->finalize();
    }

    void Generator::compile(const Node* tree)
    {
        if (!tree)
            throw InvalidPointer();

        _fileName = tree->filename();
        parseImpl(tree);
    }

    void Generator::write(const String& file) const
    {
        Path path = file;
        path      = absolute(path);

        std::ofstream stream(path);

        if (!stream.is_open())
        {
            throw InputException("failed to open the output file ",
                                 path.string());
        }

        write(stream);
    }

    void Generator::write(OStream& stream) const
    {
        const String buffer = _emitter->stream().str();
        stream.write(buffer.c_str(), buffer.size());
    }
} // namespace Hack::Compiler::CodeGenerator
