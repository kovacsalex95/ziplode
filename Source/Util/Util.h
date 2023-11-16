#ifndef ZIPLODE_UTIL_H
#define ZIPLODE_UTIL_H

#include <string>
#include <ctime>
#include <wx/wx.h>
#include <wx/filename.h>
#include <fmt/format.h>

#include "../Enum/Directions.h"

using std::string;
using std::to_string;

class Util
{
    public:
        static string normalizePath(const string& path);
        static string getFormattedFilesize(long long filesize, int decimals = 3);
        static string getFormattedDateTime(tm dateTime, bool date = true, bool time = true, bool second = false);
        static string stringPad(string str, int width, HorizontalDirection direction = ZL_HDIR_RIGHT, char padChar = ' ');
        static string stringPad(int str, int width, HorizontalDirection direction = ZL_HDIR_RIGHT, char padChar = ' ');
};


#endif //ZIPLODE_UTIL_H
