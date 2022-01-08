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

#include "XmlNode.h"
#include "Common.h"
#include "Utils/Char.h"
#include "XmlAttribute.h"

namespace Hack::DocConverter
{
    Node::Node(const NodeType type) :
        _type(type),
        _parent(nullptr)
    {
    }

    Node::~Node()
    {
        _id.clear();

        for (auto& [str, attr] : _dict)
            delete attr;

        _dict.clear();
    }

    Attribute* Node::getAttribute(const String& key)
    {
        AttributeDictionary::iterator it = _dict.find(key);
        if (it != _dict.end())
            return it->second;
        return nullptr;
    }

    bool Node::contains(const String& key) const
    {
        return _dict.find(key) != _dict.end();
    }

    void Node::insert(const String& key, Attribute* attribute)
    {
        if (_dict.find(key) == _dict.end())
            _dict.insert(std::make_pair(key, attribute));
    }

    bool Node::attribute(const String& key, const bool defaultValue)
    {
        Attribute* attribute = getAttribute(key);

        if (attribute != nullptr)
        {
            const String& value = attribute->value();
            return Char::toBool(value.c_str());
        }
        return defaultValue;
    }

    const String& Node::attribute(const String& key, const String& defaultValue)
    {
        Attribute* attribute = getAttribute(key);

        if (attribute != nullptr)
            return attribute->value();
        return defaultValue;
    }

    int Node::attribute(const String& key,
                        const int&    defaultValue,
                        const int&    defaultBase)
    {
        Attribute* attribute = getAttribute(key);

        if (attribute != nullptr)
            return Char::toInt32(attribute->value().c_str(),
                                 defaultValue,
                                 defaultBase);
        return defaultValue;
    }

    void Node::addChild(Node* child)
    {
        if (child != nullptr)
        {
            _children.push_back(child);
            child->_parent = this;
        }
    }

    void Node::append(const String& data)
    {
        if (data.empty())
            return;

        OutputStringStream oss;

        for (char ch : data)
        {
            if (ch != '\r' && ch != '\n')
                oss << ch;
        }
        const String v = oss.str();
        if (_data.empty())
            _data = v;
        else
        {
            OutputStringStream s;
            s << _data << ' ' << v;
            _data = s.str();
        }
    }

}  // namespace Hack::DocConverter
