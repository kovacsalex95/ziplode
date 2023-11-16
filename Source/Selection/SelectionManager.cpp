#include "SelectionManager.h"

#include <utility>

SelectionManager::SelectionManager(SignalManager* signalManager)
{
    this->signalManager = signalManager;
}

bool SelectionManager::hasSelection()
{
    return !this->selectedPaths.empty();
}

int SelectionManager::getSelectionCount()
{
    return (int)this->selectedPaths.size();
}

vector<string> SelectionManager::getSelection()
{
    return this->selectedPaths;
}

void SelectionManager::setSelection(vector<string> paths)
{
    this->selectedPaths = std::move(paths);
    this->signalManager->sendSignal(ZL_EVENT_SELECTION_CHANGED);
}

void SelectionManager::clearSelection()
{
    this->selectedPaths.clear();
    this->signalManager->sendSignal(ZL_EVENT_SELECTION_CHANGED);
}

