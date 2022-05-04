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
#include "Computer/AssemblyDebugger.h"
#include "AssemblyDebugger/AssemblyDebuggerPrivate.h"
#include "Chips/Computer.h"
#include "Utils/UserInterface/Context.h"

namespace Hack::Computer
{
    AssemblyDebugger::AssemblyDebugger() :
        _private(new AssemblyDebuggerPrivate())
    {
    }

    AssemblyDebugger::~AssemblyDebugger()
    {
        delete _private;
        _private = nullptr;
    }

    bool AssemblyDebugger::shouldUpdate()
    {
        return _private->input() == Ui::PR_UP_ARROW ||
               _private->input() == Ui::PR_R ||
               !_private->block();
    }

    void AssemblyDebugger::initialize(Chips::Computer* computer,
                                      Chips::Screen*) const
    {
        _private->initialize(computer);
        _private->flushMemory(computer);
    }

    bool AssemblyDebugger::exitRequest() const
    {
        return _private->input() == Ui::PR_EXIT;
    }

    void AssemblyDebugger::processEvents(Chips::Computer* computer) const
    {
        _private->processEvents(computer);
    }

    void AssemblyDebugger::flushMemory(Chips::Computer* computer) const
    {
        if (computer)
            computer->captureState();
        _private->flushMemory(computer);
    }

    void AssemblyDebugger::update(Chips::Computer* computer) const
    {
        if (computer)
            computer->update(false);
    }

}  // namespace Hack::Computer
