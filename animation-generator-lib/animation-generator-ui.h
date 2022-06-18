#pragma once

#include <string>
#include <vector>
#include <functional>
#include <wx/wx.h>
#include "AnimationGeneratorMainFrame.h"

class AnimationGeneratorUI
{
public:
	AnimationGeneratorUI(AnimationGeneratorMainFrame& mainFrame);
	void setStartKeyframePreview(const wxImage&);
	void setEndKeyframePreview(const wxImage&);
	void addMessage(std::string);
	void setAnimationFramePreview(const wxImage&);
	void setAnimationFrameCountSlider(unsigned int);
private:
	AnimationGeneratorMainFrame& mainFrame;
};

