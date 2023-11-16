#ifndef ZIPLODE_SELECTIONMANAGER_H
#define ZIPLODE_SELECTIONMANAGER_H

#include <string>
#include <vector>

#include "../Enum/ActionIDs.h"
#include "../Signal/SignalManager.h"

using std::string;

class SelectionManager {
    public:
        SelectionManager(SignalManager* signalManager);
        bool hasSelection();
        int getSelectionCount();
        vector<string> getSelection();
        void setSelection(vector<string> paths);
        void clearSelection();

    private:
        SignalManager* signalManager;
        vector<string> selectedPaths;
};


#endif //ZIPLODE_SELECTIONMANAGER_H
