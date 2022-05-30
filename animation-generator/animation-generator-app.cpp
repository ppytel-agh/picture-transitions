#include "animation-generator-app.h"

bool AnimationGeneratorApp::OnInit() {
	wxFrame* mainFrame = new wxFrame(NULL, -1, "Animation Generator");
	mainFrame->Show(true);
	SetTopWindow(mainFrame);
	return true;
}

int AnimationGeneratorApp::OnExit() {
	return 0;
}