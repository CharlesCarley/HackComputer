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

#include <unordered_map>
#include "Common.h"
#include "XmlAttribute.h"

namespace Hack::DocConverter
{
    class Node
    {
    public:
        typedef std::unordered_map<String, Attribute*> AttributeDictionary;
        typedef std::vector<Node*>                     Nodes;

    private:
        NodeType            _type;
        String              _id;
        AttributeDictionary _dict;
        Node*               _parent;
        Nodes               _children;
        String              _data;

        friend class XmlDocument;

        Attribute* getAttribute(const String& key);

    public:
        explicit Node(NodeType type);

        ~Node();

        bool contains(const String& key) const;

        void insert(const String& key, Attribute* attribute);

        bool attribute(const String& key, bool defaultValue = false);

        const String& attribute(const String& key, const String& defaultValue = nullptr);

        int attribute(const String& key,
                      const int&    defaultValue = 0,
                      const int&    defaultBase  = 10);

        void addChild(Node* child);

        Node* getParent() const;

        Nodes& children();

        void append(const String& data);

        const String& data() const;

        const NodeType& type() const;
    };

    inline Node* Node::getParent() const
    {
        return _parent;
    }

    inline Node::Nodes& Node::children()
    {
        return _children;
    }

    inline const NodeType& Node::type() const
    {
        return _type;
    }

    inline const String& Node::data() const
    {
        return _data;
    }

}  // namespace Hack::DocConverter
