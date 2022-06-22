#pragma once

#include "animation-frame-filler-interface.h"
#include "wxWidgets-buffer-converter.h"
#include "buffer-blender.h"
#include "normalized-blit.h"

class BlurTransitionFiller : public AnimationFrameFillerInterface {
public:
	BlurTransitionFiller();
	// Inherited via AnimationFrameFillerInterface
	virtual void fillAnimationFrame(const GraphicsBuffer& startKeyframe, const GraphicsBuffer& endKeyframe, GraphicsBuffer& filledFrame, float frameNorm) override;
private:
	NormalizedBlit blitter;
	BufferBlender blender;
};