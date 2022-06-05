#pragma once

#include <wx/wx.h>
#include "mainFrame.h"

class AnimationGeneratorApp : public wxApp 
{

public:
	virtual bool OnInit();
	virtual int OnExit();

protected:
	void onReset(wxCommandEvent& event);
	void onLoadInitFrame(wxCommandEvent& event);
	void onLoadLastFrame(wxCommandEvent& event);
	void onTransitionChoice(wxCommandEvent& event);
	void onFrameRateEnter(wxCommandEvent& event);
	void onGenerateFrame(wxCommandEvent& event);
	void onScroll(wxScrollEvent& event);
	void onAnimationSave(wxCommandEvent& event);
};