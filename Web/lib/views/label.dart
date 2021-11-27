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
import 'package:hack_computer/palette.dart';

class Label extends StatelessWidget {
  final double x, y;
  final String label;
  final Color color;
  final double size;

  Label.create(this.label, {Key? key, double? fontSize})
      : x = Metrics.paddingEighth,
        y = Metrics.paddingEighth,
        color = Palette.wireTitle,
        size = (fontSize == null ? 14 : fontSize.toDouble()),
        super(key: key);

  Label.position(
    this.label,
    this.x,
    this.y, {
    Key? key,
    double? fontSize,
    Color? color,
  })  : size = (fontSize == null ? 14 : fontSize.toDouble()),
        color = (color == null ? Palette.wireTitle : Color(color.value)),
        super(key: key);

  const Label({
    Key? key,
    required this.label,
    required this.x,
    required this.y,
    required this.color,
    required this.size,
  }) : super(key: key);

  @override
  Widget build(BuildContext context) {
    final metrics = Metrics.measureSizedText(label, size);
    return Positioned.fromRect(
      rect: Rect.fromLTWH(x, y, metrics.width, metrics.height),
      child: Text(
        label,
        style: TextStyle(color: color, fontSize: size),
      ),
    );
  }
}
