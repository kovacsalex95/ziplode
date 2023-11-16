#ifndef ZIPLODE_TOOLBAR_H
#define ZIPLODE_TOOLBAR_H

#include <wx/wx.h>

#include "../Core/Resources.h"
#include "../Core/ActionIDs.h"
#include "../Core/StateManager.h"

using std::string;

class ToolBar {
    public:
        ToolBar(StateManager* stateManager, wxFrame* frame, Resources* resources);
        void updateToolsEnabled();
        void updateToolsIcons();
        wxToolBar* getControl();

    private:
        StateManager* stateManager;
        Resources* resources;
        wxToolBar *wxControl;
};

#endif //ZIPLODE_TOOLBAR_H
