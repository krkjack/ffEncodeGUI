#ifndef DIALOGMESSAGES_H
#define DIALOGMESSAGES_H

//(*Headers(DialogMessages)
#include <wx/dialog.h>
//*)

class DialogMessages: public wxDialog
{
	public:

		DialogMessages(wxWindow* parent,wxWindowID id=wxID_ANY,const wxPoint& pos=wxDefaultPosition,const wxSize& size=wxDefaultSize);
		virtual ~DialogMessages();

		//(*Declarations(DialogMessages)
		//*)

	protected:

		//(*Identifiers(DialogMessages)
		//*)

	private:

		//(*Handlers(DialogMessages)
		void OnButton1Click(wxCommandEvent& event);
		//*)

		DECLARE_EVENT_TABLE()
};

#endif
