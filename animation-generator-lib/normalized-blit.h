#pragma once

#include "buffer-space-normalizer.h"
#include "graphics-buffer.h"

class NormalizedBlit {
public:
	/**
	* Blits center of source into destination at designated position.
	*/
	void blitTo(const GraphicsBuffer& source, GraphicsBuffer& destination, BufferPoint position);
};