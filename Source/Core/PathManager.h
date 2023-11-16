#ifndef ZIPLODE_PATHMANAGER_H
#define ZIPLODE_PATHMANAGER_H

#include <string>
#include <vector>
#include <fmt/format.h>
#include <wx/wx.h>
#include <wx/stdpaths.h>

#include "SignalManager.h"
#include "PathChangedSignal.h"
#include "Util.h"
#include "ActionIDs.h"

using std::string;
using std::vector;

class PathManager {
    public:
        PathManager(SignalManager* signalManager);
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
        void updateToolbarIcons();

    private:
        SignalManager* signalManager;
        string currentPath;
        vector<string> backPaths;
        vector<string> forwardPaths;
        void setPath(string path);
};


#endif //ZIPLODE_PATHMANAGER_H
