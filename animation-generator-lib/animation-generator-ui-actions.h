#pragma once

#include <functional>
#include <string>

class AnimationGeneratorUI;

struct AnimationGeneratorUIActions {
	std::function<void(AnimationGeneratorUI&)> resetAction;
	std::function<void(AnimationGeneratorUI&, std::string)> setStartKeyframeAction;
	std::function<void(AnimationGeneratorUI&, std::string)> setEndKeyframeAction;
	std::function<void(AnimationGeneratorUI&, unsigned int, unsigned int)> generateAnimationAction;
	std::function<void(AnimationGeneratorUI&, unsigned int, unsigned int)> showPreviewAction;
	std::function<void(AnimationGeneratorUI&, std::string)> saveAnimationAction;
};