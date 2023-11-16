#include "WindowMain.h"

WindowMain::WindowMain(StateManager* stateManager) : wxFrame(nullptr, wxID_ANY, AppInfo::appNameAndVersion(), wxDefaultPosition, wxSize(1200, 800)), StateUser(stateManager)
{
    menuBar = new MenuBar(this);
    toolBar = new ToolBar(this->stateManager, this);
    statusBar = new StatusBar(this);
    fileList = new FileList(this->stateManager, this);

    this->SetStatusText(this->stateManager->getPathManager()->getCurrentPath());

    this->Bind(wxEVT_MENU, &WindowMain::onOpen, this, ZL_ACTION_OPEN);
    this->Bind(wxEVT_MENU, &WindowMain::onArchive, this, ZL_ACTION_ARCHIVE);
    this->Bind(wxEVT_MENU, &WindowMain::onHome, this, ZL_ACTION_HOME);
    this->Bind(wxEVT_MENU, &WindowMain::onBack, this, ZL_ACTION_BACK);
    this->Bind(wxEVT_MENU, &WindowMain::onUp, this, ZL_ACTION_UP);
    this->Bind(wxEVT_MENU, &WindowMain::onForward, this, ZL_ACTION_FORWARD);
    this->Bind(wxEVT_MENU, &WindowMain::onAbout, this, wxID_ABOUT);
    this->Bind(wxEVT_MENU, &WindowMain::onExit, this, wxID_EXIT);
    this->Bind(wxEVT_SYS_COLOUR_CHANGED, wxSysColourChangedEventHandler(WindowMain::onSystemColourChanged), this);
}

void WindowMain::onSignalReceived(int signalID, Signal *signal)
{
    switch (signalID) {
        case ZL_EVENT_PATH_CHANGED:
            this->SetStatusText(((PathChangedSignal*)signal)->getPath());
            break;
    }
}

void WindowMain::onOpen(wxCommandEvent& event)
{
    wxLogMessage("Open file...");
}

void WindowMain::onArchive(wxCommandEvent& event)
{
    wxLogMessage("Archive files...");
}

void WindowMain::onHome(wxCommandEvent& event)
{
    this->stateManager->getPathManager()->goToHome();
}

void WindowMain::onBack(wxCommandEvent& event)
{
    this->stateManager->getPathManager()->goBack();
}

void WindowMain::onForward(wxCommandEvent& event)
{
    this->stateManager->getPathManager()->goForward();
}

void WindowMain::onUp(wxCommandEvent& event)
{
    this->stateManager->getPathManager()->goUp();
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
