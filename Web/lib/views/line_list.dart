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
import 'line.dart';

class LineListWidget extends StatefulWidget {
  final List<LineSegment> segments;
  final Color color;

  const LineListWidget({
    Key? key,
    required this.segments,
    required this.color,
  }) : super(key: key);

  @override
  State<LineListWidget> createState() => _LineListWidgetState();
}

class _LineListWidgetState extends State<LineListWidget> {
  @override
  Widget build(BuildContext context) {
    return Stack(children: _getSegments());
  }

  List<Widget> _getSegments() {
    List<Widget> widgets = [];
    for (int i = 0; i < widget.segments.length; ++i) {
      LineSegment seg = widget.segments[i];

      if (seg.dir == LineDirection.horizontal) {
        widgets.add(Line(
          segment: LineSegment.horizontal(seg.x0, seg.y0, seg.x1, seg.y1),
          color: widget.color,
        ));
      } else {
        widgets.add(Line(
          segment: LineSegment.vertical(seg.x0, seg.y0, seg.x1, seg.y1),
          color: widget.color,
        ));
      }
    }
    return widgets;
  }
}
