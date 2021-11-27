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
import 'package:hack_computer/strings.dart';
import 'package:hack_computer/views/box.dart';
import 'package:hack_computer/views/label.dart';
import 'package:hack_computer/views/view_utils.dart';
import '../metrics.dart';
import 'register.dart';

class CpuWidget extends StatelessWidget {
  final Size size = const Size(Metrics.cpuWidth, Metrics.cpuHeight);
  final Cpu current;

  const CpuWidget({
    Key? key,
    required this.current,
  }) : super(key: key);

  @override
  Widget build(BuildContext context) {

    final Offset offset = ViewUtils.size.center(-size.center(Offset.zero));
    final Rect bounds = Metrics.contentRect(context, offset, size);

    return Stack(children: [
      Box.create(offset.dx, offset.dy, size.width, size.height),
      Label.position(
        Strings.cpu,
        offset.dx + Metrics.paddingForth,
        offset.dy + Metrics.paddingEighth,
      ),
      Positioned.fromRect(
        rect: bounds,
        child: Stack(
          children: _getCurrent(context, offset, bounds),
        ),
      ),
    ]);
  }

  List<Widget> _getCurrent(BuildContext context, Offset origin, Rect bounds) {
    List<Widget> retVal = [];
    final registerSize = Offset(bounds.width / 4, bounds.width / 2);

    double size = 20;
    double offset = 0;

    retVal.add(
      Register(
        label: Strings.dRegister,
        value: current.registerD.toString(),
        x: registerSize.dx,
        y: offset,
        w: registerSize.dy,
        h: size,
      ),
    );
    offset += size + Metrics.padding;

    retVal.add(
      Register(
        label: Strings.aRegister,
        value: current.registerA.toString(),
        x: registerSize.dx,
        y: offset,
        w: registerSize.dy,
        h: size,
      ),
    );
    offset += size + Metrics.padding;
    retVal.add(
      Register(
        label: Strings.programCounter,
        value: current.instructionPointer.toString(),
        x: registerSize.dx,
        y: offset,
        w: registerSize.dy,
        h: size,
      ),
    );

    return retVal;
  }
}
