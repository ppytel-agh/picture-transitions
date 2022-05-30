#include "example-test.h"

void ExampleTest::initializeUI(wxFrame* parentFrame) {
	wxFrame* simpleFrame = new wxFrame(parentFrame, wxID_ANY, "przykladowy test");
	simpleFrame->Show();
}