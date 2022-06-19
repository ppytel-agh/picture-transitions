#pragma once

#include "animation-generator-ui.h"
#include "model.h"
#include "wxWidgets-buffer-converter.h"

class FramePreviewAction {
public:
	FramePreviewAction(Model&);
	void operator()(AnimationGeneratorUI&, unsigned int, unsigned int);
private:
	Model& model;
};
