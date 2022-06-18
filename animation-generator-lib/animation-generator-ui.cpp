#include "animation-generator-ui.h"

AnimationGeneratorUI::AnimationGeneratorUI(AnimationGeneratorMainFrame& mainFrame): mainFrame(mainFrame)
{
}

void AnimationGeneratorUI::setStartKeyframePreview(const wxImage& preview)
{
	wxImage previewCopy(preview);
	previewCopy.Rescale(240, 135);
	wxBitmap memoryBitmap(previewCopy);
	wxMemoryDC memDC;
	memDC.SelectObject(memoryBitmap);
	wxClientDC dc(this->mainFrame.firstImgPreviewPanel);
	dc.Blit(0, 0, 240, 135, &memDC, 0, 0);
}

void AnimationGeneratorUI::setEndKeyframePreview(const wxImage& preview)
{
	wxImage previewCopy(preview);
	previewCopy.Rescale(240, 135);
	wxBitmap memoryBitmap(previewCopy);
	wxMemoryDC memDC;
	memDC.SelectObject(memoryBitmap);
	wxClientDC dc(this->mainFrame.secondImgPreviewPanel);
	dc.Blit(0, 0, 240, 135, &memDC, 0, 0);
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
	previewCopy.Rescale(960, 540);
	wxBitmap memoryBitmap(previewCopy);
	wxMemoryDC memDC;
	memDC.SelectObject(memoryBitmap);
	wxClientDC dc(this->mainFrame.scenePanel);
	dc.Blit(0, 0, 960, 540, &memDC, 0, 0);
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
