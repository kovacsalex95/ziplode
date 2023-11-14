#include "FileList.h"

FileList::FileList(wxFrame* frame)
{
    this->wxControl = new wxDataViewListCtrl(frame, wxID_ANY, wxDefaultPosition, wxDefaultSize, wxDV_MULTIPLE | wxDV_ROW_LINES | wxDV_VERT_RULES);

    this->wxControl->AppendTextColumn("Name", wxDATAVIEW_CELL_INERT, wxCOL_WIDTH_AUTOSIZE);
    this->wxControl->AppendTextColumn("Size", wxDATAVIEW_CELL_INERT, wxCOL_WIDTH_AUTOSIZE);
    this->wxControl->AppendTextColumn("Last modified", wxDATAVIEW_CELL_INERT, wxCOL_WIDTH_AUTOSIZE);

    this->wxControl->SetContainingSizer(frame->GetSizer());

    wxString documentsDir = wxStandardPaths::Get().GetDocumentsDir();
    content = new FileSystemDirectoryContent();
    content->load(documentsDir.c_str());

    vector<DirectoryItem*> items = content->getItems();
    for (int i=0; i<items.size(); i++) {
        int year = rand() % 20 + 2003;
        int month = rand() % 12;
        int day = rand() % 30;

        this->addFile(items[i]->getName(), items[i]->getFormattedSize(1), fmt::format("{}.{}.{}.", year, month, day));
    }
}

wxDataViewListCtrl* FileList::getControl()
{
    return this->wxControl;
}

void FileList::generateDummies(int dummies)
{
//    for (int i = 0; i < dummies; i++) {
//        unsigned long filesize = (rand() % 99999999) * 1000 + (rand() % 1000);
//        int year = rand() % 20 + 2003;
//        int month = rand() % 12;
//        int day = rand() % 30;
//        int extensionIndex = rand() % 11;
//        string extensions[] = {"zip", "rar", "bmp", "jpeg", "exe", "iso", "tiff", "dll", "h", "cpp", "html"};
//        string extension = extensions[extensionIndex];
//
//        this->addFile(fmt::format("{} {}.{}", "File", i, extension), filesize, fmt::format("{}.{}.{}.", year, month, day));
//    }
}

void FileList::addFile(string name, string size, string lastModified)
{
    wxVector<wxVariant> data;
    data.push_back(wxVariant(name));
    data.push_back(wxVariant(size));
    data.push_back(wxVariant(lastModified)); // TODO

    this->wxControl->AppendItem(data);
}