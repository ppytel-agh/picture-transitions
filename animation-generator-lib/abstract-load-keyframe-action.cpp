#include "abstract-load-keyframe-action.h"

AbstractLoadKeyframeAction::AbstractLoadKeyframeAction(Model& m) : model(m)
{
	wxImage::AddHandler(new wxPNGHandler());
	wxImage::AddHandler(new wxJPEGHandler());
}

void AbstractLoadKeyframeAction::operator()(AnimationGeneratorUI& ui, std::string filepath)
{
	wxImage image(filepath);
	if (!image.IsOk()) {
		ui.addMessage("podano nieprawidlowy plik");
		return;
	}
	{
		int width = image.GetWidth();
		int height = image.GetHeight();

		if (width < 120 || height < 120) {
			ui.addMessage("klatka nie moze miec mniej ni¿ 120 pikseli w krotszym z bokow");
			return;
		}
		if (width > 1920 || height > 1080) {
			ui.addMessage("maksymalny rozmiar klatki to full hd - 1920x1080 px");
			return;
		}
	}
	GraphicsBuffer keyframeBuffer = WxWidgetsBufferConverter::convertWxImageToBuffer(image);
	Size keyframeSize = keyframeBuffer.getSize();
	Size secondKeyframeSize = this->getSecondKeyframeSize();
	if (secondKeyframeSize.width == 0 && secondKeyframeSize.height == 0) {
		ui.setKeyframesSize(keyframeSize.width, keyframeSize.height);
	}
	else {
		if ((keyframeSize.width != secondKeyframeSize.width) || (keyframeSize.height != secondKeyframeSize.height)) {
			ui.addMessage("rozmiary keyframe'ow nie sa zgodne");
			return;
		}
	}
	this->putIntoModel(keyframeBuffer);
	this->displayInPreview(ui, image);
}
