#include "FileList.h"

FileList::FileList(wxFrame* frame)
{
    this->wxControl = new wxDataViewListCtrl(frame, wxID_ANY, wxDefaultPosition, wxDefaultSize, wxDV_MULTIPLE | wxDV_ROW_LINES | wxDV_VERT_RULES);

    this->wxControl->AppendTextColumn("Name", wxDATAVIEW_CELL_INERT, wxCOL_WIDTH_AUTOSIZE)->SetMinWidth(200);
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

        this->addFile(items[i]);
    }
}

void FileList::addFile(DirectoryItem* newItem)
{
    int year = rand() % 20 + 2003;
    int month = rand() % 12;
    int day = rand() % 30;

    string fileSize = newItem->getType() == ZL_ITEM_TYPE_FOLDER
                        ? "-"
                        : Util::getFormattedFilesize(newItem->getSize(), 1);

    wxVector<wxVariant> data;
    data.push_back(wxVariant(newItem->getName()));
    data.push_back(wxVariant(fileSize));
    data.push_back(wxVariant(fmt::format("{}.{}.{}.", year, month, day))); // TODO

    this->wxControl->AppendItem(data);
}

void FileList::onItemDoubleClicked(wxDataViewEvent& event)
{
    wxDataViewModel* itemData = event.GetModel();

    wxVariant filenameVariant;
    itemData->GetValue(filenameVariant, event.GetItem(), 0);
    wxString filename = filenameVariant.GetString();

    // Folders
    if (filename.EndsWith("/")) {
        filename = filename.SubString(0, filename.length() - 1);

        string newPath = fmt::format("{}/{}", this->currentPath, filename.ToStdString());
        newPath = Util::normalizePath(newPath);

        this->loadPath(newPath);
    }

    // File
    else {
        std::cout << "Opening file: " << filename << std::endl;
    }
}