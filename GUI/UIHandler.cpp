#include "UIHandler.h"

void UIHandler::create_tab_page(GtkNotebook *notebook, char const *title)
{
    GtkWidget *page = gtk_box_new(GTK_ORIENTATION_VERTICAL, 0);
    GtkWidget *label = gtk_label_new(title);

    gtk_notebook_append_page(notebook, page, label);
}

GtkWidget* UIHandler::add_menu_item(GtkActionBar *action_bar, char const *label, void* on_click, MenuPosition position)
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

    if (on_click != nullptr) {
        g_signal_connect(button, "clicked", G_CALLBACK (on_click), NULL);
    }

    return button;
}