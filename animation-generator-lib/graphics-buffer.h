#pragma once

#include "buffer-pixel.h"
#include <vector>
#include <memory>

struct Pixel {
	unsigned char red, green, blue;
};

struct Size {
	unsigned int width, height;
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
	unsigned int getSubpixelIndex(BufferPixel px, SubpixelOffset offset) const;
	GraphicsBuffer createSection(BufferPixel topLeft, Size size, Pixel sectionBackgroundColour = {}) const;
	void blit(const GraphicsBuffer& source, BufferPixel sourceTopLeft, BufferPixel destinationTopLeft, Size size);
	std::vector<unsigned char> getSubpixelValues() const;
	void setSubpixelValues(const std::vector<unsigned char>& newValues, unsigned int offset = 0);

private:
	Size size;
	std::unique_ptr<Pixel[]> pixels;
};