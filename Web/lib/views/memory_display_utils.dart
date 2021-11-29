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

import 'box.dart';
import 'label.dart';
import '../metrics.dart';
import '../palette.dart';

///
typedef GetIndexCallback = String Function(int index);

class MemoryDisplayUtils {
  /// Displays a list of indexed values centered at half the contentBounds's
  /// height.
  static List<Widget> memoryContents(
    BuildContext context,
    Rect contentBounds,
    int memoryOffset,
    GetIndexCallback getIndexCallback,
  ) {
    List<Widget> widgets = [];

    final size = Metrics.defaultTextSize(context);
    final h = (contentBounds.height.toInt()) >> 1;

    // center the current instruction at
    // half the height (Metrics.defaultTextSize is the default + 2 for spacing)
    final contentCenter = contentBounds.height / 2 - size - 2;

    const textSize = 12.5;

    // start at negative half the content height
    // so that when the iteration reaches the mid point
    // it's directly center aligned.
    for (int i = -h + 1; i < h; ++i) {
      final computedIndex = i + memoryOffset;

      // ignore negative values.
      if (computedIndex >= 0) {
        // grab the value in memory at the current index
        final valueString = getIndexCallback.call(computedIndex);

        // also store the direct index
        final indexString = computedIndex.toString();

        // compute the length of both strings on screen
        final valueSize = Metrics.measureSizedText(valueString, textSize);
        final indexSize = Metrics.measureSizedText(indexString, textSize);

        final centerOffset = contentCenter + i * size;

        // highlight the center of the list.
        if (computedIndex == memoryOffset) {
          widgets.add(Box.create(
            0,
            centerOffset + 1,
            contentBounds.width,
            size + 1,
            color: Palette.memorySelection,
          ));
        }

        widgets.add(Label(
          size: textSize,
          label: indexString,
          x: Metrics.maxIndex.width - indexSize.width,
          y: centerOffset,

          // apply a selection color for the current item
          color: computedIndex == memoryOffset
              ? Palette.memoryAction
              : Palette.memoryText,
        ));

        widgets.add(Label(
          size: textSize,
          label: valueString,
          x: contentBounds.width - valueSize.width,
          y: centerOffset,

          // apply a selection color for the current item
          color: computedIndex == memoryOffset
              ? Palette.memoryHighlight
              : Palette.memoryText,
        ));

        if (computedIndex == memoryOffset) {
          widgets.add(Box.create(
            0,
            centerOffset + size / 2 - 1.5,
            contentBounds.width,
            5,
            color: Palette.memorySelectionHighlight,
          ));
        }
      }
    }
    return widgets;
  }
}
