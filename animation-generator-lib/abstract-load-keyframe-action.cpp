#include "abstract-load-keyframe-action.h"

AbstractLoadKeyframeAction::AbstractLoadKeyframeAction(Model& m) : model(m)
{
	wxImage::AddHandler(new wxPNGHandler());
	wxImage::AddHandler(new wxJPEGHandler());
}

void AbstractLoadKeyframeAction::operator()(AnimationGeneratorUI& ui, std::string filepath)
{
	wxImage image(filepath);
	GraphicsBuffer keyframeBuffer = WxWidgetsBufferConverter::convertWxImageToBuffer(image);
	Size keyframeSize = keyframeBuffer.getSize();
	Size secondKeyframeSize = this->getSecondKeyframeSize();
	if (secondKeyframeSize.width == 0 && secondKeyframeSize.height == 0) {
		ui.setKeyframesSize(keyframeSize.width, keyframeSize.height);
	}
	else {
		if ((keyframeSize.width != secondKeyframeSize.width) || (keyframeSize.height != secondKeyframeSize.height)) {
			ui.addMessage("keyframe sizes do not match");
			return;
		}
	}
	this->putIntoModel(keyframeBuffer);
	this->displayInPreview(ui, image);
}
