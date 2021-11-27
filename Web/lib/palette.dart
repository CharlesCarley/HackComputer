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
import 'package:flutter/material.dart';

class Palette {
  static const background = Color(0xFF282827);
  static const inactiveMemory = Color(0xFF3F3F4F);
  static const darkGrey = Color(0xFF181818);
  static const darkGrey1 = Color(0xFF2A2A2F);
  static const darkGrey2 = Color(0xFF222222);
  static const highlight = Color(0xFF9F9FAF);
  static const highlightTransparent = Color(0xFF9F9FAF);
  static const wireLight = Color(0xFF6A6A9F);
  static const wireTitle = Color(0xFF5A5A7F);
  static const wire = Color(0xFF4F4F69);
  static const wireShadow = Color(0xFF30303F);
  static const action = Color(0xFFE94545);
  static const actionSecondary = Color(0xFF45E945);
  static const transparent = Color(0x00E94545);

  static const wireNoChange = Color(0xFF3F3F4F);
  static const wireChange = Color(0xFF5F5F79);

  static const editTextForeground = Color(0xC08F8F98);
  static const editTextBackground = Color(0xFF282828);
  static const editTextWidgetBackground = Color(0xFF181819);
  static const editTextWidgetInnerBorder = Color(0xFF282828);
  static const editTextWidgetBorder = Color(0xFF3F3F4F);
  static const editTextButtonBackground = Color(0x1F6A6A9F);
  static const editTextButtonForeground = Color(0xFF5A5A7F);

  static const boxBackground = Color(0xFF181819);
  static const memorySelection = Color(0xC030303F);
  static const memorySelectionHighlight = Color(0x10E8E5EF);

  static const main = MaterialColor(
    0xFF1A1A1A,
    <int, Color>{
      50: Color(0xFF1A1A1A),
      100: Color(0xFF2A2A2A),
      200: Color(0xFF3A3A3A),
      300: Color(0xFF4A4A4A),
      400: Color(0xFF6A6A6A),
      500: Color(0xFF6A6A6A),
      600: Color(0xFF6A6A6A),
      700: Color(0xFF1A1A1A),
      800: Color(0xFF6A6A6A),
      900: Color(0xFF6A6A6A),
    },
  );
}
