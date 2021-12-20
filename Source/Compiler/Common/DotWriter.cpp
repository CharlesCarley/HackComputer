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
#include "Compiler/Common/DotWriter.h"
#include <iomanip>
#include "Compiler/Common/Node.h"

namespace Hack::Compiler
{
    constexpr size_t Indent = 2;

    class DotWriterImpl
    {
    private:
        Node*              _root;
        OStream*           _stream;
        OutputStringStream _out;

        int _indent;

        void writeNodeCluster(Node* nd)
        {
            String str;
            typeString(str, nd);

            _indent += Indent;
            indent();
            _out << "node" << (size_t)nd << " [shape=none, label =\"" << str << "\"]";
            _out << std::endl;
        }

        void writeNode(Node* nd)
        {
            String str;
            typeString(str, nd);

            indent();
            _out << "node" << (size_t)nd << "[shape=none, label =\"" << str << "\"]";
            _out << std::endl;
        }

        void closeNode()
        {
            _indent -= Indent;
            _out << std::endl;
        }

        void lineTo(Node* a, const Node* b)
        {
            indent();
            _out << "node" << (size_t)a;
            _out << "->";
            _out << "node" << (size_t)b;
            _out << "[";
            _out << "arrowhead=none";
            _out << "]";
            _out << std::endl;
        }
        void indent()
        {
            _out << std::setw((size_t)(_indent - 1)) << ' ';
        }

        static void typeString(String& dest, Node* node);

    public:
        explicit DotWriterImpl(Node* root, OStream* stream) :
            _root(root),
            _stream(stream),
            _indent(0)
        {
        }

        void writeHeader()
        {
            _indent += Indent;
            _out << "digraph ClassList {" << std::endl;
            indent();
            _out << "rankdir = LR;" << std::endl;
            indent();
            _out << "layout  = dot;" << std::endl;
        }

        void writeFooter()
        {
            _indent -= Indent;
            _out << "}" << std::endl;
        }

        void writeRule(Node* node)
        {
            writeNodeCluster(node);

            const Node::Children& ch = node->children();

            for (Node* nd : ch)
            {
                writeNode(nd);

                if (nd->isKeyword() || nd->isConstant() || nd->isSymbol())
                    lineTo(node, nd);
                else if (nd->isRule())
                {
                    writeRule(nd);
                    lineTo(node, nd);
                }
            }

            closeNode();
        }

        void write()
        {
            writeHeader();
            const Node::Children& ch = _root->children();

            for (Node* nd : ch)
            {
                if (nd->isRule())
                    writeRule(nd);
            }

            writeFooter();

            const String dest = _out.str();
            _stream->write(dest.c_str(), dest.size());
        }
    };

    DotWriter::DotWriter(Node* root) :
        _root(root)
    {
    }

    void DotWriter::write(OStream& out) const
    {
        DotWriterImpl impl(_root, &out);
        impl.write();
    }

