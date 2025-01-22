#CMakeLists.txt stworzony przez prof. dr hab. inż. Bogusław Cyganek
cmake_minimum_required( VERSION 3.21.0 )

# For a new project it is sufficient to change only its name in the following line
set( PROJECT_NAME Calculator )

project( ${PROJECT_NAME} )

set( CMAKE_BUILD_TYPE Debug )
#set( CMAKE_BUILD_TYPE Release )


# No UNICODE for MFC (at least in my version BC)
if( WIN32 )
	set( CMAKE_CXX_FLAGS "/DWIN32 /D_WINDOWS /W3 /GR /EHsc /std:c++17 " )
	set( CMAKE_CXX_FLAGS_DEBUG "/MDd /Zi /Ob0 /Od /RTC1 /std:c++17 " )
	message( "Win settings chosen..." )
else()
	message( "This project can run only on Windows" )
	return()
endif()


####################################################
# These are required to find out and set up MFC (BC)
add_definitions( -D_AFXDLL )
set( CMAKE_MFC_FLAG 2 )

find_package( MFC REQUIRED )
message( STATUS "MFC_FOUND: ${MFC_FOUND}" )
####################################################


# Inform CMake where the header files are
include_directories(inc)
include_directories(src)

# Automatically add all *.cpp files to the project
file ( GLOB SOURCES "src/*.cpp" "inc/*.h" "inc/*.rc" )

# Add source file to the build executable
add_executable( ${PROJECT_NAME} WIN32 ${SOURCES} )

# Set the default project 
set_property( DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR} PROPERTY VS_STARTUP_PROJECT ${PROJECT_NAME} )






