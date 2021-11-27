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
import 'package:hack_computer/views/ram.dart';
import 'package:hack_computer/views/rom.dart';

import 'cpu.dart';
import 'stacked_canvas.dart';

class CanvasChips extends StatefulWidget {
  final Cpu state;
  final StackedCanvasObserver manager;

  const CanvasChips({
    Key? key,
    required this.state,
    required this.manager,
  }) : super(key: key);

  @override
  State<CanvasChips> createState() => _CanvasChipsState();
}

class _CanvasChipsState extends State<CanvasChips> with StackedCanvasListener {

  @override
  void initState() {
    super.initState();
  }

  @override
  void dispose() {
    super.dispose();
  }

  @override
  Widget build(BuildContext context) {
    return Stack(
      children: [
        CpuWidget(current: widget.state),
        RomWidget(
            current: widget.state,
            onEdit: () {
              widget.manager.showEditor();
            }),
        RamWidget(current: widget.state),
      ],
    );
  }

  @override
  void onRestart(Cpu current, Cpu previous) {
    // TODO: implement onRestart
  }

  @override
  void onUpdate(Cpu current, Cpu previous) {
    // TODO: implement onUpdate
  }
}
