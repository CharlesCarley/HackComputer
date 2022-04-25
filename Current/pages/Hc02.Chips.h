/*!
\page Hc02 Chips

\brief Implements the circuit class library.

\section Hc02Impl Implementation 
It uses two separate implementations to compute the circuit logic.\n\n

The first implementation is written to compute the value of each circuit.
It links the circuits together in code and computes the value of each bit.
\n\n

The second implementation is with the circuit behavior abstracted away. It
replaces the circuit logic with a C++ implementation of its operation.
\n\n

The build option that toggles this behavior is `Hack_IMPLEMENT_BLACK_BOX`.
\n\n


See \ref Hc0201 for more information.


\n
\defined{Hc02Defined}
\defined_in{Source/Chips}

*/
#pragma once
