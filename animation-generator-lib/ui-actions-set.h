#pragma once

#include "animation-generator-ui-actions.h"
#include "model.h"
#include "generate-animation-interface.h"
#include "transitions-manager.h"
#include "reset-action.h"
#include "load-start-keyframe-action.h"
#include "load-end-keyframe-action.h"
#include "generate-animation-simple.h"
#include "FramePreviewAction.h"
#include "save-animation-action.h"

class UIActionsSet {
public:
	UIActionsSet(Model&, GenerateAnimationInterface&, TransitionsManager&);
	AnimationGeneratorUIActions& getActions();
private:
	ResetAction reset;
	LoadStartKeyframeAction loadStart;
	LoadEndKeyframeAction loadEnd;
	GenerateAnimationSimple generateAnimation;
	FramePreviewAction framePreview;
	SaveAnimationAction saveAnimation;
	AnimationGeneratorUIActions actions;
};