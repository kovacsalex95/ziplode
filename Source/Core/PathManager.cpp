#include "PathManager.h"

PathManager::PathManager(SignalManager* signalManager)
{
    this->signalManager = signalManager;
    this->goToHome();
}

string PathManager::getCurrentPath()
{
    return this->currentPath;
}

void PathManager::setPath(string path)
{
    if (this->currentPath == path) {
        return;
    }

    this->currentPath = Util::normalizePath(path);
}

bool PathManager::canGoBack()
{
    return !this->backPaths.empty();
}

bool PathManager::canGoForward()
{
    return !this->forwardPaths.empty();
}

bool PathManager::canGoUp()
{
    return this->getCurrentPath() != "/";
}

bool PathManager::canGoHome()
{
    return this->getCurrentPath() != this->getDefaultPath();
}

string PathManager::goToPath(string path)
{
    if (path != this->getCurrentPath() && this->getCurrentPath() != "") {
        this->backPaths.push_back(this->getCurrentPath());
    }

    this->setPath(path);
    this->forwardPaths.clear();
    this->signalManager->sendSignal(ZL_EVENT_PATH_CHANGED);

    return this->getCurrentPath();
}

string PathManager::goToSubFoler(wxString folderName)
{
    return this->goToSubFoler(folderName.ToStdString());
}

string PathManager::goToSubFoler(string folderName)
{
    string newPath = fmt::format("{}/{}", this->getCurrentPath(), folderName);

    return this->goToPath(newPath);
}

string PathManager::goToHome()
{
    return this->goToPath(this->getDefaultPath());
}

string PathManager::goBack()
{
    if (this->canGoBack()) {
        this->forwardPaths.insert(this->forwardPaths.begin(), this->getCurrentPath());
        this->setPath(this->backPaths[this->backPaths.size() - 1]);
        this->backPaths.pop_back();
        this->signalManager->sendSignal(ZL_EVENT_PATH_CHANGED);
    }

    return this->getCurrentPath();
}

string PathManager::goForward()
{
    if (this->canGoForward()) {
        this->backPaths.push_back(this->getCurrentPath());
        this->setPath(this->forwardPaths[0]);
        this->forwardPaths.erase(this->forwardPaths.begin());
        this->signalManager->sendSignal(ZL_EVENT_PATH_CHANGED);
    }

    return this->getCurrentPath();
}

string PathManager::goUp()
{
    if (this->canGoUp()) {
        return this->goToPath(fmt::format("{}/../", this->getCurrentPath()));
    }

    return this->getCurrentPath();
}
