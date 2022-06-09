<<<<<<< HEAD
#pragma once

#include "buffer-pixel.h"
#include <vector>

struct Pixel {
	unsigned int red, green, blue;
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
	// GraphicsBuffer(GraphicsBuffer&&);
	~GraphicsBuffer() = default;

	bool operator==(const GraphicsBuffer&) const;
	unsigned int getSubpixelIndex(BufferPixel px, SubpixelOffset offset) const;
	GraphicsBuffer createSection(BufferPixel topLeft, Size size, Pixel sectionBackgroundColour = {}) const;
	void blit(const GraphicsBuffer& source, BufferPixel sourceTopLeft, BufferPixel destinationTopLeft, Size size);
	std::vector<unsigned int> getSubpixelValues() const;
	void setSubpixelValues(const std::vector<unsigned int>& newValues, unsigned int offset = 0);

private:
	Size size;
	Pixel* pixels;
=======
#pragma once

#include "buffer-pixel.h"
#include <vector>

struct Pixel {
	unsigned int red, green, blue;
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
	~GraphicsBuffer();
	bool operator==(const GraphicsBuffer&) const;
	unsigned int getSubpixelIndex(BufferPixel px, SubpixelOffset offset) const;
	bool isIndexValid(unsigned int i) const;
	GraphicsBuffer createSection(BufferPixel topLeft, Size size, Pixel sectionBackgroundColour = {}) const;
	void blit(const GraphicsBuffer& source, BufferPixel sourceTopLeft, BufferPixel destinationTopLeft, Size size);
	std::vector<unsigned int> getSubpixelValues() const;
	void setSubpixelValues(const std::vector<unsigned int>& newValues, unsigned int offset = 0);
private:
	Size size;
	Pixel* pixels;
>>>>>>> dcc71a2c2c0e944523ef9139a2e01a94376265b4
};