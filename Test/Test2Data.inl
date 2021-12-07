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
#include "Assembler/Token.h"

constexpr int Scan2Tokens[] = {
    TOK_PLUS,
    TOK_MINUS,
    TOK_NOT,
    TOK_AND,
    TOK_OR,
    TOK_SEMI_COLON,
    TOK_EQUAL,
    TOK_R_PAREN,
    TOK_L_PAREN,
    TOK_D,
    TOK_A,
    TOK_NOT,
    TOK_D,
    TOK_NOT,
    TOK_A,
    TOK_MINUS,
    TOK_D,
    TOK_MINUS,
    TOK_A,
    TOK_D,
    TOK_PLUS,
    TOK_ONE,
    TOK_A,
    TOK_PLUS,
    TOK_ONE,
    TOK_D,
    TOK_MINUS,
    TOK_ONE,
    TOK_A,
    TOK_MINUS,
    TOK_ONE,
    TOK_D,
    TOK_PLUS,
    TOK_A,
    TOK_D,
    TOK_MINUS,
    TOK_A,
    TOK_A,
    TOK_MINUS,
    TOK_D,
    TOK_D,
    TOK_AND,
    TOK_A,
    TOK_D,
    TOK_OR,
    TOK_A,
    TOK_M,
    TOK_NOT,
    TOK_M,
    TOK_MINUS,
    TOK_M,
    TOK_M,
    TOK_PLUS,
    TOK_ONE,
    TOK_M,
    TOK_MINUS,
    TOK_ONE,
    TOK_D,
    TOK_PLUS,
    TOK_M,
    TOK_D,
    TOK_MINUS,
    TOK_M,
    TOK_M,
    TOK_MINUS,
    TOK_D,
    TOK_D,
    TOK_AND,
    TOK_M,
    TOK_D,
    TOK_OR,
    TOK_M,
    TOK_AMD,
    TOK_A,
    TOK_AM,
    TOK_AD,
    TOK_AMD,
    TOK_JGT,
    TOK_JEQ,
    TOK_JGE,
    TOK_JLT,
    TOK_JNE,
    TOK_JLE,
    TOK_JMP,
};
