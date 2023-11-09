#include "TabViewTab.h"

TabViewTab::TabViewTab(string tab_name, bool selected)
{
//    this->label = gtk_label_new(tab_name.c_str());
//    this->content = content;

    set_selected(selected);
}

//void TabViewTab::add_to_notebook()
//{
//    gtk_notebook_append_page(notebook, this->content, label);
//}

void TabViewTab::select()
{
    set_selected(true);
}

void TabViewTab::unselect()
{
    set_selected(false);
}

bool TabViewTab::is_selected()
{
    return this->selected;
}

void TabViewTab::set_selected(bool selected)
{
    this->selected = selected;
}
