#include "AnimationGeneratorMainFrame.h"

AnimationGeneratorMainFrame::AnimationGeneratorMainFrame( wxWindow* parent )
:
MainFrame( parent )
{

}

void AnimationGeneratorMainFrame::onReset( wxCommandEvent& event )
{
// TODO: Implement onReset
}

void AnimationGeneratorMainFrame::onLoadInitFrame( wxCommandEvent& event )
{
wxFileDialog* WxOpenFirstFrameDialog(new wxFileDialog(this, _("Choose a file"), _(" "), _(""), _("JPEG files (*.jpg)|*.jpg|PNG files (*.png)|*.png|Bitmap (*.bmp)|*.bmp"), wxFD_OPEN | wxFD_FILE_MUST_EXIST));

if (WxOpenFirstFrameDialog->ShowModal() == wxID_OK)
{
//this->
}
}

void AnimationGeneratorMainFrame::onLoadLastFrame( wxCommandEvent& event )
{
wxFileDialog* WxOpenLastFrameDialog(new wxFileDialog(this, _("Choose a file"), _(" "), _(""), _("JPEG files (*.jpg)|*.jpg|PNG files (*.png)|*.png|Bitmap (*.bmp)|*.bmp"), wxFD_OPEN | wxFD_FILE_MUST_EXIST));

if (WxOpenLastFrameDialog->ShowModal() == wxID_OK)
{
}
}

void AnimationGeneratorMainFrame::onTransitionChoice( wxCommandEvent& event )
{
// TODO: Implement onTransitionChoice
}

void AnimationGeneratorMainFrame::onFrameRateEnter( wxCommandEvent& event )
{
// TODO: Implement onFrameRateEnter
}

void AnimationGeneratorMainFrame::onGenerateFrame( wxCommandEvent& event )
{
// TODO: Implement onGenerateFrame
}

void AnimationGeneratorMainFrame::onScroll( wxScrollEvent& event )
{
// TODO: Implement onScroll
}

void AnimationGeneratorMainFrame::onAnimationSave( wxCommandEvent& event )
{
wxFileDialog WxSaveAnimationDialog(new wxFileDialog(this, _("Choose a file"), _(" "), _(""), _("JPEG files (*.jpg)|*.jpg|PNG files (*.png)|*.png|Bitmap (*.bmp)|*.bmp"), wxFD_SAVE | wxFD_OVERWRITE_PROMPT));
}


AnimationGeneratorMainFrame::AnimationGeneratorMainFrame(wxWindow* parent, std::vector<std::string> transitionNames, AnimationGeneratorUIActions& actions) : MainFrame(parent), actions(&actions)
{
	this->animationGeneratorUI = new AnimationGeneratorUI(*this);

	//wxString* chooseTransitionChoices = static_cast<wxString*>(transitionames.data());
	//int chooseTransitionNChoices = sizeof(chooseTransitionChoices) / sizeof(wxString);
	delete this->chooseTransition;
	wxString* choices = new wxString[transitionNames.size()];
	for (int i = 0; i < transitionNames.size(); i++) {
		choices[i] = wxString::FromAscii(transitionNames[i].c_str());
	}
	this->chooseTransition = new wxChoice(this, wxID_ANY, wxDefaultPosition, wxDefaultSize, transitionNames.size(), choices, 0);
	this->chooseTransition->SetSelection(0);
	this->chooseTransition->SetFont(wxFont(9, wxFONTFAMILY_MODERN, wxFONTSTYLE_NORMAL, wxFONTWEIGHT_NORMAL, false, wxT("Consolas")));
	this->chooseTransition->SetBackgroundColour(wxColour(230, 230, 230));

	this->transitionDropdownSizer->Add(this->chooseTransition, 0, wxALL, 5);
}