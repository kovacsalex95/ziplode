#ifndef ZIPLODE_MENUBAR_H
#define ZIPLODE_MENUBAR_H

#include <wx/wx.h>

#include "../Enum/ActionIDs.h"
#include "../State/StateManager.h"
#include "../State/StateUser.h"

using std::string;

class MenuBar : public StateUser {
    public:
        MenuBar(StateManager* stateManager, wxFrame* frame);
        void updateMenusEnabled();
        wxMenuBar* getControl();

    private:
        wxMenuBar *wxControl;
        void onSignalReceived(int signalID, Signal *signal);
};


#endif //ZIPLODE_MENUBAR_H
