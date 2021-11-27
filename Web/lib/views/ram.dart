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
import 'package:hack_computer/icon.dart';
import 'package:hack_computer/models/cpu.dart';
import 'package:hack_computer/strings.dart';
import 'package:hack_computer/views/memory_display_utils.dart';
import 'package:hack_computer/views/view_utils.dart';

import '../computer.dart';
import '../metrics.dart';
import '../palette.dart';
import 'box.dart';
import 'label.dart';

class RamWidget extends StatefulWidget {
  final Cpu current;

  const RamWidget({
    Key? key,
    required this.current,
  }) : super(key: key);

  @override
  State<RamWidget> createState() => _RamWidgetState();
}

class _RamWidgetState extends State<RamWidget> {
  @override
  Widget build(BuildContext context) {

    // overall black box size
    final size = Size(
      Metrics.memoryWidth,
      ViewUtils.size.height - Metrics.paddingTriple,
    );

    // the origin of the black box relative to the main canvas
    final origin = Offset(
      ViewUtils.size.width - (size.width + Metrics.paddingHalf),
      (ViewUtils.size.height - size.height) / 2,
    );

    final contentBounds = Metrics.contentRect(context, origin, size);
    final broomLocation = origin.dx + contentBounds.width - Metrics.iconSize;

    return Stack(children: [
      Box.create(origin.dx, origin.dy, size.width, size.height),
      Label.position(
        Strings.ram,
        origin.dx + Metrics.paddingForth,
        origin.dy + Metrics.paddingEighth,
      ),
      IconWidget(
        x: broomLocation,
        y: origin.dy + Metrics.paddingEighth,
        color: Palette.wireTitle,
        icon: IconMappings.brush,
        onClick: clearRam,
        tooltip: Strings.ramClear,
      ),
      Positioned.fromRect(
        rect: contentBounds,
        child: Stack(
          children: MemoryDisplayUtils.memoryContents(
            context,
            contentBounds,
            widget.current.address,
            (index) {
              return ComputerBinding.instance.getRam().get(index).toString();
            },
          ),
        ),
      ),
    ]);
  }

  void clearRam() async {

    await Future((){
      final ram = ComputerBinding.instance.getRam();
      ram.zeroMemory();
    });
    setState(() {});
  }
}
