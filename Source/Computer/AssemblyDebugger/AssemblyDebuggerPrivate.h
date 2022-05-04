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
#include "Chips/Computer.h"
#include "Computer/AssemblyDebugger.h"
#include "Utils/Char.h"
#include "Utils/UserInterface/Context.h"

namespace Hack::Computer
{
    class AssemblyDebuggerPrivate
    {
    private:
        int             _input;
        int             _mode;
        bool            _block;
        Ui::Context*    _ctx;
        Chips::Memory*  _ram;
        Chips::Rom32*   _rom;
        Chips::CpuState _cpuState;
        Chips::CpuState _prevCpuState;

    public:
        AssemblyDebuggerPrivate();

        ~AssemblyDebuggerPrivate();

        void initialize(Chips::Computer* computer);

        int input() const;

        bool block() const;

        void processEvents(Chips::Computer* computer);

        void flushMemory(Chips::Computer* computer);

        void displayMemoryContents(Ui::Context&         ctx,
                                   const Ui::Rectangle& bounds,
                                   const String&        value,
                                   int                  index,
                                   int                  offset,
                                   bool                 highlight) const;

        void displayRom(Ui::Context& ctx) const;

        void displayRam(Ui::Context& ctx) const;

        void displayCpu(Ui::Context& ctx) const;

        void render(Ui::Context& ctx) const;
    };

}  // namespace Hack::Computer
