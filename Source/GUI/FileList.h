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

#include "../Directory/FileSystemDirectoryContent.h"
#include "../Util/Util.h"
#include "../State/StateUser.h"
#include "../State/StateManager.h"

using std::string;
using std::round;

class FileList : public StateUser {
    public:
        FileList(StateManager* stateManager, wxFrame* frame);
        void loadPath();
        wxDataViewListCtrl* getControl();

    private:
        wxDataViewListCtrl *wxControl;
        DirectoryContent *content;
        void addFile(DirectoryItem* newItem);
        vector<string> getSelectedPaths();
        void onSignalReceived(int signalID, Signal *signal);
        void onItemSelectionChanged(wxDataViewEvent& event);
        void onItemDoubleClicked(wxDataViewEvent& event);
};


#endif //ZIPLODE_FILELIST_H
