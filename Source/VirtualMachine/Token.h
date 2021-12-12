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

namespace Hack::VirtualMachine
{
    enum TokenType
    {
        TOK_ERROR = -2,
        TOK_EOF,
        TOK_NULL,
        TOK_INTEGER,
        TOK_IDENTIFIER,

        TOK_PUSH,
        TOK_POP,
        TOK_ARGUMENT,
        TOK_LOCAL,
        TOK_STATIC,
        TOK_CONSTANT,
        TOK_THIS,
        TOK_THAT,
        TOK_POINTER,
        TOK_TEMP,
        TOK_IF_GOTO,
        TOK_GOTO,
        TOK_LABEL,
        TOK_FUNCTION,
        TOK_CALL,
        TOK_RETURN,
        TOK_EQ,
        TOK_GT,
        TOK_LT,
        TOK_ADD,
        TOK_SUB,
        TOK_AND,
        TOK_OR,
        TOK_NOT,
        TOK_NEG,
        TOK_RESET,
        TOK_HALT
    };

    using Token = TokenBase;

}  // namespace Hack::VirtualMachine
