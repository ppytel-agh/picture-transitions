#include "visual-tests-app.h"

bool VisualTestsApp::OnInit() {
	wxFrame* mainFrame = new wxFrame(NULL, -1, "Visual Tests");
	mainFrame->Show(true);
	SetTopWindow(mainFrame);
	return true;
}

int VisualTestsApp::OnExit() {
	return 0;
}