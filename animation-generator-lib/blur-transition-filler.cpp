#include "blur-transition-filler.h"

BlurTransitionFiller::BlurTransitionFiller(): blitter(), blender({})
{
}

void BlurTransitionFiller::fillAnimationFrame(const GraphicsBuffer& startKeyframe, const GraphicsBuffer& endKeyframe, GraphicsBuffer& filledFrame, float frameNorm)
{
	int maxBlurRadius = 40;
	if (frameNorm < 0.33f) {
		wxImage toBlur = WxWidgetsBufferConverter::convertBufferToWxImage(startKeyframe);
		int blurRadius = 3 * frameNorm * maxBlurRadius;
		wxImage blurredSource = toBlur.Blur(blurRadius);
		GraphicsBuffer blurredSourceBuffer = WxWidgetsBufferConverter::convertWxImageToBuffer(blurredSource);
		this->blitter.blitTo(blurredSourceBuffer, filledFrame, { 0.0f, 0.0f });
	}
	else if (frameNorm < 0.66f) {
		float blendProportion = (frameNorm - 0.33f) * 3.0f;
		GraphicsBuffer blend(endKeyframe);
		this->blender.blendIntoBuffer(blend, startKeyframe, blendProportion);
		wxImage toBlur = WxWidgetsBufferConverter::convertBufferToWxImage(blend);
		wxImage blendImage = toBlur.Blur(maxBlurRadius);
		GraphicsBuffer blurredBlend = WxWidgetsBufferConverter::convertWxImageToBuffer(blendImage);
		this->blitter.blitTo(blurredBlend, filledFrame, { 0.0f, 0.0f });
	}
	else {
		wxImage toBlur = WxWidgetsBufferConverter::convertBufferToWxImage(endKeyframe);
		int blurRadius = (1.0f - (frameNorm - 0.66f) * 3.0f) * maxBlurRadius;
		wxImage blurredSource = toBlur.Blur(blurRadius);
		GraphicsBuffer blurredSourceBuffer = WxWidgetsBufferConverter::convertWxImageToBuffer(blurredSource);
		this->blitter.blitTo(blurredSourceBuffer, filledFrame, { 0.0f, 0.0f });
	}
}
