#ifndef ZIPLODE_FILELIST_H
#define ZIPLODE_FILELIST_H

#include <cstdlib>
#include <string>

using namespace std;

class FileList {
    public:
        void set_items_height(int items_height = 24);
        void add_item(string name, int size = 0);
        void add_dummies(int dummy_count = 100);

    private:
        int item_height = 24;
};


#endif //ZIPLODE_FILELIST_H
