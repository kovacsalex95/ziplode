#include "Main.h"

bool ZiplodeApp::OnInit()
{
    WindowMain *frame = new WindowMain();
    frame->Show();
    return true;
}

wxIMPLEMENT_APP(ZiplodeApp);
