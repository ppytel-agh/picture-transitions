#include "pch.h"
#include "CppUnitTest.h"
#include "../animation-generator-lib/buffer-space-normalizer.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace unittests
{
	TEST_CLASS(BufferSpaceNormalizerTests)
	{
	public:

		TEST_METHOD(pixelSizes) {
			BufferSpaceNormalizer spaceNormalizer(5, 4);
			Assert::AreEqual(0.4f, spaceNormalizer.getPixelWidth());
			Assert::AreEqual(0.5f, spaceNormalizer.getPixelHeight());
		}

		TEST_METHOD(invalidBuffer) {
			{
				BufferSpaceNormalizer spaceNormalizer(0, 1024);
				Assert::AreEqual(0.0f, spaceNormalizer.getPixelWidth());
			}
			{
				BufferSpaceNormalizer spaceNormalizer(1024, 0);
				Assert::AreEqual(0.0f, spaceNormalizer.getPixelHeight());
			}
		}
		TEST_METHOD(pixelToPointInner)
		{
			BufferSpaceNormalizer spaceNormalizer(5, 4);
			Assert::AreEqual(BufferPoint{ -0.8f, 0.75f }, spaceNormalizer.pixelToPoint({ 0, 0 }));
			Assert::AreEqual(BufferPoint{ 0.0f, 0.25f }, spaceNormalizer.pixelToPoint({ 1, 2 }));
			Assert::AreEqual(BufferPoint{ 0.8f, -0.75f }, spaceNormalizer.pixelToPoint({ 3, 4 }));
		}

		TEST_METHOD(pixelToPointOuter)
		{
			BufferSpaceNormalizer spaceNormalizer(5, 4);
			Assert::AreEqual(BufferPoint{ 0.4f, -1.25f }, spaceNormalizer.pixelToPoint({ 4, 3 }));
			Assert::AreEqual(BufferPoint{ 1.2f, -0.25f }, spaceNormalizer.pixelToPoint({ 2, 5 }));
			Assert::AreEqual(BufferPoint{ -0.8f, 1.25f }, spaceNormalizer.pixelToPoint({ -1, 0 }));
			Assert::AreEqual(BufferPoint{ -1.6f, 0.25f }, spaceNormalizer.pixelToPoint({ 1, -2 }));
		}

		TEST_METHOD(pointToPixelInner)
		{
			BufferSpaceNormalizer spaceNormalizer(5, 4);
			Assert::AreEqual(BufferPixel{ 0,0 }, spaceNormalizer.pointToPixel({ -0.8f, 0.75f }));
			Assert::AreEqual(BufferPixel{ 1,2 }, spaceNormalizer.pointToPixel({ 0.0f, 0.25f }));
			Assert::AreEqual(BufferPixel{ 3,4 }, spaceNormalizer.pointToPixel({ 0.8f, -0.75f }));
		}

		TEST_METHOD(pointToPixelOuter)
		{
			BufferSpaceNormalizer spaceNormalizer(5, 4);
			Assert::AreEqual(BufferPixel{ 4,3 }, spaceNormalizer.pointToPixel({ 0.4f, -1.25f }));
			Assert::AreEqual(BufferPixel{ 2,5 }, spaceNormalizer.pointToPixel({ 1.2f, -0.25f }));
			Assert::AreEqual(BufferPixel{ -1,0 }, spaceNormalizer.pointToPixel({ -0.8f, 1.25f }));
			Assert::AreEqual(BufferPixel{ 1,-2 }, spaceNormalizer.pointToPixel({ -1.6f, 0.25f }));
		}

		TEST_METHOD(pointToPixelSlightTilt) {
			BufferSpaceNormalizer spaceNormalizer(5, 4);
			//topleft
			Assert::AreEqual(BufferPixel{ 0, 0 }, spaceNormalizer.pointToPixel({ -0.999999f, 0.999990f }));
			//bottomright
			Assert::AreEqual(BufferPixel{ 3, 4 }, spaceNormalizer.pointToPixel({ 0.999999f, -0.999999f }));
			//middle slightly down
			Assert::AreEqual(BufferPixel{ 2, 2 }, spaceNormalizer.pointToPixel({ 0.0f, -0.000001f }));
			//middle slightly up
			Assert::AreEqual(BufferPixel{ 1, 2 }, spaceNormalizer.pointToPixel({ 0.0f, 0.000001f }));
		}

	};
}
