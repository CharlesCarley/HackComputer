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
import 'package:hack_computer/views/view_utils.dart';

import '../computer.dart';
import '../icon.dart';
import '../metrics.dart';
import '../palette.dart';
import '../strings.dart';
import 'box.dart';
import 'label.dart';
import 'memory_display_utils.dart';

class RomWidget extends StatelessWidget {
  final VoidCallback onEdit;
  final Cpu current;

  const RomWidget({
    Key? key,
    required this.onEdit,
    required this.current,
  }) : super(key: key);

  @override
  Widget build(BuildContext context) {
    final size = Size(
      Metrics.memoryWidth,
      ViewUtils.size.height - Metrics.paddingTriple,
    );

    final origin = Offset(
      Metrics.paddingHalf,
      (ViewUtils.size.height - size.height) / 2,
    );

    final bounds = Metrics.contentRect(context, origin, size);
    final iconLoc = origin.dx + bounds.width - Metrics.iconSize;

    return Stack(children: [
      Box.create(origin.dx, origin.dy, size.width, size.height),
      Label.position(
        Strings.rom,
        origin.dx + Metrics.paddingForth,
        origin.dy + Metrics.paddingEighth,
        color: Palette.chipTitleForeground,
      ),
      IconWidget(
        x: iconLoc,
        y: origin.dy + Metrics.paddingEighth,
        color: Palette.chipTitleForeground,
        icon: IconMappings.edit,
        onClick: onEdit,
        tooltip: Strings.editHelp,
      ),
      Positioned.fromRect(
        rect: bounds,
        child: Stack(
          children: MemoryDisplayUtils.memoryContents(
            context,
            bounds,
            current.instructionPointer,
            (index) {
              return ComputerBinding.instance.getRom().decode(index);
            },
          ),
        ),
      ),
    ]);
  }
}
