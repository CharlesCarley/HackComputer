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
#include "Computer/ConsoleRuntime.h"
#include "Chips/Computer.h"
#include "ConsoleRuntime/ConsoleRuntimePrivate.h"
#include "Utils/Char.h"
#include "Utils/UserInterface/Context.h"

namespace Hack::Computer
{
    ConsoleRuntime::ConsoleRuntime() :
        _private(new ConsoleRuntimePrivate())
    {
    }

    ConsoleRuntime::~ConsoleRuntime()
    {
        delete _private;
        _private = nullptr;
    }

    bool ConsoleRuntime::shouldUpdate()
    {
        return true;
    }

    void ConsoleRuntime::initialize(Chips::Computer* computer,
                                    Chips::Screen*) const
    {
        _private->initialize(computer);
    }

    bool ConsoleRuntime::exitRequest() const
    {
        return _private->input() == Ui::PR_EXIT;
    }

    void ConsoleRuntime::processEvents(Chips::Computer* computer) const
    {
        _private->processEvents();
    }

    void ConsoleRuntime::flushMemory(Chips::Computer*) const
    {
    }

    void ConsoleRuntime::update(Chips::Computer* computer) const
    {
        for (int16_t i = 0; i < getRate(); ++i)
            computer->update(false);
        computer->update(true);
        _private->update(computer);
    }
}  // namespace Hack::Computer
