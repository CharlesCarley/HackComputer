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
import 'package:hack_computer/palette.dart';
import 'package:hack_computer/views/view_utils.dart';

import '../icon.dart';
import '../metrics.dart';
import '../strings.dart';
import 'box.dart';
import 'label.dart';
import 'stacked_canvas.dart';

class CanvasOverlay extends StatefulWidget {
  final Cpu state;
  final StackedCanvasObserver manager;

  const CanvasOverlay({
    Key? key,
    required this.state,
    required this.manager,
  }) : super(key: key);

  @override
  State<CanvasOverlay> createState() => _CanvasOverlayState();
}

class _CanvasOverlayState extends State<CanvasOverlay>
    with StackedCanvasListener {
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
    final size = ViewUtils.size;
    final bottomBarTop = size.height - Metrics.titleHeight;
    const iconToHeight = (Metrics.titleHeight - Metrics.iconSize) / 2;
    const topIconY = iconToHeight;
    final btmIconY = bottomBarTop + iconToHeight;
    final hw = size.width / 2;

    return Stack(
      children: [
        // top bar
        Box.create(0, 0, size.width, Metrics.titleHeight),
        // bottom bar
        Box.create(0, bottomBarTop, size.width, Metrics.titleHeight),

        /// main title
        Label.position(
          Strings.titleBar,
          Metrics.paddingEighth,
          Metrics.paddingEighth,
          fontSize: 18,
          color: Palette.titleText,
        ),

        // Top - reset
        IconWidget.tool(
          IconMappings.power,
          hw,
          btmIconY,
          () {
            widget.manager.resetComputer();
          },
          Strings.powerHelp,
          color: Palette.titleIcon,
        ),

        IconWidget.tool(
          IconMappings.play,
          size.width / 2,
          topIconY,
          () {
            widget.manager.update();
          },
          Strings.stepHelp,
          color: Palette.titleIcon,
        ),

        IconWidget.tool(
          IconMappings.screen,
          size.width / 2 + Metrics.iconSize,
          topIconY,
          () {
            widget.manager.displayScreen();
          },
          Strings.screenHelp,
          color: Palette.titleIcon,
        ),
      ],
    );
  }

  @override
  void onRestart(Cpu current, Cpu previous) {}

  @override
  void onUpdate(Cpu current, Cpu previous) {}
}
