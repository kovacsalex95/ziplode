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

string DirectoryItem::getFormattedSize(int decimals)
{
    string sizeUnits[] = {
            "B",
            "KB",
            "MB",
            "GB",
            "TB",
            "PB",
    };

    long double currentSize = this->getSize();
    int unitIndex = 0;

    while(currentSize > 1000 && unitIndex < sizeof(sizeUnits) - 1) {
        currentSize /= 1000;
        unitIndex++;
    }

    double divisor = pow(10, decimals);
    currentSize = round(currentSize * divisor) / divisor;

    return fmt::format("{} {}", currentSize, sizeUnits[unitIndex]);
}

string DirectoryItem::getFormattedCreatedAt(string format)
{
    return "";
}

string DirectoryItem::getFormattedModifiedAt(string format)
{
    return "";
}