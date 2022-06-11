#include "model.h"

void Model::setStartKeyframe(GraphicsBuffer&& newStartKeyframe)
{
	this->startKeyframe = newStartKeyframe;
}

GraphicsBuffer Model::getStartKeyframe() const
{
	if (this->startKeyframe == nullptr) {
		return GraphicsBuffer(0, 0);
	}
	else {
		return GraphicsBuffer(*this->startKeyframe);
	}
}

std::pair<unsigned int, unsigned int> Model::getStartKeyframeSize() const
{
	if (this->startKeyframe == nullptr) {
		return { 0, 0 };
	}
	else {
		return this->startKeyframe->getSize();
	}
}

void Model::setEndKeyframe(GraphicsBuffer&& newEndKeyframe)
{
	this->endKeyframe = newEndKeyframe;
}

GraphicsBuffer Model::getEndKeyframe() const
{
	if (this->startKeyframe == nullptr) {
		return GraphicsBuffer(0, 0);
	}
	else {
		return GraphicsBuffer(*this->endKeyframe);
	}
}

std::pair<unsigned int, unsigned int> Model::getEndKeyframeSize() const
{
	if (this->startKeyframe == nullptr) {
		return { 0, 0 };
	}
	else {
		return this->endKeyframe->getSize();
	}
}

unsigned int Model::getNumberOfAnimationFrames() const
{
	if (this->animationFrames == nullptr) {
		return 0;
	}
	else {
		return this->animationFrames->size();
	}
}

GraphicsBuffer Model::getAnimationFrame(unsigned int frameIndex) const
{
	if (this->animationFrames == nullptr) {
		return GraphicsBuffer(0, 0);
	}
	else {
		return GraphicsBuffer(this->animationFrames[frameIndex]);
	}
}

std::vector<GraphicsBuffer> Model::getAllAnimationFrames() const
{
	if (this->animationFrames == nullptr) {
		return std::vector<GraphicsBuffer>();
	}
	else {
		return this->animationFrames;
	}
}
