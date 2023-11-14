//
// Created by Alex Flexi on 2023.11.09.
//

#ifndef ZIPLODE_RESOURCES_H
#define ZIPLODE_RESOURCES_H

#include <map>
#include <wx/wx.h>
#include <wx/stdpaths.h>
#include <wx/image.h>
#include <wx/filename.h>

#include "../AppInfo.h"

using std::string;
using std::map;

class Resources {
    public:
        Resources();
        wxBitmapBundle iconOpen();
        wxBitmapBundle iconArchive();

    private:
        map<wxString, wxBitmapBundle> generatedBitmapBundles;
        wxBitmapBundle generateBitmap(const wxString& bitmapName);
};


#endif //ZIPLODE_RESOURCES_H
