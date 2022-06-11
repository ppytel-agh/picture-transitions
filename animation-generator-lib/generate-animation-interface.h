#pragma once

#include <vector>
#include "graphics-buffer.h"

class GenerateAnimationInterface {
public:
	virtual std::vector<GraphicsBuffer> generateAnimation(const GraphicsBuffer& startKeyframe, const GraphicsBuffer& endKeyframe, AnimationFrameFillerInterface& frameFiller, Size animationFrameSize, std::vector<float> frameNormsSeries, Pixel animationBackgroundColour = {}) = 0;
};