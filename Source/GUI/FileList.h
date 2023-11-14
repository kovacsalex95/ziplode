//
// Created by Alex Flexi on 2023.11.11.
//

#ifndef ZIPLODE_FILELIST_H
#define ZIPLODE_FILELIST_H

#include <string>
#include <wx/wx.h>
#include <wx/dataview.h>
#include <wx/stdpaths.h>
#include <fmt/core.h>
#include <fmt/format.h>

#include "../Core/FileSystemDirectoryContent.h"

using std::string;

class FileList {
    public:
        FileList(wxFrame* frame);
        void addFile(string name, string size, string lastModified);
        wxDataViewListCtrl* getControl();

    private:
        void generateDummies(int dummies = 100);
        wxDataViewListCtrl *wxControl;
        DirectoryContent *content;
};


#endif //ZIPLODE_FILELIST_H
