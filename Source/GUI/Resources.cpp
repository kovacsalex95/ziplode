#include "Resources.h"

Resources::Resources()
{
    wxInitAllImageHandlers();
}

wxBitmapBundle Resources::generateBitmap(const wxString& bitmapName)
{
    wxVector<wxBitmap> bitmaps;

    wxString basePath = wxStandardPaths::Get().GetExecutablePath();
    basePath = wxPathOnly(basePath) + wxFileName::GetPathSeparator();

    bitmaps.push_back(wxBitmap(wxImage(basePath + "Resources" + wxFileName::GetPathSeparator() + bitmapName + "-24.png")));
    bitmaps.push_back(wxBitmap(wxImage(basePath + "Resources" + wxFileName::GetPathSeparator() + bitmapName + "-36.png")));
    bitmaps.push_back(wxBitmap(wxImage(basePath + "Resources" + wxFileName::GetPathSeparator() + bitmapName + "-48.png")));
    bitmaps.push_back(wxBitmap(wxImage(basePath + "Resources" + wxFileName::GetPathSeparator() + bitmapName + "-60.png")));

    return wxBitmapBundle::FromBitmaps(bitmaps);
}

wxBitmapBundle Resources::iconOpen()
{
    return generateBitmap("folder-open-solid");
}

wxBitmapBundle Resources::iconOpenDisabled()
{
    return generateBitmap("folder-open-regular");
}