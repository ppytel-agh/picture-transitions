#include "animation-generator-app.h"

bool AnimationGeneratorApp::OnInit()
{
	AnimationGeneratorUIActions actions{};
	this->mainFrame = new AnimationGeneratorMainFrame(nullptr, { "dupa" }, actions);
	this->mainFrame->Show(true);
	SetTopWindow(this->mainFrame);
	return true;
}

int AnimationGeneratorApp::OnExit()
{
	delete this->mainFrame;
	return 0;
}