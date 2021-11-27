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

import 'dart:typed_data';

import 'package:hack_computer/cross_ffi/proxy.dart';
import 'package:hack_computer/cross_ffi/utils.dart';
import 'package:hack_computer/models/ram.dart';
import 'package:hack_computer/models/rom.dart';

import 'dart:convert';

import 'cpu.dart';
import 'types.dart';

class Computer {
  final DynamicLibrary _library;
  final UpdateComputer _update;
  final UpdateComputer _restart; // Note: reusing UpdateComputer signature
  final ComputerLoadSource _load;
  final RomGetValueDecoded _decode;
  final ComputerGetLastError _lastError;
  final ComputerGetScreenBuffer _getScreenBuffer;
  final ComputerGetScreenBufferSize _getScreenBufferSize;
  final VoidHandleMethod _screenUpdate;
  static int _handle = 0;
  static late CpuHandle _currentStateHandle;

  static late Cpu _currentState;
  static late Cpu _previousState;

  Computer(DynamicLibrary lib)
      : _library = lib,
        _update = lib
            .lookup<NativeFunction<UpdateComputerNative>>('UpdateComputer')
            .asFunction(),
        _restart = lib
            .lookup<NativeFunction<UpdateComputerNative>>('RestartComputer')
            .asFunction(),
        _load = lib
            .lookup<NativeFunction<ComputerLoadSourceNative>>(
                'ComputerLoadSource')
            .asFunction(),
        _lastError = lib
            .lookup<NativeFunction<ComputerGetLastErrorNative>>(
                'ComputerGetLastError')
            .asFunction(),
        _decode = lib
            .lookup<NativeFunction<DecodeInstructionNative>>(
                'DecodeInstruction')
            .asFunction(),
        _getScreenBufferSize = lib
            .lookup<NativeFunction<ComputerGetScreenBufferSizeNative>>(
                'ComputerGetScreenBufferSize')
            .asFunction(),
        _screenUpdate = lib
            .lookup<NativeFunction<VoidHandleMethodNative>>(
                'ComputerUpdateScreen')
            .asFunction(),
        _getScreenBuffer = lib
            .lookup<NativeFunction<ComputerGetScreenBufferNative>>(
                'ComputerGetScreenBuffer')
            .asFunction() {
    _handle = _getHandle(lib);
    _currentStateHandle = CpuHandle(lib, _handle);
    _previousState = Cpu(_currentStateHandle);
    _currentState = Cpu(_currentStateHandle);
  }

  bool isValid() {
    return _handle != 0;
  }

  int _getHandle(DynamicLibrary lib) {
    CreateComputer create = lib
        .lookup<NativeFunction<CreateComputerNative>>('CreateComputer')
        .asFunction();
    return create.call();
  }

  Ram getRam() {
    return Ram(_library, _handle);
  }

  Rom getRom() {
    return Rom(_library, _handle);
  }

  Cpu getState() {
    return _currentState;
  }

  Cpu getPreviousState() {
    return _previousState;
  }

  int load(String data) {
    if (data.isEmpty) {
      return 0;
    }

    final bytes = ascii.encode(data);
    var alloc = ComputerAlloc(_library);
    Pointer<Uint8> allocation = alloc.allocate(bytes.length);

    allocation.asTypedList(bytes.length).setAll(0, bytes);

    final result = _load.call(_handle, allocation, bytes.length);
    alloc.free(allocation);
    return result;
  }

  String getCompileError() {
    return WrapUtil.ptrToString(_lastError.call(_handle));
  }

  /// decode - attempts to convert the supplied value to
  /// a string representation of an instruction.
  ///
  /// for example,
  /// the binary instruction
  /// ```
  ///     0-00-0-000000-000-100 == @4
  /// ```
  String decode(int value) {
    return WrapUtil.ptrToString(_decode.call(_handle, value));
  }

  /// ensureLoaded - tests to make sure that the handle to computer is
  /// allocated and in a usable state.
  bool ensureLoaded() {
    // allow some sort of control over the setup and teardown of the memory
    if (_handle == 0) {
      _handle = _getHandle(_library);
    }
    return isValid();
  }

  void recreate() {
    dispose();
    ensureLoaded();
  }

  void dispose() {
    final DestroyComputer destroy = _library
        .lookup<NativeFunction<DestroyComputerNative>>('DestroyComputer')
        .asFunction();
    destroy.call(_handle);
    _handle = 0;
  }

  void update() {
    _previousState = _currentState;
    _update.call(_handle);
    _currentState = Cpu(_currentStateHandle);
  }

  void restart() {
    _restart.call(_handle);
    _previousState = _currentState = Cpu(_currentStateHandle);
  }

  void updateScreen() {
    Future.microtask(() {
      _screenUpdate.call(_handle);
    });
  }

  Uint8List getScreenBuffer() {
    final length = _getScreenBufferSize.call(_handle);
    if (length == 0x80000) {
      Pointer<Uint8> buffer = _getScreenBuffer.call(_handle);

      return Uint8List.fromList(buffer.asTypedList(length));
    } else {
      throw StateError("invalid length check");
    }
  }
}
