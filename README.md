# Hack Computer

This repository is my implementation of the Hack computer in C++/Dart from the nand2Tetris [course #1](https://www.coursera.org/learn/build-a-computer).

The [chip library](Source/Chips/) implements the low level circuits in C++.
The bulk of the library is split into two forms. The first is with the black box implemented. I wanted to keep the chip functionality present rather than abstract it away for test purposes. It links the circuits together in code but it is a lot slower, therefore, the need for the second implementation. It abstracts away the circuitry and uses plan C++ to emulate the behavior of the circuit.

The build option `Hack_IMPLEMENT_BLACK_BOX` will toggle it on or off.

The [assembler library](Source/Assembler/) implements the machine code compiler.

The [computer library](Source/Computer/) ties together the ROM, RAM and CPU chips into multiple runtime versions.
If SDL is enabled, the default runtime will open a window and map the screen region of memory to the SDL window.
Otherwise if SDL is disabled, the default runtime is the [command line debugger](Content/Debugger.png).

The [web library](Web/) Is a flutter version of the command line debugger. It binds the c++ computer library to dart with `dart:ffi` and [`web_ffi`](https://pub.dev/packages/web_ffi).
It targets the window and web flutter platforms.

## Current State

The whole project is an evolving work in progress.
The flutter application was a test to see how hard it would be to implement a non-standard UI (using stack/position widgets). The web platform is incredibly slow - there is lots of room for improvement. The demo can be found [here](#current-state)

## Building

It uses CMake to generate its make files.


### Defines

Optional CMake definitions used in this project.

| Option                   | Description                                                               | Default |
|:-------------------------|:--------------------------------------------------------------------------|:-------:|
| Hack_BUILD_TEST          | Build the unit test program.                                              |   OFF   |
| Hack_AUTO_RUN_TEST       | Automatically run the test program.                                       |   OFF   |
| Hack_CHECK_INT_BOUNDS    | Throw an overflow exception when testing individual bits.                 |   ON    |
| Hack_IMPLEMENT_BLACK_BOX | If this is true most chips will be implemented with logic gates (Slower). |   OFF   |
| Hack_PRINT_CHIP_STATE    | Enables the print method defined in the Chip base class.                  |   OFF   |
| Hack_USE_SDL             | Enables or disables SDL                                                   |   OFF   |

## Testing

The testing directory is setup to work with [googletest](https://github.com/google/googletest).

It also contains the initial setup for testing the standalone module using GitHub actions.
