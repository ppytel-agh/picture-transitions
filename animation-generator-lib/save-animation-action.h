#pragma once

#include "animation-generator-ui.h"
#include "model.h"
#include "wxWidgets-buffer-converter.h"
#include <sstream>

class SaveAnimationAction {
public:
	SaveAnimationAction(Model&);
	void operator()(AnimationGeneratorUI&, std::string saveDir);
private:
	Model& model;
};