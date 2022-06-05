#pragma once

#include <wx/wx.h>
#include "mainFrame.h"

class AnimationGeneratorApp : public wxApp {
public:
	virtual bool OnInit();
	virtual int OnExit();
};