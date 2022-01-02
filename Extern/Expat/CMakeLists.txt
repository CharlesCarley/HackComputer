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

# =========================================
# This is being setup to control the build 
# without having to modify the source tree

cmake_minimum_required(VERSION 3.0)
project(Expat)



if (Expat_ExternalTarget)
    set(TargetFolders ${Expat_TargetFolders})
    set(TargetName    ${Expat_TargetName})
    set(TargetGroup   ${Expat_TargetGroup})
else()
    set(TargetFolders FALSE)
    set(TargetName Expat)
    unset(TargetGroup )
endif()



set(Expat_LIB_DIR ${Expat_SOURCE_DIR}/Extern/expat/lib)
set(Expat_INCLUDE ${Expat_LIB_DIR} ${Expat_BINARY_DIR})
set(Expat_LIBRARY ${TargetName})



set(Expat_CFG ${Expat_SOURCE_DIR}/expat_config.h.in)
configure_file(${Expat_CFG} ${Expat_BINARY_DIR}/expat_config.h)

set(Expat_SRC
	${Expat_LIB_DIR}/xmlparse.c
	${Expat_LIB_DIR}/xmlrole.c
	${Expat_LIB_DIR}/xmltok.c
	${Expat_LIB_DIR}/xmltok_impl.c
	${Expat_LIB_DIR}/xmltok_ns.c
)

set(Expat_HDR
	${Expat_LIB_DIR}/ascii.h
	${Expat_LIB_DIR}/asciitab.h
	${Expat_LIB_DIR}/expat.h
	${Expat_LIB_DIR}/expat_external.h
	${Expat_LIB_DIR}/iasciitab.h
	${Expat_LIB_DIR}/internal.h
	${Expat_LIB_DIR}/latin1tab.h
	${Expat_LIB_DIR}/nametab.h
	${Expat_LIB_DIR}/siphash.h
	${Expat_LIB_DIR}/utf8tab.h
	${Expat_LIB_DIR}/winconfig.h
	${Expat_LIB_DIR}/xmlrole.h
	${Expat_LIB_DIR}/xmltok.h
	${Expat_LIB_DIR}/xmltok_impl.h
	${Expat_BINARY_DIR}/expat_config.h
)



include_directories(${Expat_INCLUDE})

add_definitions(-D_CRT_SECURE_NO_WARNINGS)
add_library(${Expat_LIBRARY} ${Expat_SRC} ${Expat_HDR} ${Expat_CFG})


if (TargetFolders)
    set_target_properties(${Expat_LIBRARY} PROPERTIES FOLDER "${TargetGroup}")
endif()
