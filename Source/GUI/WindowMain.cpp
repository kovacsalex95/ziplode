#include "WindowMain.h"

WindowMain::WindowMain() : wxFrame(nullptr, wxID_ANY, AppInfo::appNameAndVersion(), wxDefaultPosition, wxSize(1200, 800))
{
    this->resources = new Resources();

    menuBar = new MenuBar(this);
    toolBar = new ToolBar(this, resources);
    statusBar = new StatusBar(this);
    fileList = new FileList(this);

    this->SetStatusText("Welcome to Ziplode!");
    fileList->loadPath(this->getDefaultPath());

    this->Bind(wxEVT_MENU, &WindowMain::onOpen, this, ZL_ACTION_OPEN);
    this->Bind(wxEVT_MENU, &WindowMain::onArchive, this, ZL_ACTION_ARCHIVE);
    this->Bind(wxEVT_MENU, &WindowMain::onAbout, this, wxID_ABOUT);
    this->Bind(wxEVT_MENU, &WindowMain::onExit, this, wxID_EXIT);
    this->Bind(wxEVT_SYS_COLOUR_CHANGED, wxSysColourChangedEventHandler(WindowMain::onSystemColourChanged), this);
}

void WindowMain::onOpen(wxCommandEvent& event)
{
    wxLogMessage("Open file...");
}

void WindowMain::onArchive(wxCommandEvent& event)
{
    wxLogMessage("Archive files...");
}

void WindowMain::onAbout(wxCommandEvent& event)
{
    wxMessageBox("C++ archive handler GUI application\nAlex Kovács © 2023", "About " + AppInfo::appNameAndVersion(), wxOK | wxICON_INFORMATION);
}

void WindowMain::onExit(wxCommandEvent& event)
{
    this->Close(true);
}

void WindowMain::onSystemColourChanged(wxSysColourChangedEvent &event)
{
    toolBar->updateToolsIcons();
    event.Skip();
}
