if (USE_SDL)
	if (NOT USING_EMSCRIPTEN)
	   add_subdirectory(SDL)
	endif()
endif()


set(Expat_ExternalTarget TRUE)
set(Expat_TargetFolders  TRUE)
set(Expat_TargetName     Expat)
set(Expat_TargetGroup    Extern)
add_subdirectory(Expat)