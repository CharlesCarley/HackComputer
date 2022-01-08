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
#ifndef _XMLDocument_h_
#define _XMLDocument_h_

#include <stack>
#include <vector>
#include "Utils/FileSystem.h"
#include "XmlNode.h"
#include "expat.h"

namespace Hack::DocConverter
{
    class XmlDocument
    {
    public:
        typedef std::vector<Node*> NodeArray;
        typedef std::stack<Node*>  NodeStack;

        static const int BlockLen = 2048;

    private:
        NodeArray _nodes;
        NodeStack _stack;
        NodeArray _rootNodes;
        int       _offset;

        static NodeType getNodeType(const XML_Char* name);

        void startTag(const XML_Char* name, const XML_Char** attributes);

        void data(const XML_Char* string, int len);

        void endTag();

    public:
        XmlDocument();

        ~XmlDocument();

        void parse(const Path& path);

        void parse(IStream& stream);

        NodeArray& nodes();
    };

}  // namespace Hack::DocConverter

#endif  //_XMLDocument_h_
