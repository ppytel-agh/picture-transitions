#include "SimpleAnimationGenerator.h"

std::vector<GraphicsBuffer> SimpleAnimationGenerator::generateAnimation(const GraphicsBuffer& startKeyframe, const GraphicsBuffer& endKeyframe, AnimationFrameFillerInterface& frameFiller, unsigned int numberOfFrames)
{
	std::vector<GraphicsBuffer> animationFrames;
	if (numberOfFrames > 1) {
		NormsCalculator normCalc(numberOfFrames);
		for (int i = 0; i < numberOfFrames; i++) {
			float norm = normCalc.getNorm(i);

		}
	}
	return animationFrames;
}

std::vector<GraphicsBuffer> SimpleAnimationGenerator::generateAnimation(const GraphicsBuffer& startKeyframe, const GraphicsBuffer& endKeyframe, AnimationFrameFillerInterface& frameFiller, Size animationFrameSize, std::vector<float> frameNormsSeries, Pixel animationBackgroundColour)
{
	std::vector<GraphicsBuffer> animationFrames;
	for(float frameNorm: frameNormsSeries)
	if (numberOfFrames > 1) {
		GraphicsBuffer frame(animationFrameSize, animationBackgroundColour);
		animationFrames.push_back(frame);
	}
	return animationFrames;
}
