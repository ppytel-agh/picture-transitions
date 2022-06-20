#pragma once

#include "../abstract-visual-test.h"

class NormalizedBlitTest : public AbstractVisualTest {
public:
	// Inherited via AbstractVisualTest
	virtual void initializeUI(wxFrame* parentFrame) override;
};