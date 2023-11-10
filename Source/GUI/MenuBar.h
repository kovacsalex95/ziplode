#ifndef ZIPLODE_MENUBAR_H
#define ZIPLODE_MENUBAR_H

#include <wx/wx.h>

#include "../ActionIDs.h"

using namespace std;

class MenuBar {
    public:
        MenuBar(wxFrame* frame);
        void updateMenusEnabled();
        wxMenuBar* getControl();

    private:
        wxMenuBar *wxControl;
};


#endif //ZIPLODE_MENUBAR_H
