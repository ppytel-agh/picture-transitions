#pragma once

#include "animation-generator-ui.h"
#include "model.h"

class ResetAction {
public:
	ResetAction(Model&);
	void operator()(AnimationGeneratorUI&);
private:
	Model& model;
};