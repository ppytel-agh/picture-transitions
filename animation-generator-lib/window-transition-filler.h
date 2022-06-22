#pragma once

#include "animation-frame-filler-interface.h"

#include "normalized-blit.h"
#include "buffer-scaler.h"
#include "buffer-space-normalizer.h"

class WindowTransitionFiller :public AnimationFrameFillerInterface {
public:
	WindowTransitionFiller();
	// Inherited via AnimationFrameFillerInterface
	virtual void fillAnimationFrame(const GraphicsBuffer& startKeyframe, const GraphicsBuffer& endKeyframe, GraphicsBuffer& filledFrame, float frameNorm) override;
private:
	NormalizedBlit blitter;
	BufferScaler scaler;
};