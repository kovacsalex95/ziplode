#include "FileList.h"

FileList::FileList(wxFrame* frame)
{
    this->wxControl = new wxDataViewListCtrl(frame, wxID_ANY, wxDefaultPosition, wxDefaultSize, wxDV_MULTIPLE | wxDV_ROW_LINES | wxDV_VERT_RULES);

    this->wxControl->AppendTextColumn("Name", wxDATAVIEW_CELL_INERT, wxCOL_WIDTH_AUTOSIZE);
    this->wxControl->AppendTextColumn("Size", wxDATAVIEW_CELL_INERT, wxCOL_WIDTH_AUTOSIZE);
    this->wxControl->AppendTextColumn("Last modified", wxDATAVIEW_CELL_INERT, wxCOL_WIDTH_AUTOSIZE);

    this->wxControl->SetContainingSizer(frame->GetSizer());
    this->wxControl->Bind(wxEVT_DATAVIEW_ITEM_ACTIVATED, &FileList::onItemDoubleClicked, this, wxID_ANY);

    content = new FileSystemDirectoryContent();
}

wxDataViewListCtrl* FileList::getControl()
{
    return this->wxControl;
}

void FileList::loadPath(string path)
{
    this->currentPath = path;

    content->load(path.c_str());
    vector<DirectoryItem*> items = content->getItems();

    this->wxControl->DeleteAllItems();

    for (int i=0; i<items.size(); i++) {
        int year = rand() % 20 + 2003;
        int month = rand() % 12;
        int day = rand() % 30;

        this->addFile(items[i]->getName(), items[i]->getFormattedSize(1), fmt::format("{}.{}.{}.", year, month, day));
    }
}

void FileList::addFile(string name, string size, string lastModified)
{
    wxVector<wxVariant> data;
    data.push_back(wxVariant(name));
    data.push_back(wxVariant(size));
    data.push_back(wxVariant(lastModified)); // TODO

    this->wxControl->AppendItem(data);
}

void FileList::onItemDoubleClicked(wxDataViewEvent& event)
{
    wxDataViewModel* itemData = event.GetModel();

    wxVariant filenameVariant;
    itemData->GetValue(filenameVariant, event.GetItem(), 0);
    wxString filename = filenameVariant.GetString();

    // Folder
    // TODO: Clear out "../"-s from the path
    if (filename.EndsWith("/")) {
        filename = filename.SubString(0, filename.length() - 1);
        this->loadPath(fmt::format("{}/{}", this->currentPath, filename.ToStdString()));
    }

    // File
    else {
        std::cout << "Opening file: " << filename << std::endl;
    }
}