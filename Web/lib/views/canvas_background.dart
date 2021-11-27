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
import 'package:hack_computer/models/cpu.dart';

import '../computer.dart';
import '../metrics.dart';
import '../palette.dart';
import '../strings.dart';
import 'label.dart';
import 'line.dart';
import 'line_list.dart';
import 'stacked_canvas.dart';
import 'view_utils.dart';

class CanvasBackground extends StatefulWidget {
  final Cpu state;
  final StackedCanvasObserver manager;

  const CanvasBackground({
    Key? key,
    required this.state,
    required this.manager,
  }) : super(key: key);

  @override
  State<CanvasBackground> createState() => _CanvasBackgroundState();
}

class _CanvasBackgroundState extends State<CanvasBackground>
    with StackedCanvasListener {
  late Color _instructionColor;
  late Color _addressColor;
  late Color _cpuInput;
  late Color _instructionPointer;
  late Color _cpuOutput;
  late String _currentInstruction;

  @override
  void initState() {
    // initialize initial colors
    _instructionColor = Palette.wireNoChange;
    _addressColor = Palette.wireNoChange;
    _cpuInput = Palette.wireNoChange;
    _instructionPointer = Palette.wireNoChange;
    _cpuOutput = Palette.wireNoChange;

    // the current decoded instruction
    _currentInstruction =
        ComputerBinding.instance.decode(widget.state.instruction);

    widget.manager.addListener(this);
    super.initState();
  }

  @override
  void dispose() {
    widget.manager.removeListener(this);
    super.dispose();
  }

  @override
  Widget build(BuildContext context) {
    return Stack(
      children: _buildLinks(),
    );
  }

  List<Widget> _buildLinks() {
    final h = ViewUtils.size.height;
    final w = ViewUtils.size.width;

    final hw = w / 2;
    final hh = h / 2;

    final bt = h - Metrics.padding - Metrics.paddingForth;
    final rt = w - Metrics.paddingForth;

    Size outputSize = Metrics.measureText(Strings.output);

    double vot = hw + 75 + outputSize.width;
    double rot = hw - Metrics.cpuHalfWidth - 2 * Metrics.maxIndex.width;

    final Rect cpuRect = Rect.fromLTWH(
      hw - Metrics.cpuHalfWidth,
      hh - Metrics.cpuHeight / 2,
      Metrics.cpuWidth,
      Metrics.cpuHeight,
    );

    final Rect romRect = Rect.fromLTWH(
      Metrics.paddingHalf,
      (ViewUtils.size.height - ViewUtils.size.height) / 2,
      Metrics.memoryWidth,
      ViewUtils.size.height - Metrics.paddingTriple,
    );

    const fontSize = 12.0;
    final instScreenSize =
        Metrics.measureSizedText(_currentInstruction, fontSize);

    final String ramOut = widget.state.ram.toString();

    final ramOutScreenSize = Metrics.measureSizedText(ramOut, fontSize);
    final outputScreenSize = Metrics.measureSizedText(Strings.output, fontSize);

    return [
      Label.position(
        Strings.instruction,
        romRect.right,
        hh - fontSize - 3,
        fontSize: fontSize,
      ),
      Label.position(
        _currentInstruction,
        cpuRect.left - instScreenSize.width,
        hh - fontSize - 3,
        color: Palette.action,
        fontSize: fontSize,
      ),
      LineListWidget(
        color: _instructionColor,
        segments: [
          LineSegment.horizontal(50, hh, hw, hh),
        ],
      ),

      // CPU.ADR -> RAM
      Label.position(
        Strings.address,
        cpuRect.right,
        hh - fontSize - 3,
        fontSize: fontSize,
      ),
      LineListWidget(
        color: _addressColor,
        segments: [
          LineSegment.horizontal(hw, hh, w - 50, hh),
        ],
      ),

      // CPU.OUT -> RAM + Write
      Label.position(
        Strings.output,
        cpuRect.right,
        hh + fontSize + 10,
        fontSize: fontSize,
      ),
      LineListWidget(
        color: _cpuOutput,
        segments: [
          // CPU.OUT
          LineSegment.horizontal(hw, hh + 40, vot, hh + 40),
          LineSegment.vertical(vot, hh + 40, vot, bt + 1),
          LineSegment.horizontal(vot, bt, rt, bt),
          LineSegment.vertical(rt, hh, rt, bt),
          LineSegment.horizontal(rt - 50, hh, rt, hh),
        ],
      ),

      // RAM.OUT -> CPU.IN
      Label.position(
        ramOut,
        cpuRect.left - ramOutScreenSize.width,
        hh - (60 + fontSize + 3),
        color: Palette.action,
        fontSize: fontSize,
      ),
      Label.position(
        Strings.output,
        rt -
            Metrics.memoryWidth -
            outputScreenSize.width -
            Metrics.paddingForth -
            2,
        Metrics.paddingTriple - fontSize - 3,
        color: Palette.wireTitle,
        fontSize: fontSize,
      ),
      LineListWidget(
        color: _cpuInput,
        segments: [
          LineSegment.horizontal(
            rot,
            Metrics.paddingTriple,
            rt - 20,
            Metrics.paddingTriple,
          ),
          LineSegment.vertical(rot, Metrics.paddingTriple, rot, hh - 60),
          LineSegment.horizontal(rot, hh - 60, hw, hh - 60),
        ],
      ),
      // CPU.PC -> ROM.IN
      LineListWidget(
        color: _instructionPointer,
        segments: [
          LineSegment.vertical(hw, hh, hw, bt + 1.5),
          LineSegment.horizontal(
            Metrics.paddingForth,
            bt,
            hw,
            bt,
          ),
          LineSegment.vertical(
            Metrics.paddingForth,
            hh,
            Metrics.paddingForth,
            bt,
          ),
          LineSegment.horizontal(
            Metrics.paddingForth,
            hh,
            50,
            hh,
          ),
        ],
      ),
    ];
  }


  void _updateWireColors(Cpu current, Cpu previous) {
    if (previous.instruction != current.instruction) {
      _instructionColor = Palette.wireChange;
    } else {
      _instructionColor = Palette.wireNoChange;
    }

    if (previous.address != current.address) {
      _addressColor = Palette.wireChange;
    } else {
      _addressColor = Palette.wireNoChange;
    }

    if (previous.ram != current.ram) {
      _cpuInput = Palette.wireChange;
    } else {
      _cpuInput = Palette.wireNoChange;
    }

    if (previous.instructionPointer != current.instructionPointer) {
      _instructionPointer = Palette.wireChange;
    } else {
      _instructionPointer = Palette.wireNoChange;
    }

    if (previous.output != current.output) {
      _cpuOutput = Palette.wireChange;
    } else {
      _cpuOutput = Palette.wireNoChange;
    }
  }

  @override
  void onRestart(Cpu current, Cpu previous) {
    // TODO: implement onRestart
  }

  @override
  void onUpdate(Cpu current, Cpu previous) {
    setState(() {
      _updateWireColors(current, previous);
      // the current decoded instruction
      _currentInstruction =
          ComputerBinding.instance.decode(widget.state.instruction);
    });
  }
}