    void DotWriterImpl::typeString(String& dest, Node* node)
    {
        switch (node->type())
        {
        default:
        case RuleEnd:
        case Keyword:
        case KeywordEnd:
        case Rule:
        case Symbol:
        case SymbolEnd:
        case Constant:
        case ConstantEnd:
            dest = "Unknown";
            break;
        case RuleClass:
            dest = "Class";
            break;
        case RuleClassDescription:
            dest = "ClassDescription";
            break;
        case RuleField:
            dest = "Field";
            break;
        case RuleDataType:
            dest = "DataType";
            break;
        case RuleFieldSpecification:
            dest = "FieldSpecification";
            break;
        case RuleIdentifierList:
            dest = "IdentifierList";
            break;
        case RuleMethod:
            dest = "Method";
            break;
        case RuleMethodSpecification:
            dest = "MethodSpecification";
            break;
        case RuleMethodReturnType:
            dest = "MethodReturnType";
            break;
        case RuleMethodBody:
            dest = "MethodBody";
            break;
        case RuleBody:
            dest = "Body";
            break;
        case RuleVariable:
            dest = "Variable";
            break;
        case RuleStatement:
            dest = "Statement";
            break;
        case RuleLetStatement:
            dest = "LetStatement";
            break;
        case RuleIfStatement:
            dest = "IfStatement";
            break;
        case RuleElseStatement:
            dest = "ElseStatement";
            break;
        case RuleWhileStatement:
            dest = "WhileStatement";
            break;
        case RuleDoStatement:
            dest = "DoStatement";
            break;
        case RuleReturnStatement:
            dest = "ReturnStatement";
            break;
        case RuleStatementList:
            dest = "StatementList";
            break;
        case RuleExpression:
            dest = "Expression";
            break;
        case RuleSingleExpression:
            dest = "SingleExpression";
            break;
        case RuleTerm:
            dest = "Term";
            break;
        case RuleSimpleTerm:
            dest = "SimpleTerm";
            break;
        case RuleComplexTerm:
            dest = "ComplexTerm";
            break;
        case RuleOperator:
            dest = "Operator";
            break;
        case RuleUnaryOperator:
            dest = "UnaryOperator";
            break;
        case RuleExpressionList:
            dest = "ExpressionList";
            break;
        case RuleCallMethod:
            dest = "CallMethod";
            break;
        case RuleParameterList:
            dest = "ParameterList";
            break;
        case RuleParameter:
            dest = "Parameter";
            break;
        case KeywordClass:
            dest = "class";
            break;
        case KeywordConstructor:
            dest = "constructor";
            break;
        case KeywordFunction:
            dest = "function";
            break;
        case KeywordMethod:
            dest = "method";
            break;
        case KeywordField:
            dest = "field";
            break;
        case KeywordStatic:
            dest = "static";
            break;
        case KeywordInt:
            dest = "int";
            break;
        case KeywordChar:
            dest = "char";
            break;
        case KeywordBool:
            dest = "boolean";
            break;
        case KeywordVoid:
            dest = "void";
            break;
        case KeywordVar:
            dest = "var";
            break;
        case KeywordLet:
            dest = "let";
            break;
        case KeywordIf:
            dest = "if";
            break;
        case KeywordElse:
            dest = "else";
            break;
        case KeywordDo:
            dest = "do";
            break;
        case KeywordWhile:
            dest = "while";
            break;
        case KeywordReturn:
            dest = "return";
            break;
        case SymbolOpenBrace:
            dest = "{";
            break;
        case SymbolCloseBrace:
            dest = "}";
            break;
        case SymbolLeftParenthesis:
            dest = "(";
            break;
        case SymbolRightParenthesis:
            dest = ")";
            break;
        case SymbolSemiColon:
            dest = ";";
            break;
        case SymbolComma:
            dest = ",";
            break;
        case SymbolEquals:
            dest = "=";
            break;
        case SymbolPlus:
            dest = "+";
            break;
        case SymbolMinus:
            dest = "-";
            break;
        case SymbolMultiply:
            dest = "*";
            break;
        case SymbolDivide:
            dest = "/";
            break;
        case SymbolAnd:
            dest = "&";
            break;
        case SymbolOr:
            dest = "|";
            break;
        case SymbolGreater:
            dest = ">";
            break;
        case SymbolLess:
            dest = "<";
            break;
        case SymbolNot:
            dest = "!";
            break;
        case SymbolPeriod:
            dest = ".";
            break;
        case SymbolLeftBracket:
            dest = "[";
            break;
        case SymbolRightBracket:
            dest = "]";
            break;
        case ConstantTrue:
            dest = "true";
            break;
        case ConstantFalse:
            dest = "false";
            break;
        case ConstantNull:
            dest = "null";
            break;
        case ConstantThis:
            dest = "this";
            break;
        case ConstantString:
        case ConstantInteger:
        case ConstantIdentifier:
            dest = node->value();
            break;
        }
    }

}  // namespace Hack::Compiler
