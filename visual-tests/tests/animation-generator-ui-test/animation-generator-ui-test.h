#pragma once

#include "../../abstract-visual-test.h"
#include <functional>
#include <animation-generator-ui.h>
#include <string>
#include <sstream>
#include "startkeyframe.h"
#include "endkeyframe.h"
#include "interframe.h"

class AnimationGeneratorUITest : public AbstractVisualTest {
public:
	void initializeUI(wxFrame* parentFrame) override;
};