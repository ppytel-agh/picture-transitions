#include "buffer-brightness-changer.h"

void BufferBrightnessChanger::changeBufferBrightness(GraphicsBuffer& buffer, float brightnessNorm)
{
	float brightness = brightnessNorm;
	if (brightness < 0.0f) {
		brightness = 0.0f;
	}
	else if (brightness > 1.0f) {
		brightness = 1.0f;
	}
	std::vector<unsigned char> subpixels = buffer.getSubpixelValues();
	for (unsigned char& subpixel : subpixels) {
		subpixel *= brightness;
	}
	buffer.setSubpixelValues(subpixels);
}