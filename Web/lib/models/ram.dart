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
import 'types.dart';

class Ram {
  final VoidHandleMethod _zero;
  final RamGetValue _get;
  static late int _handle;

  Ram(DynamicLibrary lib, int computer)
      : _get = lib
            .lookup<NativeFunction<RamGetValueNative>>('RamGetValue')
            .asFunction(),
        _zero = lib
            .lookup<NativeFunction<VoidHandleMethodNative>>('RamZeroMemory')
            .asFunction() {
    final ComputerGetRam create = lib
        .lookup<NativeFunction<ComputerGetRamNative>>('ComputerGetRam')
        .asFunction();
    _handle = create(computer);
  }

  int get(int idx) {
    return _get.call(_handle, idx);
  }

  void zeroMemory() {
    Future.microtask(() {
      _zero.call(_handle);
    });
  }
}
