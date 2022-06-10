#include "graphics-buffer.h"

GraphicsBuffer::GraphicsBuffer(Size size, Pixel initialColour = {}) : size{ size }
{
	pixels[0] = initialColour;

	/*
		0. (0, 0, 0)
		1.
		2.
		3.
		4.
		5.
		...


	*/

	// czy powinienem uwzglêdniaæ lewy górny róg?
}

GraphicsBuffer::GraphicsBuffer(const GraphicsBuffer& buffer)
{
	size = buffer.size;
	pixels = buffer.pixels;
}

bool GraphicsBuffer::operator==(const GraphicsBuffer& buffer) const
{
	if (size.width != buffer.size.width ||
		size.height != buffer.size.height) return false;

	for (unsigned int i = 0; i < size.width * size.height; i++)
	{
		if (pixels[i].red != buffer.pixels[i].red ||
			pixels[i].green != buffer.pixels[i].red ||
			pixels[i].blue != buffer.pixels[i].blue) return false;
	}
}

unsigned int GraphicsBuffer::getSubpixelIndex(BufferPixel px, SubpixelOffset offset) const
{
	Pixel tmp = {};

	tmp = pixels[size.width * px.i + px.j];

	if (offset == 0) return tmp.red;
	else if (offset == 1) return tmp.green;
	else return tmp.blue;
}

GraphicsBuffer GraphicsBuffer::createSection(BufferPixel topLeft, Size size, Pixel sectionBackgroundColour = {}) const
{
	// jak ten lewy górny róg ³¹czy siê z tym bufferem?
	GraphicsBuffer tmp = GraphicsBuffer(size, sectionBackgroundColour);

	return tmp;
}

std::vector<unsigned int> GraphicsBuffer::getSubpixelValues() const
{
	return std::vector<unsigned int> {pixels->red, pixels->green, pixels->blue};
}

void GraphicsBuffer::setSubpixelValues(const std::vector<unsigned int>& newValues, unsigned int offset = 0)
{
	pixels->red = newValues[0];
	pixels->green = newValues[1];
	pixels->blue = newValues[2];
}

void GraphicsBuffer::blit(const GraphicsBuffer& source, BufferPixel sourceTopLeft, BufferPixel destinationTopLeft, Size size)
{
	// co z tymi rogami?
}