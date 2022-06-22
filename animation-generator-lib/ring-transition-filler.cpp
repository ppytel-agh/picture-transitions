#include "ring-transition-filler.h"

void RingTransitionFiller::fillAnimationFrame(const GraphicsBuffer& startKeyframe, const GraphicsBuffer& endKeyframe, GraphicsBuffer& filledFrame, float frameNorm)
{
	const float minScale = 0.5f;
	float diff = 1.0f - minScale;
	float z = sin(frameNorm * 3.1416f);	
	float scale = 1.0f - diff * z;
	GraphicsBuffer scaledStart = this->scaler.scaleBuffer(startKeyframe, scale, scale);
	GraphicsBuffer scaledEnd = this->scaler.scaleBuffer(endKeyframe, scale, scale);
	float startX = 2.0f * frameNorm;
	float endX = -2.0f + startX;
	this->blitter.blitTo(scaledStart, filledFrame, { startX, 0.0f });
	this->blitter.blitTo(scaledEnd, filledFrame, { endX, 0.0f });
}
