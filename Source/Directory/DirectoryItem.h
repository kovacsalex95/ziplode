//
// Created by Alex Flexi on 2023.11.13.
//

#ifndef ZIPLODE_DIRECTORYITEM_H
#define ZIPLODE_DIRECTORYITEM_H

#include <string>
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
                      tm modifiedAt);
        string getName();
        string getExtension();
        string getFolder();
        ZL_ITEM_TYPE getType();
        long long getSize();
        tm getModifiedAt();
        string getPath(bool useFolder = true, bool useExtension = true);

    private:
        string name;
        string extension;
        string folder;
        ZL_ITEM_TYPE type = ZL_ITEM_TYPE_UNKNOWN;
        long long size = 0;
        tm modifiedAt;
};


#endif //ZIPLODE_DIRECTORYITEM_H
