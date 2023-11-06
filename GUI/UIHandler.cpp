#include "UIHandler.h"

UIHandler::UIHandler(int argc, char **argv)
{
    GtkApplication *app;
    app = gtk_application_new("org.gtk.example", G_APPLICATION_DEFAULT_FLAGS);
    WindowMain window_main = *new WindowMain(app);
    status = g_application_run(G_APPLICATION (app), argc, argv);
    g_object_unref(app);
}

void UIHandler::create_tab_page(GtkNotebook *notebook, char const *title)
{
    GtkWidget *page = gtk_box_new(GTK_ORIENTATION_VERTICAL, 0);
    GtkWidget *label = gtk_label_new(title);

    gtk_notebook_append_page(notebook, page, label);
}

GtkWidget* UIHandler::add_menu_item(GtkActionBar *action_bar, char const *label, MenuPosition position)
{
    GtkWidget *button = gtk_button_new_with_label(label);

    switch(position)
    {
        case MENU_POS_LEFT:
            gtk_action_bar_pack_start(GTK_ACTION_BAR(action_bar), button);
            break;

        case MENU_POS_RIGHT:
            gtk_action_bar_pack_end(GTK_ACTION_BAR(action_bar), button);
            break;
    }

    return button;
}