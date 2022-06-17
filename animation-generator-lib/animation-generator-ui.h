#pragma once

#include <string>
#include <vector>
#include <functional>
#include <wx/wx.h>

struct AnimationGeneratorUIActions {

};

class AnimationGeneratorUI 
{
public:
	AnimationGeneratorUI(std::vector<std::string>, AnimationGeneratorUIActions, wxFrame*);
	void addMessage(wxFrame&, std::string&);
	void setStartKeyframePreview(wxFrame&, wxImage&);
	void setEndKeyframePreview(wxFrame&, wxImage&);
	void resetAction(wxFrame&);
	void generateAnimationAction(wxFrame&);
	void showPreviewAction(wxFrame&);
	void saveAnimationAction(wxFrame&);
private:
	AnimationGeneratorUIActions actions;
};

