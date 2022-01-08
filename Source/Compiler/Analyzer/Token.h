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
        TokError = -2,
        TokEof,
        TokNull,

        TokInt = 'A',
        TokId,
        TokString,
        TokKwClass,
        TokKwConstructor,
        TokKwFunction,
        TokKwMethod,
        TokKwField,
        TokKwStatic,
        TokKwVar,
        TokKwInt,
        TokKwChar,
        TokKwBool,
        TokKwVoid,
        TokKwLet,
        TokKwDo,
        TokKwIf,
        TokKwElse,
        TokKwWhile,
        TokKwReturn,
        TokKwTrue,
        TokKwFalse,
        TokKwNull,
        TokKwThis,
        TokKwInlineVm,
        TokKwInlineAsm,

        TokOpPlus = '+',
        TokOpMinus = '-',
        TokOpMultiply = '*',
        TokOpDivide = '/',
        TokOpAnd = '&',
        TokOpOr = '|',
        TokOpNot = '!',
        TokOpGt = '>',
        TokOpLt = '<',
        TokOpEq = '=',
        TokSymLBracket = '[',
        TokSymRBracket = ']',
        TokSymLBrace = '{',
        TokSymRBrace = '}',
        TokSymLPar = '(',
        TokSymRPar = ')',
        TokSymPeriod = '.',
        TokSymComma = ',',
        TokSymSemicolon = ';',
    };

    using Token = TokenBase;
} // namespace Hack::Compiler::Analyzer
