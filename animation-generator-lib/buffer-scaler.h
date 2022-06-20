#pragma once

#include "graphics-buffer.h"
#include "wxWidgets-buffer-converter.h"
#include "normalized-blit.h"

class BufferScaler {
public:
	/**
	* Creates rescaled copy of buffer\n
	* scale value in (0, 1) makes buffer smaller, scale bigger than 1 enlarges buffer
	* @param scaleX if negative then image is flipped in Y axis
	* @param scaleY if negative then image is flipped in X axis
	*/
	GraphicsBuffer scaleBuffer(const GraphicsBuffer& scaledBuffer, float scaleX, float scaleY);
private:
	NormalizedBlit blitOp;
};