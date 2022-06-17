#include "graphics-buffer.h"

GraphicsBuffer::GraphicsBuffer(Size size, Pixel initialColour) : size{ size }, pixels{ std::make_unique<Pixel[]>(size.width * size.height) }
{	
	for (unsigned int i = 0; i < size.width * size.height; i++)
	{
		this->pixels[i] = initialColour;
	}
}

GraphicsBuffer::GraphicsBuffer(const GraphicsBuffer& buffer)
{
	size = buffer.size;
	//pixels = buffer.pixels;//èLE - kaødy bufor jest ekskluzywny
}

GraphicsBuffer::GraphicsBuffer(GraphicsBuffer&&)
{
	//to siÍ przyda do funkcji, ktÛre generujπ jakiú bufor
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
	//tutaj nie trzeba siÍ odnosiÊ do tablicy pikseli, po prostu wyliczyÊ indeks na w oparciu o rozmiar bufora i wspÛ≥rzÍdnπ w przestrzeni bufora(BufferPixel)
	Pixel tmp = {};

	tmp = pixels[size.width * px.i + px.j];

	if (offset == 0) return tmp.red;
	else if (offset == 1) return tmp.green;
	else return tmp.blue;
}

GraphicsBuffer GraphicsBuffer::createSection(BufferPixel topLeft, Size size, Pixel sectionBackgroundColour) const
{
	// jak ten lewy gÛrny rÛg ≥πczy siÍ z tym bufferem?
	//top left to jest wspÛ≥rzÍdna piksela instancji, ktÛry bÍdzie stanowi≥ lewy gÛrny piksel wycinka
	GraphicsBuffer tmp = GraphicsBuffer(size, sectionBackgroundColour);

	return tmp;
}

std::vector<unsigned char> GraphicsBuffer::getSubpixelValues() const
{
	//to ma zrobiÊ kopiÍ ca≥ej tablicy pikseli
	//return std::vector<unsigned char> {pixels->red, pixels->green, pixels->blue};
	return std::vector<unsigned char>{};
}

void GraphicsBuffer::setSubpixelValues(const std::vector<unsigned char>& newValues, unsigned int offset)
{
	//to ma docelowo byÊ uøywane przez kod, ktÛry wykonuje operacje piksel po pikselu
	/*pixels->red = newValues[0];
	pixels->green = newValues[1];
	pixels->blue = newValues[2];*/
}

Size GraphicsBuffer::GetSize() const
{
	return this->size;
}

bool GraphicsBuffer::IsEmpty() const
{
	return (this->size.width == 0) || (this->size.height == 0);
}

void GraphicsBuffer::blit(const GraphicsBuffer& source, BufferPixel sourceTopLeft, BufferPixel destinationTopLeft, Size size)
{
	// co z tymi rogami?
	//w instancji przesuwasz siÍ na pozycjÍ destinationTopLeft i wklejasz tam piksele pobrane z source od pozycji sourceTopLeft; piksele ktÛre nie mieszczπ siÍ w instancji trzeba zignorowaÊ
}