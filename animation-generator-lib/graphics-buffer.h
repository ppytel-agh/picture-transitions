#pragma once

#include "buffer-pixel.h"
#include <vector>
#include <memory>

struct Pixel {
	unsigned char red, green, blue;
	Pixel& operator=(const Pixel& rPixel) {
		this->red = rPixel.red;
		this->green = rPixel.green;
		this->blue = rPixel.blue;
		return *this;
	};
};

struct Size {
	unsigned int width, height;
	unsigned int getNumberOfPixels() const {
		return this->width * this->height;
	}
};

enum SubpixelOffset {
	Red = 0,
	Green = 1,
	Blue = 2
};

class GraphicsBuffer {
public:
	GraphicsBuffer(Size size, Pixel initialColour = {});
	GraphicsBuffer(const GraphicsBuffer&);
	GraphicsBuffer(GraphicsBuffer&&);
	~GraphicsBuffer() = default;

	bool operator==(const GraphicsBuffer&) const;
	unsigned int getPixelIndex(BufferPixel px) const;
	unsigned int getSubpixelIndex(BufferPixel px, SubpixelOffset offset) const;
	GraphicsBuffer createSection(BufferPixel topLeft, Size size, Pixel sectionBackgroundColour = {}) const;
	void blit(const GraphicsBuffer& source, BufferPixel sourceTopLeft, BufferPixel destinationTopLeft, Size size);
	std::vector<unsigned char> getSubpixelValues() const;
	void setSubpixelValues(const std::vector<unsigned char>& newValues, unsigned int offset = 0);
	Size getSize() const;
	bool isEmpty() const;
private:
	Size size;
	std::unique_ptr<Pixel[]> pixels;
	Size calculateVisibleFrame(BufferPixel, Size) const;
	BufferPixel adjustFrame(BufferPixel&, Size&) const;
};