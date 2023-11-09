#ifndef ZIPLODE_TABVIEWTAB_H
#define ZIPLODE_TABVIEWTAB_H

#include <string>

using namespace std;

class TabViewTab {
    public:
        TabViewTab(string tab_name, bool selected = false);

    TabViewTab();

    void select();
        void unselect();
        bool is_selected();
        void set_selected(bool selected);

    protected:
        bool selected = false;
};


#endif //ZIPLODE_TABVIEWTAB_H
