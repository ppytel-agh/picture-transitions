#include "buffer-space-normalizer.h"

BufferSpaceNormalizer::BufferSpaceNormalizer(unsigned int w, unsigned int h): width(w), height(h), pixelWidth(0.0f), pixelHeight(0.0f)
{
    if (this->width > 0) {//prevent miscalculations
        this->pixelWidth = 2.0f / this->width;
    }
    if (this->height > 0) {//prevent miscalculations
        this->pixelHeight = 2.0f / this->height;
    }
    this->centralPixel = { int(this->height-1) / 2, int(this->width-1) / 2 };
    this->centralPixelPoint = this->pixelToPoint(centralPixel);
}

BufferPoint BufferSpaceNormalizer::pixelToPoint(BufferPixel px)
{
    float x = -1.0f + (0.5f + px.j) * this->pixelWidth;
    float y = 1.0f - (0.5f + px.i) * this->pixelHeight;
    return BufferPoint{ x, y };
}

BufferPixel BufferSpaceNormalizer::pointToPixel(BufferPoint p)
{
    int xOffset = 0;
    if (this->width > 1) {
        xOffset = (p.x - this->centralPixelPoint.x) / this->pixelWidth;
    }
    int yOffset = 0;
    if (this->height > 1) {
        yOffset = (p.y - this->centralPixelPoint.y) / this->pixelHeight;
    }
    int i = this->centralPixel.i - yOffset;
    int j = this->centralPixel.j + xOffset;
    return BufferPixel{ i, j };
}

float BufferSpaceNormalizer::getPixelWidth()
{
    return this->pixelWidth;
}

float BufferSpaceNormalizer::getPixelHeight()
{
    return this->pixelHeight;
}

BufferPixel BufferSpaceNormalizer::getCentralPixel()
{
    return this->centralPixel;
}

BufferPoint BufferSpaceNormalizer::getCentralPixelPoint()
{
    return this->centralPixelPoint;
}
