#include "animation-generator-app.h"

bool AnimationGeneratorApp::OnInit() 
{
	wxFrame* frame = new Frame(NULL);
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
	wxFileDialog* WxOpenFirstFrameDialog(new wxFileDialog(this, _("Choose a file"), _(" "), _(""), _("JPEG files (*.jpg)|*.jpg|PNG files (*.png)|*.png|Bitmap (*.bmp)|*.bmp"), wxFD_OPEN|wxFD_FILE_MUST_EXIST));

	if (WxOpenFirstFrameDialog->ShowModal() == wxID_OK)
	{
	}
}

void Frame::onLoadLastFrame(wxCommandEvent& event)
{
	wxFileDialog* WxOpenLastFrameDialog(new wxFileDialog(this, _("Choose a file"), _(" "), _(""), _("JPEG files (*.jpg)|*.jpg|PNG files (*.png)|*.png|Bitmap (*.bmp)|*.bmp"), wxFD_OPEN | wxFD_FILE_MUST_EXIST));

	if (WxOpenLastFrameDialog->ShowModal() == wxID_OK)
	{
	}

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
	wxFileDialog WxSaveAnimationDialog(new wxFileDialog(this, _("Choose a file"), _(" "), _(""), _("JPEG files (*.jpg)|*.jpg|PNG files (*.png)|*.png|Bitmap (*.bmp)|*.bmp"), wxFD_SAVE | wxFD_OVERWRITE_PROMPT));

}


