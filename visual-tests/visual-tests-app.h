#pragma once

#include <wx/wx.h>
#include "visual-tests-manager.h"
#include "visual-tests-frame.h"

class VisualTestsApp : public wxApp {
public:
	virtual bool OnInit();
	virtual int OnExit();
};