#ifndef ZIPLODE_WINDOWMAIN_H
#define ZIPLODE_WINDOWMAIN_H

#include <string>
#include <format>
#include <iostream>
#include <wx/wx.h>
#include <fmt/core.h>
#include <fmt/format.h>

#include "../Core/Resources.h"
#include "MenuBar.h"
#include "ToolBar.h"
#include "StatusBar.h"
#include "FileList.h"

using std::string;

class WindowMain : public wxFrame
{
    public:
        WindowMain();

    private:
        MenuBar *menuBar;
        ToolBar *toolBar;
        StatusBar *statusBar;
        Resources *resources;
        FileList *fileList;
        void onOpen(wxCommandEvent& event);
        void onArchive(wxCommandEvent& event);
        void onHome(wxCommandEvent& event);
        void onBack(wxCommandEvent& event);
        void onUp(wxCommandEvent& event);
        void onExit(wxCommandEvent& event);
        void onAbout(wxCommandEvent& event);
        void onSystemColourChanged(wxSysColourChangedEvent &event);
        string getDefaultPath() const { return wxStandardPaths::Get().GetDocumentsDir().ToStdString(); }
};

#endif //ZIPLODE_WINDOWMAIN_H
