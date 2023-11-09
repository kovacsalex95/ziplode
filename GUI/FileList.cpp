#include "FileList.h"

void FileList::set_items_height(int items_height)
{
    this->item_height = items_height;

//    this->file_list_scroll = gtk_scrolled_window_new();
//    gtk_scrolled_window_set_propagate_natural_height (GTK_SCROLLED_WINDOW(file_list_scroll), true);
//
//    this->file_list = gtk_list_box_new();
//    gtk_list_box_set_selection_mode(GTK_LIST_BOX(this->file_list), GTK_SELECTION_MULTIPLE);
//    gtk_list_box_set_activate_on_single_click(GTK_LIST_BOX(this->file_list), false);
//
//    gtk_scrolled_window_set_child(GTK_SCROLLED_WINDOW(file_list_scroll), file_list);
}

void FileList::add_item(string name, int size)
{
//    GtkWidget *line_container = gtk_box_new(GTK_ORIENTATION_HORIZONTAL, 10);
//
//    GtkWidget *line_label = gtk_label_new(name.c_str());
//    gtk_widget_set_halign(line_label, GTK_ALIGN_START);
//    gtk_widget_set_size_request(line_label, gtk_widget_get_width(line_label), this->item_height);
//    gtk_widget_set_margin_start(line_label, 10);
//    gtk_box_append(GTK_BOX(line_container), line_label);
//
//    GtkWidget *size_label = gtk_label_new((to_string(size) + "MB").c_str());
//    gtk_widget_set_halign(size_label, GTK_ALIGN_START);
//    gtk_widget_set_size_request(size_label, gtk_widget_get_width(size_label), this->item_height);
//    gtk_widget_set_margin_end(size_label, 10);
//    gtk_box_append(GTK_BOX(line_container), size_label);
//
//    gtk_list_box_append(GTK_LIST_BOX(file_list), line_container);
}

void FileList::add_dummies(int dummy_count)
{
    int dummies = dummy_count;

    while (dummies --> 0) {
        int file_size = rand() % 1024;
        add_item("Dummy file #" + to_string(dummy_count - dummies), file_size);
    }
}

//GtkWidget* FileList::get_widget()
//{
//    return this->file_list_scroll;
//}