//
// Created by Alex Flexi on 2023.11.13.
//

#ifndef ZIPLODE_DIRECTORYITEM_H
#define ZIPLODE_DIRECTORYITEM_H

#include <string>
#include <chrono>
#include <fmt/format.h>

using std::string;
using namespace std::literals;

enum ZL_ITEM_TYPE
{
    ZL_ITEM_TYPE_UNKNOWN = 1000,
    ZL_ITEM_TYPE_FOLDER = 2000,
    ZL_ITEM_TYPE_FILE = 3000,
};

class DirectoryItem {
    public:
        DirectoryItem(string name,
                      string extension,
                      string folder,
                      ZL_ITEM_TYPE type,
                      long long size,
                      std::chrono::time_point<std::chrono::system_clock> createdAt,
                      std:: chrono::time_point<std::chrono::system_clock> modifiedAt);
        string getName();
        string getExtension();
        string getFolder();
        ZL_ITEM_TYPE getType();
        long long getSize();
        std::chrono::time_point<std::chrono::system_clock> getCreatedAt();
        std::chrono::time_point<std::chrono::system_clock> getModifiedAt();
        string getFormattedPath(bool useFolder = true, bool useExtension = true);
        string getFormattedCreatedAt(string format = "{:%Y-%m-%d}");
        string getFormattedModifiedAt(string format = "{:%Y-%m-%d}");

    private:
        string name;
        string extension;
        string folder;
        ZL_ITEM_TYPE type = ZL_ITEM_TYPE_UNKNOWN;
        long long size = 0;
        std::chrono::time_point<std::chrono::system_clock> createdAt;
        std::chrono::time_point<std::chrono::system_clock> modifiedAt;
};


#endif //ZIPLODE_DIRECTORYITEM_H
