#include "FileList.h"

FileList::FileList(StateManager* stateManager, wxFrame* frame) : StateUser(stateManager)
{
    this->wxControl = new wxDataViewListCtrl(frame, wxID_ANY, wxDefaultPosition, wxDefaultSize, wxDV_MULTIPLE | wxDV_ROW_LINES | wxDV_VERT_RULES);

    this->wxControl->AppendTextColumn("Name", wxDATAVIEW_CELL_INERT, wxCOL_WIDTH_AUTOSIZE)->SetMinWidth(200);
    this->wxControl->AppendTextColumn("Size", wxDATAVIEW_CELL_INERT, wxCOL_WIDTH_AUTOSIZE);
    this->wxControl->AppendTextColumn("Modified", wxDATAVIEW_CELL_INERT, wxCOL_WIDTH_AUTOSIZE);

    this->wxControl->SetContainingSizer(frame->GetSizer());
    this->wxControl->Bind(wxEVT_DATAVIEW_SELECTION_CHANGED, &FileList::onItemSelectionChanged, this, wxID_ANY);
    this->wxControl->Bind(wxEVT_DATAVIEW_ITEM_ACTIVATED, &FileList::onItemDoubleClicked, this, wxID_ANY);

    content = new FileSystemDirectoryContent(stateManager);
    content->load();
}

wxDataViewListCtrl* FileList::getControl()
{
    return this->wxControl;
}

void FileList::loadPath()
{
    vector<DirectoryItem*> items = content->getItems();

    this->wxControl->DeleteAllItems();

    for (int i=0; i<items.size(); i++) {

        this->addFile(items[i]);
    }
}

void FileList::addFile(DirectoryItem* newItem)
{
    string fileSize = newItem->getType() == ZL_ITEM_TYPE_FOLDER
                        ? "-"
                        : Util::getFormattedFilesize(newItem->getSize(), 1);

    wxVector<wxVariant> data;
    data.push_back(wxVariant(newItem->getName()));
    data.push_back(wxVariant(fileSize));
    data.push_back(wxVariant(Util::getFormattedDateTime(newItem->getModifiedAt())));

    this->wxControl->AppendItem(data);
}

void FileList::onSignalReceived(int signalID, Signal *signal)
{
    switch (signalID) {
        case ZL_EVENT_PATH_CHANGED:
            content->load();
            this->stateManager->getSelectionManager()->clearSelection();
            break;

        case ZL_EVENT_CONTENT_LOADED:
            loadPath();
            break;
    }
}

vector<string> FileList::getSelectedPaths()
{
    vector<string> paths;
    const vector<DirectoryItem*> items = content->getItems();

    if (this->wxControl->GetItemCount() != items.size()) {
        return paths;
    }

    for (int i = 0; i < items.size(); i++) {
        if (this->wxControl->IsRowSelected(i)) {
            paths.push_back(items[i]->getName());
        }
    }

    return paths;
}

void FileList::onItemSelectionChanged(wxDataViewEvent& event)
{
    this->stateManager->getSelectionManager()->setSelection(this->getSelectedPaths());
}

void FileList::onItemDoubleClicked(wxDataViewEvent& event)
{
    wxDataViewModel* itemData = event.GetModel();

    wxVariant filenameVariant;
    itemData->GetValue(filenameVariant, event.GetItem(), 0);
    wxString filename = filenameVariant.GetString();

    // Folders
    if (filename.EndsWith("/"))
    {
        if (filename == "../") {
            this->stateManager->getPathManager()->goUp();
        }

        else {
            this->stateManager->getPathManager()->goToSubFoler(filename);
        }

        content->load();
    }

    // File
    else
    {
        std::cout << "Opening file: " << filename << std::endl;
    }
}