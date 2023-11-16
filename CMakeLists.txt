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
        Source/Core/ResourceManager.cpp
        Source/Core/ResourceManager.h
        Source/GUI/MenuBar.cpp
        Source/GUI/MenuBar.h
        Source/GUI/ToolBar.cpp
        Source/GUI/ToolBar.h
        Source/Core/ActionIDs.h
        Source/GUI/StatusBar.cpp
        Source/GUI/StatusBar.h
        Source/GUI/FileList.cpp
        Source/GUI/FileList.h
        Source/Core/DirectoryContent.cpp
        Source/Core/DirectoryContent.h
        Source/Core/DirectoryItem.cpp
        Source/Core/DirectoryItem.h
        Source/Core/FileSystemDirectoryContent.cpp
        Source/Core/FileSystemDirectoryContent.h
        Source/Core/Util.cpp
        Source/Core/Util.h
        Source/Core/PathManager.cpp
        Source/Core/PathManager.h
        Source/Core/StateManager.cpp
        Source/Core/StateManager.h
        Source/Core/SignalReceiver.h
        Source/Core/Signal.h
        Source/Core/SignalManager.cpp
        Source/Core/SignalManager.h
        Source/Core/StateUser.cpp
        Source/Core/StateUser.h
        Source/Core/PathChangedSignal.cpp
        Source/Core/PathChangedSignal.h
)

target_link_libraries(ziplode ${wxWidgets_LIBRARIES})
target_link_libraries(ziplode fmt::fmt)
