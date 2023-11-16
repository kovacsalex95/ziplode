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
#include "../Core/Util.h"

using std::string;

class FileList {
    public:
        FileList(wxFrame* frame);
        void loadPath(string path);
        wxDataViewListCtrl* getControl();

    private:
        string currentPath;
        wxDataViewListCtrl *wxControl;
        DirectoryContent *content;
        void addFile(string name, string size, string lastModified);
        void onItemDoubleClicked(wxDataViewEvent& event);
};


#endif //ZIPLODE_FILELIST_H
