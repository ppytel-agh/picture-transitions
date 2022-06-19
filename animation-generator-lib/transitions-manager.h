#pragma once

#include <vector>
#include <string>
#include <utility>
#include <functional>
#include "animation-frame-filler-interface.h"

class EmptyTransitionFiller : public AnimationFrameFillerInterface {
public:
	void fillAnimationFrame(const GraphicsBuffer& startKeyframe, const GraphicsBuffer& endKeyframe, GraphicsBuffer& filledFrame, float frameNorm) override {
	}
};

class TransitionsManager {
public:
	TransitionsManager(std::vector<std::pair<std::wstring, AnimationFrameFillerInterface&>>);
	std::vector<std::wstring> getTransitionNames() const;
	bool transitionExists(unsigned int) const;
	AnimationFrameFillerInterface& getTransitionFiller(unsigned int);
	bool fillerIsEmpty(AnimationFrameFillerInterface& fillerToCheck);
private:
	EmptyTransitionFiller emptyFiller;
	std::vector<std::wstring> transitionNames;
	std::vector<std::reference_wrapper<AnimationFrameFillerInterface>> transitionFillers;
};