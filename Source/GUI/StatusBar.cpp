#include "StatusBar.h"

StatusBar::StatusBar(wxFrame *frame)
{
    wxControl = frame->CreateStatusBar();
}