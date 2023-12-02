#include "app.h"
#include "mainframe.h"
#include<wx/wx.h>

wxIMPLEMENT_APP(app);

bool app::onInit() {
	mainframe* mainFrame = new mainframe("C++ GUI");
	mainFrame->SetClientSize(800, 600);
	mainFrame->Center();
	mainFrame->Show();
	
	return true;
}
