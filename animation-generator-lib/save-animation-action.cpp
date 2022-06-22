#include "save-animation-action.h"

SaveAnimationAction::SaveAnimationAction(Model& m) :model(m)
{
}

void SaveAnimationAction::operator()(AnimationGeneratorUI& ui, std::string saveDir)
{
	for (unsigned int i = 0; i < this->model.getNumberOfAnimationFrames(); i++)
	{
		GraphicsBuffer buffer = this->model.getAnimationFrame(i);
		wxImage frameImage = WxWidgetsBufferConverter::convertBufferToWxImage(buffer);
		std::stringstream ss;
		ss << saveDir << "/" << (i + 1) << ".jpg";
		frameImage.SaveFile(ss.str(), wxBITMAP_TYPE_JPEG);
	}
	ui.addMessage("zapisano animacje na dysk");
}
