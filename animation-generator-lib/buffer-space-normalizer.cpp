#include "buffer-space-normalizer.h"

BufferSpaceNormalizer::BufferSpaceNormalizer(unsigned int w, unsigned int h): width(w), height(h), pixelWidth(0.0f), pixelHeight(0.0f)
{
    if (this->width > 0) {//prevent miscalculations
        this->pixelWidth = 2.0f / this->width;
    }
    if (this->height > 0) {//prevent miscalculations
        this->pixelHeight = 2.0f / this->height;
    }
    this->centralPixel = { int(this->height) / 2, int(this->width) / 2 };
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
    if (this->width > 0) {
        float xDiff = p.x - this->centralPixelPoint.x;
        float xPixelStep = xDiff / this->pixelWidth;
        xOffset = int(xPixelStep);
        float xStepMod = fmod(xPixelStep, 1.0f);
        if (xStepMod >= 0.5f) {
            xOffset += 1;
        }
        else if (xStepMod < -0.5f) {
            xOffset -= 1;
        }
    }

    int yOffset = 0;
    if (this->height > 0) {
        float yDiff = p.y - this->centralPixelPoint.y;
        float yPixelStep = yDiff / this->pixelHeight;
        yOffset = int(yPixelStep);
        float yStepMod = fmod(yPixelStep, 1.0f);
        if (yStepMod > 0.5f) {
            yOffset += 1;
        }
        else if (yStepMod <= -0.5f) {
            yOffset -= 1;
        }
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
