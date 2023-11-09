#ifndef ZIPLODE_MAIN_H
#define ZIPLODE_MAIN_H

#include <wx/wx.h>

#include "GUI/WindowMain.h"

class ZiplodeApp : public wxApp
{
    public:
        bool OnInit() override;
};

#endif //ZIPLODE_MAIN_H
