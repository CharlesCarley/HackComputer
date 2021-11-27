import 'package:flutter_test/flutter_test.dart';
import 'package:hack_computer/computer.dart';
import 'package:hack_computer/models/computer.dart';

typedef TestCallback = bool Function(Computer comp);

void guardedTest(String name, TestCallback? callback) {
  test(name, () {
    try {
      ComputerBinding.instance.ensureLoaded();
      expect(ComputerBinding.instance.isValid(), true,
          reason: "Computer handle is not valid");

      expect(
        callback?.call(ComputerBinding.instance),
        true,
        reason: "guardedTest assertion failed. $callback returned false",
      );

      ComputerBinding.instance.dispose();
      expect(ComputerBinding.instance.isValid(), false,
          reason: "Computer handle is valid after a call to dispose");
    } catch (s) {
      expect(
        0,
        1,
        reason: s.toString(),
      );
    }
  });
}

bool conversion(Computer computer) {
  int inVal = int.parse("0000000000000100", radix: 2);
  String outVal = computer.decode(inVal);
  expect(outVal, "@4");

  inVal = int.parse("1110101010000111", radix: 2);
  outVal = computer.decode(inVal);
  expect(outVal, "0;JMP");

  return true;
}

void main() {
  ComputerBinding.initialize();

  guardedTest("setup", (comp) => true);
  guardedTest("conversion", conversion);
}
