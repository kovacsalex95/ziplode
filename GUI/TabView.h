//
// Created by Alex Flexi on 2023.11.07.
//

#ifndef ZIPLODE_TABVIEW_H
#define ZIPLODE_TABVIEW_H

#include <gtk/gtk.h>
#include <string>
#include <vector>
#include "TabViewTab.h"

using namespace std;

class TabView {
    public:
        TabView();
        int get_tab_count();
        int get_tab_index();
        void set_tab_index(int index);
        int add_tab(string tab_name, GtkWidget* content = nullptr, bool selected = false);
        int add_tab(TabViewTab* new_tab, bool selected = false);
        GtkWidget* get_widget();

    private:
        int tab_index = 0;
        vector<TabViewTab> tabs;
        GtkWidget* notebook = nullptr;
};


#endif //ZIPLODE_TABVIEW_H
