#include "AppInfo.h"

string AppInfo::appName()
{
    string name = APP_NAME;
    return name;
}

string AppInfo::appVersion()
{
    string version = APP_VERSION;
    return version;
}

string AppInfo::appNameAndVersion()
{
    return fmt::format("{} v{}", appName(), appVersion());
}

bool AppInfo::appInDarkMode()
{
    return wxSystemSettings::GetAppearance().IsDark();
}