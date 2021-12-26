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
#include "Utils/Exceptions/Exception.h"
#include "Utils/String.h"

namespace Hack::Compiler::Analyzer
{
    class ParseUtils
    {
    public:
        static String string(int index);

        static bool isOperator(int8_t id);

        static bool isTerm(int8_t t0);

        static bool isUnary(int8_t t0, int8_t t1, int8_t t2);

        static bool isExpressionExitTerm(int8_t t0);

        static bool isFunctionCall(int8_t t0, int8_t t1);

        static bool isMethodCall(int8_t t0, int8_t t1, int8_t t2, int8_t t3);

        static bool isCallTerm(int8_t t0, int8_t t1, int8_t t2, int8_t t3);

        static bool isComplexTerm(int8_t t0, int8_t t1, int8_t t2, int8_t t3);
    };

}  // namespace Hack::Compiler::Analyzer
