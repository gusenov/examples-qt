macro(add_qmllive PROJECT)

get_target_property(qmake Qt5::qmake LOCATION)
execute_process(
    COMMAND ${qmake} -query QT_INSTALL_HEADERS
    OUTPUT_VARIABLE QT_INSTALL_HEADERS
    OUTPUT_STRIP_TRAILING_WHITESPACE
)
execute_process(
    COMMAND ${qmake} -query QT_INSTALL_LIBS
    OUTPUT_VARIABLE QT_INSTALL_LIBS
    OUTPUT_STRIP_TRAILING_WHITESPACE
)
# См. https://github.com/wang-bin/QtAV/blob/master/CMakeLists.txt
message("Header files: ${QT_INSTALL_HEADERS}")
message(Libraries: ${QT_INSTALL_LIBS})

target_link_directories(${PROJECT} PRIVATE ${QT_INSTALL_LIBS})
target_include_directories(${PROJECT} PRIVATE ${QT_INSTALL_HEADERS}/qmllive)

target_link_libraries(${PROJECT}
    qmllive  # ${QT_INSTALL_LIBS}/libqmllive.dylib
)

target_compile_definitions(${PROJECT} PRIVATE SRCDIR="${CMAKE_CURRENT_SOURCE_DIR}")

endmacro()
