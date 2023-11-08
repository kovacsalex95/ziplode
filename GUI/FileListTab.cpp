#include "FileListTab.h"

FileListTab::FileListTab(string tabName, bool selected) : TabViewTab(std::move(tabName), nullptr, selected) {
    this->file_list = new FileList();
    file_list->set_items_height(24);

    file_list->add_dummies(100); // TODO

    this->content = this->file_list->get_widget();
}
