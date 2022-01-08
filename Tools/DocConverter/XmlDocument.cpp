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

#include "XmlDocument.h"
#include <cstdio>
#include <fstream>
#include "Common.h"
#include "Utils/Char.h"
#include "Utils/Exception.h"
#include "XmlNode.h"
#include "expat.h"

namespace Hack::DocConverter
{
    XmlDocument::XmlDocument() = default;

    XmlDocument::~XmlDocument()
    {
        for (Node* node : _nodes)
            delete node;
    }

    NodeType XmlDocument::getNodeType(const XML_Char* name)
    {
        if (Char::equals("doxygen", name, 7))
            return NT_DOXYGEN;
        if (Char::equals("compounddefType", name, 15))
            return NT_COMPOUND_DEF;
        return NT_UNKNOWN;
    }

    void XmlDocument::startTag(const XML_Char* name, const XML_Char** attributes)
    {
        const NodeType type = getNodeType(name);

        Node* node = new Node(type);

        _offset = 0;
        // keep a running list of the allocations.
        _nodes.push_back(node);

        if (attributes != nullptr)
        {
            int j = 0;
            while (attributes[j] != nullptr)
            {
                const XML_Char* key = attributes[j];
                const XML_Char* val = attributes[j + 1];

                if (key != nullptr && val != nullptr)
                {
                    // It's not an identifier so just keep a record of it.
                    if (!node->contains(key))
                        node->insert(key, new Attribute(key, val));
                }

                j += 2;
            }
        }

        _stack.push(node);
    }

    void XmlDocument::data(const XML_Char* string, int len)
    {
        const String value(string, len);
        if (!value.empty())
            _stack.top()->append(value);
    }

    void XmlDocument::endTag()
    {
        if (!_stack.empty())
        {
            Node* top = _stack.top();
            _stack.pop();

            if (!_stack.empty())
            {
                Node* node = _stack.top();
                node->addChild(top);
            }
            else
                _rootNodes.push_back(top);
        }
    }

    void XmlDocument::parse(const Path& path)
    {
        std::ifstream in(path.string());
        if (!in.is_open())
            throw Exception("failed to open the supplied file '", path, '\'');

        parse(in);
    }

    void XmlDocument::parse(IStream& stream)
    {
        bool status = true;

        XML_ParserStruct* parser = XML_ParserCreate(nullptr);

        if (parser)
        {
            XML_SetUserData(parser, this);

            // clang-format off
            XML_SetStartElementHandler(parser, 
            [](void* userData, const XML_Char* name, const XML_Char** attributes) {

                XmlDocument *user = (XmlDocument*)userData;
                if (user)
                    user->startTag(name, attributes);
            });
            XML_SetEndElementHandler(parser, 
                [](void* userData, const XML_Char*) {

                    XmlDocument *user = (XmlDocument*)userData;
                    if (user)
                        user->endTag();
                    
            });

            XML_SetCharacterDataHandler(parser,
                [](void * userData, const XML_Char * string, const int len) {
                    XmlDocument *user = (XmlDocument*)userData;
                    if (user)
                        user->data(string, len);
                
            });
            // clang-format on

            do
            {
                IStream::pos_type br;

                char* buffer = (char*)XML_GetBuffer(parser, BlockLen);

                if (!buffer)
                    throw Exception("Failed to get buffer.");

                stream.read(buffer, BlockLen);
                br = stream.gcount();

                if (br <= 0 || br > BlockLen)
                    throw Exception("invalid read");

                if (XML_ParseBuffer(parser, BlockLen, br == 0) == XML_STATUS_ERROR && !stream.eof())
                {
                    const XML_Error code = XML_GetErrorCode(parser);

                    if (code != XML_ERROR_NONE)
                        throw Exception(XML_ErrorString(code),
                                        (int)XML_GetCurrentLineNumber(parser));

                    status = false;
                }
            } while (status && !stream.eof());
        }
        else
            throw Exception("Failed to create an expat parser.");

        XML_ParserFree(parser);
    }

    XmlDocument::NodeArray& XmlDocument::nodes()
    {
        return _rootNodes;
    }

}  // namespace Hack::DocConverter
