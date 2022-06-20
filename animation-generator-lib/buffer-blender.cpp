#include "buffer-blender.h"

BufferBlender::BufferBlender(Pixel backgroundColor) : backgroundColor(backgroundColor)
{
}

void BufferBlender::blendIntoBuffer(GraphicsBuffer& destination, const GraphicsBuffer& source, float destionationProportion)
{
	float destinationCapped = destionationProportion;
	if (destinationCapped < 0.0f) {
		destinationCapped = 0.0f;
	}
	else if (destinationCapped > 1.0f) {
		destinationCapped = 1.0f;
	}
	float sourceProportion = 1.0f - destinationCapped;
	Size destinationSize = destination.getSize();
	BufferSpaceNormalizer sourceSpace(source.getSize().width, source.getSize().height);
	BufferSpaceNormalizer destinationSpace(destinationSize.width, destinationSize.height);
	BufferPixel sourceTopLeft = sourceSpace.pointToPixel({ 0.0f, 0.0f });
	BufferPixel destinationCenterPixel = destinationSpace.pointToPixel({ 0.0f, 0.0f });
	sourceTopLeft.i -= destinationCenterPixel.i;
	sourceTopLeft.j -= destinationCenterPixel.j;
	GraphicsBuffer sourceCenterSection = source.createSection(sourceTopLeft, destinationSize, this->backgroundColor);
	std::vector<unsigned char> sourceSubpixels = sourceCenterSection.getSubpixelValues();
	std::vector<unsigned char> destinationPixels = destination.getSubpixelValues();
	for (int i = 0; i < destinationPixels.size(); i++) {
		destinationPixels[i] = destinationPixels[i] * destinationCapped + sourceSubpixels[i] * sourceProportion;
	}
	destination.setSubpixelValues(destinationPixels);
}
