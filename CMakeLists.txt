cmake_minimum_required(VERSION 3.26)
project(ziplode)

set(CMAKE_CXX_STANDARD 20)

# Use the package PkgConfig to detect GTK+ headers/library files
FIND_PACKAGE(PkgConfig REQUIRED)
PKG_CHECK_MODULES(GTK REQUIRED gtkmm-4.0)

# Setup CMake to use GTK+, tell the compiler where to look for headers
# and to the linker where to look for libraries
INCLUDE_DIRECTORIES(${GTK_INCLUDE_DIRS})
LINK_DIRECTORIES(${GTK_LIBRARY_DIRS})

# Add other flags to the compiler
ADD_DEFINITIONS(${GTK_CFLAGS_OTHER})

add_executable(ziplode main.cpp
        GUI/UIHandler.cpp
        GUI/UIHandler.h
        GUI/WindowMain.cpp
        GUI/WindowMain.h
        GUI/FileList.cpp
        GUI/FileList.h
        GUI/TabView.cpp
        GUI/TabView.h
        GUI/TabViewTab.cpp
        GUI/TabViewTab.h
        GUI/FileListTab.cpp
        GUI/FileListTab.h)
TARGET_LINK_LIBRARIES(ziplode ${GTK_LIBRARIES})
