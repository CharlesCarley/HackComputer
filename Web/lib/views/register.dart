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

import 'label.dart';
import '../metrics.dart';
import '../palette.dart';

class Register extends StatelessWidget {
  final double x, y, w, h;
  final String label;
  final String value;

  const Register({
    Key? key,
    required this.x,
    required this.y,
    required this.w,
    required this.h,
    required this.label,
    required this.value,
  }) : super(key: key);

  @override
  Widget build(BuildContext context) {
    double size = Metrics.defaultTextSize(context);

    return Stack(
      children: [
        Label.position(
          label,
          x,
          y,
          color: Palette.memoryText,
          fontSize: 10,
        ),
        Positioned.fromRect(
          rect: Rect.fromLTWH(x, y + size + 2, w, h),
          child: Container(
            decoration: BoxDecoration(
              border: Border.all(color: Palette.memorySelectionBorder),
            ),
            child: ColoredBox(
              color: Palette.memorySelection,
              child: Text(
                value,
                textAlign: TextAlign.center,
                style: const TextStyle(
                    color: Palette.memoryTextMiddle, fontSize: 12),
              ),
            ),
          ),
        ),
      ],
    );
  }
}
