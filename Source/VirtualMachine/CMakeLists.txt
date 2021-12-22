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
set(TargetName VirtualMachine)
set(TargetGroup VirtualMachine)


set(Target_HDR
   Token.h
   Scanner.h
   Parser.h
   Emitter.h
   Constants.h
   VM.grm
)

set(Target_SRC 
   Scanner.cpp
   Parser.cpp
   Emitter.cpp
)

include_directories(${Hack_SOURCE_DIR}/Source)
add_library(${TargetName} 
    ${Target_SRC} 
    ${Target_HDR}
)


if (TargetFolders)
    set_target_properties(${TargetName} PROPERTIES FOLDER "${TargetGroup}")
endif()



#------------------------------------------------------

if (BuildType STREQUAL "CPP")

    # The command line application
    set(TargetName Vm2Asm)
    
    unset(Target_HDR)
    unset(Target_SRC)
    set(Target_SRC Main.cpp)

    include_directories(${Hack_SOURCE_DIR}/Source)

    add_executable(${TargetName}  ${Target_SRC})

    target_link_libraries(${TargetName} VirtualMachine Utils)

    copy_target(${TargetName} ${Hack_BINARY_DIR}/build_files) 

    if (NOT Hack_INSTALL_PATH STREQUAL  "")
        copy_target(${TargetName} ${Hack_INSTALL_PATH}) 
    endif()

    if (TargetFolders)
        set_target_properties(${TargetName} PROPERTIES FOLDER "${TargetGroup}")
    endif()

endif()
