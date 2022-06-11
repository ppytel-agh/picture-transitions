#pragma once

#include <string>
#include <memory>
#include <vector>
#include <utility>
#include "graphics-buffer.h"

class Model {
public:
	void setStartKeyframe(GraphicsBuffer&&);
	GraphicsBuffer getStartKeyframe() const;
	std::pair<unsigned int, unsigned int> getStartKeyframeSize() const;
	void setEndKeyframe(GraphicsBuffer&&);
	GraphicsBuffer getEndKeyframe() const;
	std::pair<unsigned int, unsigned int> getEndKeyframeSize() const;
	unsigned int getNumberOfAnimationFrames() const;
	GraphicsBuffer getAnimationFrame(unsigned int) const;
	std::vector<GraphicsBuffer> getAllAnimationFrames() const;
private:
	std::unique_ptr<GraphicsBuffer> startKeyframe;
	std::unique_ptr<GraphicsBuffer> endKeyframe;
	std::unique_ptr<std::vector<GraphicsBuffer>> animationFrames;
};