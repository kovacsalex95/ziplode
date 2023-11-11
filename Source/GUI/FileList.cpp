#include "FileList.h"

FileList::FileList(wxFrame* frame)
{
    this->wxControl = new wxDataViewListCtrl(frame, wxID_ANY, wxDefaultPosition, wxDefaultSize, wxDV_MULTIPLE | wxDV_ROW_LINES | wxDV_VERT_RULES);

    this->wxControl->AppendTextColumn("Name", wxDATAVIEW_CELL_INERT, wxCOL_WIDTH_AUTOSIZE);
    this->wxControl->AppendTextColumn("Size", wxDATAVIEW_CELL_INERT, wxCOL_WIDTH_AUTOSIZE);
    this->wxControl->AppendTextColumn("Last modified", wxDATAVIEW_CELL_INERT, wxCOL_WIDTH_AUTOSIZE);

    this->wxControl->SetContainingSizer(frame->GetSizer());

    generateDummies(100);
}

wxDataViewListCtrl* FileList::getControl()
{
    return this->wxControl;
}

void FileList::generateDummies(int dummies)
{
    for (int i = 0; i < dummies; i++) {
        int filesize = rand() % 4096;
        int year = rand() % 20 + 2003;
        int month = rand() % 12;
        int day = rand() % 30;
        int extensionIndex = rand() % 11;
        string extensions[] = {"zip", "rar", "bmp", "jpeg", "exe", "iso", "tiff", "dll", "h", "cpp", "html"};
        string extension = extensions[extensionIndex];

        this->addFile(fmt::format("{} {}.{}", "File", i, extension), filesize, fmt::format("{}.{}.{}.", year, month, day));
    }
}

void FileList::addFile(string name, int size, string lastModified)
{
    string sizeStr = fmt::format("{} {}", size, "MB"); // TODO

    wxVector<wxVariant> data;
    data.push_back(wxVariant(name));
    data.push_back(wxVariant(sizeStr));
    data.push_back(wxVariant(lastModified)); // TODO

    this->wxControl->AppendItem(data);
}