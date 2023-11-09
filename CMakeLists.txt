cmake_minimum_required(VERSION 3.26)
project(ziplode)

set(CMAKE_CXX_STANDARD 20)

find_package(wxWidgets REQUIRED COMPONENTS net core base)
if(wxWidgets_USE_FILE) # not defined in CONFIG mode
    include(${wxWidgets_USE_FILE})
endif()

add_executable(ziplode main.cpp
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

target_link_libraries(ziplode ${wxWidgets_LIBRARIES})
