#include "mainframe.h"
#include <wx/wx.h>

mainframe::mainframe(const wxString& title) : wxFrame(nullptr, wxID_ANY, title) {
	
	wxPanel* panel = new wxPanel(this);
	
	wxButton* button = new wxButton(panel, wxID_ANY, "button", wxPoint(150, 50), wxSize(100, 35));

	wxCheckBox* checkbox = new wxCheckBox(panel, wxID_ANY, "checkbox", wxPoint(550, 55));

	wxStaticText* statictext = new wxStaticText(panel, wxID_ANY, "statictext - not editable", wxPoint(120,150) );

	wxTextCtrl* textctrl = new wxTextCtrl(panel, wxID_ANY, "textctrl - editable", wxPoint(500, 145), wxSize(200, -1));

	wxSlider* slider = new wxSlider(panel, wxID_ANY, 25 , 0, 100, wxPoint(100, 250), wxSize(200, -1));

	wxGauge* gauge = new wxGauge(panel, wxID_ANY, 100, wxPoint(500, 255), wxSize(200, -1));
	gauge->SetValue(50);

	wxArrayString choices; 
	choices.Add("item A");
	choices.Add("item B");
	choices.Add("item C");

	wxChoice* choice = new wxChoice(panel, wxID_ANY, wxPoint(150, 375), wxSize(100, -1), choices);
	choice->Select(0);

	//wxSpinCtrl* SpinCtrl = new wxSpinCtrl(panel, wxID_ANY, "", wxPoint(550, 375), wxSize(100, -1));
	
}
