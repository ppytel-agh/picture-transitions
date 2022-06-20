#include "normalized-blit.h"

void NormalizedBlit::blitTo(const GraphicsBuffer& source, GraphicsBuffer& destination, BufferPoint position)
{
	Size sourceSize = source.getSize();
	BufferSpaceNormalizer sourceSpace(sourceSize.width, sourceSize.height);
	BufferSpaceNormalizer destinationSpace(destination.getSize().width, destination.getSize().height);
	BufferPixel soruceCenterPixel = sourceSpace.pointToPixel({ 0.0, 0.0 });
	BufferPixel destinationPixel = destinationSpace.pointToPixel(position);
	BufferPixel destinationTopLeft = destinationSpace.pointToPixel(position);
	destinationTopLeft.i -= soruceCenterPixel.i;
	destinationTopLeft.j -= soruceCenterPixel.j;
	destination.blit(source, { 0, 0 }, destinationTopLeft, sourceSize);
}
