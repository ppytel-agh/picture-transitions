#include "animation-generator-app.h"

bool AnimationGeneratorApp::OnInit() 
{
	mainFrame* frame = new mainFrame(NULL);
	frame->Show(true);
	SetTopWindow(frame);
	return true;
}

int AnimationGeneratorApp::OnExit() 
{
	return 0;
}

void AnimationGeneratorApp::onReset(wxCommandEvent& event)
{
	// TODO: Implement onReset
}

void AnimationGeneratorApp::onLoadInitFrame(wxCommandEvent& event)
{
	// TODO: Implement onLoadInitFrame
}

void AnimationGeneratorApp::onLoadLastFrame(wxCommandEvent& event)
{
	// TODO: Implement onLoadLastFrame
}

void AnimationGeneratorApp::onTransitionChoice(wxCommandEvent& event)
{
	// TODO: Implement onTransitionChoice
}

void AnimationGeneratorApp::onFrameRateEnter(wxCommandEvent& event)
{
	// TODO: Implement onFrameRateEnter
}

void AnimationGeneratorApp::onGenerateFrame(wxCommandEvent& event)
{
	// TODO: Implement onGenerateFrame
}

void AnimationGeneratorApp::onScroll(wxScrollEvent& event)
{
	// TODO: Implement onScroll
}

void AnimationGeneratorApp::onAnimationSave(wxCommandEvent& event)
{
	// TODO: Implement onAnimationSave
}

