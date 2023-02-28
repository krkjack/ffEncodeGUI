/***************************************************************
 * Name:      ffEncodeGUIApp.cpp
 * Purpose:   Code for Application Class
 * Author:    KJ ()
 * Created:   2021-07-03
 * Copyright: KJ ()
 * License:
 **************************************************************/

#include "ffEncodeGUIApp.h"
//(*AppHeaders
#include "ffEncodeGUIMain.h"
#include <wx/image.h>
//*)

IMPLEMENT_APP(ffEncodeGUIApp);

bool ffEncodeGUIApp::OnInit()
{
    //(*AppInitialize
    bool wxsOK = true;
    wxInitAllImageHandlers();
    if ( wxsOK )
    {
    ffEncodeGUIFrame* Frame = new ffEncodeGUIFrame(0);
    Frame->Show();
    SetTopWindow(Frame);
    }
    //*)
    return wxsOK;
}
