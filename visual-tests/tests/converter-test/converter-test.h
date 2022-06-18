#pragma once

#include "../../abstract-visual-test.h"
#include <wx/wx.h>
#include <wxWidgets-buffer-converter.h>

class ConverterTest : public AbstractVisualTest {
public:


	// Inherited via AbstractVisualTest
	virtual void initializeUI(wxFrame* parentFrame) override;

};