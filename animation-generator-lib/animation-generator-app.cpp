#include "animation-generator-app.h"

bool AnimationGeneratorApp::OnInit() 
{
	wxFrame* frame = new mainFrame(NULL);
	frame->Show(true);
	SetTopWindow(frame);
	return true;
}

int AnimationGeneratorApp::OnExit() 
{
	return 0;
}

Frame::Frame(wxWindow* parent)
	: mainFrame(parent)
{

}

void Frame::onReset(wxCommandEvent& event)
{
	// TODO: Implement onReset
}

void Frame::onLoadInitFrame(wxCommandEvent& event)
{
	std::shared_ptr<wxFileDialog> WxOpenFileDialog1(new wxFileDialog(this, _("Choose a file"), _(" "), _("render"), _("JPEG files (*.jpg)|*.jpg|PNG files (*.png)|*.png|Bitmap (*.bmp)|*.bmp")));


}

void Frame::onLoadLastFrame(wxCommandEvent& event)
{
	// TODO: Implement onLoadLastFrame
}

void Frame::onTransitionChoice(wxCommandEvent& event)
{
	// TODO: Implement onTransitionChoice
}

void Frame::onFrameRateEnter(wxCommandEvent& event)
{
	// TODO: Implement onFrameRateEnter
}

void Frame::onGenerateFrame(wxCommandEvent& event)
{
	// TODO: Implement onGenerateFrame
}

void Frame::onScroll(wxScrollEvent& event)
{
	// TODO: Implement onScroll
}

void Frame::onAnimationSave(wxCommandEvent& event)
{
	// TODO: Implement onAnimationSave
}

