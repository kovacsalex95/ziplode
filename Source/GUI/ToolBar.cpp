#include "ToolBar.h"

ToolBar::ToolBar(StateManager* stateManager, wxFrame* frame) : StateUser(stateManager)
{
    wxControl = frame->CreateToolBar();
    wxControl->AddTool(ZL_ACTION_BACK, "Go back", this->stateManager->getResourceManager()->iconBack());
    wxControl->AddTool(ZL_ACTION_UP, "Go up", this->stateManager->getResourceManager()->iconUp());
    wxControl->AddTool(ZL_ACTION_FORWARD, "Go forward", this->stateManager->getResourceManager()->iconForward());
    wxControl->AddSeparator();
    wxControl->AddTool(ZL_ACTION_HOME, "Home", this->stateManager->getResourceManager()->iconHome());
    wxControl->AddSeparator();
    wxControl->AddTool(ZL_ACTION_OPEN, "Open", this->stateManager->getResourceManager()->iconOpen());
    wxControl->AddTool(ZL_ACTION_ARCHIVE, "Archive", this->stateManager->getResourceManager()->iconArchive());
    wxControl->Realize();

    this->updateToolsEnabled();

    frame->SetToolBar(wxControl);
}

wxToolBar *ToolBar::getControl()
{
    return this->wxControl;
}

void ToolBar::onSignalReceived(int signalID, Signal *signal)
{
    switch (signalID) {
        case ZL_EVENT_PATH_CHANGED:
        case ZL_EVENT_SELECTION_CHANGED:
            this->updateToolsEnabled();
            break;
    }
}

void ToolBar::updateToolsEnabled()
{
    wxControl->EnableTool(ZL_ACTION_BACK, this->stateManager->getPathManager()->canGoBack());
    wxControl->EnableTool(ZL_ACTION_UP, this->stateManager->getPathManager()->canGoUp());
    wxControl->EnableTool(ZL_ACTION_FORWARD, this->stateManager->getPathManager()->canGoForward());
    wxControl->EnableTool(ZL_ACTION_HOME, this->stateManager->getPathManager()->canGoHome());

    wxControl->EnableTool(ZL_ACTION_OPEN, true); // TODO
    wxControl->EnableTool(ZL_ACTION_ARCHIVE, this->stateManager->getSelectionManager()->hasSelection());
}

void ToolBar::updateToolsIcons()
{
    wxControl->SetToolNormalBitmap(ZL_ACTION_BACK, this->stateManager->getResourceManager()->iconBack());
    wxControl->SetToolNormalBitmap(ZL_ACTION_UP, this->stateManager->getResourceManager()->iconUp());
    wxControl->SetToolNormalBitmap(ZL_ACTION_FORWARD, this->stateManager->getResourceManager()->iconForward());
    wxControl->SetToolNormalBitmap(ZL_ACTION_HOME, this->stateManager->getResourceManager()->iconHome());
    wxControl->SetToolNormalBitmap(ZL_ACTION_OPEN, this->stateManager->getResourceManager()->iconOpen());
    wxControl->SetToolNormalBitmap(ZL_ACTION_ARCHIVE, this->stateManager->getResourceManager()->iconArchive());
}
