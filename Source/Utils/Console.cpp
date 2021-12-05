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
#ifdef _WIN32
#include <Windows.h>
#endif

#include <iostream>
#include <sstream>
#include "Console.h"

namespace Hack
{
    static ConsoleColor __gForeground = CS_WHITE;
    static ConsoleColor __gBackground = CS_BLACK;

#ifndef _WIN32
    static uint8_t MapColor(const ConsoleColor& col, bool bg)
    {
        uint8_t color = 0;
        switch (col)
        {
        case CS_BLACK:
            color = 30;
            break;
        case CS_DARK_BLUE:
            color = 34;
            break;
        case CS_DARK_GREEN:
            color = 32;
            break;
        case CS_DARK_CYAN:
            color = 36;
            break;
        case CS_DARK_RED:
            color = 31;
            break;
        case CS_DARK_MAGENTA:
            color = 35;
            break;
        case CS_DARK_YELLOW:
            color = 33;
            break;
        case CS_LIGHT_GREY:
            color = 90;
            break;
        case CS_GREY:
            color = 37;
            break;
        case CS_BLUE:
            color = 94;
            break;
        case CS_GREEN:
            color = 92;
            break;
        case CS_CYAN:
            color = 96;
            break;
        case CS_RED:
            color = 91;
            break;
        case CS_MAGENTA:
            color = 95;
            break;
        case CS_YELLOW:
            color = 93;
            break;
        case CS_WHITE:
            color = 0;
            break;
        }
        if (bg)
            color += 10;
        return color;
    }

#endif

    static void SetColor()
    {
#ifdef _WIN32
        SetConsoleTextAttribute(
            GetStdHandle(STD_OUTPUT_HANDLE),
            (UCHAR)((UCHAR)__gBackground * 16 + (UCHAR)__gForeground));
#else
        uint8_t color[2] = {
            MapColor(__gForeground, false),
            MapColor(__gBackground, true),
        };
        if (__gBackground != CS_BLACK)
            printf("\033[%dm\033[%dm", color[0], color[1]);
        else
            printf("\033[%dm", color[0]);
#endif
    }

    void Console::read()
    {
        std::cin.get();
    }

    void Console::read(int8_t& v)
    {
        std::cin >> v;
    }

    void Console::read(uint8_t& v)
    {
        std::cin >> v;
    }

    void Console::read(int16_t& v)
    {
        std::cin >> v;
    }

    void Console::read(uint16_t& v)
    {
        std::cin >> v;
    }

    void Console::read(int32_t& v)
    {
        std::cin >> v;
    }

    void Console::read(uint32_t& v)
    {
        std::cin >> v;
    }

    void Console::read(int64_t& v)
    {
        std::cin >> v;
    }

    void Console::read(uint64_t& v)
    {
        std::cin >> v;
    }

    void Console::read(String& v)
    {
        std::cin >> v;
    }

    void Console::readLine(String& v)
    {
        std::getline(std::cin, v);
    }

    void Console::setForeground(const ConsoleColor col)
    {
        __gForeground = col;
    }

    void Console::setBackground(const ConsoleColor col)
    {
        __gBackground = col;
    }

    void Console::resetColor()
    {
#ifndef _WIN32
        __gForeground = CS_WHITE;
        __gBackground = CS_BLACK;
        printf("\033[0m");
#else
        __gForeground = CS_WHITE;
        __gBackground = CS_BLACK;
        SetColor();
#endif
    }

    void Console::write(const String& str)
    {
        SetColor();
        std::cout << str;
    }

    void Console::writeLine(const String& str)
    {
        SetColor();
        std::cout << str << std::endl;
        resetColor();
    }

    void Console::writeError(const String& str)
    {
        std::cerr << str << std::endl;
    }

    void Console::writeLine(const int64_t& i)
    {
        OutputStringStream oss;
        oss << i;
        writeLine(oss);
    }

    void Console::writeLine(const OutputStringStream& str)
    {
        writeLine(str.str());
    }

    void Console::writeError(const OutputStringStream& str)
    {
        writeError(str.str());
    }

}  // namespace Utils
