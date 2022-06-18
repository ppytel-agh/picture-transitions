#pragma once

#include <vector>
#include <string>
#include <utility>
#include "animation-frame-filler-interface.h"

class TransitionsManager {
public:
	TransitionsManager(std::vector<std::pair<std::wstring, AnimationFrameFillerInterface*>>);
	std::vector<std::wstring> getTransitionNames() const;
	bool transitionExists(unsigned int) const;
	AnimationFrameFillerInterface* getTransitionFiller(unsigned int) const;
private:
	std::vector<std::wstring> transitionNames;
	std::vector<AnimationFrameFillerInterface*> transitionFillers;
};