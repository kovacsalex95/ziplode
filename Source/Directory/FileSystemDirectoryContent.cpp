#include "FileSystemDirectoryContent.h"

void FileSystemDirectoryContent::load()
{
    string path = this->stateManager->getPathManager()->getCurrentPath();

    struct dirent *entry;
    DIR *dir = opendir(path.c_str());
    if (dir == NULL) {
        return;
    }

    this->clearItems();

    while ((entry = readdir(dir)) != NULL) {
        DirectoryItem* directoryItem = this->generateDirectoryItem(path.c_str(), entry->d_name);

        if (directoryItem != nullptr) {
            this->addItem(directoryItem);
        }
    }

    closedir(dir);

    this->sortItems();

    this->stateManager->getSignalManager()->sendSignal(ZL_EVENT_CONTENT_LOADED);
}

DirectoryItem* FileSystemDirectoryContent::generateDirectoryItem(char const* path, char const* filename)
{
    struct stat fileInfo;
    ZL_ITEM_TYPE itemType = ZL_ITEM_TYPE_FILE;

    string fullPath = fmt::format("{}/{}", path, filename);

    if (stat(fullPath.c_str(), &fileInfo) != 0) {
        std::cout << "Error " << fullPath << std::endl;
        return nullptr;
    }

    if ((fileInfo.st_mode & S_IFMT) == S_IFDIR) {
        itemType = ZL_ITEM_TYPE_FOLDER;
    }

    long long itemSize = fileInfo.st_size;
    string filenameSuffix = itemType == ZL_ITEM_TYPE_FOLDER ? "/" : "";

    DirectoryItem* item = new DirectoryItem(filename + filenameSuffix, "", path, itemType, itemSize, std::chrono::system_clock::now(), std::chrono::system_clock::now());
    return item;
}
