#pragma once

#include "../../abstract-visual-test.h"
#include <animation-generator-app.h>
#include <misc.h>
#include <sstream>

class ExampleTest: public AbstractVisualTest {
public:
	void initializeUI(wxFrame* parentFrame) override;
};