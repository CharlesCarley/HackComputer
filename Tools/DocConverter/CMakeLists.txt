set(TargetName  DocConverter)
set(TargetGroup Executables)

set(Target_SRC Main.cpp)


add_executable(${TargetName} ${Target_SRC})

if (TargetFolders)
    set_target_properties(${TargetName} PROPERTIES FOLDER "${TargetGroup}")
endif()

