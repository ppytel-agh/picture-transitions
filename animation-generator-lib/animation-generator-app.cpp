#include "animation-generator-app.h"

bool AnimationGeneratorApp::OnInit()
{
	this->animationGeneratorUI = new AnimationGeneratorUI(NULL, );	
	return true;
}

int AnimationGeneratorApp::OnExit()
{
	delete this->animationGeneratorUI;
	return 0;
}