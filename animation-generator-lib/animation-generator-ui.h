#pragma once

#include <string>
#include <vector>
#include <functional>
#include <wx/wx.h>
#include "animation_generator_main_frame.h"

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

