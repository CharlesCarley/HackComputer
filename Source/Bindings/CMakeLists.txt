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
set(TargetName bindings)
include (VSEmscripten)
set(Target_SRC 
   Bindings.cpp
)

include_directories(
    ${Utils_INCLUDE} 
    ${Hack_SOURCE_DIR}/Source
    )

if (BuildType STREQUAL "CPP")

    add_library(${TargetName} SHARED ${Target_SRC})

else()
 
    set(Flags "-O3 -s EXPORT_NAME=${TargetName} -s MODULARIZE=1 -s RELOCATABLE=1")

    # Compile the list of functions that should be exported 

    set(Export_METHODS 
        ComputerAllocate
        ComputerFree
        CreateComputer
        DestroyComputer
        UpdateComputer
        RestartComputer
        ComputerGetLastError
        DecodeInstruction
        ComputerGetState
        ComputerLoadSource
        ComputerGetRam
        ComputerGetRom
        RamGetValue
        RamZeroMemory
        RomGetValue
        RomGetValueDecoded
        CpuGetInstructionPointer
        CpuGetOutputValue
        CpuGetOutputAddress
        CpuGetDRegister
        CpuGetARegister
        CpuGetClock
        CpuGetInstruction
        CpuGetLoadRam
        CpuGetInput
        CpuGetReset
        ComputerGetScreenBufferSize
        ComputerGetScreenBuffer
        ComputerUpdateScreen
        malloc
        free
        main
    )

    set(Symbols "")
    foreach(meth ${Export_METHODS} )
        if (Symbols STREQUAL "")
            set(Symbols "'_${meth}'")
        else()
            set(Symbols "'_${meth}', ${Symbols}")
        endif()
    endforeach()

    set(Symbols "-s EXPORTED_FUNCTIONS=\"[${Symbols}]\"")

    set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} ${Flags} ${Symbols}")
    set(CMAKE_EXE_LINKER_FLAGS "${CMAKE_LINKER_FLAGS}  ${Flags}")

    add_executable(${TargetName} ${Target_SRC})

    emscripten_copy_wasm_target_wasm_js(${TargetName} ${Hack_BINARY_DIR}/build_files)

endif()


target_link_libraries(
    ${TargetName} 
    Assembler 
    Chips
    ${Utils_LIBRARY} 
    )

if (BuildType STREQUAL "CPP")
    copy_target(${TargetName} ${Hack_BINARY_DIR}/build_files)
endif()

if (TargetFolders)
    set_target_properties(${TargetName} PROPERTIES FOLDER "${TargetGroup}")
endif()
