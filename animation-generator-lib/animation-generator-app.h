#pragma once

#include <wx/wx.h>
#include "AnimationGeneratorMainFrame.h"

class AnimationGeneratorApp : public wxApp
{
public:
	virtual bool OnInit();
	virtual int OnExit();
private:
	AnimationGeneratorMainFrame* mainFrame;
};