#include "DirectoryItem.h"

DirectoryItem::DirectoryItem(string name,
                             string extension,
                             string folder,
                             ZL_ITEM_TYPE type,
                             long long size,
                             std::chrono::time_point<std::chrono::system_clock> createdAt,
                             std::chrono::time_point<std::chrono::system_clock> modifiedAt)
{
    this->name = name;
    this->extension = extension;
    this->folder = folder;
    this->type = type;
    this->size = size;
    this->createdAt = createdAt;
    this->modifiedAt = modifiedAt;
}

string DirectoryItem::getName()
{
    return this->name;
}

string DirectoryItem::getExtension()
{
    return this->extension;
}

string DirectoryItem::getFolder()
{
    return this->folder;
}

ZL_ITEM_TYPE DirectoryItem::getType()
{
    return this->type;
}

long long DirectoryItem::getSize()
{
    return this->size;
}

std::chrono::time_point<std::chrono::system_clock> DirectoryItem::getCreatedAt()
{
    return this->createdAt;
}

std::chrono::time_point<std::chrono::system_clock> DirectoryItem::getModifiedAt()
{
    return this->modifiedAt;
}

string DirectoryItem::getFormattedPath(bool useFolder, bool useExtension)
{
    string result = this->getName();

    if (useFolder) {
        result = folder + "/" + result;
    }

    if (useExtension) {
        result = result + "." + extension;
    }

    return result;
}

string DirectoryItem::getFormattedCreatedAt(string format)
{
    return "";
}

string DirectoryItem::getFormattedModifiedAt(string format)
{
    return "";
}