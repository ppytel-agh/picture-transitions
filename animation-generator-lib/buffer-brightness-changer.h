#pragma once

#include "graphics-buffer.h"

class BufferBrightnessChanger {
public:
	/**
	* @param buffer modified buffer
	* @brightnessNorm \in [0,1] 0 - dark, 1 - normal colors
	*/
	void changeBufferBrightness(GraphicsBuffer& buffer, float brightnessNorm);
};