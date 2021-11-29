import 'package:web_ffi/web_ffi.dart';
import 'package:web_ffi/web_ffi_modules.dart';
import 'package:inject_js/inject_js.dart';
import 'package:flutter/services.dart';

Module? _module;

const String _path = "assets";

Future<void> initFfi() async {
  // Only initialize if there is no module yet
  if (_module == null) {
    Memory.init();
    // If your generated code would contain something that
    // extends Opaque, you would register it here
    // registerOpaqueType<MyOpaque>();

    await importLibrary('$_path/assets/bindings.js');
    final result = await rootBundle.load('$_path/assets/bindings.wasm');
    final binary = result.buffer.asUint8List();

    _module = await EmscriptenModule.compile(binary, "bindings");
  }
}

DynamicLibrary openComputer() {
  Module? m = _module;
  if (m != null) {
    return DynamicLibrary.fromModule(m);
  } else {
    throw StateError('You can not open bindings before calling initFfi()!');
  }
}
