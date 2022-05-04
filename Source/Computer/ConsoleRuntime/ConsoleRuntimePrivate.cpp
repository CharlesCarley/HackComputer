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
#include "Computer/ConsoleRuntime/ConsoleRuntimePrivate.h"
#include "Chips/Computer.h"
#include "Utils/UserInterface/Context.h"

using namespace Hack::Chips;
using namespace Hack::Ui;

namespace Hack::Computer
{
    ConsoleRuntimePrivate::ConsoleRuntimePrivate() :
        _input(PR_NO_INPUT),
        _ram(nullptr),
        _rom(nullptr),
        _cpuState{}
    {
    }

    ConsoleRuntimePrivate::~ConsoleRuntimePrivate() = default;

    void ConsoleRuntimePrivate::initialize(Chips::Computer* computer)
    {
        _rom = computer->rom();
        _ram = computer->memory();
    }

    int ConsoleRuntimePrivate::input() const
    {
        return _input;
    }

    void ConsoleRuntimePrivate::processEvents()
    {
        if (_cpuState.pc > _rom->size())
            _input = PR_EXIT;
    }

    void ConsoleRuntimePrivate::update(Chips::Computer* computer)
    {
        _cpuState = computer->state();
    }

}  // namespace Hack::Computer
