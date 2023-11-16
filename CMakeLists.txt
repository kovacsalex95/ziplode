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
        Source/Util/AppInfo.h
        Source/Util/AppInfo.cpp
        Source/Resource/ResourceManager.cpp
        Source/Resource/ResourceManager.h
        Source/GUI/MenuBar.cpp
        Source/GUI/MenuBar.h
        Source/GUI/ToolBar.cpp
        Source/GUI/ToolBar.h
        Source/Enum/ActionIDs.h
        Source/GUI/StatusBar.cpp
        Source/GUI/StatusBar.h
        Source/GUI/FileList.cpp
        Source/GUI/FileList.h
        Source/Directory/DirectoryContent.cpp
        Source/Directory/DirectoryContent.h
        Source/Directory/DirectoryItem.cpp
        Source/Directory/DirectoryItem.h
        Source/Directory/FileSystemDirectoryContent.cpp
        Source/Directory/FileSystemDirectoryContent.h
        Source/Util/Util.cpp
        Source/Util/Util.h
        Source/Path/PathManager.cpp
        Source/Path/PathManager.h
        Source/State/StateManager.cpp
        Source/State/StateManager.h
        Source/Signal/SignalReceiver.h
        Source/Signal/Signal.h
        Source/Signal/SignalManager.cpp
        Source/Signal/SignalManager.h
        Source/State/StateUser.cpp
        Source/State/StateUser.h
        Source/Path/PathChangedSignal.cpp
        Source/Path/PathChangedSignal.h
        Source/Enum/Directions.h
        Source/Selection/SelectionManager.cpp
        Source/Selection/SelectionManager.h
)

target_link_libraries(ziplode ${wxWidgets_LIBRARIES})
target_link_libraries(ziplode fmt::fmt)
