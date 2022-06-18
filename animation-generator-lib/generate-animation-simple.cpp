#include "generate-animation-simple.h"

GenerateAnimationSimple::GenerateAnimationSimple(GenerateAnimationInterface& animGen, Model& model, TransitionsManager& transitionsMgr) : animationGenerator(animGen), model(model), transitionsManager(transitionsMgr)
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
		GraphicsBuffer endKeyframe = this->model.getEndKeyframe();
		AnimationFrameFillerInterface* filler = this->transitionsManager.getTransitionFiller(transitionId);
		if (filler != nullptr) {
			AnimationFrameFillerInterface& fillerRef = &(*filler);
		}
		this->animationGenerator.generateAnimation(
			startKeyframe,
			endKeyframe,
			this->model.getEndKeyframe(), this->transitionsManager.getTransitionFiller(transitionId), startKeyframe.getSize(), [](unsigned int, unsigned int) {
			//for now unnecessary
			}, [&](std::vector<GraphicsBuffer> frames) {
			this->model.setAnimationFrames(std::move(frames));
			ui.changeSliderRange(numberOfFrames);
			GraphicsBuffer firstAnimationFrame = this->model.getAnimationFrame(0);
			ui.setAnimationFramePreview(WxWidgetsBufferConverter::toWxImage(firstAnimationFram));
		})
	}
}


