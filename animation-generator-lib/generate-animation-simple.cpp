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
		AnimationFrameFillerInterface& filler = this->transitionsManager.getTransitionFiller(transitionId);
		Size framesSize = startKeyframe.getSize();
		std::vector<GraphicsBuffer> animationFrames = this->animationGenerator.generateAnimation(
			startKeyframe,
			endKeyframe,
			filler,
			framesSize,
			norms,
			nullptr
		);
		if (animationFrames.size() > 0) {
			ui.setAnimationFrameCountSlider(animationFrames.size());
			ui.setAnimationFramePreview(WxWidgetsBufferConverter::convertBufferToWxImage(animationFrames[0]));
		}
		this->model.setAnimationFrames(std::move(animationFrames));
	}
}


