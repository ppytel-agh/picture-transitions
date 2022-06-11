#include "generate-animation-simple.h"

GenerateAnimationSimple::GenerateAnimationInterface& animGen, AnimationGeneratorModel& model, TransitionsManager& transitionsMgmt) : animationGenerator(animGen), model(model), transitionsManger(transitionsMgmt)
{
}

void GenerateAnimationSimple::operator()(AnimationGeneratorUI& ui, unsigned int transitionId, unsigned int numberOfFrames)
{
	if (numberOfFrames > 1) {
		std::vector<float> norms;
		NormsCalculator normCalc(numberOfFrames);
		for (int i = 0; i < numberOfFrames; i++) {
			norms.push_back(normCalc.getNorm(i));
		}
		GraphicsBuffer startKeyframe = this->model.getStartKeyframe();
		this->animationGenerator.generateAnimation(startKeyframe, this->model.getEndKeyframe(), this->transitionsManager.getTransition(transitionId), startKeyframe.getSize(), [](unsigned int, unsigned int) {
			//for now unnecessary
			}, [&](std::vector<GraphicsBuffer> frames) {
			this->model.setAnimationFrames(std::move(frames));
			ui.changeSliderRange(numberOfFrames);
			GraphicsBuffer firstAnimationFrame = this->model.getAnimationFrame(0);
			ui.setAnimationFramePreview(WxWidgetsBufferConverter::toWxImage(firstAnimationFram));
		})
	}
}


