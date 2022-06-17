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

		TEST_METHOD(centralPixel) {
			{
				BufferSpaceNormalizer spaceNormalizer(5, 4);
				Assert::AreEqual(BufferPixel{ 2,2 }, spaceNormalizer.getCentralPixel());
			}
			{
				BufferSpaceNormalizer spaceNormalizer(4, 5);
				Assert::AreEqual(BufferPixel{ 2,2 }, spaceNormalizer.getCentralPixel());
			}
			{
				BufferSpaceNormalizer spaceNormalizer(3, 3);
				Assert::AreEqual(BufferPixel{ 1,1 }, spaceNormalizer.getCentralPixel());
			}
			{
				BufferSpaceNormalizer spaceNormalizer(2, 2);
				Assert::AreEqual(BufferPixel{ 1,1 }, spaceNormalizer.getCentralPixel());
			}
			{
				BufferSpaceNormalizer spaceNormalizer(1, 1);
				Assert::AreEqual(BufferPixel{ 0,0 }, spaceNormalizer.getCentralPixel());
			}
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


		TEST_METHOD(pointToPixelEdge) {
			{
				BufferSpaceNormalizer spaceNormalizer(5, 4);
				//center
				Assert::AreEqual(BufferPixel{ 2, 2 }, spaceNormalizer.pointToPixel({ 0.0f, 0.0f }));
				Assert::AreEqual(BufferPixel{ 0, 2 }, spaceNormalizer.pointToPixel({ 0.0f, 1.0f }));
				Assert::AreEqual(BufferPixel{ 4, 2 }, spaceNormalizer.pointToPixel({ 0.0f, -1.0f }));
				Assert::AreEqual(BufferPixel{ 2, 0 }, spaceNormalizer.pointToPixel({ -1.0f, 0.0f }));
				Assert::AreEqual(BufferPixel{ 2, 5 }, spaceNormalizer.pointToPixel({ 1.0f, 0.0f }));
			}
			{
				BufferSpaceNormalizer spaceNormalizer(4, 5);
				//center
				Assert::AreEqual(BufferPixel{ 2, 2 }, spaceNormalizer.pointToPixel({ 0.0f, 0.0f }));
				Assert::AreEqual(BufferPixel{ 0, 2 }, spaceNormalizer.pointToPixel({ 0.0f, 1.0f }));
				Assert::AreEqual(BufferPixel{ 5, 2 }, spaceNormalizer.pointToPixel({ 0.0f, -1.0f }));
				Assert::AreEqual(BufferPixel{ 2, 4 }, spaceNormalizer.pointToPixel({ 1.0f, 0.0f }));
				Assert::AreEqual(BufferPixel{ 2, 0 }, spaceNormalizer.pointToPixel({ -1.0f, 0.0f }));
			}
		}

		TEST_METHOD(pointToPixelInnerEdge) {
			{
				BufferSpaceNormalizer spaceNormalizer(5, 4);
				Assert::AreEqual(BufferPixel{1, 3}, spaceNormalizer.pointToPixel({0.5f, 0.5f}));
				Assert::AreEqual(BufferPixel{ 3, 3 }, spaceNormalizer.pointToPixel({ 0.5f, -0.5f }));
				Assert::AreEqual(BufferPixel{ 1, 1 }, spaceNormalizer.pointToPixel({ -0.5f, 0.5f }));
				Assert::AreEqual(BufferPixel{ 3, 1 }, spaceNormalizer.pointToPixel({ -0.5f, -0.5f }));
			}
			{
				BufferSpaceNormalizer spaceNormalizer(4, 5);
				Assert::AreEqual(BufferPixel{ 1, 3 }, spaceNormalizer.pointToPixel({ 0.5f, 0.5f }));
				Assert::AreEqual(BufferPixel{ 3, 3 }, spaceNormalizer.pointToPixel({ 0.5f, -0.5f }));
				Assert::AreEqual(BufferPixel{ 1, 1 }, spaceNormalizer.pointToPixel({ -0.5f, 0.5f }));
				Assert::AreEqual(BufferPixel{ 3, 1 }, spaceNormalizer.pointToPixel({ -0.5f, -0.5f }));
			}
		}

		TEST_METHOD(pointToPixelMinSize) {
			BufferSpaceNormalizer spaceNormalizer(1, 1);
			Assert::AreEqual(BufferPixel{0, 0}, spaceNormalizer.pointToPixel({0.0f, 0.0f}));
			Assert::AreEqual(BufferPixel{0, 0}, spaceNormalizer.pointToPixel({0.5f, 0.5f}));
			Assert::AreEqual(BufferPixel{0, 0}, spaceNormalizer.pointToPixel({-0.5f, 0.5f}));
			Assert::AreEqual(BufferPixel{0, 0}, spaceNormalizer.pointToPixel({-0.5f, -0.5f}));
			Assert::AreEqual(BufferPixel{0, 0}, spaceNormalizer.pointToPixel({0.5f, -0.5f}));

			Assert::AreEqual(BufferPixel{ 0, 0 }, spaceNormalizer.pointToPixel({ 0.0f, 1.0f }));
			Assert::AreEqual(BufferPixel{ 0, 0 }, spaceNormalizer.pointToPixel({ -1.0f, 0.0f }));

			Assert::AreEqual(BufferPixel{ 0, 1 }, spaceNormalizer.pointToPixel({ 1.0f, 0.0f }));
			Assert::AreEqual(BufferPixel{ 1, 0 }, spaceNormalizer.pointToPixel({ 0.0f, -1.0f }));
			Assert::AreEqual(BufferPixel{ 1, 1 }, spaceNormalizer.pointToPixel({ 1.0f, -1.0f }));
		}

		TEST_METHOD(pointToPixelMinSizeTilt) {
			BufferSpaceNormalizer spaceNormalizer(1, 1);
			Assert::AreEqual(BufferPixel{ 0, 0 }, spaceNormalizer.pointToPixel({ -0.999999f, 0.999999f }));
			Assert::AreEqual(BufferPixel{ 0, 0 }, spaceNormalizer.pointToPixel({ 0.999999f, 0.999999f }));
			Assert::AreEqual(BufferPixel{ 0, 0 }, spaceNormalizer.pointToPixel({ 0.999999f, -0.999999f }));
			Assert::AreEqual(BufferPixel{ 0, 0 }, spaceNormalizer.pointToPixel({ -0.999999f, -0.999999f }));

			Assert::AreEqual(BufferPixel{ -1, 0 }, spaceNormalizer.pointToPixel({ -1.0f, 1.000001f }));
			Assert::AreEqual(BufferPixel{ 0, -1 }, spaceNormalizer.pointToPixel({ -1.000001f, 1.00000f }));
		}
	};
}
