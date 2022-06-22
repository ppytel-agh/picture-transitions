#include "graphics-buffer.h"

GraphicsBuffer::GraphicsBuffer(Size size, Pixel initialColour) : size{ size }
{
	if (this->size.width > 0 && this->size.height > 0) {
		this->pixels = std::make_unique<Pixel[]>(size.getNumberOfPixels());
		for (unsigned int i = 0; i < size.getNumberOfPixels(); i++)
		{
			this->pixels[i] = initialColour;
		}
	}
}

GraphicsBuffer::GraphicsBuffer(const GraphicsBuffer& buffer) : size{ buffer.size }, pixels{ std::make_unique<Pixel[]>(size.getNumberOfPixels()) }
{
	for (unsigned int i = 0; i < size.getNumberOfPixels(); i++)
	{
		this->pixels[i] = buffer.pixels[i];
	}
}

GraphicsBuffer::GraphicsBuffer(GraphicsBuffer&& bufferToMove) : size{ bufferToMove.size }, pixels{ std::move(bufferToMove.pixels) }
{
	bufferToMove.size.width = 0;
	bufferToMove.size.height = 0;
	bufferToMove.pixels = nullptr;
}

bool GraphicsBuffer::operator==(const GraphicsBuffer& buffer) const
{
	if (size.width != buffer.size.width) {
		return false;
	}
	if (size.height != buffer.size.height) {
		return false;
	}

	for (unsigned int i = 0; i < this->size.getNumberOfPixels(); i++)
	{
		Pixel leftPixel = this->pixels[i];
		Pixel rightPixel = buffer.pixels[i];
		if (leftPixel.red != rightPixel.red) {
			return false;
		}
		if (leftPixel.green != rightPixel.green) {
			return false;
		}
		if (leftPixel.blue != rightPixel.blue) {
			return false;
		}
	}
	return true;
}

unsigned int GraphicsBuffer::getPixelIndex(BufferPixel px) const
{
	return this->size.width * px.i + px.j;
}

unsigned int GraphicsBuffer::getSubpixelIndex(BufferPixel px, SubpixelOffset offset) const
{
	//tutaj nie trzeba si� odnosi� do tablicy pikseli, po prostu wyliczy� indeks na w oparciu o rozmiar bufora i wsp�rz�dn� w przestrzeni bufora(BufferPixel)
	Pixel tmp = {};

	tmp = pixels[size.width * px.i + px.j];

	if (offset == 0) return tmp.red;
	else if (offset == 1) return tmp.green;
	else return tmp.blue;
}

GraphicsBuffer GraphicsBuffer::createSection(BufferPixel topLeft, Size size, Pixel sectionBackgroundColour) const
{
	BufferPixel destionationStart{};
	Size sectionOverlapSize = size;
	if (topLeft.j + size.width > this->size.width) {
		sectionOverlapSize.width = this->size.width - topLeft.j;
	}
	if (topLeft.j < 0) {
		destionationStart.j = -topLeft.j;
	}
	if (topLeft.i + size.height > this->size.height) {
		sectionOverlapSize.height = this->size.height - topLeft.i;
	}
	if (topLeft.i < 0) {
		destionationStart.i = -topLeft.i;
	}
	GraphicsBuffer buffer(size, sectionBackgroundColour);
	if (!buffer.isEmpty()) {
		for (int i = destionationStart.i; i < sectionOverlapSize.height; i++) {
			for (int j = destionationStart.j; j < sectionOverlapSize.width; j++) {
				buffer.pixels[buffer.getPixelIndex({ i, j })] = this->pixels[this->getPixelIndex({ topLeft.i + i, topLeft.j + j })];
			}
		}
	}
	return buffer;
}

std::vector<unsigned char> GraphicsBuffer::getSubpixelValues() const
{
	std::vector<unsigned char> subpixelValues;
	for (int i = 0; i < this->size.getNumberOfPixels(); i++) {
		subpixelValues.push_back(this->pixels[i].red);
		subpixelValues.push_back(this->pixels[i].green);
		subpixelValues.push_back(this->pixels[i].blue);
	}
	return subpixelValues;
}

void GraphicsBuffer::setSubpixelValues(const std::vector<unsigned char>& newValues, unsigned int offset)
{
	for (int i = 0; i < newValues.size(); i++) {
		int j = i + offset;
		int pixel = j / 3;
		int subpixel = j % 3;
		if (pixel >= this->size.getNumberOfPixels()) {
			break;
		}
		switch (subpixel) {
		case 0:
			this->pixels[pixel].red = newValues[i];
			break;
		case 1:
			this->pixels[pixel].green = newValues[i];
			break;
		case 2:
			this->pixels[pixel].blue = newValues[i];
			break;
		}
	}
}

Size GraphicsBuffer::getSize() const
{
	return this->size;
}

bool GraphicsBuffer::isEmpty() const
{
	return (this->size.width == 0) || (this->size.height == 0);
}

BufferPixel GraphicsBuffer::adjustFrame(BufferPixel& topLeft, Size& size) const
{
	BufferPixel adjustment{};
	if (topLeft.i < 0) {
		adjustment.i = -topLeft.i;
		size.height += topLeft.i;
		topLeft.i = 0;
	}
	else if (topLeft.i > this->size.height) {
		adjustment.i = this->size.height - topLeft.i;
		topLeft.i = this->size.height;
	}
	if (topLeft.j < 0) {
		adjustment.j = -topLeft.j;
		size.width += topLeft.j;
		topLeft.j = 0;
	}
	else if (topLeft.j > this->size.width) {
		adjustment.j = this->size.width - topLeft.j;
		topLeft.j = this->size.width;
	}
	if (topLeft.j + size.width > this->size.width) {
		int xDiff = this->size.width - topLeft.j;
		if (xDiff < 0) {
			size.width = 0;
		}
		else {
			size.width = xDiff;
		}
	}
	if (topLeft.i + size.height > this->size.height) {
		int yDiff = this->size.height - topLeft.i;
		if (yDiff < 0) {
			size.height = 0;
		}
		else {
			size.height = yDiff;
		}
	}
	return adjustment;
}

void GraphicsBuffer::blit(const GraphicsBuffer& source, BufferPixel sourceTopLeft, BufferPixel destinationTopLeft, Size size)
{
	BufferPixel sourceSectionTopLeft = sourceTopLeft;
	Size sourceSectionSize = size;
	BufferPixel sourceAdjustment = source.adjustFrame(sourceSectionTopLeft, sourceSectionSize);
	GraphicsBuffer sourceSection = source.createSection(sourceSectionTopLeft, sourceSectionSize);

	BufferPixel copyToTopLeft = destinationTopLeft + sourceAdjustment;
	Size copiedSize = sourceSectionSize;
	BufferPixel destinationAdjustment = this->adjustFrame(copyToTopLeft, copiedSize);

	for (int i = 0; i < copiedSize.height; i++) {
		for (int j = 0; j < copiedSize.width; j++) {
			BufferPixel destionationPixel = copyToTopLeft;
			destionationPixel.i += i;
			destionationPixel.j += j;
			BufferPixel sourcePixel = destinationAdjustment;
			sourcePixel.i += i;
			sourcePixel.j += j;
			this->pixels[this->getPixelIndex(destionationPixel)] = sourceSection.pixels[sourceSection.getPixelIndex(sourcePixel)];
		}
	}
}