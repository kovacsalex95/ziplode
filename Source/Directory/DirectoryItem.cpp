#include "DirectoryItem.h"

#include <utility>

DirectoryItem::DirectoryItem(string name,
                             string extension,
                             string folder,
                             ZL_ITEM_TYPE type,
                             long long size,
                             tm modifiedAt)
{
    this->name = std::move(name);
    this->extension = std::move(extension);
    this->folder = std::move(folder);
    this->type = type;
    this->size = size;
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

tm DirectoryItem::getModifiedAt()
{
    return this->modifiedAt;
}

string DirectoryItem::getPath(bool useFolder, bool useExtension)
{
    string result = this->getName();

    if (useFolder) {
        result = folder + "/" + result;
    }

    if (this->getType() == ZL_ITEM_TYPE_FILE && useExtension) {
        result = result + "." + extension;
    }

    return result;
}
