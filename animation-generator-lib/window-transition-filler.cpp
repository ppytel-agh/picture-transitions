#include "window-transition-filler.h"

WindowTransitionFiller::WindowTransitionFiller(): blitter(), scaler()
{
}

void WindowTransitionFiller::fillAnimationFrame(const GraphicsBuffer& startKeyframe, const GraphicsBuffer& endKeyframe, GraphicsBuffer& filledFrame, float frameNorm)
{
	float perspectiveCoefficient = 1.0f;
	int N = 10;
	if (frameNorm < 0.5f) {
		float sx = cos(3.1416f * frameNorm);		
		GraphicsBuffer scaledFrame = this->scaler.scaleBuffer(startKeyframe, sx, 1.0f);
		float normalizedWidth = sx * 2.0f;
		float normalizedDelta = normalizedWidth / N;
		BufferSpaceNormalizer scaledFrameSpace(scaledFrame.getSize().width, scaledFrame.getSize().height);
		for (int i = 0; i < N; i++) {
			float deltaX = (i + 0.5) * normalizedDelta;
			float x = 1.0 - deltaX;
			float scaleY = perspectiveCoefficient / (1 + tan(3.1416f * frameNorm) * deltaX);
			float sectionX = -1.0f + i * (2.0f / N);
			BufferPixel topLeft = scaledFrameSpace.pointToPixel({ sectionX,1.0f });
			Size sectionSize = { scaledFrame.getSize().width * i / N, scaledFrame.getSize().height };
			GraphicsBuffer section = scaledFrame.createSection(topLeft, sectionSize);
			GraphicsBuffer scaledSection = this->scaler.scaleBuffer(section, 1.0f, scaleY);
			this->blitter.blitTo(scaledSection, filledFrame, { x, 0.0f });
		}
	}
	else {
		float sx = cos(3.1416f * (1.0f - frameNorm));
		GraphicsBuffer scaledFrame = this->scaler.scaleBuffer(endKeyframe, sx, 1.0f);
		float normalizedWidth = sx * 2.0f;
		float normalizedDelta = normalizedWidth / N;
		BufferSpaceNormalizer scaledFrameSpace(scaledFrame.getSize().width, scaledFrame.getSize().height);
		for (int i = 0; i < N; i++) {
			float deltaX = (i + 0.5) * normalizedDelta;
			float x = -1.0 + deltaX;
			float scaleY = perspectiveCoefficient / (1 + tan(3.1416f * frameNorm) * deltaX);
			float sectionX = -1.0f + i * (2.0f / N);
			BufferPixel topLeft = scaledFrameSpace.pointToPixel({ sectionX,1.0f });
			Size sectionSize = { scaledFrame.getSize().width * i / N, scaledFrame.getSize().height };
			GraphicsBuffer section = scaledFrame.createSection(topLeft, sectionSize);
			GraphicsBuffer scaledSection = this->scaler.scaleBuffer(section, 1.0f, scaleY);
			this->blitter.blitTo(scaledSection, filledFrame, { x, 0.0f });
		}
	}
}
