#pragma once

#include <string>
#include <memory>
#include <vector>
#include <utility>
#include "graphics-buffer.h"

class Model {
public:
	/**
	* empties current field values
	*/
	void reset();
	/**
	* model claims ownership of start keyframe buffer
	* @param nskf new start keyframe
	*/
	void setStartKeyframe(GraphicsBuffer&& nskf);
	/*
	* If start keyframe is not set, then empty buffer is returned
	* @return copy of start keyframe
	*/
	GraphicsBuffer getStartKeyframe() const;
	/**
	* Returns {0,0} is start keyframe is not set
	* @return size of start keyframe
	*/
	std::pair<unsigned int, unsigned int> getStartKeyframeSize() const;
	/**
	* model claims ownership of end keyframe buffer
	* @param nekf new end keyframe
	*/
	void setEndKeyframe(GraphicsBuffer&& nekf);
	/*
	* If end keyframe is not set, then empty buffer is returned
	* @return copy of end keyframe
	*/
	GraphicsBuffer getEndKeyframe() const;
	/**
	* Returns {0,0} is end keyframe is not set
	* @return size of end keyframe
	*/
	std::pair<unsigned int, unsigned int> getEndKeyframeSize() const;
	void setAnimationFrames(std::vector<GraphicsBuffer>&&);
	/**
	* If animation is not set, then 0 is returned
	* @return number of animation frames
	*/
	unsigned int getNumberOfAnimationFrames() const;
	/**
	* @return empty buffer if frame with provided index does not exist
	* @param i frame index
	* @return copy of selected frame buffer
	*/
	GraphicsBuffer getAnimationFrame(unsigned int i) const;
	/**
	* If animation is not set, then ampty vector is returned
	* @return copy of all animation frames
	*/
	std::vector<GraphicsBuffer> getAllAnimationFrames() const;
private:
	std::unique_ptr<GraphicsBuffer> startKeyframe;
	std::unique_ptr<GraphicsBuffer> endKeyframe;
	std::unique_ptr<std::vector<GraphicsBuffer>> animationFrames;
};