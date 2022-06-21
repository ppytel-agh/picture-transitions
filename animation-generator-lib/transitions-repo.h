#pragma once

#include "transitions-manager.h"

#include "slide-transition-filler.h"
#include "central-scaling-transition-filler.h"
#include "letter-rotation-transition-filler.h"
#include "brightness-change-transition-filler.h"
#include "blend-transition-filler.h"

class TransitionsRepo {
public:
	TransitionsRepo();
	~TransitionsRepo();
	TransitionsManager& getAvailableTransitions();
private:
	TransitionsManager* availableTransitions;
	std::vector<AnimationFrameFillerInterface*>* fillers;
};