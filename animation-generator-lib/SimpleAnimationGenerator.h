#pragma once

#include "generate-animation-interface.h"
#include "norm-calc.h"

class SimpleAnimationGenerator: public GenerateAnimationInterface {
public:


	// Inherited via GenerateAnimationInterface
	virtual std::vector<GraphicsBuffer> generateAnimation(const GraphicsBuffer& startKeyframe, const GraphicsBuffer& endKeyframe, AnimationFrameFillerInterface& frameFiller, Size animationFrameSize, std::vector<float> frameNormsSeries, Pixel animationBackgroundColour) override;

};