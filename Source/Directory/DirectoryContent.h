#ifndef ZIPLODE_DIRECTORYCONTENT_H
#define ZIPLODE_DIRECTORYCONTENT_H

#include <string>
#include <vector>
#include <filesystem>
#include <algorithm>

#include "DirectoryItem.h"
#include "../State/StateManager.h"

using std::string;
using std::vector;

class DirectoryContent {

    public:
        DirectoryContent(StateManager* stateManager);
        virtual void load() = 0;
        const vector<DirectoryItem*>& getItems() const;
        unsigned long getItemCount();

    protected:
        StateManager* stateManager;
        DirectoryItem* getItem(int index);
        void addItem(DirectoryItem* item);
        void removeItem(int index);
        void clearItems();
        void sortItems();

    private:
        vector<DirectoryItem*> items;
        //bool compareItems(DirectoryItem i1, DirectoryItem i2);
};

#endif //ZIPLODE_DIRECTORYCONTENT_H
