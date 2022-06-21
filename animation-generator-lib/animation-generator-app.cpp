#include "animation-generator-app.h"

AnimationGeneratorApp::AnimationGeneratorApp() : wxApp(), actionsRepo(this->model, this->animationGenerator, this->transitionsRepository.getAvailableTransitions())
{
}

bool AnimationGeneratorApp::OnInit()
{
	AnimationGeneratorUIActions actions{};
	this->mainFrame = new AnimationGeneratorMainFrame(nullptr, this->transitionsRepository.getAvailableTransitions().getTransitionNames(), this->actionsRepo.getActions());
	this->mainFrame->Show(true);
	SetTopWindow(this->mainFrame);
	return true;
}

int AnimationGeneratorApp::OnExit()
{
	return 0;
}