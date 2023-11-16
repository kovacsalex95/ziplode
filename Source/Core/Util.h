#ifndef ZIPLODE_UTIL_H
#define ZIPLODE_UTIL_H

#import <string>
#include <wx/wx.h>
#include <wx/filename.h>
#include <fmt/format.h>

using std::string;

class Util
{
    public:
        static string normalizePath(const string& path);
        static string getFormattedFilesize(long long filesize, int decimals = 3);
};


#endif //ZIPLODE_UTIL_H
