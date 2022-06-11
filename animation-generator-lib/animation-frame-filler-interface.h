#pragma once

#include "graphics-buffer.h"

class AnimationFrameFillerInterface {
public:
	virtual void fillAnimationFrame(const GraphicsBuffer& startKeyframe, const GraphicsBuffer& endKeyframe, GraphicsBuffer& filledFrame, float frameNorm) = 0;
};