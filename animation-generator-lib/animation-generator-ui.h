#pragma once

#include "animation-generator-app.h"

class AnimationGeneratorUI 
{
	Frame* ui;

public:
	AnimationGeneratorUI();

	void addMessage(std::string&);
	void setStartKeyframePreview(wxImage&);
	void setEndKeyframePreview(wxImage&);
	void resetAction();
	void generateAnimationAction();
	void showPreviewAction();
	void saveAnimationAction();
};

