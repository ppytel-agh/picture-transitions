#include "central-scaling-transition-filler.h"

CentralScalingTransitionFiller::CentralScalingTransitionFiller(bool b) : scaleStartKeyframe(b), blit(), scaler()
{
}

void CentralScalingTransitionFiller::fillAnimationFrame(const GraphicsBuffer& startKeyframe, const GraphicsBuffer& endKeyframe, GraphicsBuffer& filledFrame, float frameNorm)
{
	if (this->scaleStartKeyframe) {
		blit.blitTo(endKeyframe, filledFrame, { 0.0f, 0.0f });
		float scale = 1.0f - frameNorm;
		GraphicsBuffer scaledFrame = scaler.scaleBuffer(startKeyframe, scale, scale);
		blit.blitTo(scaledFrame, filledFrame, { 0.0f, 0.0f });
	}
	else {
		blit.blitTo(startKeyframe, filledFrame, { 0.0f, 0.0f });
		GraphicsBuffer scaledFrame = scaler.scaleBuffer(endKeyframe, frameNorm, frameNorm);
		blit.blitTo(scaledFrame, filledFrame, { 0.0f, 0.0f });
	}
}
