#include "TabView.h"

TabView::TabView()
{
    this->notebook = gtk_notebook_new();
}

int TabView::add_tab(string tab_name, GtkWidget* content, bool selected)
{
    TabViewTab *new_tab = new TabViewTab(std::move(tab_name), content, false);
    return add_tab(new_tab);
}

int TabView::add_tab(TabViewTab* new_tab, bool selected)
{
    int new_index = get_tab_count();

    this->tabs.push_back(*new_tab);
    set_tab_index(selected ? new_index : this->tab_index);

    new_tab->add_to_notebook(GTK_NOTEBOOK(this->notebook));

    return new_index;
}

int TabView::get_tab_count()
{
    return (int)this->tabs.size();
}

int TabView::get_tab_index()
{
    return this->tab_index;
}

void TabView::set_tab_index(int index)
{
    if (index < 0 || index >= get_tab_count()) {
        return;
    }

    this->tab_index = index;

    for (int i = 0; i < this->tabs.size(); i++) {
        this->tabs[i].set_selected(i == index);
    }

    gtk_notebook_set_current_page(GTK_NOTEBOOK(this->notebook), index);
}

GtkWidget* TabView::get_widget()
{
    return this->notebook;
}
