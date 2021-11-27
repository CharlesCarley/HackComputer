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

import 'cross_ffi/proxy.dart';
import 'models/computer.dart';

class ComputerBinding {
  static late final DynamicLibrary _library;
  static final Computer _computer = Computer(_library);

  static Computer get instance => _computer;

  static Future<void> initialize() async {
    await initFfi();
    _library = openComputer();
  }

  static void dispose() {
    // frees all the handles
    _computer.dispose();
  }

  static void load(String code) {
    _computer.load(code);
  }
}
