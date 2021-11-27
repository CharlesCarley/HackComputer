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
function(LOG)
	message(STATUS ${ARGN})
endfunction()


if (NOT Flutter_FIND_QUIETLY)
	Log("Looking for Flutter via the Environment variable FLUTTER_PATH $ENV{FLUTTER_PATH}" )
endif()



find_file(Flutter_EXE NAMES flutter.bat HINTS  $ENV{FLUTTER_PATH} )
find_file(Flutter_Dart_EXE NAMES dart.bat dart.exe HINTS  $ENV{FLUTTER_PATH} )


if (NOT Flutter_FIND_QUIETLY)
	if (Flutter_EXE)
	   Log("Found ${Flutter_EXE}" )
	else()
	   Log("Flutter_EXE not found" )
	endif()

	if (Flutter_Dart_EXE)
	   Log("Found ${Flutter_Dart_EXE}" )
	else()
	   Log("Flutter_Dart_EXE not found" )
	endif()



endif()


if (Flutter_EXE AND Flutter_Dart_EXE )
	set(Flutter_FOUND TRUE)
endif()