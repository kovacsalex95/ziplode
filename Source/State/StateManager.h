#ifndef ZIPLODE_STATEMANAGER_H
#define ZIPLODE_STATEMANAGER_H

#include "../Path/PathManager.h"
#include "../Signal/SignalManager.h"
#include "../Resource/ResourceManager.h"
#include "../Selection/SelectionManager.h"

class StateManager {
public:
    StateManager();
    PathManager* getPathManager();
    SignalManager* getSignalManager();
    ResourceManager* getResourceManager();
    SelectionManager* getSelectionManager();

private:
    PathManager* pathManager;
    SignalManager* signalManager;
    ResourceManager* resourceManager;
    SelectionManager* selectionManager;
};


#endif //ZIPLODE_STATEMANAGER_H
