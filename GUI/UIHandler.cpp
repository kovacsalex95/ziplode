#include "UIHandler.h"

UIHandler::UIHandler(int argc, char **argv)
{
    app = gtk_application_new("org.gtk.example", G_APPLICATION_DEFAULT_FLAGS);
    windowMain = *new WindowMain(app);
    status = g_application_run(G_APPLICATION (app), argc, argv);
    g_object_unref(app);
}
