#include "animation-generator-app.h"

bool AnimationGeneratorApp::OnInit() {
	mainFrame* frame = new mainFrame(NULL);
	frame->Show(true);
	SetTopWindow(frame);
	return true;
}

int AnimationGeneratorApp::OnExit() {
	return 0;
}