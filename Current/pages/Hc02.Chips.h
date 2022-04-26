/*!
\page Hc02 Chips

\brief Implements the circuit class library.

\h1 Implementation 
It uses two separate implementations to compute the circuit logic.\br

The first implementation is written to compute the value of each circuit.
This version links the circuits together in code and computes the value of each bit
programatically.
\br

The second implementation is with the circuit behavior abstracted away. This
version replaces the circuit logic with a C++ implementation of the chips operation.
\br

The build option that toggles this behavior is `Hack_IMPLEMENT_BLACK_BOX`.

\h2 Example

Regardless of the underlying implementation, class usage is constant.\br

For example, The \chip{Or16} chip contains two inputs A and B, and one output.
Evaluation of the chip works from a cached state  of its inputs. Meaning, every
time an input value changes, the next call to an output function will recompute
the state of the chip. Otherwise, the previous evaluation state will be returned.
\br
Since evaluation happens internally, all regular usage is through its inputs
and outputs. 

\code{.cpp}
    Or16 or;

    or.setA(0b1010101010101010);
    or.setB(0b0101010101010101);


    uint16_t out = or.getOut();

    cout << out << endl;
    // 1111111111111111
\endcode



See the \ref Hc0201 document for a complete list.

\defined{Hc02Defined}
\defined_in{Source/Chips}

*/
#pragma once
