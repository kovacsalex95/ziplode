#ifndef ZIPLODE_WINDOWMAIN_H
#define ZIPLODE_WINDOWMAIN_H

#include <string>
#include <format>
#include <iostream>
#include <wx/wx.h>
#include <fmt/core.h>
#include <fmt/format.h>

#include "../Resources.h"
#include "MenuBar.h"
#include "ToolBar.h"
#include "StatusBar.h"

using namespace std;

class WindowMain : public wxFrame
{
    public:
        WindowMain();

    private:
        MenuBar *menuBar;
        ToolBar *toolBar;
        StatusBar *statusBar;
        Resources *resources;
        void onOpen(wxCommandEvent& event);
        void onArchive(wxCommandEvent& event);
        void onExit(wxCommandEvent& event);
        void onAbout(wxCommandEvent& event);
        void onSystemColourChanged(wxSysColourChangedEvent &event);
};

#endif //ZIPLODE_WINDOWMAIN_H
