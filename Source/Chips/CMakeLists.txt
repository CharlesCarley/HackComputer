# -----------------------------------------------------------------------------
#   Copyright (c) Charles Carley.
#
#   This software is provided 'as-is', without any express or implied
# warranty. In no event will the authors be held liable for any damages
# arising from the use of this software.
#
#   Permission is granted to anyone to use this software for any purpose,
# including commercial applications, and to alter it and redistribute it
# freely, subject to the following restrictions:
#
# 1. The origin of this software must not be misrepresented; you must not
#    claim that you wrote the original software. If you use this software
#    in a product, an acknowledgment in the product documentation would be
#    appreciated but is not required.
# 2. Altered source versions must be plainly marked as such, and must not be
#    misrepresented as being the original software.
# 3. This notice may not be removed or altered from any source distribution.
# ------------------------------------------------------------------------------
set(TargetName Chips)
set(TargetGroup P1.Hardware)


set(Target_HDR
    Add16.h
    ALU.h
    And.h
    And16.h
    Bit.h
    BitUtils.h
    Chip.h
    Clock.h
    Computer.h
    CPU.h
    DefaultMemorySegment.h
    DFlipFlop.h
    DMux.h
    DMux4Way.h
    DMux8Way.h
    FullAdder.h
    HalfAdder.h
    Inc16.h
    IMemorySegment.h
    Memory.h
    Mux.h
    Mux16.h
    Mux4Way16.h
    Mux8Way16.h
    NAnd.h
    NOr.h
    Not.h
    Not16.h
    Or.h
    Or16.h
    Or8Way.h
    ProgramCounter.h
    Keyboard.h
    Ram16k.h
    Ram4k.h
    Ram512.h
    Ram64.h
    Ram8.h
    Rom32.h
    Register.h
    Screen.h
    SRLatch.h
    Timer.h
    XOr.h
)

set(Target_SRC 
    Add16.cpp
    ALU.cpp
    And.cpp
    And16.cpp
    Bit.cpp
    Clock.cpp
    Computer.cpp
    CPU.cpp
    DFlipFlop.cpp
    DMux.cpp
    DMux4Way.cpp
    DMux8Way.cpp
    FullAdder.cpp
    HalfAdder.cpp
    Inc16.cpp
    Memory.cpp
    Mux.cpp
    Mux16.cpp
    Mux4Way16.cpp
    Mux8Way16.cpp
    Nand.cpp
    NOr.cpp
    Not.cpp
    Not16.cpp
    Or.cpp
    Or16.cpp
    Or8Way.cpp
    ProgramCounter.cpp
    Keyboard.cpp
    Ram4K.cpp
    Ram512.cpp
    Ram64.cpp
    Ram8.cpp
    Register.cpp
    Rom32.cpp
    SRLatch.cpp
    Timer.cpp
    XOr.cpp
    ${Target_HDR}
)

include_directories(${Hack_SOURCE_DIR}/Source)
add_library(${TargetName} ${Target_SRC})

if (TargetFolders)
    set_target_properties(${TargetName} PROPERTIES FOLDER "${TargetGroup}")
endif()
