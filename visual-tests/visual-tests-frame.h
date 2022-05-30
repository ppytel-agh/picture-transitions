#pragma once

#include <wx/wx.h>
#include "visual-test-record.h"

class VisualTestsFrame : public wxFrame {
public:
	VisualTestsFrame(VisualTestRecord* tests, size_t noTests);
};