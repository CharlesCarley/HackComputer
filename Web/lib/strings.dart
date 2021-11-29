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

class Strings {
  static const String title = "Hack Computer";
  static const String titleBar = "Hack Computer";
  static const String cpu = "CPU";
  static const String rom = "ROM 32K";
  static const String ram = "RAM 24K";
  static const String output = "Output";
  static const String address = "Address";
  static const String instruction = "Instruction";
  static const String dRegister = "D";
  static const String aRegister = "A/M";
  static const String programCounter = "PC";

  static String projectURL = "https://github.com/CharlesCarley/HackComputer";

  static String editProgramTitle = "Edit Program";
  static const editHelp = "Edit (E) - Edit the current program";

  static String screenBufferTitle = "Screen Buffer";
  static String screenHelp =
      "Screen (P) - Display the contents of the screen buffer in a popup";
  static const powerHelp = "Reset (R) - reset the program counter to 0";
  static const stepHelp = "Step (Up Arrow) - Advance one clock step";
  static var ramClear = "Clear - zeros the entire contents of RAM";
}

class Samples {
  static const String fillScreen = """
// Fills the screen buffer with with black pixels then with white pixels
(Start)
@R0      M=0
@8192    D=A
@R1      M=D
(fillTop)
@R0      M=0
@R3      M=!M
(loopTop)
@SCREEN  D=A
@R2      M=D
@R0      D=M
@R4      M=D
@R2      D=M
@R4      M=D+M
@R3      D=M
@R4      A=M 
         M=D
@R0      M=M+1
         D=M
@R1      D=M
@R0      D=D-M
@fillTop D;JEQ
@loopTop 0;JMP
""";
}
