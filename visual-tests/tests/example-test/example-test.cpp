#include "example-test.h"

void ExampleTest::initializeUI(wxFrame* parentFrame) {	
	Misc misc;
	int miscVal = misc.action();
	wxFrame* simpleFrame = new wxFrame(parentFrame, wxID_ANY, "przykladowy test");
	simpleFrame->SetSizeHints(wxDefaultSize, wxDefaultSize);
	wxBoxSizer* mainSizer;
	mainSizer = new wxBoxSizer(wxHORIZONTAL);
	std::stringstream ss;
	ss << "misc val " << miscVal;
	wxStaticText* text = new wxStaticText(simpleFrame, wxID_ANY, ss.str());
	mainSizer->Add(text);
	simpleFrame->SetSizer(mainSizer);
	simpleFrame->Layout();
	simpleFrame->Show();
}