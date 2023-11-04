#ifndef ZIPLODE_WINDOWMAIN_H
#define ZIPLODE_WINDOWMAIN_H

#include <gtk/gtk.h>

class WindowMain
{
    public:
        WindowMain(GtkApplication *app);
        static void open(GtkApplication *app, gpointer user_data);

    private:
        GtkApplication *app{};
        static void print_hello(GtkWidget *widget, gpointer data);
};


#endif //ZIPLODE_WINDOWMAIN_H
