#ifndef ZIPLODE_UIHANDLER_H
#define ZIPLODE_UIHANDLER_H

#include <gtk/gtk.h>
#include "WindowMain.h"

class UIHandler
{
    public:
        WindowMain windowMain = nullptr;
        int status;
        UIHandler(int argc, char **argv);

    private:
        GtkApplication *app;
};


#endif //ZIPLODE_UIHANDLER_H
