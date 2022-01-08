set(TargetName  DoxygenToMarkdown)
set(TargetGroup Executables)

set(Target_HDR 
    Document.h
    Common.h
    XmlAttribute.h
    XmlDocument.h
    XmlNode.h
)

set(Target_SRC 
    Document.cpp
    XmlDocument.cpp
    Main.cpp
    XmlNode.cpp
)

add_definitions(-DXML_STATIC)
include_directories(${Hack_SOURCE_DIR}/Source ${Hack_SOURCE_DIR}/Extern/Expat/Extern/expat/lib)

add_executable(${TargetName} ${Target_SRC} ${Target_HDR})

target_link_libraries(${TargetName} Utils Expat)

if (TargetFolders)
    set_target_properties(${TargetName} PROPERTIES FOLDER "${TargetGroup}")
endif()

