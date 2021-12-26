# -----------------------------------------------------------------------------
#
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
include (GroupSet)

set(TargetName     Unit)
set(TestTargetName ${TargetName}Test)

set_group(TestTarget_Data
    TestFiles/Inline:*.inl
    TestFiles/Assembler/ASM:Assembler/*.asm
    TestFiles/Assembler/Cmp:Assembler/*.cmp
    TestFiles/ROM/ASM:Rom/*.asm
    TestFiles/VM/Cmp:VM/*.cmp
    TestFiles/VM/ASM:VM/*.asm
    TestFiles/VM/VM:VM/*.vm
    TestFiles/Jack/Cmp:Jack/*.xml
    TestFiles/Jack/Jack:Jack/*.jack
)

if (Hack_TEST_REGEN_CMP)
    include(Jack2Svg)
    set(Jack_FILES 
        Jack/Test01.jack
        Jack/Test02.jack
        Jack/Test03.jack
        Jack/Test04.jack
        Jack/Test05.jack
        Jack/Test06.jack
        Jack/Test07.jack
        Jack/Test08.jack
        Jack/Test09.jack
        Jack/Test10.jack
        Jack/Test11.jack
    )

    if (Jack2Svg_ENABLED)
        jack_to_svg(Parse_Trees ${Jack_FILES})
    endif()

    jack_to_xml(XML_Trees ${Jack_FILES})
else()
    set(XML_Trees 
        Jack/Test01.xml
        Jack/Test02.xml
        Jack/Test03.xml
        Jack/Test04.xml
        Jack/Test05.xml
        Jack/Test06.xml
        Jack/Test07.xml
        Jack/Test08.xml
        Jack/Test09.xml
        Jack/Test10.xml
    )

    set(Parse_Trees 
        Jack/Test01.svg
        Jack/Test02.svg
        Jack/Test03.svg
        Jack/Test04.svg
        Jack/Test05.svg
        Jack/Test06.svg
        Jack/Test07.svg
        Jack/Test08.svg
        Jack/Test09.svg
        Jack/Test10.svg
    )
endif()

source_group("Reference\\SVG" FILES  ${Parse_Trees})
source_group("Reference\\XML" FILES  ${XML_Trees})

set(TestTarget_SOURCE
    FileCmp.h
    FileCmp.cpp
    Test1.cpp
    Test2.cpp
    Test3.cpp
    Test4.cpp
    Test5.cpp
    ${XML_Trees}
    ${Parse_Trees}
    ${TestTarget_Data}
)

set(ABSOLUTE_TEST_DIRECTORY  ${CMAKE_CURRENT_SOURCE_DIR})
set(ABSOLUTE_BUILD_DIRECTORY ${CMAKE_CURRENT_BINARY_DIR})

configure_file(
    ${CMAKE_CURRENT_SOURCE_DIR}/TestDirectory.h.in
    ${CMAKE_CURRENT_BINARY_DIR}/TestDirectory.h
)

include_directories(. 
    ${GTEST_INCLUDE} 
    ${CMAKE_CURRENT_BINARY_DIR} 
    ${Hack_SOURCE_DIR}/Source
)

add_executable(
    ${TestTargetName}
    ${TestTarget_SOURCE}
)

target_link_libraries(${TestTargetName} 
    ${GTEST_LIBRARY} 
    Chips 
    Assembler
    VirtualMachine
    Utils
    SyntaxAnalyzer
    CompileUtils
 )

if (Hack_AUTO_RUN_TEST)

   add_custom_command(TARGET 
        ${TestTargetName} POST_BUILD
        WORKING_DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR}
        COMMAND  $<TARGET_FILE:${TestTargetName}>
    )

    set_target_properties(
        ${TestTargetName} 
        PROPERTIES 
        VS_DEBUGGER_WORKING_DIRECTORY  
        ${CMAKE_CURRENT_SOURCE_DIR}
    )

endif()
