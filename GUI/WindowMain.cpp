#include "WindowMain.h"

WindowMain::WindowMain(GtkApplication *app)
{
    g_signal_connect(app, "activate", G_CALLBACK(open), NULL);
}

void WindowMain::open(GtkApplication *app, gpointer user_data)
{
    GtkWidget *window = gtk_application_window_new (app);
    gtk_window_set_title(GTK_WINDOW (window), "Ziplode");
    gtk_window_set_default_size(GTK_WINDOW (window), 1000, 600);

    GtkWidget *window_container = gtk_box_new(GTK_ORIENTATION_VERTICAL, 0);
    gtk_window_set_child(GTK_WINDOW (window), window_container);

    GtkWidget *tab_view = gtk_notebook_new();
    UIHandler::create_tab_page(GTK_NOTEBOOK(tab_view), "Page 1");
    UIHandler::create_tab_page(GTK_NOTEBOOK(tab_view), "Page 2");
    UIHandler::create_tab_page(GTK_NOTEBOOK(tab_view), "Page 3");
    gtk_box_append(GTK_BOX(window_container), tab_view);

    GtkWidget *toolbar = gtk_action_bar_new();
    gtk_action_bar_set_revealed(GTK_ACTION_BAR(toolbar), true);
    GtkWidget *menu1 = UIHandler::add_menu_item(GTK_ACTION_BAR(toolbar), "Menu 1");
    g_signal_connect(menu1, "clicked", G_CALLBACK (button1Clicked), NULL);
    GtkWidget *menu2 = UIHandler::add_menu_item(GTK_ACTION_BAR(toolbar), "Menu 2");
    g_signal_connect(menu2, "clicked", G_CALLBACK (button2Clicked), NULL);
    GtkWidget *menu3 = UIHandler::add_menu_item(GTK_ACTION_BAR(toolbar), "Menu 3");
    g_signal_connect(menu3, "clicked", G_CALLBACK (button3Clicked), NULL);
    gtk_box_append(GTK_BOX(window_container), toolbar);

    gtk_window_present(GTK_WINDOW (window));
}

void WindowMain::button1Clicked()
{
    g_print("Button 1 clicked\n");
}

void WindowMain::button2Clicked()
{
    g_print("Button 2 clicked\n");
}

void WindowMain::button3Clicked()
{
    g_print("Button 3 clicked\n");
}