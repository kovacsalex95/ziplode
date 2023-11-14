#ifndef ZIPLODE_STATUSBAR_H
#define ZIPLODE_STATUSBAR_H

#include <string>
#include <wx/wx.h>

using std::string;

class StatusBar {
    public:
        StatusBar(wxFrame* frame);
        wxMenuBar* getControl();

    private:
        wxStatusBar *wxControl;
};


#endif //ZIPLODE_STATUSBAR_H
