#pragma once

#include <vector>
#include <functional>
#include "graphics-buffer.h"
#include "animation-frame-filler-interface.h"

class GenerateAnimationInterface {
public:
	virtual std::vector<GraphicsBuffer> generateAnimation(const GraphicsBuffer& startKeyframe, const GraphicsBuffer& endKeyframe, AnimationFrameFillerInterface& frameFiller, Size animationFrameSize, std::vector<float> frameNormsSeries, std::function<void(unsigned int frameNumber, unsigned int animationlength)> generatedFrameCallback, Pixel animationBackgroundColour = {}) = 0;
};