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
#include "Compiler/Common/Node.h"
#include <utility>
#include "Utils/Exceptions/Exception.h"

namespace Hack::Compiler
{
    Node::Node() :
        _parent(nullptr),
        _type(-1)
    {
    }

    Node::Node(const int8_t type) :
        _parent(nullptr),
        _type(type)
    {
    }

    Node::Node(const int8_t type, String data) :
        _parent(nullptr),
        _type(type),
        _data(std::move(data))
    {
    }

    Node::~Node()
    {
        for (Node* chi : _children)
            delete chi;
        _children.clear();
    }

    Node* Node::getChild(const size_t idx) const
    {
        if (idx < _children.size())
            return _children.at(idx);

        IndexOutOfBounds();

    }

    void Node::addChild(Node* node)
    {
        if (!node)
            InvalidPointer();
        _children.insert(node);
        node->_parent = this;
    }

    void Node::addChild(const int8_t type, const String& data)
    {
        addChild(new Node(type, data));
    }

    void Node::addChild(int8_t type)
    {
        addChild(new Node(type));
    }

}  // namespace Hack::Compiler
