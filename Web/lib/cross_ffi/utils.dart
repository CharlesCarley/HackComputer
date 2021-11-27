import 'proxy.dart';
import 'dart:convert';

typedef IntHandleMethodNative = Int32 Function(IntPtr handle);
typedef IntHandleMethod = int Function(int handle);

typedef AllocateNative = Pointer<Uint8> Function(Int32 length);
typedef Allocate = Pointer<Uint8> Function(int length);
typedef FreeNative = Void Function(Pointer<Uint8> free);
typedef Free = void Function(Pointer<Uint8> free);

/// Allocator for strings
class ComputerAlloc implements Allocator {
  final DynamicLibrary library;
  final Allocate _allocate;
  final Free _free;

  ComputerAlloc(this.library)
      : _allocate = library
            .lookup<NativeFunction<AllocateNative>>("ComputerAllocate")
            .asFunction(),
        _free = library
            .lookup<NativeFunction<FreeNative>>("ComputerFree")
            .asFunction(),
        super();

  @override
  Pointer<T> allocate<T extends NativeType>(int byteCount, {int? alignment}) {
    return _allocate.call(byteCount).cast();
  }

  @override
  void free(Pointer<NativeType> pointer) {
    _free.call(pointer.cast());
  }
}

class WrapUtil {
  /// getIntHandle - provides a common loader for the exported
  ///  function signature int method(Handle handle)
  static IntHandleMethod getIntHandle(DynamicLibrary lib, String name) {
    return lib.lookup<NativeFunction<IntHandleMethodNative>>(name).asFunction();
  }

  /// implements the conversion of a char* to String
  static String ptrToString(Pointer<Uint8> val) {
    int v = 0;
    while (val[v] != 0) {
      ++v;
    }
    return v > 0 ? ascii.decode(val.asTypedList(v)) : '';
  }
}
