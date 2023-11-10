cmake_minimum_required(VERSION 3.26)
project(ziplode)

set(CMAKE_CXX_STANDARD 23)

file(COPY ${CMAKE_SOURCE_DIR}/Resources DESTINATION ${CMAKE_BINARY_DIR})

find_package(wxWidgets REQUIRED COMPONENTS net core base)
if(wxWidgets_USE_FILE) # not defined in CONFIG mode
    include(${wxWidgets_USE_FILE})
endif()

find_package(fmt)

add_executable(ziplode Source/Main.cpp
        Source/GUI/WindowMain.cpp
        Source/GUI/WindowMain.h
        Source/Main.h
        Source/AppInfo.h
        Source/AppInfo.cpp
        Source/Resources.cpp
        Source/Resources.h
        Source/GUI/MenuBar.cpp
        Source/GUI/MenuBar.h
        Source/GUI/ToolBar.cpp
        Source/GUI/ToolBar.h
        Source/ActionIDs.h
        Source/GUI/StatusBar.cpp
        Source/GUI/StatusBar.h)

target_link_libraries(ziplode ${wxWidgets_LIBRARIES})
target_link_libraries(ziplode fmt::fmt)
