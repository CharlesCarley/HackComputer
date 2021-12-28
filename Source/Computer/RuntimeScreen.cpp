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

#include "Computer/RuntimeScreen.h"

namespace Hack::Chips
{
    RuntimeScreen::RuntimeScreen() :
        _ram(new uint16_t[Max + 1]),
        _texture(nullptr),
        _pixels(nullptr),
        _pitch(0)
    {
        zero();
    }

    RuntimeScreen::~RuntimeScreen()
    {
        delete[] _ram;
    }

    uint16_t RuntimeScreen::get(const size_t& i) const
    {
        if (i < HighAddress)
            return _ram[i];

#ifdef CHECK_INT_BOUNDS
        throw IndexOutOfBounds();
#else
        return 0;
#endif
    }

    uint16_t* RuntimeScreen::pointer(const size_t& address) const
    {
        if (address < HighAddress)
            return &_ram[address];
        return nullptr;
    }

    void RuntimeScreen::setValue(const size_t& address, const uint16_t& v) const
    {
        if (address < HighAddress)
            _ram[address] = _ram[address + HighAddress] = v;
    }

    void RuntimeScreen::zero() const
    {
        memset(_ram, 0, sizeof(uint16_t) * Max);
    }

    SDL_Texture* RuntimeScreen::createBuffer(SDL_Renderer* renderer)
    {
        _texture = SDL_CreateTexture(renderer,
                                     SDL_PIXELFORMAT_ABGR32,
                                     SDL_TEXTUREACCESS_STREAMING,
                                     512,
                                     256);
        return _texture;
    }

    void RuntimeScreen::lockScreen()
    {
        if (_texture)
        {
            void* pixels;
            int   pitch;

            SDL_LockTexture(_texture, nullptr, &pixels, &pitch);

            _pixels = (uint8_t*)pixels;
            _pitch  = (size_t)pitch;
        }
    }

    void RuntimeScreen::unlockScreen()
    {
        if (_texture)
        {
            _pixels = nullptr;
            _pitch  = 0;

            SDL_UnlockTexture(_texture);
        }
    }

    void RuntimeScreen::evaluate()
    {
        const uint16_t loAddr = _address;
        if (loAddr >= HighAddress)
            return;

        if (_bits & 1)
        {
            const uint16_t hiAddr = loAddr + HighAddress;

            if (hiAddr < Max)
            {
                if (_bits & 2)
                    _ram[loAddr] = _ram[hiAddr] = _in;
                else
                {
                    _ram[loAddr] = _ram[hiAddr];
                    _ram[loAddr] = _in;
                }
            }
            else
            {
                throw InputException("ram index (",
                                     hiAddr,
                                     ") out of bounds [0, ",
                                     hiAddr,
                                     ']');
            }
        }

        _out = _ram[loAddr];
        _bits &= 0b01111100;
    }

    void RuntimeScreen::flush() const
    {
        if (_pixels)
        {
            uint8_t* base = _pixels;

            for (int i = 0; i < 0x2000; ++i)
            {
                const uint16_t v = _ram[i];

                for (int j = 0; j < 16; ++j)
                {
                    if (v & 1 << j)
                    {
                        *base++ = 0xFF;
                        *base++ = 0xFF;
                        *base++ = 0xFF;
                        *base++ = 0xFF;
                    }
                    else
                    {
                        *base++ = 0xFF;
                        *base++ = 0x00;
                        *base++ = 0x00;
                        *base++ = 0x00;
                    }
                }
            }
        }
    }

}  // namespace Hack::Chips
#endif
