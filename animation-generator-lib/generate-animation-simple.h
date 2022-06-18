#pragma once

#include "norm-calc.h"
#include "generate-animation-interface.h"
#include "animation-generator-ui.h"
#include "wxWidgets-buffer-converter.h"
#include "transitions-manager.h"
#include "model.h"
#include "animation-generator-ui.h"
#include <vector>

class GenerateAnimationSimple {
public:
	GenerateAnimationSimple(GenerateAnimationInterface&, Model&, TransitionsManager&, AnimationGeneratorUI&);
	void operator()(AnimationGeneratorUI& ui, unsigned int transitionId, unsigned int numberOfFrames);
private:
	GenerateAnimationInterface& animationGenerator;
	Model& model;
	TransitionsManager& transitionsManager;
};