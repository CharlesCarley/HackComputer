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
#include "Computer/RuntimeSDL.h"
#include "Chips/Computer.h"
#include "ScreenSDL.h"
#include "SDL.h"
#include "Utils/Exception.h"

namespace Hack::Computer
{
    using namespace Chips;

    constexpr uint32_t RenderFlags = SDL_RENDERER_ACCELERATED |
                                     SDL_RENDERER_PRESENTVSYNC;

    constexpr uint32_t WindowFlags = SDL_WINDOW_SHOWN |
                                     SDL_WINDOW_RESIZABLE;

    class RuntimePrivate
    {
    private:
        SDL_Window*   _window;
        SDL_Renderer* _renderer;
        SDL_Texture*  _screenBuffer;
        bool          _quit;

    public:
        RuntimePrivate() :
            _window(nullptr),
            _renderer(nullptr),
            _screenBuffer(nullptr),
            _quit(false)
        {
        }

        ~RuntimePrivate()
        {
            if (_screenBuffer)
                SDL_DestroyTexture(_screenBuffer);

            if (_renderer)
                SDL_DestroyRenderer(_renderer);

            if (_window)
                SDL_DestroyWindow(_window);

            SDL_Quit();
        }

        void initialize(ScreenSDL* screen)
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

        bool exitRequest() const
        {
            return _quit;
        }

        void processEvents(Chips::Computer* computer)
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

        void flushMemory(Chips::Computer* computer) const
        {
            SDL_RenderPresent(_renderer);
        }
    };

    inline int16_t RuntimeSDL::getRate() const
    {
        return 0x6000 - 1;
    }

    RuntimeSDL::RuntimeSDL() :
        _private(new RuntimePrivate())
    {
    }

    RuntimeSDL::~RuntimeSDL()
    {
        delete _private;
    }

    bool RuntimeSDL::exitRequest() const
    {
        return _private->exitRequest();
    }

    void RuntimeSDL::processEvents(Chips::Computer* computer) const
    {
        _private->processEvents(computer);
    }

    void RuntimeSDL::flushMemory(Chips::Computer* computer) const
    {
        _private->flushMemory(computer);
    }

    void RuntimeSDL::initialize(Chips::Computer*, Screen* screen) const
    {
        _private->initialize((ScreenSDL*)screen);
    }

    void RuntimeSDL::update(Chips::Computer* computer) const
    {
        const int32_t rate = getRate();

        ScreenSDL* rc = (ScreenSDL*)computer->memory()->getScreen();
        rc->lockScreen();
        computer->update(true);

        for (int32_t i = 0; i < rate && computer->canRead(); ++i)
        {
            computer->update(false);
            computer->update(true);
        }
        rc->unlockScreen();
    }

}  // namespace Hack::Computer

#endif
