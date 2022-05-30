#pragma once

#include "../../abstract-visual-test.h"

class ExampleTest: public AbstractVisualTest {
public:
	void initializeUI(wxFrame* parentFrame) override;
};