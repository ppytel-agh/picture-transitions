#include "load-start-keyframe-action.h"

Size LoadStartKeyframeAction::getSecondKeyframeSize()
{
    return this->model.getEndKeyframeSize();
}

void LoadStartKeyframeAction::putIntoModel(GraphicsBuffer& startKeyframe)
{
    this->model.setStartKeyframe(std::move(startKeyframe));
}

void LoadStartKeyframeAction::displayInPreview(AnimationGeneratorUI& ui, wxImage& image)
{
    ui.setStartKeyframePreview(image);
}
