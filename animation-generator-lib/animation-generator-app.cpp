#include "animation-generator-app.h"

bool AnimationGeneratorApp::OnInit()
{
	AnimationGeneratorUIActions actions{};
	this->mainFrame = new AnimationGeneratorMainFrame(nullptr, { L"placeholder ¹¿" }, actions);
	this->mainFrame->Show(true);
	SetTopWindow(this->mainFrame);
	return true;
}

int AnimationGeneratorApp::OnExit()
{
	return 0;
}