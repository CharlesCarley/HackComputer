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
#include "WindowedRuntimePrivate.h"
#ifdef USE_SDL
#include "Chips/Computer.h"
#include "Computer/WindowedRuntime.h"
#include "Computer/WindowedRuntime/ScreenMemory.h"
#include "SDL.h"
#include "Utils/Exception.h"

namespace Hack::Computer
{
    using namespace Chips;

    WindowedRuntimePrivate::WindowedRuntimePrivate() :
        _window(nullptr),
        _renderer(nullptr),
        _screenBuffer(nullptr),
        _quit(false)
    {
    }

    WindowedRuntimePrivate::~WindowedRuntimePrivate()
    {
        if (_screenBuffer)
            SDL_DestroyTexture(_screenBuffer);

        if (_renderer)
            SDL_DestroyRenderer(_renderer);

        if (_window)
            SDL_DestroyWindow(_window);

        SDL_Quit();
    }

    void WindowedRuntimePrivate::initialize(ScreenMemory* screen)
    {
        if (SDL_Init(SDL_INIT_VIDEO) < 0)
        {
            OutputStringStream oss;
            oss << "SDL initialization failed, " << SDL_GetError();
            throw Exception(oss.str());
        }

        _window = SDL_CreateWindow("Hack Computer",
                                   SDL_WINDOWPOS_CENTERED,
                                   SDL_WINDOWPOS_CENTERED,
                                   512,
                                   256,
                                   WindowFlags);
        if (!_window)
        {
            OutputStringStream oss;
            oss << "Failed to create window, " << SDL_GetError();
            throw Exception(oss.str());
        }

        _renderer = SDL_CreateRenderer(_window, -1, RenderFlags);

        _screenBuffer = screen->createBuffer(_renderer);
    }

    bool WindowedRuntimePrivate::exitRequest() const
    {
        return _quit;
    }

    void WindowedRuntimePrivate::processEvents(Chips::Computer* computer)
    {
        // TODO: map keyboard..
        SDL_Event evt;
        while (SDL_PollEvent(&evt))
        {
            switch (evt.type)
            {
            case SDL_KEYDOWN:
                if (evt.key.keysym.sym == SDLK_r)
                {
                    computer->reset();
                }
                if (evt.key.keysym.sym == SDLK_ESCAPE)
                {
                    _quit = true;
                }
                break;
            case SDL_WINDOWEVENT_RESIZED:
                flushMemory(computer);
                break;
            case SDL_QUIT:
                _quit = true;
                break;
            default:
                break;
            }
        }

        if (!computer->canRead())
            _quit = true;
    }

    void WindowedRuntimePrivate::flushMemory(Chips::Computer* computer)
    {
        ScreenMemory* scr = (ScreenMemory*)computer->memory()->getScreen();

        scr->lockScreen();
        scr->writeToBuffer();
        scr->unlockScreen();
    }

}  // namespace Hack::Computer

#endif
