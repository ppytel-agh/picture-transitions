#pragma once

#include <wx/wx.h>
#include <memory>
#include "mainFrame.h"

class AnimationGeneratorApp : public wxApp 
{

public:
	virtual bool OnInit();
	virtual int OnExit();
};

class Frame : public mainFrame
{

public:
	void onReset(wxCommandEvent& event) override;
	void onLoadInitFrame(wxCommandEvent& event) override;
	void onLoadLastFrame(wxCommandEvent& event) override;
	void onTransitionChoice(wxCommandEvent& event) override;
	void onFrameRateEnter(wxCommandEvent& event) override;
	void onGenerateFrame(wxCommandEvent& event) override;
	void onScroll(wxScrollEvent& event) override;
	void onAnimationSave(wxCommandEvent& event) override;
	
	void addMessage();
	void setStartKeyframePreview(wxImage&);
	void setEndKeyframePreview(wxImage&);
	void saveAnimationAction();

public:
	Frame(wxWindow* parent);
};

