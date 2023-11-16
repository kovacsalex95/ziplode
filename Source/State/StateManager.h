#ifndef ZIPLODE_STATEMANAGER_H
#define ZIPLODE_STATEMANAGER_H

#include "../Path/PathManager.h"
#include "../Signal/SignalManager.h"
#include "../Resource/ResourceManager.h"

class StateManager {
public:
    StateManager();
    PathManager* getPathManager();
    SignalManager* getSignalManager();
    ResourceManager* getResourceManager();

private:
    PathManager* pathManager;
    SignalManager* signalManager;
    ResourceManager* resourceManager;
};


#endif //ZIPLODE_STATEMANAGER_H
