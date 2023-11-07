#ifndef ZIPLODE_WINDOWMAIN_H
#define ZIPLODE_WINDOWMAIN_H

#include <gtk/gtk.h>
#include "UIHandler.h"

class WindowMain
{
    public:
        WindowMain(GtkApplication *app);
        static void open(GtkApplication *app, gpointer user_data);

    private:
        GtkApplication *app{};
        static void button1Clicked();
        static void button2Clicked();
        static void button3Clicked();
};


#endif //ZIPLODE_WINDOWMAIN_H