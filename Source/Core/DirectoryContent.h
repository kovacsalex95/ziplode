#ifndef ZIPLODE_DIRECTORYCONTENT_H
#define ZIPLODE_DIRECTORYCONTENT_H

#include <string>
#include <vector>
#include <filesystem>
#include <algorithm>

#include "DirectoryItem.h"

using std::string;
using std::vector;

class DirectoryContent {

    public:
        virtual void load(char const* path) = 0;
        string getPath();
        const vector<DirectoryItem*>& getItems() const;
        unsigned long getItemCount();

    protected:
        DirectoryItem* getItem(int index);
        void addItem(DirectoryItem* item);
        void removeItem(int index);
        void clearItems();
        void sortItems();

    private:
        string path = "";
        vector<DirectoryItem*> items;
        //bool compareItems(DirectoryItem i1, DirectoryItem i2);
};

#endif //ZIPLODE_DIRECTORYCONTENT_H
