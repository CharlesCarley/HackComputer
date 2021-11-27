import 'dart:ffi';
import 'dart:io' as os;

Future<void> initFfi() async {
// For dart:ffi platforms, this can be a no-op (empty function)
}

DynamicLibrary openComputer() {
  if (os.Platform.isWindows) {
    return DynamicLibrary.open("bindings.dll");
  } else if (os.Platform.isLinux) {
    return DynamicLibrary.open("assets/libbindings.so");
  } else {
    throw StateError("Undefined platform");
  }
}
