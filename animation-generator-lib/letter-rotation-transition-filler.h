#pragma once

#include "animation-frame-filler-interface.h"
#include "normalized-blit.h"
#include "buffer-scaler.h"

class LetterRotationTransitionFiller : public AnimationFrameFillerInterface {
public:
	/**
	* @param rotateAgainstYAxis if false then rotate against X axis
	*/
	LetterRotationTransitionFiller(bool rotateAgainstYAxis);
	// Inherited via AnimationFrameFillerInterface
	virtual void fillAnimationFrame(const GraphicsBuffer& startKeyframe, const GraphicsBuffer& endKeyframe, GraphicsBuffer& filledFrame, float frameNorm) override;
private:
	static const float pi;
	bool rotateAgainstYAxis;
	NormalizedBlit blitter;
	BufferScaler scaler;
};