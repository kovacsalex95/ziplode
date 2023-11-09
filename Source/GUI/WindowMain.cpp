#include "WindowMain.h"

WindowMain::WindowMain() : wxFrame(nullptr, wxID_ANY, "Hello Ziplode", wxDefaultPosition, wxSize(1200, 900))
{
    this->resources = new Resources();

    wxMenu *menuFile = new wxMenu;
    menuFile->Append(MAIN_MENU_IDS::MENU_HELLO, "&Hello...\tCtrl+H",
                     "Help string shown in status bar for this menu item");
    menuFile->AppendSeparator();
    menuFile->Append(wxID_EXIT);

    wxMenu *menuHelp = new wxMenu;
    menuHelp->Append(wxID_ABOUT);

    wxMenuBar *menuBar = new wxMenuBar;
    menuBar->Append(menuFile, "&File");
    menuBar->Append(menuHelp, "&Help");

    this->SetMenuBar(menuBar);

    this->CreateStatusBar();
    this->SetStatusText("Welcome to Ziplode!");

    this->Bind(wxEVT_MENU, &WindowMain::OnHello, this, MAIN_MENU_IDS::MENU_HELLO);
    this->Bind(wxEVT_MENU, &WindowMain::OnAbout, this, wxID_ABOUT);
    this->Bind(wxEVT_MENU, &WindowMain::OnExit, this, wxID_EXIT);

    wxToolBar *toolbar = CreateToolBar();
    toolbar->AddTool(wxID_OPEN, "Open", resources->iconOpen(), resources->iconOpenDisabled());
    toolbar->Realize();
    this->SetToolBar(toolbar);
}

void WindowMain::OnExit(wxCommandEvent& event)
{
    this->Close(true);
}

void WindowMain::OnAbout(wxCommandEvent& event)
{
    wxMessageBox("C++ archive handler GUI application",
                 "About " + AppInfo::appNameAndVersion(), wxOK | wxICON_INFORMATION);
}

void WindowMain::OnHello(wxCommandEvent& event)
{
    wxLogMessage("Hello world from wxWidgets!");
}

void WindowMain::button1Clicked()
{
    cout << "Button 1 clicked\n";
}

void WindowMain::button2Clicked()
{
    cout << "Button 2 clicked\n";
}

void WindowMain::button3Clicked()
{
    cout << "Button 3 clicked\n";
}

//void WindowMain::open()
//{
//    GtkWidget *toolbar = gtk_action_bar_new();
//    gtk_action_bar_set_revealed(GTK_ACTION_BAR(toolbar), true);
//    UIHandler::add_menu_item(GTK_ACTION_BAR(toolbar), "Menu 1", (void*)button1Clicked);
//    UIHandler::add_menu_item(GTK_ACTION_BAR(toolbar), "Menu 2", (void*)button2Clicked);
//    UIHandler::add_menu_item(GTK_ACTION_BAR(toolbar), "Menu 3", (void*)button3Clicked);
//    gtk_box_append(GTK_BOX(window_container), toolbar);
//
//    TabView *tabview = new TabView();
//    tabview->add_tab(new FileListTab("Files 1"));
//    tabview->add_tab(new FileListTab("Files 2"));
//    tabview->add_tab(new FileListTab("Files 3"));
//    gtk_box_append(GTK_BOX(window_container), tabview->get_widget());
//    tabview->set_tab_index(0);
//}
