#include "DirectoryContent.h"

string DirectoryContent::getPath()
{
    return this->path;
}

const std::vector<DirectoryItem*>& DirectoryContent::getItems() const {
    return this->items;
}

unsigned long DirectoryContent::getItemCount()
{
    return this->items.size();
}

DirectoryItem* DirectoryContent::getItem(int index)
{
    if (index < 0 || index >= getItemCount()) {
        return nullptr;
    }

    return this->items[index];
}

void DirectoryContent::addItem(DirectoryItem* item)
{
    if (item->getType() == ZL_ITEM_TYPE_FOLDER) {
        if (item->getName() == "./") {
            return;
        }
        if (item->getName() == "../" && this->path == "/") {
            return;
        }
    }

    this->items.push_back(item);
}

void DirectoryContent::removeItem(int index)
{
    if (index < 0 || index >= getItemCount()) {
        return;
    }

    this->items.erase(this->items.begin() + index);
}

void DirectoryContent::clearItems()
{
    this->items.clear();
}

bool compareItems(DirectoryItem* i1, DirectoryItem* i2)
{
    return (i1->getType() < i2->getType());
}

void DirectoryContent::sortItems()
{
    sort(this->items.begin(), this->items.end(), compareItems);
}
