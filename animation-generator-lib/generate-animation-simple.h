#pragma once

#include "norm-calc.h"
#include "generate-animation-interface.h"
#include "animation-generator-ui.h"
#include "norm-calc.h"
#include "wx-widgets-buffer-converter.h"
#include "transitions-manager.h"
#include <vector>

class GenerateAnimationSimple {
public:
	GenerateAnimationSimple(GenerateAnimationInterface&, AnimationGeneratorModel&, TransitionsManager&);
	void operator()(AnimationGeneratorUI& ui, unsigned int transitionId, unsigned int numberOfFrames);
private:
	GenerateAnimationInterface& animationGenerator;
	AnimationGeneratorModel& model;
	TransitionsManager& transitionsManager;
};