#include "blend-transition-filler.h"

BlendTransitionFiller::BlendTransitionFiller(): blitter(), blender({})
{
}

void BlendTransitionFiller::fillAnimationFrame(const GraphicsBuffer& startKeyframe, const GraphicsBuffer& endKeyframe, GraphicsBuffer& filledFrame, float frameNorm)
{
	this->blitter.blitTo(startKeyframe, filledFrame, { 0.0f, 0.0f });
	this->blender.blendIntoBuffer(filledFrame, endKeyframe, 1.0f - frameNorm);
}
