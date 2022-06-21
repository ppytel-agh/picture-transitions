#pragma once

#include "abstract-load-keyframe-action.h"

class LoadEndKeyframeAction : public AbstractLoadKeyframeAction {
public:
	using AbstractLoadKeyframeAction::AbstractLoadKeyframeAction;
protected:
	// Inherited via AbstractLoadKeyframeAction
	virtual Size getSecondKeyframeSize() override;
	virtual void putIntoModel(GraphicsBuffer&) override;
	virtual void displayInPreview(AnimationGeneratorUI&, wxImage&) override;
};