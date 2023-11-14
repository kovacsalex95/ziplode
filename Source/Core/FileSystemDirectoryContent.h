#ifndef ZIPLODE_FILESYSTEMDIRECTORYCONTENT_H
#define ZIPLODE_FILESYSTEMDIRECTORYCONTENT_H

#include <iostream>
#include <fstream>
#include <stdio.h>
#include <sys/types.h>
#include <dirent.h>
#include <ctime>
#include <sys/types.h>
#include <sys/stat.h>
#include <fmt/format.h>

#include "DirectoryContent.h"

using namespace std::filesystem;

class FileSystemDirectoryContent : public DirectoryContent {
    public:
        void load(char const* path);

    private:
        long long getFileSize(char const* path);
        DirectoryItem* generateDirectoryItem(char const* path, char const* filename);

};


#endif //ZIPLODE_FILESYSTEMDIRECTORYCONTENT_H
