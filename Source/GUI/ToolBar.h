#ifndef ZIPLODE_TOOLBAR_H
#define ZIPLODE_TOOLBAR_H

#include <wx/wx.h>

#include "../Enum/ActionIDs.h"
#include "../State/StateUser.h"
#include "../State/StateManager.h"

using std::string;

class ToolBar : public StateUser {
    public:
        ToolBar(StateManager* stateManager, wxFrame* frame);
        void updateToolsEnabled();
        void updateToolsIcons();
        wxToolBar* getControl();

    private:
        ResourceManager* resources;
        wxToolBar *wxControl;
        void onSignalReceived(int signalID, Signal *signal);
        bool onPathChanged(Signal* signal);
};

#endif //ZIPLODE_TOOLBAR_H
