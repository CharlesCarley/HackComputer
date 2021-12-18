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
#include "Compiler/Common/Tree.h"
#include <fstream>
#include <iostream>
#include "Compiler/Common/Node.h"
#include "Compiler/Common/XmlWriter.h"

namespace Hack::Compiler
{
    Tree::Tree() :
        _root(new Node())
    {
    }

    Tree::~Tree()
    {
        delete _root;
        _root = nullptr;
    }

    void Tree::read(IStream& in)
    {
    }

    void Tree::write(OStream& out, int format) const
    {
        if (format == 0)
        {
            const XmlWriter writer(_root);
            writer.write(out);
        }
        else
        {
        }
    }

}  // namespace Hack::Compiler
