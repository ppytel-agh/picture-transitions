#pragma once

#include <string>
#include <optional>
#include <functional>

#include "animation-generator-app.h"

class AnimationGeneratorUI 
{
	Frame* ui;

public:
	AnimationGeneratorUI();

	void addMessage(wxFrame&, std::string&);
	void setStartKeyframePreview(wxFrame&, wxImage&);
	void setEndKeyframePreview(wxFrame&, wxImage&);
	void resetAction(wxFrame&);
	void generateAnimationAction(wxFrame&);
	void showPreviewAction(wxFrame&);
	void saveAnimationAction(wxFrame&);
};

