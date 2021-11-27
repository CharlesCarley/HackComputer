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

import 'dart:typed_data';
import 'dart:ui' as ui;

import 'package:flutter/material.dart';
import 'package:flutter/services.dart';
import 'package:hack_computer/computer.dart';
import 'package:hack_computer/palette.dart';
import 'package:hack_computer/views/view_utils.dart';

import '../metrics.dart';
import '../strings.dart';
import 'label.dart';
import 'stacked_canvas.dart';

class Screen extends StatefulWidget {
  final StackedCanvasObserver manager;

  const Screen({Key? key, required this.manager}) : super(key: key);

  @override
  State<Screen> createState() => _ScreenState();
}

class _ScreenState extends State<Screen> {
  late FocusNode _focusNode;
  ui.Image? _image;

  @override
  void initState() {
    _focusNode = FocusNode();
    _focusNode.requestFocus();
    _focusNode.addListener(() {
      if (!_focusNode.hasFocus) {
        widget.manager.hideScreen();
      }
    });
    super.initState();
  }

  @override
  void dispose() {
    super.dispose();
    _focusNode.dispose();
  }

  @override
  Widget build(BuildContext context) {
    const size = Size(
      Metrics.screenBufferWidth + Metrics.padding + 2,
      Metrics.screenBufferHeight + Metrics.padding + Metrics.paddingHalf + 2,
    );

    final view = ViewUtils.size;
    final Offset origin = view.center(-size.center(Offset.zero));
    final bounds = Rect.fromLTWH(origin.dx, origin.dy, size.width, size.height);
    final Size titleSize =
        Metrics.measureSizedText(Strings.screenBufferTitle, 14);

    const textBounds = Rect.fromLTWH(
      Metrics.paddingHalf,
      Metrics.padding + Metrics.paddingEighth,
      Metrics.screenBufferWidth + 2,
      Metrics.screenBufferHeight + 2,
    );

    return Positioned.fromRect(
      rect: Rect.fromLTWH(origin.dx, origin.dy, size.width, size.height),
      child: RawKeyboardListener(
        focusNode: _focusNode,
        onKey: (value) {
          if (value.physicalKey == PhysicalKeyboardKey.escape) {
            widget.manager.hideScreen();
          }
        },
        child: Container(
          decoration: BoxDecoration(
            border: Border.all(color: Palette.editTextWidgetBorder),
          ),
          child: ColoredBox(
            color: Palette.editTextWidgetBackground,
            child: Stack(
              children: [
                Label(
                  label: Strings.screenBufferTitle,
                  size: 14,
                  x: bounds.width / 2 - titleSize.width / 2,
                  y: titleSize.height / 2,
                  color: Palette.wireLight,
                ),
                Positioned.fromRect(
                  rect: textBounds,
                  child: Container(
                    decoration: BoxDecoration(
                      border: Border.all(
                          style: BorderStyle.solid, color: Palette.wireShadow),
                    ),
                    child: CustomPaint(
                      painter: ScreenPainter(getImage()),
                    ),
                  ),
                ),
              ],
            ),
          ),
        ),
      ),
    );
  }

  void updateState() {
    setState(() {});
  }

  Future<ui.Image> getImageAsync() async {
    // extract the bytes in the image
    Uint8List elements = ComputerBinding.instance.getScreenBuffer();

    // build the image format descriptor
    var buffer = await ui.ImmutableBuffer.fromUint8List(elements);

    var desc = ui.ImageDescriptor.raw(
      buffer,
      width: 512,
      height: 256,
      pixelFormat: ui.PixelFormat.rgba8888,
    );

    var codec = await desc.instantiateCodec(
      targetWidth: 512,
      targetHeight: 256,
    );

    return (await codec.getNextFrame()).image;
  }

  ui.Image? getImage() {
    Future(() {
      ComputerBinding.instance.updateScreen();
    }).whenComplete(() {
      getImageAsync().then((value) => _image = value).whenComplete(() {
        updateState();
      });
    });
    return _image;
  }
}

class ScreenPainter extends CustomPainter {
  final ui.Image? image;
  final Paint _paint;

  ScreenPainter(this.image) : _paint = Paint() {
    _paint.color = Palette.darkGrey;
  }

  @override
  void paint(Canvas canvas, Size size) {
    if (image == null) {
      canvas.drawRect(Rect.fromLTWH(0, 0, size.width, size.height), _paint);
    } else {
      _paint.blendMode = BlendMode.srcATop;
      canvas.drawImage(image!, Offset.zero, _paint);
    }
  }

  @override
  bool shouldRepaint(covariant CustomPainter oldDelegate) => true;
}
