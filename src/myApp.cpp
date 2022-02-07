#include "myApp.h"
#include "myMain.h"

#include <wx/image.h>

bool myApp::OnInit()
{
    bool wxsOK = true;
    wxInitAllImageHandlers();
    if (wxsOK)
    {
    	myFrame* mainFrame = new myFrame(0);
    	mainFrame->Show();
    	SetTopWindow(mainFrame);
    }
    return wxsOK;
}

IMPLEMENT_APP(myApp);
