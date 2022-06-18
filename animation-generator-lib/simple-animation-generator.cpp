#include "simple-animation-generator.h"

std::vector<GraphicsBuffer> SimpleAnimationGenerator::generateAnimation(const GraphicsBuffer& startKeyframe, const GraphicsBuffer& endKeyframe, AnimationFrameFillerInterface& frameFiller, Size animationFrameSize, std::vector<float> frameNormsSeries, std::function<void(unsigned int, unsigned int)> generatedFrameCallback, Pixel animationBackgroundColour)
{
	std::vector<GraphicsBuffer> animationFrames;
	int numberOfFrames = frameNormsSeries.size();
	int currentAnimationIndex = 0;
	for (float frameNorm : frameNormsSeries) {
		GraphicsBuffer frame(animationFrameSize, animationBackgroundColour);
		frameFiller.fillAnimationFrame(startKeyframe, endKeyframe, frame, frameNorm);
		animationFrames.push_back(frame);
		if (generatedFrameCallback != nullptr) {
			generatedFrameCallback(currentAnimationIndex++, numberOfFrames);
		}
	}
	return animationFrames;
}
