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
    class DotWriterImpl
    {
    private:
        Node*              _root;
        OStream*           _stream;
        OutputStringStream _out;

        void writeNodeCluster(Node* nd)
        {
            String str;
            NodeUtils::nodeTypeString(str, nd);

            _out << std::setw(3) << ' ';
            _out << "node_" << std::hex << (size_t)nd << " [shape=none, label =\"" << str << "\"]";
            _out << std::endl;
        }

        void writeNode(Node* nd)
        {
            String str;
            NodeUtils::nodeTypeXmlString(str, nd);

            _out << std::setw(3) << ' ';
            _out << "node_" << std::hex << (size_t)nd << "[shape=none, label =\"" << str << "\"]";
            _out << std::endl;
        }

        void lineTo(Node* a, const Node* b)
        {
            _out << std::setw(3) << ' ';
            _out << "node_" << std::hex << (size_t)a; 
            _out << "->";
            _out << "node_" << std::hex << (size_t)b ;
            _out << "[";
            _out << "arrowhead=none";
            _out << "]";
            _out << std::endl;
        }
        
    public:
        DotWriterImpl(Node* root, OStream* stream) :
            _root(root),
            _stream(stream)
        {
        }

        void writeHeader()
        {
            _out << "digraph ClassList {" << std::endl;
            _out << std::setw(3) << ' ';
            _out << "rankdir = LR;" << std::endl;
            _out << std::setw(3) << ' ';
            _out << "layout  = dot;" << std::endl;
        }

        void writeFooter()
        {
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
    
}  // namespace Hack::Compiler
