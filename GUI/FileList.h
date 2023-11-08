#ifndef ZIPLODE_FILELIST_H
#define ZIPLODE_FILELIST_H

#include <gtk/gtk.h>
#include <string>
#include "UIHandler.h"

using namespace std;

class FileList {
    public:
        void set_items_height(int items_height = 24);
        void add_item(string label);
        void add_dummies(int dummy_count = 100);
        GtkWidget* get_widget();

    private:
        GtkWidget *file_list_scroll;
        GtkWidget *file_list;
        int item_height = 24;
};


#endif //ZIPLODE_FILELIST_H
