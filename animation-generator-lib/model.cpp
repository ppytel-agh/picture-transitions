#include "model.h"

void Model::reset()
{
	this->startKeyframe = nullptr;
	this->endKeyframe = nullptr;
	this->animationFrames = nullptr;
}

void Model::setStartKeyframe(GraphicsBuffer&& newStartKeyframe)
{
	this->startKeyframe.reset(new GraphicsBuffer(std::move(newStartKeyframe)));
}

GraphicsBuffer Model::getStartKeyframe() const
{
	if (this->startKeyframe == nullptr) {
		return GraphicsBuffer({ 0, 0 });
	}
	else {
		return GraphicsBuffer(*this->startKeyframe);
	}
}

Size Model::getStartKeyframeSize() const
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
	this->endKeyframe.reset(new GraphicsBuffer(std::move(newEndKeyframe)));
}

GraphicsBuffer Model::getEndKeyframe() const
{
	if (this->endKeyframe == nullptr) {
		return GraphicsBuffer({ 0, 0 });
	}
	else {
		return GraphicsBuffer(*this->endKeyframe);
	}
}

Size Model::getEndKeyframeSize() const
{
	if (this->endKeyframe == nullptr) {
		return { 0, 0 };
	}
	else {
		return this->endKeyframe->getSize();
	}
}

void Model::setAnimationFrames(std::vector<GraphicsBuffer>&& newAnimationFrames)
{
	this->animationFrames.reset(new std::vector<GraphicsBuffer>(std::move(newAnimationFrames)));
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
		return GraphicsBuffer({ 0, 0 });
	}
	else {
		return GraphicsBuffer(( * this->animationFrames)[frameIndex]);
	}
}

std::vector<GraphicsBuffer> Model::getAllAnimationFrames() const
{
	if (this->animationFrames == nullptr) {
		return std::vector<GraphicsBuffer>();
	}
	else {
		return *this->animationFrames;
	}
}
