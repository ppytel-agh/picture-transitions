#include "animation-generator-main-frame.h"

AnimationGeneratorMainFrame::AnimationGeneratorMainFrame(wxWindow* parent)
	:
	MainFrame(parent)
{

}

AnimationGeneratorMainFrame::AnimationGeneratorMainFrame(wxWindow* parent, std::vector<std::string> transitionNames, AnimationGeneratorUIActions& actions) : MainFrame(parent), actions(&actions)
{
	this->animationGeneratorUI = new AnimationGeneratorUI(*this);
	for (int i = 0; i < transitionNames.size(); i++) {
		this->chooseTransition->SetString(i, transitionNames[i]);
	}
}

void AnimationGeneratorMainFrame::onReset(wxCommandEvent& event)
{
	// TODO: Implement onReset
}

void AnimationGeneratorMainFrame::onLoadInitFrame(wxCommandEvent& event)
{
	wxFileDialog* WxOpenFirstFrameDialog(new wxFileDialog(this, _("Choose a file"), _(" "), _(""), _("JPEG files (*.jpg)|*.jpg|PNG files (*.png)|*.png|Bitmap (*.bmp)|*.bmp"), wxFD_OPEN | wxFD_FILE_MUST_EXIST));

	if (WxOpenFirstFrameDialog->ShowModal() == wxID_OK)
	{
		//this->
	}
}

void AnimationGeneratorMainFrame::onLoadLastFrame(wxCommandEvent& event)
{
	wxFileDialog* WxOpenLastFrameDialog(new wxFileDialog(this, _("Choose a file"), _(" "), _(""), _("JPEG files (*.jpg)|*.jpg|PNG files (*.png)|*.png|Bitmap (*.bmp)|*.bmp"), wxFD_OPEN | wxFD_FILE_MUST_EXIST));

	if (WxOpenLastFrameDialog->ShowModal() == wxID_OK)
	{
	}
}

void AnimationGeneratorMainFrame::onTransitionChoice(wxCommandEvent& event)
{
	// TODO: Implement onTransitionChoice
}

void AnimationGeneratorMainFrame::onFrameRateEnter(wxCommandEvent& event)
{
	// TODO: Implement onFrameRateEnter
}

void AnimationGeneratorMainFrame::onGenerateFrame(wxCommandEvent& event)
{
	// TODO: Implement onGenerateFrame
}

void AnimationGeneratorMainFrame::onScroll(wxScrollEvent& event)
{
	// TODO: Implement onScroll
}

void AnimationGeneratorMainFrame::onAnimationSave(wxCommandEvent& event)
{
	wxFileDialog WxSaveAnimationDialog(new wxFileDialog(this, _("Choose a file"), _(" "), _(""), _("JPEG files (*.jpg)|*.jpg|PNG files (*.png)|*.png|Bitmap (*.bmp)|*.bmp"), wxFD_SAVE | wxFD_OVERWRITE_PROMPT));
}
