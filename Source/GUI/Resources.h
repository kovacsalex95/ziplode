//
// Created by Alex Flexi on 2023.11.09.
//

#ifndef ZIPLODE_RESOURCES_H
#define ZIPLODE_RESOURCES_H

#include <wx/wx.h>
#include <wx/stdpaths.h>
#include <wx/image.h>
#include <wx/filename.h>

using namespace std;

class Resources {
    public:
        Resources();
        wxBitmapBundle iconOpen();
        wxBitmapBundle iconOpenDisabled();

    private:
        wxBitmapBundle generateBitmap(const wxString& bitmapName);
};


#endif //ZIPLODE_RESOURCES_H
