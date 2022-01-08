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
#include "Chips/Screen.h"
#include "SDL.h"

namespace Hack::Chips
{
    class ScreenSDL final : public Screen
    {
    private:
        uint16_t*    _ram;
        SDL_Texture* _texture;
        SDL_Renderer* _renderer;
        uint8_t*     _pixels;
        size_t       _pitch;

    public:
        ScreenSDL();

        ~ScreenSDL() override;

        uint16_t get(const size_t& i) const override;

        uint16_t* pointer(const size_t& address) const override;

        void setValue(const size_t& address, const uint16_t& v) const override;

        void zero() const override;

        SDL_Texture* createBuffer(SDL_Renderer* renderer);

        void lockScreen() override;

        void unlockScreen() override;

        void  writeToBuffer() const;

    protected:

        void evaluate() override;
    };

}  // namespace Hack::Chips
#endif
