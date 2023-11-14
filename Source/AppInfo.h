#define APP_NAME "Ziplode";
#define APP_VERSION "0.1.0";

#include <string>
#include <fmt/core.h>
#include <fmt/format.h>
#include <wx/settings.h>

using std::string;

class AppInfo
{
    public:
        static string appName();
        static string appVersion();
        static string appNameAndVersion();
        static bool appInDarkMode();
};
