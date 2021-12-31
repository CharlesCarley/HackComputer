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

#include "Computer/ScreenSDL.h"

namespace Hack::Chips
{
    ScreenSDL::ScreenSDL() :
        _ram(new uint16_t[Max + 1]),
        _texture(nullptr),
        _renderer(nullptr),
        _pixels(nullptr),
        _pitch(0)
    {
        zero();
    }

    ScreenSDL::~ScreenSDL()
    {
        delete[] _ram;
    }

    uint16_t ScreenSDL::get(const size_t& i) const
    {
        if (i < HighAddress)
            return _ram[i];

#ifdef CHECK_INT_BOUNDS
        throw IndexOutOfBounds();
#else
        return 0;
#endif
    }

    uint16_t* ScreenSDL::pointer(const size_t& address) const
    {
        if (address < HighAddress)
            return &_ram[address];
        return nullptr;
    }

    void ScreenSDL::setValue(const size_t& address, const uint16_t& v) const
    {
        if (address < HighAddress)
            _ram[address] = _ram[address + HighAddress] = v;
        else
            throw IndexOutOfBounds();
    }

    void ScreenSDL::zero() const
    {
        memset(_ram, 0, sizeof(uint16_t) * Max);
    }

    SDL_Texture* ScreenSDL::createBuffer(SDL_Renderer* renderer)
    {
        _renderer = renderer;
        _texture  = SDL_CreateTexture(renderer,
                                     SDL_PIXELFORMAT_ABGR32,
                                     SDL_TEXTUREACCESS_STREAMING,
                                     512,
                                     256);
        return _texture;
    }

    void ScreenSDL::lockScreen()
    {
        if (_texture)
        {
            void* pixels;
            int   pitch;

            if (_pixels == nullptr)
            {
                SDL_LockTexture(_texture, nullptr, &pixels, &pitch);

                _pixels = (uint8_t*)pixels;
                _pitch  = (size_t)pitch;
            }
        }
    }

    void ScreenSDL::unlockScreen()
    {
        if (_texture)
        {
            _pixels = nullptr;
            _pitch  = 0;

            SDL_UnlockTexture(_texture);
            // grab the final size
            SDL_Rect dest = {0, 0, 0, 0};
            SDL_GetRendererOutputSize(_renderer, &dest.w, &dest.h);

            SDL_Rect src = {0, 0, 512, 256};
            SDL_RenderCopy(_renderer, _texture, &src, &dest);

            SDL_RenderPresent(_renderer);
        }
    }

    void ScreenSDL::evaluate()
    {
        const uint16_t loAddr = _address;
        if (loAddr >= HighAddress)
            return;

        if (_bits & Bit0)
        {
            const uint16_t hiAddr = loAddr + HighAddress;

            if (hiAddr < Max)
            {
                if (_bits & Bit1)
                    _ram[loAddr] = _ram[hiAddr] = _in;
                else
                {
                    _ram[loAddr] = _ram[hiAddr];
                    _ram[hiAddr] = _in;
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

    void ScreenSDL::writeToBuffer() const
    {
        if (_pixels)
        {
            for (int i = 0; i < 0x2000; ++i)
            {
                const size_t baseAddr = (size_t)&_pixels[i * 64];

                uint32_t*      base = (uint32_t*)baseAddr;
                const uint16_t out  = _ram[i];

                *base++ = out & Bit0 ? 0xFFFFFFFF : 0xFF;
                *base++ = out & Bit1 ? 0xFFFFFFFF : 0xFF;
                *base++ = out & Bit2 ? 0xFFFFFFFF : 0xFF;
                *base++ = out & Bit3 ? 0xFFFFFFFF : 0xFF;
                *base++ = out & Bit4 ? 0xFFFFFFFF : 0xFF;
                *base++ = out & Bit5 ? 0xFFFFFFFF : 0xFF;
                *base++ = out & Bit6 ? 0xFFFFFFFF : 0xFF;
                *base++ = out & Bit7 ? 0xFFFFFFFF : 0xFF;
                *base++ = out & Bit8 ? 0xFFFFFFFF : 0xFF;
                *base++ = out & Bit9 ? 0xFFFFFFFF : 0xFF;
                *base++ = out & Bit10 ? 0xFFFFFFFF : 0xFF;
                *base++ = out & Bit11 ? 0xFFFFFFFF : 0xFF;
                *base++ = out & Bit12 ? 0xFFFFFFFF : 0xFF;
                *base++ = out & Bit13 ? 0xFFFFFFFF : 0xFF;
                *base++ = out & Bit14 ? 0xFFFFFFFF : 0xFF;
                *base   = out & Bit15 ? 0xFFFFFFFF : 0xFF;
            }
        }
    }

}  // namespace Hack::Chips

#endif
