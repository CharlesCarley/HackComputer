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
#include "Utils/ParserBase/TokenBase.h"

namespace Hack::Compiler::Analyzer
{
    enum TokenType
    {
        TOK_ERROR = -2,
        TOK_EOF,
        TOK_NULL,
        TOK_INTEGER = 'A',
        TOK_IDENTIFIER,
        TOK_STRING,
        TOK_KW_CLASS,
        TOK_KW_CTOR,
        TOK_KW_FUNCTION,
        TOK_KW_METHOD,
        TOK_KW_FIELD,
        TOK_KW_STATIC,
        TOK_KW_VAR,
        TOK_KW_INT,
        TOK_KW_CHAR,
        TOK_KW_BOOL,
        TOK_KW_VOID,
        TOK_KW_LET,
        TOK_KW_DO,
        TOK_KW_IF,
        TOK_KW_ELSE,
        TOK_KW_WHILE,
        TOK_KW_RETURN,
        TOK_CONST_TRUE,
        TOK_CONST_FALSE,
        TOK_CONST_NULL,
        TOK_CONST_THIS,

        TOK_OP_PLUS     = '+',
        TOK_OP_MINUS    = '-',
        TOK_OP_MULTIPLY = '*',
        TOK_OP_DIVIDE   = '/',
        TOK_OP_AND      = '&',
        TOK_OP_OR       = '|',
        TOK_OP_NOT      = '!',
        TOK_L_BRACKET   = '[',
        TOK_R_BRACKET   = ']',
        TOK_L_BRACE     = '{',
        TOK_R_BRACE     = '}',
        TOK_L_PAR       = '(',
        TOK_R_PAR       = ')',
        TOK_PERIOD      = '.',
        TOK_GT          = '>',
        TOK_LT          = '<',
        TOK_EQ          = '=',
        TOK_COMMA       = ',',
        TOK_SEMICOLON   = ';',
    };

    using Token = TokenBase;

}  // namespace Hack::Compiler::Analyzer
