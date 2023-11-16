#include "Main.h"

bool ZiplodeApp::OnInit()
{
    StateManager *stateManager = new StateManager();

    WindowMain *frame = new WindowMain(stateManager);
    frame->Show();
    return true;
}

wxIMPLEMENT_APP(ZiplodeApp);
