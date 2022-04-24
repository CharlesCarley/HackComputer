/*!
\page Hc02 Chips

\brief Implements a circuit class library.

\n
It uses two separate implementations to compute the circuit logic.\n\n

The first implementation is written to compute the value of each circuit.
I wanted to keep the chip functionality present rather than abstract it away.
It links the circuits together in code and computes the value of each bit.\n\n

The second implementation is with the circuit behavior abstracted away. It
replaces the circuit logic with a C++ implementation of for its operation.\n\n

The build option that toggles this behavior is `Hack_IMPLEMENT_BLACK_BOX`.\n\n

\section Hc02Defined Defined In

The source is defined in [Source/Chips](../../Source/Chips/)

*/
#pragma once
