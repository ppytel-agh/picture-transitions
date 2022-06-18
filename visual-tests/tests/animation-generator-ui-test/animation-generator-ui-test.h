#pragma once

#include "../../abstract-visual-test.h"
#include <functional>
#include <AnimationGeneratorMainFrame.h>
#include <string>
#include <sstream>

class AnimationGeneratorUITest : public AbstractVisualTest {
public:
	void initializeUI(wxFrame* parentFrame) override;
};