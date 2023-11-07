#include "FileList.h"

void FileList::set_items_height(int items_height)
{
    this->item_height = items_height;

    this->file_list_scroll = gtk_scrolled_window_new();
    gtk_scrolled_window_set_propagate_natural_height (GTK_SCROLLED_WINDOW(file_list_scroll), true);

    this->file_list = gtk_list_box_new();

    gtk_scrolled_window_set_child(GTK_SCROLLED_WINDOW(file_list_scroll), file_list);
}

void FileList::add_item(string label)
{
    GtkWidget *line_label = gtk_label_new(label.c_str());
    gtk_widget_set_halign(line_label, GTK_ALIGN_START);
    gtk_widget_set_size_request(line_label, gtk_widget_get_width(file_list), this->item_height);
    gtk_widget_set_margin_start(line_label, 10);
    gtk_list_box_append(GTK_LIST_BOX(file_list), line_label);
}

GtkWidget* FileList::get_widget()
{
    return this->file_list_scroll;
}