#include "slide-transition-filler.h"

SliderTransitionFiller::SliderTransitionFiller(bool horizontal, bool negativeToPositive): horizontal(horizontal), negativeToPositive(negativeToPositive)
{
}

void SliderTransitionFiller::fillAnimationFrame(const GraphicsBuffer& startKeyframe, const GraphicsBuffer& endKeyframe, GraphicsBuffer& filledFrame, float frameNorm)
{
	BufferPoint copyPosition{};
	if (horizontal) {
		if (negativeToPositive) {
			copyPosition.x = -2.0f + 2.0f * frameNorm;
		}
		else {
			copyPosition.x = 2.0f - 2.0 * frameNorm;
		}
	}
	else {
		if (negativeToPositive) {
			copyPosition.y = -2.0f + 2.0f * frameNorm;
		}
		else {
			copyPosition.y = 2.0f - 2.0 * frameNorm;
		}
	}
	this->blitOp.blitTo(endKeyframe, filledFrame, copyPosition);
}
