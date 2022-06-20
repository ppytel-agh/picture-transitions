#pragma once

#include "buffer-brightness-changer.h"
#include "animation-frame-filler-interface.h"
#include "normalized-blit.h"

class BrightnessChangeTransitionFiller:public AnimationFrameFillerInterface {
public:
	// Inherited via AnimationFrameFillerInterface
	virtual void fillAnimationFrame(const GraphicsBuffer& startKeyframe, const GraphicsBuffer& endKeyframe, GraphicsBuffer& filledFrame, float frameNorm) override;
private:
	BufferBrightnessChanger brightnessChanger;
	NormalizedBlit normalizedBlit;
};