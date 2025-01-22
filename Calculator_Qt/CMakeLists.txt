cmake_minimum_required(VERSION 3.16)

project(Calculator VERSION 1.0.0 LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

find_package(Qt6 REQUIRED COMPONENTS Widgets)

qt_standard_project_setup()

include_directories(Calculator PRIVATE inc src)

set(SOURCES
    src/Bin.cpp
    src/Calculator.cpp
    src/Hex.cpp
    src/main.cpp
    src/mainwindow.cpp
    src/mainwindow.ui
    src/Oct.cpp
)

set(HEADERS
    inc/Bin.h
    inc/Calculator.h
    inc/Hex.h
    inc/mainwindow.h
    inc/Oct.h
)

qt_add_executable(Calculator ${SOURCES} ${HEADERS})

target_link_libraries(Calculator PRIVATE Qt6::Widgets)

set_target_properties(Calculator PROPERTIES
    WIN32_EXECUTABLE ON
    MACOSX_BUNDLE ON
)
