#include "FileSystemDirectoryContent.h"

void FileSystemDirectoryContent::load(char const* path)
{
    std::cout << "Reading directory: " << path << std::endl;
    this->path = path;

    struct dirent *entry;
    DIR *dir = opendir(path);
    if (dir == NULL) {
        std::cout << "Directory is empty" << std::endl;
        return;
    }

    this->clearItems();

    while ((entry = readdir(dir)) != NULL) {
        DirectoryItem* directoryItem = this->generateDirectoryItem(path, entry->d_name);

        if (directoryItem != nullptr) {
            this->addItem(directoryItem);
        }
    }

    closedir(dir);

    this->sortItems();
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
