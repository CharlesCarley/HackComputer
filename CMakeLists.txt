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
cmake_minimum_required(VERSION 3.6)
project(Hack)
enable_language(CXX)
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# Set the module path to include scripts
list(APPEND CMAKE_MODULE_PATH  ${Hack_SOURCE_DIR}/CMake ${Hack_SOURCE_DIR}/CMake/Modules)
include(Configure)

if (Hack_ExternalTarget)

    set(TargetFolders ${Hack_TargetFolders})
    set(TargetName    ${Hack_TargetName})
    set(TargetGroup   ${Hack_TargetGroup})
else()
    subdirs(CMake)

    set(TargetFolders TRUE)
    set(TargetName Hack)
    set(TargetGroup )

    set(Hack_INCLUDE  ${Hack_SOURCE_DIR}/Source)
    set(Hack_LIBRARY  ${TargetName})
endif()

if (Hack_CHECK_INT_BOUNDS)
    add_definitions(-DCHECK_INT_BOUNDS)
endif()


if (Hack_IMPLEMENT_BLACK_BOX)
    add_definitions(-DIMPLEMENT_BLACK_BOX)
endif()

if (BuildType STREQUAL "CPP")
    add_subdirectory(Extern)
endif()

add_subdirectory(Source)
add_subdirectory(Tools)

if (Hack_BUILD_TEST)
    if (BuildType STREQUAL "CPP")
        set(TargetGroup Extern)
        add_subdirectory(${GTEST_DIR})
        if (TargetFolders)
            set_target_properties(gtest_main PROPERTIES FOLDER "${TargetGroup}")
            set_target_properties(gtest      PROPERTIES FOLDER "${TargetGroup}")
        endif()
        add_subdirectory(Test)
    endif()
endif()
