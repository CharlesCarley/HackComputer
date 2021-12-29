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
#include "Chips/Screen.h"
#include "Computer/RuntimeInterface.h"
#ifdef USE_SDL

namespace Hack::Computer
{
    class RuntimePrivate;

    class RuntimeSDL final : public RuntimeInterface
    {
    private:
        RuntimePrivate* _private;

        int16_t getRate() const override;

        
    public:
        RuntimeSDL();
        ~RuntimeSDL() override;

        void initialize(Chips::Computer* computer,
                        Chips::Screen*   screen) const override;

        bool exitRequest() const override;

        void processEvents(Chips::Computer* computer) const override;

        void flushMemory(Chips::Computer* computer) const override;

        void update(Chips::Computer* computer) const override;
    };

}  // namespace Hack::Computer

#endif
