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
#ifdef USE_SDL
#include "Chips/Computer.h"
#include "Computer/WindowedRuntime.h"
#include "Computer/WindowedRuntime/WindowedRuntimePrivate.h"

namespace Hack::Computer
{
    inline int16_t WindowedRuntime::getRate() const
    {
        return 0x2000 - 1;
    }

    WindowedRuntime::WindowedRuntime() :
        _private(new WindowedRuntimePrivate())
    {
    }

    WindowedRuntime::~WindowedRuntime()
    {
        delete _private;
    }

    bool WindowedRuntime::exitRequest() const
    {
        return _private->exitRequest();
    }

    void WindowedRuntime::processEvents(Chips::Computer* computer) const
    {
        _private->processEvents(computer);
    }

    void WindowedRuntime::flushMemory(Chips::Computer* computer) const
    {
        WindowedRuntimePrivate::flushMemory(computer);
    }

    void WindowedRuntime::initialize(Chips::Computer*, Screen* screen) const
    {
        _private->initialize((ScreenMemory*)screen);
    }

    void WindowedRuntime::update(Chips::Computer* computer) const
    {
        if (computer)
        {
            computer->update(false);
            computer->update(false);
        }
    }

}  // namespace Hack::Computer

#endif
