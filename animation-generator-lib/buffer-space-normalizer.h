#pragma once

#include "buffer-pixel.h"
#include "buffer-point.h"

class BufferSpaceNormalizer {
public:
	/**
	* 
	*/
	BufferSpaceNormalizer(unsigned int w, unsigned int h);
	/**
	* Returns position of the center of pixel assuming they're evenly sized rectangles
	*/
	BufferPoint pixelToPoint(BufferPixel px);
	BufferPixel pointToPixel(BufferPoint p);
	float getPixelWidth();
	float getPixelHeight();
	BufferPixel getCentralPixel();
	BufferPoint getCentralPixelPoint();
private:
	unsigned int width, height;
	float pixelWidth, pixelHeight;
	BufferPixel centralPixel;
	BufferPoint centralPixelPoint;
};