cmake_minimum_required(VERSION 3.14)

project(Example)

set(CMAKE_CXX_STANDARD 17)

list(APPEND CMAKE_PREFIX_PATH "~/Qt5.13.0/5.13.0/clang_64")

find_package(Qt5 REQUIRED
    Quick
)
if (${Qt5_FOUND})
    message(${Qt5_VERSION})
endif()

qt5_add_resources(QT_RESOURCES qml.qrc)

add_executable(${PROJECT_NAME} main.cpp ${QT_RESOURCES})

target_link_libraries(${PROJECT_NAME}
    Qt5::Quick
)


# Вызов target_link_libraries должен идти после add_executable и find_package!
# См. https://stackoverflow.com/questions/25909943/getting-a-cmake-error-cannot-specify-link-libraries-for-target-which-is-not-bui

include(${CMAKE_CURRENT_SOURCE_DIR}/qmllive.cmake)
add_qmllive(${PROJECT_NAME})