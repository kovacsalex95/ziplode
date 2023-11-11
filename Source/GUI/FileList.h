//
// Created by Alex Flexi on 2023.11.11.
//

#ifndef ZIPLODE_FILELIST_H
#define ZIPLODE_FILELIST_H

#include <string>
#include <wx/wx.h>
#include <wx/dataview.h>
#include <fmt/core.h>
#include <fmt/format.h>

using namespace std;

class FileList {
    public:
        FileList(wxFrame* frame);
        void addFile(string name, int size, string lastModified);
        wxDataViewListCtrl* getControl();

    private:
        void generateDummies(int dummies = 100);
        wxDataViewListCtrl *wxControl;
};


#endif //ZIPLODE_FILELIST_H
