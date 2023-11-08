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

    GtkWidget *toolbar = gtk_action_bar_new();
    gtk_action_bar_set_revealed(GTK_ACTION_BAR(toolbar), true);
    UIHandler::add_menu_item(GTK_ACTION_BAR(toolbar), "Menu 1", (void*)button1Clicked);
    UIHandler::add_menu_item(GTK_ACTION_BAR(toolbar), "Menu 2", (void*)button2Clicked);
    UIHandler::add_menu_item(GTK_ACTION_BAR(toolbar), "Menu 3", (void*)button3Clicked);
    gtk_box_append(GTK_BOX(window_container), toolbar);

    TabView *tabview = new TabView();
    tabview->add_tab(new FileListTab("Files 1"));
    tabview->add_tab(new FileListTab("Files 2"));
    tabview->add_tab(new FileListTab("Files 3"));
    gtk_box_append(GTK_BOX(window_container), tabview->get_widget());
    tabview->set_tab_index(0);

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