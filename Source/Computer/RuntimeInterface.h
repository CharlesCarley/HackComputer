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
#include "Assembler/Parser.h"
#include "Chips/Computer.h"
#include "Chips/Screen.h"

namespace Hack::Computer
{
    class RuntimeInterface
    {
    public:
        virtual ~RuntimeInterface() = default;

        virtual bool shouldUpdate();

        virtual int16_t getRate() const;

        virtual void setRate(int16_t v);

        virtual void initialize(Chips::Computer* computer, Chips::Screen* screen) const = 0;

        virtual bool exitRequest() const = 0;

        virtual void processEvents(Chips::Computer* computer) const = 0;

        virtual void flushMemory(Chips::Computer* computer) const = 0;

        virtual void update(Chips::Computer* computer) const = 0;

        virtual void setInstructions(const Assembler::Parser::Instructions& is)
        {
        }
    };

    inline bool RuntimeInterface::shouldUpdate()
    {
        return true;
    }

    inline int16_t RuntimeInterface::getRate() const
    {
        return 1;
    }

    inline void RuntimeInterface::setRate(int16_t v)
    {
    }

}  // namespace Hack::Computer
