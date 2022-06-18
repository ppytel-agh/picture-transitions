#pragma once

#include <vector>
#include <functional>
#include "graphics-buffer.h"
#include "animation-frame-filler-interface.h"

class GenerateAnimationInterface {
public:
	virtual std::vector<GraphicsBuffer> generateAnimation(const GraphicsBuffer& startKeyframe, const GraphicsBuffer& endKeyframe, AnimationFrameFillerInterface& frameFiller, Size animationFrameSize, std::vector<float> frameNormsSeries, std::function<void(unsigned int, unsigned int)> generatedFrameCallback, std::function<void(std::vector<GraphicsBuffer>)> generatedAnimationCallback, Pixel animationBackgroundColour = {}) = 0;
};