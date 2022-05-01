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
include(MdDoxBuilder)

# Setup for generating the site

if (Hack_BUILD_DOCS)

    set(MdDoxBuilder_SourceLocation  ${Hack_SOURCE_DIR})
    set(MdDoxBuilder_OutputDir       ${Hack_SOURCE_DIR}/Current)
    set(MdDoxBuilder_SourceExclude   ${Hack_SOURCE_DIR}/Test ${Hack_SOURCE_DIR}/Extern ${Hack_SOURCE_DIR}/CMake ${CMAKE_BINARY_DIR})
    set(MdDoxBuilder_SymbolExclude   "std")
    set(MdDoxBuilder_ExamplePaths    ${Hack_SOURCE_DIR}/Current/pages)
    set(MdDoxBuilder_ImagePaths      ${Hack_SOURCE_DIR}/Current/images)
    set(MdDoxBuilder_Config          ${Hack_SOURCE_DIR}/Current/MdDox.cfg)
    set(MdDoxBuilder_ExtraSource     ${Hack_SOURCE_DIR}/Current/colors.cfg)
    set(MdDoxBuilder_InvokeDotScript ${Hack_SOURCE_DIR}/CMake/Modules/invokeDot.py)
    set(MdDoxBuilder_AutoBuild TRUE)
    set(MdDoxBuilder_BackEnd   md)
    MdDox(Doxyfile.txt.in ${CMAKE_CURRENT_BINARY_DIR}/Doxyfile)
endif()