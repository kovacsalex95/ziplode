#include "Resources.h"

Resources::Resources()
{
    wxInitAllImageHandlers();
}

wxBitmapBundle Resources::generateBitmap(const wxString& bitmapName)
{
    string bitmapNameSuffix = AppInfo::appInDarkMode() ? "-bright" : "-dark";
    const wxString& bitmapNameThemed = wxString(bitmapName + bitmapNameSuffix);

    if (generatedBitmapBundles.contains(bitmapNameThemed)) {
        return generatedBitmapBundles[bitmapNameThemed];
    }

    wxVector<wxBitmap> bitmaps;

    wxString basePath = wxStandardPaths::Get().GetExecutablePath();
    basePath = wxPathOnly(basePath) + wxFileName::GetPathSeparator();

    bitmaps.push_back(wxBitmap(wxImage(basePath + "Resources" + wxFileName::GetPathSeparator() + bitmapName + "-24" + bitmapNameSuffix + ".png")));
    bitmaps.push_back(wxBitmap(wxImage(basePath + "Resources" + wxFileName::GetPathSeparator() + bitmapName + "-36" + bitmapNameSuffix + ".png")));
    bitmaps.push_back(wxBitmap(wxImage(basePath + "Resources" + wxFileName::GetPathSeparator() + bitmapName + "-48" + bitmapNameSuffix + ".png")));
    bitmaps.push_back(wxBitmap(wxImage(basePath + "Resources" + wxFileName::GetPathSeparator() + bitmapName + "-60" + bitmapNameSuffix + ".png")));

    generatedBitmapBundles[bitmapNameThemed] = wxBitmapBundle::FromBitmaps(bitmaps);
    return generatedBitmapBundles[bitmapNameThemed];
}

wxBitmapBundle Resources::iconOpen()
{
    return generateBitmap("folder-open-regular");
}

wxBitmapBundle Resources::iconArchive()
{
    return generateBitmap("box-regular");
}
