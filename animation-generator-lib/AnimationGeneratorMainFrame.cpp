#include "AnimationGeneratorMainFrame.h"
#include "graphics-buffer.h"
#include "model.h"

AnimationGeneratorMainFrame::AnimationGeneratorMainFrame(wxWindow* parent)
	:
	MainFrame(parent)
{
	this->setPolishLabels();
}

void AnimationGeneratorMainFrame::onLoadInitFrame(wxCommandEvent& event)
{
	wxFileDialog* WxOpenFirstFrameDialog(new wxFileDialog(this, _("Wybierz klatke poczatkowa"), _(" "), _(""), _("JPEG files (*.jpg)|*.jpg|PNG files (*.png)|*.png|Bitmap (*.bmp)|*.bmp"), wxFD_OPEN | wxFD_FILE_MUST_EXIST));

	if (WxOpenFirstFrameDialog->ShowModal() == wxID_OK)
	{
		if (this->actions != nullptr) {
			if (this->actions->setStartKeyframeAction != nullptr) {
				std::string filePath = WxOpenFirstFrameDialog->GetPath();
				this->actions->setStartKeyframeAction(*this->animationGeneratorUI, filePath);
			}
		}
	}
}

void AnimationGeneratorMainFrame::onLoadLastFrame(wxCommandEvent& event)
{
	wxFileDialog* WxOpenLastFrameDialog(new wxFileDialog(this, _("Wybierz klatke koncowa"), _(" "), _(""), _("JPEG files (*.jpg)|*.jpg|PNG files (*.png)|*.png|Bitmap (*.bmp)|*.bmp"), wxFD_OPEN | wxFD_FILE_MUST_EXIST));

	if (WxOpenLastFrameDialog->ShowModal() == wxID_OK)
	{
		if (this->actions != nullptr) {
			if (this->actions->setEndKeyframeAction != nullptr) {
				std::string filePath = WxOpenLastFrameDialog->GetPath();
				this->actions->setEndKeyframeAction(*this->animationGeneratorUI, filePath);
			}
		}
	}
}

void AnimationGeneratorMainFrame::onReset(wxCommandEvent& event)
{
	wxMessageDialog* dial = new wxMessageDialog(NULL, L"Zresetowac sesje?", _("Potwierdz reset sesji"), wxYES_NO | wxNO_DEFAULT | wxICON_QUESTION);
	auto dialResult = dial->ShowModal();
	if (dialResult == wxID_YES) {
		this->firstImgPreviewPanel->ClearBackground();
		this->secondImgPreviewPanel->ClearBackground();
		this->scenePanel->ClearBackground();
		this->slider->SetRange(1, 1);
		this->messagesLog->SetLabel("");
		this->loadedKeyframeSize->SetLabel("");
		this->Layout();
		if (this->actions != nullptr) {
			if (this->actions->resetAction != nullptr) {
				AnimationGeneratorUI& uiRef = *this->animationGeneratorUI;
				std::function<void(AnimationGeneratorUI&)> resetAction = this->actions->resetAction;
				resetAction(uiRef);
			}
		}
	}
}

void AnimationGeneratorMainFrame::onTransitionChoice(wxCommandEvent& event)
{
	// TODO: Implement onTransitionChoice
}

void AnimationGeneratorMainFrame::onFrameRateEnter(wxSpinEvent& event)
{
	// TODO: Implement onFrameRateEnter
}

void AnimationGeneratorMainFrame::onGenerateFrame(wxCommandEvent& event)
{
	int selectedTransitionId = this->chooseTransition->GetSelection();
	int numberOfFrames = this->frameRate->GetValue();
	if (this->actions != nullptr) {
		if (this->actions->generateAnimationAction != nullptr) {
			this->actions->generateAnimationAction(*this->animationGeneratorUI, selectedTransitionId, numberOfFrames);
		}
	}
}

void AnimationGeneratorMainFrame::onScroll(wxScrollEvent& event)
{
	int selectedFrameNumber = this->slider->GetValue();
	int numberOfFrames = this->slider->GetMax();
	if (this->actions != nullptr) {
		if (this->actions->showPreviewAction != nullptr) {
			this->actions->showPreviewAction(*this->animationGeneratorUI, selectedFrameNumber, numberOfFrames);
		}
	}
}

void AnimationGeneratorMainFrame::onAnimationSave(wxCommandEvent& event)
{
	Model model;
	wxImage::AddHandler(new wxJPEGHandler);

	wxDirDialog* WxSaveAnimationDialog(new wxDirDialog(this, _("Wybierz katalog zapisu animacji")));

	if (WxSaveAnimationDialog->ShowModal() == wxID_OK)
	{
		if (this->actions != nullptr) {
			wxString saveDir = WxSaveAnimationDialog->GetPath();
			// this->actions->saveAnimationAction(*this->animationGeneratorUI, saveDir);

			for (unsigned int i = 0; i < model.getNumberOfAnimationFrames(); i++)
			{
				GraphicsBuffer buffer = model.getAnimationFrame(i);
				std::vector<unsigned char> bmp = buffer.getSubpixelValues();
				wxSize imgSize = wxSize(960, 540);
				wxImage img = wxImage(imgSize, bmp.data());
				img.SaveFile(saveDir, wxBITMAP_TYPE_JPEG);
			}
		}
	}
}

void AnimationGeneratorMainFrame::setPolishLabels()
{
	/*this->loadInitFrameButton->SetLabel(wxT("Wczytaj klatkę początkową"));
	this->loadLastFrameButton->SetLabel(wxT("Wczytaj klatkę końcową"));*/
}

AnimationGeneratorMainFrame::AnimationGeneratorMainFrame(wxWindow* parent, std::vector<std::wstring> transitionNames, AnimationGeneratorUIActions& actions) : MainFrame(parent), actions(&actions)
{

	this->animationGeneratorUI = new AnimationGeneratorUI(*this);

	delete this->chooseTransition;
	wxString* choices = new wxString[transitionNames.size()];
	for (int i = 0; i < transitionNames.size(); i++) {
		choices[i] = transitionNames[i].c_str();
	}
	this->chooseTransition = new wxChoice(this, wxID_ANY, wxDefaultPosition, wxDefaultSize, transitionNames.size(), choices, 0);
	this->chooseTransition->SetSelection(0);
	this->chooseTransition->SetFont(wxFont(9, wxFONTFAMILY_MODERN, wxFONTSTYLE_NORMAL, wxFONTWEIGHT_NORMAL, false, wxT("Consolas")));
	this->chooseTransition->SetBackgroundColour(wxColour(230, 230, 230));
	this->transitionDropdownSizer->Add(this->chooseTransition, 0, wxALL, 5);


	this->setPolishLabels();
}

AnimationGeneratorUI* AnimationGeneratorMainFrame::getUI()
{
	return this->animationGeneratorUI;
}