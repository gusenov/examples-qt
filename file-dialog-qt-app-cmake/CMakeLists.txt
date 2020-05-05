cmake_minimum_required(VERSION 3.14)

project(FileDialogForPix)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_AUTOMOC ON)

list(APPEND CMAKE_PREFIX_PATH "~/Qt5.13.0/5.13.0/clang_64")

find_package(Qt5 REQUIRED Gui Widgets)

message(${Qt5_VERSION})

add_executable(${PROJECT_NAME} main.cc MyProgram.h)

target_link_libraries(${PROJECT_NAME} Qt5::Gui Qt5::Widgets)
