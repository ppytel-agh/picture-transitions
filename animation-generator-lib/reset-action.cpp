#include "reset-action.h"

ResetAction::ResetAction(Model& m) :model(m)
{
}

void ResetAction::operator()(AnimationGeneratorUI& ui)
{
	this->model.reset();
}
