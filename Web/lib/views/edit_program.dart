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
import 'package:hack_computer/computer.dart';
import 'package:hack_computer/metrics.dart';
import 'package:hack_computer/palette.dart';
import 'package:hack_computer/views/view_utils.dart';

import '../strings.dart';
import 'button.dart';
import 'label.dart';

typedef StringCallback = void Function(String text);

class TextEditor extends StatelessWidget {
  final TextEditingController controller;
  final Rect rect;
  final FocusNode focus;

  const TextEditor({
    Key? key,
    required this.rect,
    required this.controller,
    required this.focus,
  }) : super(key: key);

  @override
  Widget build(BuildContext context) {
    return Positioned.fromRect(
      rect: rect,
      child: Container(
        decoration: BoxDecoration(
          border: Border.all(color: Palette.editTextWidgetInnerBorder),
        ),
        child: ColoredBox(
          color: Palette.editTextBackground,
          child: TextFormField(
            autofocus: true,
            focusNode: focus,
            controller: controller,
            keyboardType: TextInputType.multiline,
            maxLines: null,
            cursorColor: Palette.action,
            style: Common.editTextStyle,
            decoration: Common.defaultTextDecoration,
          ),
        ),
      ),
    );
  }
}

class EditProgram extends StatefulWidget {
  final StringCallback onOkClicked;
  final VoidCallback onCancelClicked;
  final String program;

  const EditProgram({
    Key? key,
    required this.program,
    required this.onOkClicked,
    required this.onCancelClicked,
  }) : super(key: key);

  @override
  State<EditProgram> createState() => _EditProgramState();
}

class _EditProgramState extends State<EditProgram> {
  late String _errorText;
  late FocusNode _keyboardFocus;
  late FocusNode _editFocus;
  late TextEditingController _controller;

  @override
  void initState() {
    _errorText = "";

    _controller = TextEditingController();
    _controller.text = widget.program;

    _keyboardFocus = FocusNode();
    _keyboardFocus.requestFocus();

    _editFocus = FocusNode();
    _editFocus.requestFocus();

    super.initState();
  }

  @override
  void dispose() {
    super.dispose();
    _controller.dispose();
  }

  void handleKey(RawKeyEvent value) {
    if (value.physicalKey == PhysicalKeyboardKey.escape) {
      widget.onCancelClicked();
    }
  }

  @override
  Widget build(BuildContext context) {
    final size = ViewUtils.size;
    final windowBounds =
        Rect.fromLTWH(15, 40, size.width / 1.3, size.height / 1.3);

    final textBounds = Rect.fromLTWH(
      Metrics.paddingHalf,
      Metrics.padding,
      windowBounds.width - Metrics.padding,
      windowBounds.height - Metrics.paddingDouble,
    );

    final titleSize = Metrics.measureSizedText(Strings.editProgramTitle, 18);

    return Positioned.fromRect(
      rect: windowBounds,
      child: RawKeyboardListener(
        onKey: handleKey,
        focusNode: _keyboardFocus,
        child: Container(
          decoration: BoxDecoration(
            border: Border.all(color: Palette.editTextWidgetBorder),
          ),
          child: ColoredBox(
            color: Palette.editTextWidgetBackground,
            child: Stack(
              children: [
                Label(
                  label: Strings.editProgramTitle,
                  size: 16,
                  x: windowBounds.width / 2 - titleSize.width / 2,
                  y: titleSize.height / 4,
                  color: Palette.titleText,
                ),
                TextEditor(
                  rect: textBounds,
                  focus: _editFocus,
                  controller: _controller,
                ),
                ButtonWidget(
                  onClick: () {
                    _compile();
                  },
                  x: windowBounds.width - 140,
                  y: windowBounds.height - 27,
                  label: "OK",
                ),
                ButtonWidget(
                  onClick: widget.onCancelClicked,
                  x: windowBounds.width - 75,
                  y: windowBounds.height - 27,
                  label: "Cancel",
                ),
                Label.position(
                  _errorText,
                  Metrics.paddingHalf,
                  windowBounds.height -
                      Metrics.textSpacer -
                      Metrics.paddingForth,
                  color: Palette.wireLight,
                )
              ],
            ),
          ),
        ),
      ),
    );
  }

  void _compile() async {
    await Future<void>(() {
      if (ComputerBinding.instance.load(_controller.text) == 1) {
        _errorText = ComputerBinding.instance.getCompileError();
      } else {
        _errorText = "";
      }
    }).whenComplete(() {
      if (_errorText.isEmpty) {
        widget.onOkClicked.call(_controller.text);
      }
    });

    if (_errorText.isNotEmpty) {
      setState(() {});
    }
  }
}
