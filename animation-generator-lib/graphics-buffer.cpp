#include "graphics-buffer.h"

GraphicsBuffer::GraphicsBuffer(Size size, Pixel initialColour) : size{ size }, pixels{ std::make_unique<Pixel[]>(size.getNumberOfPixels()) }
{
	for (unsigned int i = 0; i < size.getNumberOfPixels(); i++)
	{
		this->pixels[i] = initialColour;
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
		if (pixels[i].red != buffer.pixels[i].red) {
			return false;
		}
		if (pixels[i].green != buffer.pixels[i].green) {
			return false;
		}
		if (pixels[i].blue != buffer.pixels[i].blue) {
			return false;
		}
	}
	return true;
}

unsigned int GraphicsBuffer::getSubpixelIndex(BufferPixel px, SubpixelOffset offset) const
{
	//tutaj nie trzeba siê odnosiæ do tablicy pikseli, po prostu wyliczyæ indeks na w oparciu o rozmiar bufora i wspó³rzêdn¹ w przestrzeni bufora(BufferPixel)
	Pixel tmp = {};

	tmp = pixels[size.width * px.i + px.j];

	if (offset == 0) return tmp.red;
	else if (offset == 1) return tmp.green;
	else return tmp.blue;
}

GraphicsBuffer GraphicsBuffer::createSection(BufferPixel topLeft, Size size, Pixel sectionBackgroundColour) const
{
	// jak ten lewy górny róg ³¹czy siê z tym bufferem?
	//top left to jest wspó³rzêdna piksela instancji, który bêdzie stanowi³ lewy górny piksel wycinka
	GraphicsBuffer tmp = GraphicsBuffer(size, sectionBackgroundColour);

	return tmp;
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

void GraphicsBuffer::blit(const GraphicsBuffer& source, BufferPixel sourceTopLeft, BufferPixel destinationTopLeft, Size size)
{
	// co z tymi rogami?
	//w instancji przesuwasz siê na pozycjê destinationTopLeft i wklejasz tam piksele pobrane z source od pozycji sourceTopLeft; piksele które nie mieszcz¹ siê w instancji trzeba zignorowaæ
}