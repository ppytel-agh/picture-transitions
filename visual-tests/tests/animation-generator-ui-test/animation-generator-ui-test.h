#pragma once

#include "../../abstract-visual-test.h"
#include <functional>
#include <animation_generator_main_frame.h>
#include <string>
#include <sstream>

class AnimationGeneratorUITest : public AbstractVisualTest {
public:
	void initializeUI(wxFrame* parentFrame) override;
};