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
import 'package:hack_computer/cross_ffi/proxy.dart';

typedef CreateComputerNative = IntPtr Function();
typedef DestroyComputerNative = Void Function(IntPtr handle);
typedef UpdateComputerNative = Void Function(IntPtr handle);
typedef RestartComputerNative = Void Function(IntPtr handle);
typedef ComputerGetLastErrorNative = Pointer<Uint8> Function(IntPtr handle);
typedef DecodeInstructionNative = Pointer<Uint8> Function(
    IntPtr handle, Int32 value);
typedef ComputerLoadSourceNative = Int32 Function(
    IntPtr handle, Pointer<Uint8>, Int32 length);
typedef ComputerGetRamNative = IntPtr Function(IntPtr handle);
typedef ComputerGetRomNative = IntPtr Function(IntPtr handle);
typedef RamGetValueNative = Int32 Function(IntPtr handle, Int32 index);
typedef RomGetValueNative = Int32 Function(IntPtr handle, Int32 index);
typedef RomGetValueDecodedNative = Pointer<Uint8> Function(
    IntPtr handle, Int32 index);
typedef ComputerGetCpuNative = IntPtr Function(IntPtr handle);

typedef CreateComputer = int Function();
typedef DestroyComputer = void Function(int handle);
typedef UpdateComputer = void Function(int handle);
typedef RestartComputer = void Function(int handle);
typedef ComputerGetLastError = Pointer<Uint8> Function(int handle);
typedef DecodeInstruction = Pointer<Uint8> Function(int handle, int value);
typedef ComputerLoadSource = int Function(
    int handle, Pointer<Uint8>, int length);
typedef ComputerGetRam = int Function(int handle);
typedef ComputerGetRom = int Function(int handle);
typedef RamGetValue = int Function(int handle, int index);
typedef RomGetValue = int Function(int handle, int index);
typedef RomGetValueDecoded = Pointer<Uint8> Function(int handle, int index);

typedef ComputerGetCpu = int Function(int handle);

typedef VoidHandleMethodNative = Void Function(IntPtr handle);
typedef VoidHandleMethod = void Function(int handle);

typedef ComputerGetScreenBufferNative = Pointer<Uint8> Function(IntPtr handle);
typedef ComputerGetScreenBuffer = Pointer<Uint8> Function(int handle);

typedef ComputerGetScreenBufferSizeNative =Int32 Function(IntPtr handle);
typedef ComputerGetScreenBufferSize = int Function(int handle);
