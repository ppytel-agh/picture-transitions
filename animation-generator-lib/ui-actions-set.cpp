#include "ui-actions-set.h"

UIActionsSet::UIActionsSet(Model& m, GenerateAnimationInterface& generator, TransitionsManager& transitions) : reset(m), loadStart(m), loadEnd(m), generateAnimation(generator, m, transitions), framePreview(m), saveAnimation(m)
{
	this->actions.resetAction = this->reset;
	this->actions.setStartKeyframeAction = this->loadStart;
	this->actions.setEndKeyframeAction = this->loadEnd;
	this->actions.generateAnimationAction = this->generateAnimation;
	this->actions.showPreviewAction = this->framePreview;
	this->actions.saveAnimationAction = this->saveAnimation;
}

AnimationGeneratorUIActions& UIActionsSet::getActions()
{
	return this->actions;
}
