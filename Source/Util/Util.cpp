#import "Util.h"

string Util::normalizePath(const string& path) {
    wxFileName* fileName = new wxFileName(wxString(path));
    fileName->Normalize(wxPATH_NORM_ALL);
    return fileName->GetFullPath().ToStdString();
}

string Util::getFormattedFilesize(long long filesize, int decimals)
{
    string sizeUnits[] = {
            "B",
            "KB",
            "MB",
            "GB",
            "TB",
            "PB",
    };

    long double currentSize = filesize;
    int unitIndex = 0;

    while(currentSize > 1000 && unitIndex < sizeof(sizeUnits) - 1) {
        currentSize /= 1000;
        unitIndex++;
    }

    double divisor = pow(10, decimals);
    currentSize = round(currentSize * divisor) / divisor;

    return fmt::format("{} {}", currentSize, sizeUnits[unitIndex]);
}
