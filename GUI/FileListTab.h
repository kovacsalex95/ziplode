#ifndef ZIPLODE_FILELISTTAB_H
#define ZIPLODE_FILELISTTAB_H

#include "TabViewTab.h"
#include "FileList.h"


class FileListTab : public TabViewTab {
    public:
        FileListTab(string tabName, bool selected = false);

    private:
        FileList* file_list;
};


#endif //ZIPLODE_FILELISTTAB_H
