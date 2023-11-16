#import "Util.h"

string Util::normalizePath(const string& path) {
    wxFileName* fileName = new wxFileName(wxString(path));
    fileName->Normalize(wxPATH_NORM_ALL);
    return fileName->GetFullPath().ToStdString();
}

