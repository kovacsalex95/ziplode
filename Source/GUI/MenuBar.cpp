#include "MenuBar.h"

MenuBar::MenuBar(StateManager* stateManager, wxFrame* frame) : StateUser(stateManager)
{
    wxMenu *menuFile = new wxMenu;
    menuFile->Append(ZL_ACTION_OPEN, "&Open...\tCtrl+O", "Open an archive file");
    menuFile->Append(ZL_ACTION_ARCHIVE, "&Create archive...\tCtrl+S", "Create archive from selection");
    menuFile->AppendSeparator();
    menuFile->Append(wxID_EXIT);

    wxMenu *menuHelp = new wxMenu;
    menuHelp->Append(wxID_ABOUT);

    wxControl = new wxMenuBar;
    wxControl->Append(menuFile, "&File");
    wxControl->Append(menuHelp, "&Help");

    this->updateMenusEnabled();

    frame->SetMenuBar(wxControl);
}

wxMenuBar* MenuBar::getControl()
{
    return wxControl;
}

void MenuBar::onSignalReceived(int signalID, Signal *signal)
{
    switch (signalID) {
        case ZL_EVENT_SELECTION_CHANGED:
            this->updateMenusEnabled();
            break;
    }
}

void MenuBar::updateMenusEnabled()
{
    wxControl->Enable(ZL_ACTION_OPEN, true); // TODO
    wxControl->Enable(ZL_ACTION_ARCHIVE, this->stateManager->getSelectionManager()->hasSelection());
}