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
import 'package:hack_computer/strings.dart';
import 'package:hack_computer/views/stacked_canvas.dart';
import 'computer.dart';

class MainApp extends StatefulWidget {
  const MainApp({Key? key}) : super(key: key);

  @override
  State<MainApp> createState() => _MainAppState();
}

class _MainAppState extends State<MainApp> {
  @override
  void dispose() {
    ComputerBinding.dispose();
    super.dispose();
  }

  @override
  Widget build(BuildContext context) {
    return const MaterialApp(
      title: Strings.title,
      home: StackedCanvas(),
    );
  }
}

void main() async {
  WidgetsFlutterBinding.ensureInitialized();
  await ComputerBinding.initialize();

  // feed it some code
  ComputerBinding.load(Samples.fillScreen);

  runApp(const MainApp());
}
