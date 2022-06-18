#pragma once

#include "abstract-visual-test.h"
#include <simple-animation-generator.h>
#include <generate-animation-simple.h>
#include <model.h>

class AnimGeneratorTest : public AbstractVisualTest {
public:


	// Inherited via AbstractVisualTest
	virtual void initializeUI(wxFrame* parentFrame) override;

};