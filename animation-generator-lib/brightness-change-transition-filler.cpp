#include "brightness-change-transition-filler.h"

void BrightnessChangeTransitionFiller::fillAnimationFrame(const GraphicsBuffer& startKeyframe, const GraphicsBuffer& endKeyframe, GraphicsBuffer& filledFrame, float frameNorm)
{
	float brightnessNorm;
	if (frameNorm < 0.5f) {
		this->normalizedBlit.blitTo(startKeyframe, filledFrame, { 0.0f, 0.0f });
		brightnessNorm = (0.5f - frameNorm) * 2.0f;
	}
	else {
		this->normalizedBlit.blitTo(endKeyframe, filledFrame, { 0.0f, 0.0f });
		brightnessNorm = (frameNorm - 0.5f) * 2.0f;
	}
	this->brightnessChanger.changeBufferBrightness(filledFrame, brightnessNorm);
}
