#include "ToolBar.h"

ToolBar::ToolBar(wxFrame* frame, Resources* resources)
{
    this->resources = resources;

    wxControl = frame->CreateToolBar();
    wxControl->AddTool(ZL_ACTION_BACK, "Go back", this->resources->iconBack());
    wxControl->AddTool(ZL_ACTION_UP, "Go up", this->resources->iconUp());
    wxControl->AddSeparator();
    wxControl->AddTool(ZL_ACTION_HOME, "Home", this->resources->iconHome());
    wxControl->AddSeparator();
    wxControl->AddTool(ZL_ACTION_OPEN, "Open", this->resources->iconOpen());
    wxControl->AddTool(ZL_ACTION_ARCHIVE, "Archive", this->resources->iconArchive());
    wxControl->Realize();

    this->updateToolsEnabled();
    this->updateToolsIcons();

    frame->SetToolBar(wxControl);
}

wxToolBar *ToolBar::getControl()
{
    return this->wxControl;
}

void ToolBar::updateToolsEnabled()
{
    wxControl->EnableTool(ZL_ACTION_BACK, true); // TODO
    wxControl->EnableTool(ZL_ACTION_UP, true); // TODO
    wxControl->EnableTool(ZL_ACTION_HOME, true); // TODO
    wxControl->EnableTool(ZL_ACTION_OPEN, true); // TODO
    wxControl->EnableTool(ZL_ACTION_ARCHIVE, false); // TODO
}

void ToolBar::updateToolsIcons()
{
    wxControl->SetToolNormalBitmap(ZL_ACTION_BACK, this->resources->iconBack());
    wxControl->SetToolNormalBitmap(ZL_ACTION_UP, this->resources->iconUp());
    wxControl->SetToolNormalBitmap(ZL_ACTION_HOME, this->resources->iconHome());
    wxControl->SetToolNormalBitmap(ZL_ACTION_OPEN, this->resources->iconOpen());
    wxControl->SetToolNormalBitmap(ZL_ACTION_ARCHIVE, this->resources->iconArchive());
}
