#ifndef ZIPLODE_WINDOWMAIN_H
#define ZIPLODE_WINDOWMAIN_H

#include <string>
#include <format>
#include <iostream>
#include <wx/wx.h>
#include <fmt/core.h>
#include <fmt/format.h>

#include "../State/StateManager.h"
#include "../State/StateUser.h"
#include "../Resource/ResourceManager.h"
#include "MenuBar.h"
#include "ToolBar.h"
#include "StatusBar.h"
#include "FileList.h"

using std::string;

class WindowMain : public wxFrame, public StateUser
{
    public:
        WindowMain(StateManager* stateManager);

    private:
        MenuBar *menuBar;
        ToolBar *toolBar;
        StatusBar *statusBar;
        FileList *fileList;
        void onSignalReceived(int signalID, Signal *signal);
        void onOpen(wxCommandEvent& event);
        void onArchive(wxCommandEvent& event);
        void onHome(wxCommandEvent& event);
        void onBack(wxCommandEvent& event);
        void onUp(wxCommandEvent& event);
        void onForward(wxCommandEvent& event);
        void onExit(wxCommandEvent& event);
        void onAbout(wxCommandEvent& event);
        void onSystemColourChanged(wxSysColourChangedEvent &event);
};

#endif //ZIPLODE_WINDOWMAIN_H
