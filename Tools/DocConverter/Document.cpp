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
#include "Document.h"
#include <fstream>

#include "XmlDocument.h"

namespace Hack::DocConverter
{
    Document::Document()
    {
    }

    Document::~Document()
    {
    }

    void Document::handleDoxygenNode(Node* doxy)
    {
        for (Node* node : doxy->children())
        {
            _out << "# " << node->attribute("title", "undefined") << std::endl;
        }

    }

    void Document::merge(const Path& path, const Path& out)
    {
        XmlDocument xml;
        xml.parse(path);

        XmlDocument::NodeArray& nodes = xml.nodes();
        for (Node* node : nodes)
        {
            if (node->type() == NT_DOXYGEN)
            {
                handleDoxygenNode(node);
            }
        }

        std::ofstream of(out.string());
        if (of.is_open())
        {
            const String str = _out.str();
            of.write(str.c_str(), str.size());
        }
    }

}  // namespace Hack::DocConverter
