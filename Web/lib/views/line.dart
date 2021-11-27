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
import 'package:hack_computer/metrics.dart';

enum LineDirection {
  horizontal,
  vertical,
}

class LineSegment {
  final double x0, y0, x1, y1;
  final LineDirection dir;

  const LineSegment.zero()
      : x0 = 0,
        x1 = 0,
        y0 = 0,
        y1 = 0,
        dir = LineDirection.horizontal;

  const LineSegment(this.x0, this.y0, this.x1, this.y1, this.dir);

  const LineSegment.horizontal(this.x0, this.y0, this.x1, this.y1)
      : dir = LineDirection.horizontal;

  const LineSegment.vertical(this.x0, this.y0, this.x1, this.y1)
      : dir = LineDirection.vertical;
}

class Line extends StatefulWidget {
  final LineSegment segment;
  final Color color;

  const Line({
    Key? key,
    required this.segment,
    required this.color,
  }) : super(key: key);

  @override
  State<Line> createState() => _LineState();
}

class _LineState extends State<Line> {
  @override
  Widget build(BuildContext context) {
    final double w, h;
    if (widget.segment.dir == LineDirection.horizontal) {
      h = Metrics.lineWidth;
      w = 0;
    } else {
      w = Metrics.lineWidth;
      h = 0;
    }

    return Positioned.fromRect(
      rect: Rect.fromLTRB(
        widget.segment.x0,
        widget.segment.y0,
        widget.segment.x1 + w,
        widget.segment.y1 + h,
      ),
      child: ColoredBox(
        color: widget.color,
      ),
    );
  }
}
