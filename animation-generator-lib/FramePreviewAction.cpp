#include "FramePreviewAction.h"

FramePreviewAction::FramePreviewAction(Model& m): model(m)
{
}

void FramePreviewAction::operator()(AnimationGeneratorUI& ui, unsigned int frameNumber, unsigned int numberOfAnimationFrames)
{
	GraphicsBuffer frameBuffer = this->model.getAnimationFrame(frameNumber - 1);
	wxImage frameImage = WxWidgetsBufferConverter::convertBufferToWxImage(frameBuffer);
	ui.setAnimationFramePreview(frameImage);
}
