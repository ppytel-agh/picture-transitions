#pragma once

#include <wx/wx.h>
#include "animation_generator_main_frame.h"

class AnimationGeneratorApp : public wxApp
{
public:
	virtual bool OnInit();
	virtual int OnExit();
private:
	AnimationGeneratorMainFrame* mainFrame;
};