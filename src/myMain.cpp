#include "myApp.h"
#include "myMain.h"

#include <wx/display.h>
#include <wx/msgdlg.h>

#define SCREEN_RATIO 0.9

// wxWidgets Build Info
enum wxbuildinfoformat {
    short_f, long_f
};

wxString wxbuildinfo(wxbuildinfoformat format)
{
    wxString wxbuild(wxVERSION_STRING);

    if (format == long_f )
    {
        #if defined(__WXMSW__)
                wxbuild << _("-Windows");
        #elif defined(__UNIX__)
                wxbuild << _("-Linux");
        #endif

        #if wxUSE_UNICODE
                wxbuild << _("-Unicode build");
        #else
                wxbuild << _("-ANSI build");
        #endif
    }

    return wxbuild;
}
// End of wxWidgets Build Info

// File Menu Items
const long myFrame::idMenuQuit = wxNewId();
// End of File Menu Items

// Help Menu Items
const long myFrame::idMenuAbout = wxNewId();
// End of Help Menu Items

const long myFrame::idStatusBar = wxNewId();


BEGIN_EVENT_TABLE(myFrame, wxFrame)
    EVT_MENU(idMenuQuit, myFrame::onQuit)
    EVT_MENU(idMenuAbout, myFrame::onAbout)
END_EVENT_TABLE()


myFrame::myFrame(wxWindow* parent, wxWindowID id)
{
    Create(parent, wxID_ANY, wxEmptyString, wxDefaultPosition, wxDefaultSize, wxDEFAULT_FRAME_STYLE, _("wxID_ANY"));

    wxDisplay display(wxDisplay::GetFromWindow(this));
    wxRect activeScreenRect = display.GetClientArea();

    this->SetClientSize(wxSize(SCREEN_RATIO * activeScreenRect.GetWidth(), SCREEN_RATIO * activeScreenRect.GetHeight()));

    this->CenterOnScreen();

    topMenuBar = new wxMenuBar();

    // File Menu
    fileMenu = new wxMenu();
    topMenuBar->Append(fileMenu, _("&File"));

    quitItem = new wxMenuItem(fileMenu, idMenuQuit, _("Quit\tAlt-F4"), _("Quit the application"), wxITEM_NORMAL);
    fileMenu->Append(quitItem);
    // End of File Menu

    // Help Menu
    helpMenu = new wxMenu();
    topMenuBar->Append(helpMenu, _("Help"));

    aboutItem = new wxMenuItem(helpMenu, idMenuAbout, _("About\tF1"), _("Show info about this application"), wxITEM_NORMAL);
    helpMenu->Append(aboutItem);
    // End of Help Menu

    SetMenuBar(topMenuBar);

    statusBar = new wxStatusBar(this, idStatusBar, wxSTB_DEFAULT_STYLE, _("idStatusBar"));
    int __wxStatusBarWidths_1[1] = { -1 };
    int __wxStatusBarStyles_1[1] = { wxSB_NORMAL };
    statusBar->SetFieldsCount(1, __wxStatusBarWidths_1);
    statusBar->SetStatusStyles(1, __wxStatusBarStyles_1);
    SetStatusBar(statusBar);
}

myFrame::~myFrame()
{
    this->Destroy();
}

void myFrame::onQuit(wxCommandEvent& event)
{
    Close();
}

void myFrame::onAbout(wxCommandEvent& event)
{
    wxMessageBox(wxbuildinfo(long_f), _("myApp"));
}

