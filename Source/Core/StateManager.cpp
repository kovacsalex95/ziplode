#include "StateManager.h"

StateManager::StateManager()
{
    this->pathManager = new PathManager();
}

PathManager* StateManager::getPathManager()
{
    return this->pathManager;
}