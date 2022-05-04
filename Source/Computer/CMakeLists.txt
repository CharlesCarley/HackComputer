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
set(TargetName Computer)
include (CopyTarget)

set(TargetName_DAT
    Samples/Fill.asm
)
source_group("Content" FILES ${TargetName_DAT})

set(TargetName_HDR 
    AssemblyDebugger.h
    Common.h
    ConsoleRuntime.h
    RuntimeInterface.h
    WindowedRuntime.h

    AssemblyDebugger/AssemblyDebuggerPrivate.h
    ConsoleRuntime/ConsoleRuntimePrivate.h
    WindowedRuntime/ScreenMemory.h
    WindowedRuntime/WindowedRuntimePrivate.h
)

    
set(TargetName_SRC 
    AssemblyDebugger.cpp
    ConsoleRuntime.cpp
    Executable.cpp
    WindowedRuntime.cpp
    AssemblyDebugger/AssemblyDebuggerPrivate.cpp
    ConsoleRuntime/ConsoleRuntimePrivate.cpp
    WindowedRuntime/ScreenMemory.cpp
    WindowedRuntime/WindowedRuntimePrivate.cpp
)

include_directories(..)
if (USE_SDL)
    add_definitions(-DUSE_SDL)
    include_directories(${SDL_INCLUDE})
endif()


add_executable(${TargetName} 
    ${TargetName_HDR}
    ${TargetName_SRC}
)

target_link_libraries(${TargetName} 
    CodeGenerator
    ParseTreeBuilder
    ParseTree
    Utils 
    Chips 
    Assembler
    VirtualMachine
)

if (USE_SDL)
    target_link_libraries(${TargetName} ${SDL_LIBRARY} )
endif()

copy_target(${TargetName} ${Hack_BINARY_DIR}/build_files) 
if (NOT Hack_INSTALL_PATH STREQUAL  "")
    copy_target(${TargetName} ${Hack_INSTALL_PATH}) 
endif()
