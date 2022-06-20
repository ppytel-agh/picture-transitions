#pragma once

#include "animation-frame-filler-interface.h"
#include "normalized-blit.h"
#include "buffer-scaler.h"

class CentralScalingTransitionFiller : public AnimationFrameFillerInterface {
public:
	/**
	* @param scaleStaryKeyframe if true start reduced if false end is enlarged
	*/
	CentralScalingTransitionFiller(bool scaleStaryKeyframe);
	// Inherited via AnimationFrameFillerInterface
	virtual void fillAnimationFrame(const GraphicsBuffer& startKeyframe, const GraphicsBuffer& endKeyframe, GraphicsBuffer& filledFrame, float frameNorm) override;
private:
	bool scaleStartKeyframe;
	NormalizedBlit blit;
	BufferScaler scaler;
};