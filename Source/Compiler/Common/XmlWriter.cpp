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
#include "Compiler/Common/XmlWriter.h"
#include <iomanip>
#include "Compiler/Common/Node.h"

namespace Hack::Compiler
{
    constexpr size_t Indent = 2;

    class XmlWriterImpl
    {
    private:
        Node*              _root;
        OStream*           _stream;
        OutputStringStream _out;

        int _indent;

        void openTag(const String& name, Node* node)
        {
            _out << std::setw((size_t)(_indent - 1)) << ' ';
            _out << '<' << name;
            if (node->subtype() != SubtypeNone)
            {
                String subTypeName;
                NodeUtils::nodeSubtypeString(subTypeName, node);
                _out << " Subtype=\"" << subTypeName << "\">" << std::endl;
            }
            else
            {
                _out << '>' << std::endl;
            }
            _indent += Indent;
        }

        void closeTag(const String& name)
        {
            _indent -= Indent;
            _out << std::setw((size_t)(_indent - 1)) << ' ';
            _out << '<' << '/' << name << '>' << std::endl;
        }

        void inlineTag(const String& name, const String& value)
        {
            _out << std::setw((size_t)(_indent - 1)) << ' ';
            _out << '<' << name << '>' << ' ' << value << ' ';
            _out << '<' << '/' << name << '>' << std::endl;
        }
        
    public:
        explicit XmlWriterImpl(Node* root, OStream* stream) :
            _root(root), _stream(stream), _indent(0)
        {
        }

        void writeHeader()
        {
            _out << "<?xml version='1.0'?>" << std::endl;
            _out << "<ClassList>" << std::endl;
            _indent += Indent;
        }

        void writeFooter()
        {
            _indent -= Indent;
            _out << "</ClassList>" << std::endl;
        }

        void writeRule(Node* node)
        {
            String name, typeValue;
            NodeUtils::nodeTypeXmlString(name, node);
            openTag(name, node);

            const Node::Children& ch = node->children();

            for (Node* nd : ch)
            {
                NodeUtils::nodeTypeXmlString(typeValue, nd);

                if (nd->isKeyword())
                    inlineTag("Keyword", typeValue);
                else if (nd->isConstant())
                    inlineTag("Identifier", typeValue);
                else if (nd->isSymbol())
                    inlineTag("Symbol", typeValue);
                else if (nd->isRule())
                    writeRule(nd);
                else
                    inlineTag("Undefined", nd->value());
            }
            closeTag(name);
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

    XmlWriter::XmlWriter(Node* root) :
        _root(root)
    {
    }

    void XmlWriter::write(OStream& out) const
    {
        XmlWriterImpl impl(_root, &out);
        impl.write();
    }

}  // namespace Hack::Compiler
