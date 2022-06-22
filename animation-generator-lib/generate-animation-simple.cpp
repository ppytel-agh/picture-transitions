#include "generate-animation-simple.h"

GenerateAnimationSimple::GenerateAnimationSimple(GenerateAnimationInterface& animGen, Model& model, TransitionsManager& transitionsMgr) : animationGenerator(animGen), model(model), transitionsManager(transitionsMgr)
{
}

void GenerateAnimationSimple::operator()(AnimationGeneratorUI& ui, unsigned int transitionId, unsigned int numberOfFrames)
{
	if (this->model.getStartKeyframeSize() == Size{ 0, 0 }) {
		ui.addMessage("nie wczytano keyframe'u poczatkowego");
		return;
	}
	if (this->model.getEndKeyframeSize() == Size{ 0, 0 }) {
		ui.addMessage("nie wczytano keyframe'u koncowego");
		return;
	}
 	if (numberOfFrames < 2) {
		ui.addMessage("minimalna liczba klatek animacji to 2");
		return;
	}
	if (numberOfFrames > 240) {
		ui.addMessage("maksymalna liczba klatek animacji to 240");
		return;
	}
	if (!this->transitionsManager.transitionExists(transitionId)) {
		ui.addMessage("przejscie o podanym id nie istnieje");
		return;
	}
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
		this->model.setAnimationFrames(std::move(animationFrames));
	}
	else {
		ui.addMessage("nie uda³o siê wygenerowaæ animacji");
	}
}


