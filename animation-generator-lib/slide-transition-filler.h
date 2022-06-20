#pragma once

#include "animation-frame-filler-interface.h"
#include "normalized-blit.h"

class SlideTransitionFiller : public AnimationFrameFillerInterface {
public:
	/**
	* @param horizontal if false then vertical
	* @param negativeToPositive if false then positiveToNegative
	*/
	SlideTransitionFiller(bool horizontal, bool negativeToPositive);
	// Inherited via AnimationFrameFillerInterface
	virtual void fillAnimationFrame(const GraphicsBuffer& startKeyframe, const GraphicsBuffer& endKeyframe, GraphicsBuffer& filledFrame, float frameNorm) override;
private:
	bool horizontal;
	bool negativeToPositive;
	NormalizedBlit blitOp;
};