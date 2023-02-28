#include "DialogMessages.h"

//(*InternalHeaders(DialogMessages)
#include <wx/intl.h>
#include <wx/string.h>
//*)

//(*IdInit(DialogMessages)
const long DialogMessages::ID_BUTTON1 = wxNewId();
//*)

BEGIN_EVENT_TABLE(DialogMessages,wxDialog)
	//(*EventTable(DialogMessages)
	//*)
END_EVENT_TABLE()

DialogMessages::DialogMessages(wxWindow* parent,wxWindowID id,const wxPoint& pos,const wxSize& size)
{
	//(*Initialize(DialogMessages)
	Create(parent, id, wxEmptyString, wxDefaultPosition, wxDefaultSize, wxDEFAULT_DIALOG_STYLE, _T("id"));
	SetClientSize(wxDefaultSize);
	Move(wxDefaultPosition);
	Button1 = new wxButton(this, ID_BUTTON1, _("Label"), wxPoint(224,256), wxDefaultSize, 0, wxDefaultValidator, _T("ID_BUTTON1"));
	//*)
}

DialogMessages::~DialogMessages()
{
	//(*Destroy(DialogMessages)
	//*)
}

