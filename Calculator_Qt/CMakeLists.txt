cmake_minimum_required(VERSION 3.16)

project(Calculator VERSION 1.0.0 LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

find_package(Qt6 REQUIRED COMPONENTS Widgets)

qt_standard_project_setup()

include_directories(inc)
include_directories(src)

file(GLOB_RECURSE SOURCES "src/*.cpp" "inc/*.h")

qt_add_executable(Calculator ${SOURCES})

target_link_libraries(Calculator PRIVATE Qt6::Widgets)

set_target_properties(Calculator PROPERTIES
    WIN32_EXECUTABLE ON
    MACOSX_BUNDLE ON
)