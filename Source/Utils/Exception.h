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
#include "Utils/Console.h"
#include "Utils/String.h"

namespace Hack
{
    class Exception : public std::exception
    {
    private:
        String _string;

    public:
        explicit Exception(const char* what) :
            std::exception(),
            _string(what)
        {
            Console::debugBreak();
        }

        explicit Exception(String what) :
            std::exception(),
            _string(std::move(what))
        {
            Console::debugBreak();
        }

        template <typename... Args>
        explicit Exception(const String& what, Args&&...args) :
            std::exception()
        {
            OutputStringStream oss;
            oss << what;
            ((oss << std::forward<Args>(args)), ...);
            _string = oss.str();

            Console::debugBreak();
        }

        const char* what() const noexcept override
        {
            return _string.c_str();
        }
    };

    // clang-format off
#ifdef _DEBUG
#define FLS __FILE__ "(", __LINE__, "):\n\t" __FUNCTION__ "\n\n"
#define NotImplemented()            Exception(FLS, "not implemented")
#define IndexOutOfBounds()          Exception(FLS, "array index out of bounds")
#define NotFound()                  Exception(FLS, "not found")
#define InvalidPointer()            Exception(FLS, "invalid pointer")
#define InputException(msg, ...)    Exception(FLS, msg, __VA_ARGS__)
#define MessageException(msg)       Exception(FLS, msg)
#define NullOrEmptyString()         Exception(FLS, "the supplied string is empty")
#else
    #define NotImplemented()            Exception("not implemented")
    #define IndexOutOfBounds()          Exception("array index out of bounds")
    #define NotFound()                  Exception("not found")
    #define InvalidPointer()            Exception("invalid pointer")
    #define InputException(msg, ...)    Exception(msg, __VA_ARGS__)
    #define MessageException(msg)       Exception(msg)
    #define NullOrEmptyString()         Exception("the supplied string is empty")
#endif
    // clang-format on
} // namespace Hack
