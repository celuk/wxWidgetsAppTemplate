#ifndef MYAPP_H
#define MYAPP_H

#include <wx/app.h>

class myApp : public wxApp
{
    public:
        virtual bool OnInit();
};

DECLARE_APP(myApp);

#endif
