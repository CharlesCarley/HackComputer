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
import 'package:hack_computer/cross_ffi/utils.dart';


class CpuHandle {
  final IntHandleMethod _instructionPointer; // The current program counter
  final IntHandleMethod _output; // The CPU's output to RAM
  final IntHandleMethod _address; // The current index in to RAM
  final IntHandleMethod _registerD; // Current contents of the D register
  final IntHandleMethod _registerA; // Contents of the A register
  final IntHandleMethod _clock; // The current clock cycle
  final IntHandleMethod _instruction; // The instruction in ROM at the pc index
  final IntHandleMethod _loadRam; // The load bit for the CPU.
  final IntHandleMethod _ram; // The last output from RAM
  final IntHandleMethod _reset; // Reset indicator
  final int _handle;

  CpuHandle(DynamicLibrary lib, int computer)
      : _instructionPointer =
            WrapUtil.getIntHandle(lib, "CpuGetInstructionPointer"),
        _output = WrapUtil.getIntHandle(lib, "CpuGetOutputValue"),
        _address = WrapUtil.getIntHandle(lib, "CpuGetOutputAddress"),
        _registerD = WrapUtil.getIntHandle(lib, "CpuGetDRegister"),
        _registerA = WrapUtil.getIntHandle(lib, "CpuGetARegister"),
        _clock = WrapUtil.getIntHandle(lib, "CpuGetClock"),
        _instruction = WrapUtil.getIntHandle(lib, "CpuGetInstruction"),
        _loadRam = WrapUtil.getIntHandle(lib, "CpuGetLoadRam"),
        _ram = WrapUtil.getIntHandle(lib, "CpuGetInput"),
        _reset = WrapUtil.getIntHandle(lib, "CpuGetReset"),
        _handle = computer;

  int getInstructionPointer() {
    return _instructionPointer.call(_handle);
  }

  int getOutputValue() {
    return _output.call(_handle);
  }

  int getOutputAddress() {
    return _address.call(_handle);
  }

  int getDRegister() {
    return _registerD.call(_handle);
  }

  int getARegister() {
    return _registerA.call(_handle);
  }

  int getClock() {
    return _clock.call(_handle);
  }

  int getInstruction() {
    return _instruction.call(_handle);
  }

  int getLoadRam() {
    return _loadRam.call(_handle);
  }

  int getInRam() {
    return _ram.call(_handle);
  }

  int getReset() {
    return _reset.call(_handle);
  }
}

class Cpu {
  final int instructionPointer; // The current program counter
  final int output; // The CPU's output to RAM
  final int address; // The current index in to RAM
  final int registerD; // Current contents of the D register
  final int registerA; // Contents of the A register
  final int clock; // The current clock cycle
  final int instruction; // The instruction in ROM at the pc index
  final int loadRam; // The load bit for the CPU.
  final int ram; // The last output from RAM
  final int reset; // Reset indicator

  Cpu(CpuHandle handle)
      : instructionPointer = handle.getInstructionPointer(),
        output = handle.getOutputValue(),
        address = handle.getOutputAddress(),
        registerD = handle.getDRegister(),
        registerA = handle.getARegister(),
        clock = handle.getClock(),
        instruction = handle.getInstruction(),
        loadRam = handle.getLoadRam(),
        ram = handle.getInRam(),
        reset = handle.getReset();
}
