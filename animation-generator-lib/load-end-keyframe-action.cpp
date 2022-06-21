#include "load-end-keyframe-action.h"

Size LoadEndKeyframeAction::getSecondKeyframeSize()
{
    return this->model.getStartKeyframeSize();
}

void LoadEndKeyframeAction::putIntoModel(GraphicsBuffer& endKeyframeBuffer)
{
    this->model.setEndKeyframe(std::move(endKeyframeBuffer));
}

void LoadEndKeyframeAction::displayInPreview(AnimationGeneratorUI& ui, wxImage& image)
{
    ui.setEndKeyframePreview(image);
}
