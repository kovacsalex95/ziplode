#include "ToolBar.h"

ToolBar::ToolBar(StateManager* stateManager, wxFrame* frame, Resources* resources)
{
    this->stateManager = stateManager;
    this->resources = resources;

    wxControl = frame->CreateToolBar();
    wxControl->AddTool(ZL_ACTION_BACK, "Go back", this->resources->iconBack());
    wxControl->AddTool(ZL_ACTION_UP, "Go up", this->resources->iconUp());
    wxControl->AddTool(ZL_ACTION_FORWARD, "Go forward", this->resources->iconForward());
    wxControl->AddSeparator();
    wxControl->AddTool(ZL_ACTION_HOME, "Home", this->resources->iconHome());
    wxControl->AddSeparator();
    wxControl->AddTool(ZL_ACTION_OPEN, "Open", this->resources->iconOpen());
    wxControl->AddTool(ZL_ACTION_ARCHIVE, "Archive", this->resources->iconArchive());
    wxControl->Realize();

    this->updateToolsEnabled();
    this->updateToolsIcons();

    frame->SetToolBar(wxControl);
    this->stateManager->getPathManager()->setToolbarControl(wxControl);
    this->stateManager->getPathManager()->updateToolbarIcons();
}

wxToolBar *ToolBar::getControl()
{
    return this->wxControl;
}

void ToolBar::updateToolsEnabled()
{
    this->stateManager->getPathManager()->updateToolbarIcons();

    wxControl->EnableTool(ZL_ACTION_OPEN, true); // TODO
    wxControl->EnableTool(ZL_ACTION_ARCHIVE, false); // TODO
}

void ToolBar::updateToolsIcons()
{
    wxControl->SetToolNormalBitmap(ZL_ACTION_BACK, this->resources->iconBack());
    wxControl->SetToolNormalBitmap(ZL_ACTION_UP, this->resources->iconUp());
    wxControl->SetToolNormalBitmap(ZL_ACTION_FORWARD, this->resources->iconForward());
    wxControl->SetToolNormalBitmap(ZL_ACTION_HOME, this->resources->iconHome());
    wxControl->SetToolNormalBitmap(ZL_ACTION_OPEN, this->resources->iconOpen());
    wxControl->SetToolNormalBitmap(ZL_ACTION_ARCHIVE, this->resources->iconArchive());
}
