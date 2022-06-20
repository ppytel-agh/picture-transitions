#include "animation-generator-ui.h"

AnimationGeneratorUI::AnimationGeneratorUI(AnimationGeneratorMainFrame& mainFrame): mainFrame(mainFrame)
{
}

void scaleToFit(wxImage& image, unsigned short width, unsigned short height) {
	float destinationRatio = float(width) / float(height);
	int imageWidth = image.GetWidth();
	int imageHeight = image.GetHeight();
	float imageRatio = float(imageWidth) / float(imageHeight);
	int newWidth = width;
	int newHeight = height;
	if (imageRatio > destinationRatio) {
		float scaleRatio = float(width) / float(imageWidth);
		newHeight = imageHeight * scaleRatio;
	}
	else if (imageRatio < destinationRatio) {
		float scaleRatio = float(height) / float(imageHeight);
		newWidth = imageWidth * scaleRatio;
	}
	image.Rescale(newWidth, newHeight);
}

void drawInCenterOfPanel(wxWindow* panel, const wxImage& scaledImage, int panelWidth, int panelHeight) {
	int imageWidth = scaledImage.GetWidth();
	int imageHeight = scaledImage.GetHeight();
	int xOffset = 0;
	int yOffset = 0;
	if (imageWidth < panelWidth) {
		xOffset = (panelWidth - imageWidth) / 2;
	}
	if (imageHeight < panelHeight) {
		yOffset = (panelHeight - imageHeight) / 2;
	}
	wxBitmap memoryBitmap(scaledImage);
	wxMemoryDC memDC;
	memDC.SelectObject(memoryBitmap);
	wxClientDC dc(panel);
	dc.Blit(xOffset, yOffset, imageWidth, imageHeight, &memDC, 0, 0);
}

void AnimationGeneratorUI::setStartKeyframePreview(const wxImage& preview)
{
	wxImage previewCopy(preview);
	scaleToFit(previewCopy, 240, 135);
	drawInCenterOfPanel(this->mainFrame.firstImgPreviewPanel, previewCopy, 240, 135);
}

void AnimationGeneratorUI::setEndKeyframePreview(const wxImage& preview)
{
	wxImage previewCopy(preview);
	scaleToFit(previewCopy, 240, 135);
	drawInCenterOfPanel(this->mainFrame.secondImgPreviewPanel, previewCopy, 240, 135);
}

void AnimationGeneratorUI::addMessage(std::string message)
{
	std::stringstream ss;
	ss << this->mainFrame.messagesLog->GetLabel();
	ss << std::endl << message;
	std::string newLabel = ss.str();
	this->mainFrame.messagesLog->SetLabel(newLabel);
	this->mainFrame.Layout();
	this->mainFrame.logScroll->Scroll(0, this->mainFrame.logScroll->GetScrollRange(wxVERTICAL));
}

void AnimationGeneratorUI::setAnimationFramePreview(const wxImage& preview)
{
	wxImage previewCopy(preview);
	scaleToFit(previewCopy, 960, 540);
	drawInCenterOfPanel(this->mainFrame.scenePanel, previewCopy, 960, 540);
}

void AnimationGeneratorUI::setAnimationFrameCountSlider(unsigned int newMaxVal)
{
	this->mainFrame.slider->SetRange(1, newMaxVal);
	this->mainFrame.slider->SetValue(1);
}

void AnimationGeneratorUI::setKeyframesSize(unsigned int w, unsigned int h)
{
	std::stringstream ss;
	ss << w << " x " << h << "px";
	this->mainFrame.loadedKeyframeSize->SetLabel(ss.str());
}
