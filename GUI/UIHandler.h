#ifndef ZIPLODE_UIHANDLER_H
#define ZIPLODE_UIHANDLER_H

#include <gtk/gtk.h>
#include "WindowMain.h"

enum MenuPosition
{
    MENU_POS_LEFT = 1,
    MENU_POS_RIGHT = 2,
};

class UIHandler
{
    public:
        int status;
        UIHandler(int argc, char **argv);
        static void create_tab_page(GtkNotebook *notebook, char const *title);
        static GtkWidget* add_menu_item(GtkActionBar *action_bar, char const *label, MenuPosition position = MENU_POS_LEFT);
};


#endif //ZIPLODE_UIHANDLER_H
