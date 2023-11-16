//
// Created by Alex Flexi on 2023.11.09.
//

#ifndef ZIPLODE_RESOURCEMANAGER_H
#define ZIPLODE_RESOURCEMANAGER_H

#include <map>
#include <wx/wx.h>
#include <wx/stdpaths.h>
#include <wx/image.h>
#include <wx/filename.h>

#include "../AppInfo.h"

using std::string;
using std::map;

class ResourceManager {
    public:
        ResourceManager();
        wxBitmapBundle iconOpen();
        wxBitmapBundle iconArchive();
        wxBitmapBundle iconHome();
        wxBitmapBundle iconBack();
        wxBitmapBundle iconForward();
        wxBitmapBundle iconUp();

    private:
        map<wxString, wxBitmapBundle> generatedBitmapBundles;
        wxBitmapBundle generateBitmap(const wxString& bitmapName);
};


#endif //ZIPLODE_RESOURCEMANAGER_H
