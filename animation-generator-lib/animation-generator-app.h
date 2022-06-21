#pragma once

#include <wx/wx.h>
#include "AnimationGeneratorMainFrame.h"
#include "model.h"
#include "transitions-repo.h"
#include "simple-animation-generator.h"
#include "ui-actions-set.h"

class AnimationGeneratorApp : public wxApp
{
public:
	AnimationGeneratorApp();
	virtual bool OnInit();
	virtual int OnExit();
private:
	AnimationGeneratorMainFrame* mainFrame;
	Model model;
	SimpleAnimationGenerator animationGenerator;
	TransitionsRepo transitionsRepository;
	UIActionsSet actionsRepo;
};