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
#ifdef USE_SDL
#include "Chips/Computer.h"
#include "Computer/WindowedRuntime/ScreenMemory.h"

namespace Hack::Computer
{
    using namespace Chips;

    constexpr uint32_t RenderFlags = SDL_RENDERER_ACCELERATED |
                                     SDL_RENDERER_PRESENTVSYNC;

    constexpr uint32_t WindowFlags = SDL_WINDOW_SHOWN |
                                     SDL_WINDOW_RESIZABLE;

    class WindowedRuntimePrivate
    {
    private:
        SDL_Window*   _window;
        SDL_Renderer* _renderer;
        SDL_Texture*  _screenBuffer;
        bool          _quit;

    public:
        WindowedRuntimePrivate();

        ~WindowedRuntimePrivate();

        void initialize(ScreenMemory* screen);

        bool exitRequest() const;

        void processEvents(Chips::Computer* computer);

        static void flushMemory(Chips::Computer* computer);
    };

}  // namespace Hack::Computer

#endif
