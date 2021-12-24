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
find_package(Dot)

if (Dot_FOUND)
    set(Jack2Svg_ENABLED TRUE)
else()
    set(Jack2Svg_ENABLED FALSE)
endif()

if (Jack2Svg_ENABLED)

    macro(jack_to_svg Output)

        set(Output)
        foreach (FILE ${ARGN})
            get_filename_component(inFile ${FILE} ABSOLUTE)
            get_filename_component(fileDir ${inFile} DIRECTORY)
            get_filename_component(fileBase ${inFile} NAME_WLE)

            set(outFileDot "${CMAKE_CURRENT_SOURCE_DIR}/${fileBase}.dot")
            set(outFileSVG "${fileDir}/${fileBase}.svg")

            add_custom_command(
                OUTPUT  ${outFileDot}
                COMMAND Jack2XML -f dot -o ${outFileDot} ${inFile}
                DEPENDS Jack2XML ${inFile}
                COMMENT "Converting ${outFileDot}"
            )

            add_custom_command(
                OUTPUT  ${outFileSVG}
                COMMAND ${Dot_EXE} -T svg -o ${outFileSVG} ${outFileDot}
                DEPENDS ${inFile} ${outFileDot}
                COMMENT "Converting ${outFileSVG}"
            )
            list(APPEND ${Output} ${outFileSVG})
        
        endforeach()
    
    endmacro()
    

endif()
