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

import 'package:flutter/material.dart';
import 'package:flutter/services.dart';
import 'package:flutter/widgets.dart';
import 'package:hack_computer/models/cpu.dart';
import 'package:hack_computer/strings.dart';
import 'package:hack_computer/views/canvas_background.dart';
import 'package:hack_computer/views/canvas_chips.dart';
import 'package:hack_computer/views/canvas_overlay.dart';
import 'package:hack_computer/views/view_utils.dart';
import '../computer.dart';
import '../palette.dart';
import 'edit_program.dart';
import 'screen.dart';

abstract class StackedCanvasListener {
  void onRestart(Cpu current, Cpu previous);

  void onUpdate(Cpu current, Cpu previous);
}

class StackedCanvasObserver {
  List<StackedCanvasListener> listeners = <StackedCanvasListener>[];

  void addListener(StackedCanvasListener listener) {
    listeners.add(listener);
  }

  void removeListener(StackedCanvasListener listener) {
    if (listeners.contains(listener)) {
      listeners.remove(listener);
    }
  }

  void notifyRestart(Cpu current, Cpu previous) {
    for (var value in listeners) {
      value.onRestart(current, previous);
    }
  }

  void notifyUpdate(Cpu current, Cpu previous) {
    for (var value in listeners) {
      value.onUpdate(current, previous);
    }
  }

  void showEditor() {}

  void resetComputer() {}

  void update() {}

  void displayScreen() {}

  void viewOnGithub() {}

  void hideScreen() {}
}

class StackedCanvas extends StatefulWidget {
  const StackedCanvas({Key? key}) : super(key: key);

  @override
  State<StackedCanvas> createState() => _StackedCanvasState();
}

class _StackedCanvasState extends State<StackedCanvas>
    with StackedCanvasObserver {
  late FocusNode _focusNode;
  late String _currentProgram;

  // variables to control the state of the dialog windows.
  late bool _textWidgetVisible;
  late bool _screenWidgetVisible;

  late Cpu _cpuState;
  late Cpu _prevState;

  @override
  void initState() {
    ComputerBinding.instance.ensureLoaded();

    _focusNode = FocusNode(debugLabel: "KeyboardFocus");

    _cpuState = ComputerBinding.instance.getState();
    _prevState = _cpuState;

    _currentProgram = Samples.fillScreen;

    _focusNode.requestFocus();

    _textWidgetVisible = false;
    _screenWidgetVisible = false;

    super.initState();
  }

  @override
  void dispose() {
    ComputerBinding.instance.dispose();
    super.dispose();
  }

  @override
  void resetComputer() async {
    final state = await Future<Cpu>(() {
      ComputerBinding.instance.restart();
      return ComputerBinding.instance.getState();
    });

    setState(() {
      _prevState = _cpuState = state;
      notifyRestart(_cpuState, _prevState);
    });
  }

  @override
  void update() async {
    // save the previous state then determine updates regions from the change
    // from previous to current.

    _cpuState = await Future<Cpu>(() {
      _prevState = _cpuState;

      // update it
      ComputerBinding.instance.update();

      // grab the current
      return ComputerBinding.instance.getState();
    });

    setState(() {
      notifyUpdate(_cpuState, _prevState);
    });
  }

  @override
  void viewOnGithub() async {
    // print("viewOnGithub - clicked");
  }

  @override
  void showEditor() {
    setState(() {
      _textWidgetVisible = true;
      _focusNode.unfocus();
    });
  }

  void handleKeys(RawKeyEvent value) {
    if (_textWidgetVisible || _screenWidgetVisible) {
      if (value.physicalKey == PhysicalKeyboardKey.escape) {
        if (_textWidgetVisible) {
          hideEdit();
        }
        if (_screenWidgetVisible) {
          hideScreen();
        }
      } else {
        return;
      }
    }

    if (value.physicalKey == PhysicalKeyboardKey.arrowUp) {
      update();
    } else if (value.physicalKey == PhysicalKeyboardKey.keyR ||
        value.logicalKey == LogicalKeyboardKey.keyR) {
      resetComputer();
    } else if (value.physicalKey == PhysicalKeyboardKey.keyE) {
      showEditor();
    } else if (value.physicalKey == PhysicalKeyboardKey.keyP) {
      displayScreen();
    }
  }

  void hideEdit() {
    setState(() {
      _textWidgetVisible = false;
      _focusNode.requestFocus();
    });
  }

  void loadText(String text) {
    setState(() {
      _currentProgram = text;
      _textWidgetVisible = false;

      _focusNode.requestFocus();
    });
    resetComputer();
  }

  @override
  Widget build(BuildContext context) {
    ViewUtils.update(context);

    return RawKeyboardListener(
      focusNode: _focusNode,
      autofocus: false,
      onKey: handleKeys,
      child: Scaffold(
        backgroundColor: Palette.background,
        body: Stack(
          children: getElements(),
        ),
      ),
    );
  }

  List<Widget> getElements() {
    List<Widget> content = [];

    content.add(CanvasBackground(state: _cpuState, manager: this));
    content.add(CanvasChips(state: _cpuState, manager: this));
    content.add(CanvasOverlay(state: _cpuState, manager: this));

    if (_textWidgetVisible) {
      content.add(EditProgram(
        program: _currentProgram,
        onOkClicked: loadText,
        onCancelClicked: hideEdit,
      ));
    } else if (_screenWidgetVisible) {
      content.add(Screen(manager: this));
    }

    return content;
  }

  @override
  void displayScreen() {
    setState(() {
      _screenWidgetVisible = true;
      update();
      _focusNode.unfocus();
    });
  }

  @override
  void hideScreen() {
    setState(() {
      _screenWidgetVisible = false;
      _focusNode.requestFocus();
    });
  }
}
