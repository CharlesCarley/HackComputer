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
#include "Computer/Runtime.h"
#include "Chips/Computer.h"
#include "SDL.h"
#include "Utils/Exceptions/Exception.h"

namespace Hack::Computer
{
    using namespace Chips;

    constexpr uint32_t RenderFlags =
        SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC;

    constexpr uint32_t WindowFlags = SDL_WINDOW_SHOWN | SDL_WINDOW_RESIZABLE;

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

        void initialize()
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

            _screenBuffer = SDL_CreateTexture(_renderer,
                                              SDL_PIXELFORMAT_ABGR32,
                                              SDL_TEXTUREACCESS_STREAMING,
                                              512,
                                              256);
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
                case SDL_QUIT:
                    _quit = true;
                    break;
                default:
                    break;
                }
            }
        }

        void flushMemory(Chips::Computer* computer) const
        {
            if (!computer)
                throw Exception("computer is null");

            Memory* mem = computer->getRam();
            if (!mem)
                throw Exception("computer memory is null");

            void* texturePixels;
            int   imagePitch;

            SDL_LockTexture(
                _screenBuffer, nullptr, &texturePixels, &imagePitch);

            uint16_t* screenPixels = mem->pointer(Memory::ScreenAddress);
            uint8_t*  imagePixels  = (uint8_t*)texturePixels;

            // Copy 0x2000 shorts -> 2*0x2000 bytes
            for (int i = 0; i < 0x2000; ++i)
            {
                const uint16_t pc = screenPixels[i];
                for (int j = 0; j < 16; ++j)
                {
                    // 4:1 ARGB -> BW per bit
                    if (pc & 1 << j)
                    {
                        *imagePixels++ = 0xFF;
                        *imagePixels++ = 0xFF;
                        *imagePixels++ = 0xFF;
                        *imagePixels++ = 0xFF;
                    }
                    else
                    {
                        *imagePixels++ = 0xFF;
                        *imagePixels++ = 0x00;
                        *imagePixels++ = 0x00;
                        *imagePixels++ = 0x00;
                    }
                }
            }
            SDL_UnlockTexture(_screenBuffer);

            // grab the final size
            SDL_Rect dest = {0, 0, 0, 0};
            SDL_GetRendererOutputSize(_renderer, &dest.w, &dest.h);

            SDL_Rect src = {0, 0, 512, 256};
            SDL_RenderCopy(_renderer, _screenBuffer, &src, &dest);
            SDL_RenderPresent(_renderer);
        }
    };

    Runtime::Runtime() : _private(new RuntimePrivate())
    {
    }

    Runtime::~Runtime()
    {
        delete _private;
    }

    bool Runtime::exitRequest() const
    {
        return _private->exitRequest();
    }

    void Runtime::processEvents(Chips::Computer* computer) const
    {
        _private->processEvents(computer);
    }

    void Runtime::flushMemory(Chips::Computer* computer) const
    {
        _private->flushMemory(computer);
    }

    void Runtime::initialize(Chips::Computer*) const
    {
        _private->initialize();
    }

    void Runtime::update(Chips::Computer* computer) const
    {
        for (int i = 0; i < 0x2000; ++i)
            computer->update(false);
    }

}  // namespace Hack::Computer
#endif
