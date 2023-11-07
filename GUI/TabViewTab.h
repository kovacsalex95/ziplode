#ifndef ZIPLODE_TABVIEWTAB_H
#define ZIPLODE_TABVIEWTAB_H

#include <gtk/gtk.h>
#include <string>

using namespace std;

class TabViewTab {
    public:
        TabViewTab(string tab_name, GtkWidget* content = nullptr, bool selected = false);
        void select();
        void unselect();
        bool is_selected();
        void set_selected(bool selected);
        void add_to_notebook(GtkNotebook* notebook);

    private:
        bool selected = false;
        GtkWidget* label = nullptr;
        GtkWidget* content = nullptr;
};


#endif //ZIPLODE_TABVIEWTAB_H
