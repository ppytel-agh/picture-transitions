#pragma once

#include "animation-frame-filler-interface.h"
#include "buffer-scaler.h"
#include "normalized-blit.h"

class RingTransitionFiller : public AnimationFrameFillerInterface {
public:
	// Inherited via AnimationFrameFillerInterface
	virtual void fillAnimationFrame(const GraphicsBuffer& startKeyframe, const GraphicsBuffer& endKeyframe, GraphicsBuffer& filledFrame, float frameNorm) override;
private:
	BufferScaler scaler;
	NormalizedBlit blitter;
};