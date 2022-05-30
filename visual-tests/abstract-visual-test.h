#pragma once

#include <wx/wx.h>

class AbstractVisualTest {
public:
	virtual void initializeUI(wxFrame* parentFrame) = 0;
};