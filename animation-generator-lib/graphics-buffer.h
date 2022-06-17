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
	Size getSize() const;
	/**
	* @return copy of subpixel values
	*/
	std::vector<unsigned char> getSubpixelValues() const;
	/**
	* copies provided values into pixels array
	* @param offset subpixels offset
	*/
	void setSubpixelValues(const std::vector<unsigned char>& newValues, unsigned int offset = 0);
	bool isEmpty() const;
	/**
	* calculates pixel index based on buffer size
	*/
	unsigned int getPixelIndex(BufferPixel px) const;
	/**
	* calculates subpixel index based on buffer size and provied subpixel offset
	*/
	unsigned int getSubpixelIndex(BufferPixel px, SubpixelOffset offset) const;
	/**
	* adjusts provided top left pixel and frame size to be put in buffer boundary
	* @return top left pixel adjustment
	*/
	BufferPixel adjustFrame(BufferPixel& topLeft, Size& size) const;
	/*
	* Creates section of buffer.\n
	* Section has exact provided size.\n
	* If buffer does not contain pixel section is filled with provided background colour.
	*/
	GraphicsBuffer createSection(BufferPixel topLeft, Size size, Pixel sectionBackgroundColour = {}) const;
	/**
	* Blits pixels of provided source buffer into current buffer.\n
	* If source does not contains pixel, it is ignored.\n
	* If buffer does not contain pixel it is ignored.\n
	* Blit size is adjusted to not overflow destination buffer.\n
	*/
	void blit(const GraphicsBuffer& source, BufferPixel sourceTopLeft, BufferPixel destinationTopLeft, Size size);
private:
	Size size;
	std::unique_ptr<Pixel[]> pixels;
};