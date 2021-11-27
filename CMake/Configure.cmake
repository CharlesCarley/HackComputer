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
find_package (Python COMPONENTS Interpreter)

if(Python_Interpreter_FOUND)
	
	# Attempts to pull submodules with python.

	if (NOT EXISTS ${CMAKE_SOURCE_DIR}/Test/googletest/CMakeLists.txt)
		execute_process(COMMAND ${Python_EXECUTABLE} 
				${CMAKE_SOURCE_DIR}/gitupdate.py
				WORKING_DIRECTORY ${CMAKE_SOURCE_DIR}
				
		)
	endif()

	endif()


# Include files in ${CMAKE_SOURCE_DIR}/CMake/Modules 
include(StaticRuntime)
include(ExternalTarget)
include(FindVSEmscripten)

set_static_runtime()
set_property(GLOBAL PROPERTY USE_FOLDERS ON)

option(Hack_BUILD_TEST           "Build the unit test program." ON)
option(Hack_AUTO_RUN_TEST        "Automatically run the test program." OFF)
option(Hack_CHECK_INT_BOUNDS     "Throw an exception on overflow ." ON)
option(Hack_IMPLEMENT_BLACK_BOX  "If this is true all chips will be implemented with logic gates." OFF)
option(Hack_PRINT_CHIP_STATE     "Enables the print method defined in the Chip class" OFF)
option(Hack_USE_SDL              "Enables or disables SDL" OFF)
option(Hack_INSTALL_PATH         "Specify installation directory" "")


set(BUILD_GMOCK   OFF CACHE BOOL "" FORCE)
set(INSTALL_GTEST OFF CACHE BOOL "" FORCE)
set(GTEST_DIR     ${Hack_SOURCE_DIR}/Test/googletest)
set(GTEST_INCLUDE ${Hack_SOURCE_DIR}/Test/googletest/googletest/include)
set(GTEST_LIBRARY gtest_main)



set(Extern_DIR ${Hack_SOURCE_DIR}/Extern)


DefineExternalTarget(
	Utils 
	Modules 
	${Hack_SOURCE_DIR}/Utils
	${Hack_SOURCE_DIR}/Utils
)

DefineExternalTarget(FreeImage     
	Modules 
	${Hack_SOURCE_DIR}/FreeImage/Source
)


if (Hack_USE_SDL)

	if (NOT USING_EMSCRIPTEN)
		set(SDL_INCLUDE ${Extern_DIR}/Extern/SDL)
		set(SDL_LIBRARY SDL2-static SDL2main)
		set(SDL_FOLDER Extern)
	endif()
	set(USE_SDL TRUE)
else ()
	set(USE_SDL FALSE)
endif()


if (USING_EMSCRIPTEN)
	add_definitions(-DUSING_EMSCRIPTEN)
	set(BuildType "WASM")
else()
	set(BuildType "CPP")
endif()



if (MSVC)
	# globally disable scoped enum warnings
	set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} /wd26812")

	# Enable just my code...
	set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} /JMC")

	set(WebRunner_DIR ${Hack_SOURCE_DIR}/Web/build/windows/runner)
	set(Test_DIR      ${Hack_SOURCE_DIR}/Web/test)
	
else()
	set(WebRunner_DIR ${Hack_SOURCE_DIR}/Web/build/linux/x64)
	set(Test_DIR      ${Hack_SOURCE_DIR}/Web/test)

	set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Os -O3 -fPIC")
endif()

include(CopyTarget)
