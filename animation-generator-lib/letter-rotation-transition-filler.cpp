#include "letter-rotation-transition-filler.h"

const float LetterRotationTransitionFiller::pi = 3.1416f;

LetterRotationTransitionFiller::LetterRotationTransitionFiller(bool rotateAgainstYAxis) : rotateAgainstYAxis(rotateAgainstYAxis)
{
}

void LetterRotationTransitionFiller::fillAnimationFrame(const GraphicsBuffer& startKeyframe, const GraphicsBuffer& endKeyframe, GraphicsBuffer& filledFrame, float frameNorm)
{
	if (this->rotateAgainstYAxis) {
		if (frameNorm < 0.5f) {
			float scaleX = cos(LetterRotationTransitionFiller::pi * frameNorm);
			GraphicsBuffer scaledFrame = this->scaler.scaleBuffer(startKeyframe, scaleX, 1.0f);
			this->blitter.blitTo(scaledFrame, filledFrame, { 0.0f, 0.0f });
		}
		else {
			float scaleX = cos(LetterRotationTransitionFiller::pi * (frameNorm-1.0f));
			GraphicsBuffer scaledFrame = this->scaler.scaleBuffer(endKeyframe, scaleX, 1.0f);
			this->blitter.blitTo(scaledFrame, filledFrame, { 0.0f, 0.0f });
		}
	}
	else {
		if (frameNorm < 0.5f) {
			float scaleY = cos(LetterRotationTransitionFiller::pi * frameNorm);
			GraphicsBuffer scaledFrame = this->scaler.scaleBuffer(startKeyframe, 1.0f, scaleY);
			this->blitter.blitTo(scaledFrame, filledFrame, { 0.0f, 0.0f });
		}
		else {
			float scaleY = cos(LetterRotationTransitionFiller::pi * (frameNorm - 1.0f));
			GraphicsBuffer scaledFrame = this->scaler.scaleBuffer(endKeyframe, 1.0f, scaleY);
			this->blitter.blitTo(scaledFrame, filledFrame, { 0.0f, 0.0f });
		}
	}
}
