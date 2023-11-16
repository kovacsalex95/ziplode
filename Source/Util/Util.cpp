#include "Util.h"

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

string Util::stringPad(string str, int width, HorizontalDirection direction, char padChar)
{
    if (str.length() >= width) {
        return str;
    }

    int characters = width - (int)str.length();
    string padString;

    for (int i=0; i<characters; i++) {
        padString += padChar;
    }

    switch (direction) {
        case ZL_HDIR_LEFT: return padString + str;
        case ZL_HDIR_RIGHT: return str + padString;
    }

    return str;
}

string Util::stringPad(int str, int width, HorizontalDirection direction, char padChar)
{
    return stringPad(to_string(str), width, direction, padChar);
}

string Util::getFormattedDateTime(tm dateTime, bool date, bool time, bool second)
{
    string formattedDate;

    if (date) {
        formattedDate += fmt::format("{}.{}.{}.",
                                     stringPad(1900 + dateTime.tm_year, 4, ZL_HDIR_LEFT, '0'),
                                     stringPad(1 + dateTime.tm_mon, 2, ZL_HDIR_LEFT, '0'),
                                     stringPad(dateTime.tm_mday, 2, ZL_HDIR_LEFT, '0'));
    }

    if (date && time) {
        formattedDate += ' ';
    }

    if (time) {
        formattedDate += fmt::format("{}:{}",
                                     stringPad(dateTime.tm_hour, 2, ZL_HDIR_LEFT, '0'),
                                     stringPad(dateTime.tm_min, 2, ZL_HDIR_LEFT, '0'));

        if (second) {
            formattedDate += ':' + stringPad(dateTime.tm_sec, 2, ZL_HDIR_LEFT, '0');
        }
    }

    return formattedDate;
}
