#ifndef ZIPLODE_PATHMANAGER_H
#define ZIPLODE_PATHMANAGER_H

#include <string>
#include <vector>
#include <fmt/format.h>
#include <wx/wx.h>
#include <wx/stdpaths.h>

#include "Util.h"
#include "ActionIDs.h"

using std::string;
using std::vector;

class PathManager {
    public:
        PathManager();
        string getCurrentPath();
        bool canGoBack();
        bool canGoForward();
        bool canGoUp();
        bool canGoHome();
        string goToPath(string path);
        string goToSubFoler(string folderName);
        string goToSubFoler(wxString folderName);
        string goToHome();
        string goBack();
        string goForward();
        string goUp();
        string getDefaultPath() const { return wxStandardPaths::Get().GetDocumentsDir().ToStdString(); }
        void setToolbarControl(wxToolBar* toolbar);
        void updateToolbarIcons();

    private:
        string currentPath;
        vector<string> backPaths;
        vector<string> forwardPaths;
        void setPath(string path);
        wxToolBar* toolbarControl = nullptr;
};


#endif //ZIPLODE_PATHMANAGER_H
