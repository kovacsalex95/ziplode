#include "StateManager.h"

StateManager::StateManager()
{
    this->signalManager = new SignalManager();
    this->resourceManager = new ResourceManager();
    this->pathManager = new PathManager(this->signalManager);
    this->selectionManager = new SelectionManager(this->signalManager);
}

PathManager* StateManager::getPathManager()
{
    return this->pathManager;
}

SignalManager* StateManager::getSignalManager()
{
    return this->signalManager;
}

ResourceManager* StateManager::getResourceManager()
{
    return this->resourceManager;
}

SelectionManager* StateManager::getSelectionManager()
{
    return this->selectionManager;
}