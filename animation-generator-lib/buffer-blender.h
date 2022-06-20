#pragma once

#include "graphics-buffer.h"
#include "buffer-space-normalizer.h"

class BufferBlender {
public:
	BufferBlender(Pixel backgroundColor);
	/**
	* source is blended with (1.0f - destionationPercentage) proportion
	* @param destionationProportion capped into [0,1]
	*/
	void blendIntoBuffer(GraphicsBuffer& destination, const GraphicsBuffer& source, float destionationProportion);
private:
	Pixel backgroundColor;
};