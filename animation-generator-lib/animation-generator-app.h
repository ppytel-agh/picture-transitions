#pragma once

#include <wx/wx.h>
#include "animation-generator-ui.h"

class AnimationGeneratorApp : public wxApp
{
public:
	virtual bool OnInit();
	virtual int OnExit();
private:
	AnimationGeneratorUI* animationGeneratorUI;
};