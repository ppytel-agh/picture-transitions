#pragma once

#include "animation-generator-ui.h"
#include "model.h"
#include "wxWidgets-buffer-converter.h"
#include <string>

class AbstractLoadKeyframeAction {
public:
	AbstractLoadKeyframeAction(Model&);
	void operator()(AnimationGeneratorUI&, std::string);
protected:
	virtual Size getSecondKeyframeSize() = 0;
	virtual void putIntoModel(GraphicsBuffer&) = 0;
	virtual void displayInPreview(AnimationGeneratorUI&, wxImage&) = 0;
	Model& model;
};