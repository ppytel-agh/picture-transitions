#include "visual-tests-app.h"

bool VisualTestsApp::OnInit() {
	VisualTestsManager testsManager;
	wxFrame* mainFrame = new VisualTestsFrame(testsManager.getTests(), testsManager.getNumberOfTests());
	mainFrame->Show(true);
	SetTopWindow(mainFrame);
	return true;
}

int VisualTestsApp::OnExit() {
	return 0;
}