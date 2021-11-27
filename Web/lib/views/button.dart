import 'package:flutter/material.dart';
import 'package:hack_computer/palette.dart';

import '../metrics.dart';

class ButtonWidget extends StatefulWidget {
  final double x, y;
  final double size;
  final String label;
  final Color foreground;
  final Color background;
  final VoidCallback onClick;

  const ButtonWidget({
    Key? key,
    required this.label,
    required this.x,
    required this.y,
    required this.onClick,
  })  : foreground = Palette.editTextButtonForeground,
        background = Palette.editTextButtonBackground,
        size = 60,
        super(key: key);

  @override
  State<ButtonWidget> createState() => _ButtonWidgetState();
}

class _ButtonWidgetState extends State<ButtonWidget> {
  @override
  Widget build(BuildContext context) {
    return Positioned.fromRect(
      rect: Rect.fromLTWH(
        widget.x,
        widget.y,
        widget.size,
        Metrics.textSpacer,
      ),
      child: SizedBox(
        width: widget.size,
        child: ColoredBox(
          color: widget.background,
          child: TextButton(
            clipBehavior: Clip.none,
            // invoke the callback
            onPressed: () {
              widget.onClick.call();
            },
            child: Text(
              widget.label,
              textAlign: TextAlign.center,
              style: TextStyle(
                color: widget.foreground,
              ),
            ),
          ),
        ),
      ),
    );
  }
}
