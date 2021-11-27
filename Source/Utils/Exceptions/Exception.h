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
#include <exception>
#include <stdexcept>
#include <utility>
#include "Utils/String.h"

namespace Hack
{
    class Exception : public std::exception
    {
    private:
        String _string;

    public:
        explicit Exception(const char* what) : std::exception(), _string(what)
        {
        }

        explicit Exception(String what) :
            std::exception(), _string(std::move(what))
        {
        }

        template <typename... Args>
        explicit Exception(const String& what, Args&&... args) :
            std::exception()
        {
            OutputStringStream oss;
            oss << what << std::endl << std::endl;
            ((oss << std::forward<Args>(args)), ...);
            _string = oss.str();
        }

        const char* what() const noexcept override
        {
            return _string.c_str();
        }
    };

}  // namespace Hack