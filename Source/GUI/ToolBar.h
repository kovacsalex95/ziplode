#ifndef ZIPLODE_TOOLBAR_H
#define ZIPLODE_TOOLBAR_H

#include <wx/wx.h>

#include "../Resources.h"
#include "../ActionIDs.h"

using namespace std;

class ToolBar {
    public:
        ToolBar(wxFrame* frame, Resources* resources);
        void updateToolsEnabled();
        void updateToolsIcons();
        wxToolBar* getControl();

    private:
        Resources* resources;
        wxToolBar *wxControl;
};

#endif //ZIPLODE_TOOLBAR_H
