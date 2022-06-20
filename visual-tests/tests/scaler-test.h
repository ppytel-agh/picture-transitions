#pragma once

#include "../abstract-visual-test.h"

class ScalerTest : public AbstractVisualTest {
public:

	// Inherited via AbstractVisualTest
	virtual void initializeUI(wxFrame* parentFrame) override;
};