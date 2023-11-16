#include "PathManager.h"

PathManager::PathManager()
{
    this->goToHome();
}

string PathManager::getCurrentPath()
{
    return this->currentPath;
}

void PathManager::setPath(string path)
{
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

    this->updateToolbarIcons();
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
    }

    this->updateToolbarIcons();
    return this->getCurrentPath();
}

string PathManager::goForward()
{
    if (this->canGoForward()) {
        this->backPaths.push_back(this->getCurrentPath());
        this->setPath(this->forwardPaths[0]);
        this->forwardPaths.erase(this->forwardPaths.begin());
    }

    this->updateToolbarIcons();
    return this->getCurrentPath();
}

string PathManager::goUp()
{
    if (this->canGoUp()) {
        return this->goToPath(fmt::format("{}/../", this->getCurrentPath()));
    }

    return this->getCurrentPath();
}

void PathManager::setToolbarControl(wxToolBar* toolbar)
{
    this->toolbarControl = toolbar;
}

void PathManager::updateToolbarIcons()
{
    if (this->toolbarControl == nullptr) {
        return;
    }

    std::cout << "Back: (" << this->backPaths.size() << ")" << std::endl;
    for (int i = 0; i < this->backPaths.size(); i++) {
        std::cout << "\t" << this->backPaths[i] << std::endl;
    }

    std::cout << "--------" << std::endl;

    std::cout << "Forward: (" << this->forwardPaths.size() << ")" << std::endl;
    for (int i = 0; i < this->forwardPaths.size(); i++) {
        std::cout << "\t" << this->forwardPaths[i] << std::endl;
    }

    this->toolbarControl->EnableTool(ZL_ACTION_BACK, this->canGoBack());
    this->toolbarControl->EnableTool(ZL_ACTION_UP, this->canGoUp());
    this->toolbarControl->EnableTool(ZL_ACTION_FORWARD, this->canGoForward());
    this->toolbarControl->EnableTool(ZL_ACTION_HOME, this->canGoHome());
}
