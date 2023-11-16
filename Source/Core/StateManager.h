#ifndef ZIPLODE_STATEMANAGER_H
#define ZIPLODE_STATEMANAGER_H

#include "PathManager.h"
#include "SignalManager.h"
#include "ResourceManager.h"

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
