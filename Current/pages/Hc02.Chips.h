/*!
\page Hc02 Chips

\brief Implements the circuit class library.

\h1 Implementation 
It uses two separate implementations to compute the circuit logic.\br

The first implementation is written to compute the value of each circuit.
It links the circuits together in code and computes the value of each bit.
\br

The second implementation is with the circuit behavior abstracted away. It
replaces the circuit logic with a C++ implementation of its operation.
\br

The build option that toggles this behavior is `Hack_IMPLEMENT_BLACK_BOX`.
\br

See the \ref Hc0201 document for more information.

\defined{Hc02Defined}
\defined_in{Source/Chips}

*/
#pragma once
