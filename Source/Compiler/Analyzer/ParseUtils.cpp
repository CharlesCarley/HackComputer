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
#include "Compiler/Analyzer/ParseUtils.h"
#include "Compiler/Analyzer/Token.h"
#include "Compiler/Common/Node.h"
#include "Utils/Char.h"

namespace Hack::Compiler::Analyzer
{
    bool ParseUtils::isOperator(const int8_t id)
    {
        switch (id)
        {
        case TokOpMinus:
        case TokOpPlus:
        case TokOpMultiply:
        case TokOpDivide:
        case TokOpAnd:
        case TokOpOr:
        case TokOpGt:
        case TokOpLt:
        case TokOpEq:
            return true;
        default:
            return false;
        }
    }

    bool ParseUtils::isTerm(const int8_t t0)
    {
        switch (t0)
        {
        case TokId:
        case TokInt:
        case TokString:
        case TokKwFalse:
        case TokKwTrue:
        case TokKwNull:
        case TokKwThis:
        case TokSymLPar:
            return true;
        default:
            return false;
        }
    }

    bool ParseUtils::isExpressionExitTerm(const int8_t t0)
    {
        switch (t0)
        {
        case TokSymRBracket:
        case TokSymSemicolon:
        case TokSymRPar:
        case TokSymComma:
            return true;
        default:
            return false;
        }
    }

    bool ParseUtils::isUnary(const int8_t t0,
                             const int8_t t1,
                             const int8_t t2)
    {
        const bool notOrMinus = t0 == TokOpNot || t0 == TokOpMinus;
        if (notOrMinus && isTerm(t1))
        {
            if (t2 != TokSymLPar || !isTerm(t2))
                return true;
        }
        return false;
    }

    bool ParseUtils::isFunctionCall(const int8_t t0,
                                    const int8_t t1)
    {
        if (t0 == TokId && t1 == TokSymLPar)
            return true;
        return false;
    }

    bool ParseUtils::isMethodCall(const int8_t t0,
                                  const int8_t t1,
                                  const int8_t t2,
                                  const int8_t t3)
    {
        const bool idOrThis = t0 == TokId || t0 == TokKwThis;
        if (idOrThis && t1 == TokSymPeriod && t2 == TokId && t3 == TokSymLPar)
            return true;
        return false;
    }

    bool ParseUtils::isCallTerm(const int8_t t0,
                                const int8_t t1,
                                const int8_t t2,
                                const int8_t t3)
    {
        return isFunctionCall(t0, t1) || isMethodCall(t0, t1, t2, t3);
    }

    bool ParseUtils::isComplexTerm(const int8_t t0,
                                   const int8_t t1,
                                   const int8_t t2,
                                   const int8_t t3)
    {
        if (t0 == TokSymLPar)
            return true;
        if (t0 == TokId && t1 == TokSymLBracket)
            return true;
        return isCallTerm(t0, t1, t2, t3);
    }

    String ParseUtils::string(int index)
    {
        switch (index)
        {
        default:
        case TokNull:
            return "?";
        case TokError:
            return "error";
        case TokEof:
            return "eof";
        case TokInt:
            return "int";
        case TokId:
            return "id";
        case TokString:
            return "string";
        case TokKwClass:
            return "class";
        case TokKwConstructor:
            return "constructor";
        case TokKwFunction:
            return "function";
        case TokKwMethod:
            return "method";
        case TokKwField:
            return "field";
        case TokKwStatic:
            return "static";
        case TokKwVar:
            return "var";
        case TokKwInt:
            return "int";
        case TokKwChar:
            return "char";
        case TokKwBool:
            return "bool";
        case TokKwVoid:
            return "void";
        case TokKwLet:
            return "let";
        case TokKwDo:
            return "do";
        case TokKwIf:
            return "if";
        case TokKwElse:
            return "else";
        case TokKwWhile:
            return "while";
        case TokKwReturn:
            return "return";
        case TokKwTrue:
            return "true";
        case TokKwFalse:
            return "false";
        case TokKwNull:
            return "null";
        case TokKwThis:
            return "this";
        case TokOpPlus:
            return "'+'";
        case TokOpMinus:
            return "'-'";
        case TokOpMultiply:
            return "'*'";
        case TokOpDivide:
            return "'/'";
        case TokOpAnd:
            return "'&'";
        case TokOpOr:
            return "'|'";
        case TokOpNot:
            return "'!'";
        case TokOpGt:
            return "'>'";
        case TokOpLt:
            return "'<'";
        case TokOpEq:
            return "'='";
        case TokSymLBracket:
            return "'['";
        case TokSymRBracket:
            return "']'";
        case TokSymLBrace:
            return "'{'";
        case TokSymRBrace:
            return "'}'";
        case TokSymLPar:
            return "'('";
        case TokSymRPar:
            return "')'";
        case TokSymPeriod:
            return "'.'";
        case TokSymComma:
            return "','";
        case TokSymSemicolon:
            return "';'";
        }
    }
}  // namespace Hack::Compiler::Analyzer
