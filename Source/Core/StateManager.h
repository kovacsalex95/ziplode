#ifndef ZIPLODE_STATEMANAGER_H
#define ZIPLODE_STATEMANAGER_H

#include "PathManager.h"

class StateManager {
public:
    StateManager();
    PathManager* getPathManager();

private:
    PathManager* pathManager;
};


#endif //ZIPLODE_STATEMANAGER_H
