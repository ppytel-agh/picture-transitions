#pragma once

#include "generate-animation-interface.h"
#include "norm-calc.h"

class SimpleAnimationGenerator: public GenerateAnimationInterface {
public:


	// Inherited via GenerateAnimationInterface
	virtual void generateAnimation(const GraphicsBuffer& startKeyframe, const GraphicsBuffer& endKeyframe, AnimationFrameFillerInterface& frameFiller, Size animationFrameSize, std::vector<float> frameNormsSeries, std::function<void(unsigned int, unsigned int)> generatedFrameCallback, std::function<void(std::vector<GraphicsBuffer>)> generatedAnimationCallback, Pixel animationBackgroundColour = {}) override;

};