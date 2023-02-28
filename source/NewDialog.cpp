#include "NewDialog.h"

//(*InternalHeaders(NewDialog)
#include <wx/intl.h>
#include <wx/string.h>
//*)

//(*IdInit(NewDialog)
const long NewDialog::ID_BUTTON1 = wxNewId();
//*)

BEGIN_EVENT_TABLE(NewDialog,wxDialog)
	//(*EventTable(NewDialog)
	//*)
END_EVENT_TABLE()

NewDialog::NewDialog(wxWindow* parent,wxWindowID id,const wxPoint& pos,const wxSize& size)
{
	//(*Initialize(NewDialog)
	Create(parent, id, wxEmptyString, wxDefaultPosition, wxDefaultSize, wxDEFAULT_DIALOG_STYLE, _T("id"));
	SetClientSize(wxSize(280,68));
	Move(wxDefaultPosition);
	Button1 = new wxButton(this, ID_BUTTON1, _("Label"), wxPoint(120,24), wxDefaultSize, 0, wxDefaultValidator, _T("ID_BUTTON1"));
	//*)
}

NewDialog::~NewDialog()
{
	//(*Destroy(NewDialog)
	//*)
}

