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
			Assert::AreEqual(BufferPoint{ -0.8f, 0.75f }, spaceNormalizer.pixelToPoint({0, 0}));
			Assert::AreEqual(BufferPoint{ 0.0f, 0.25f}, spaceNormalizer.pixelToPoint({ 1, 2 }));
			Assert::AreEqual(BufferPoint{ 0.8f, -0.75f}, spaceNormalizer.pixelToPoint({ 3, 4 }));
		}

		TEST_METHOD(pixelToPointOuter)
		{
			BufferSpaceNormalizer spaceNormalizer(5, 4);
			Assert::AreEqual(BufferPoint{ 0.4f, -1.25f }, spaceNormalizer.pixelToPoint({ 4, 3 }));
			Assert::AreEqual(BufferPoint{ 1.2f, -0.25f }, spaceNormalizer.pixelToPoint({ 2, 5 }));
			Assert::AreEqual(BufferPoint{ -0.8f, 1.25f }, spaceNormalizer.pixelToPoint({ -1, 0 }));
			Assert::AreEqual(BufferPoint{ -1.6f, 0.25f }, spaceNormalizer.pixelToPoint({ 1, -2 }));
		}

		/*TEST_METHOD(pixelToPointOutOfBounds)
		{
			BufferSpaceNormalizer spaceNormalizer(3, 3);
			Assert::AreEqual(BufferPoint{ 2.0f, 0.0f }, spaceNormalizer.pixelToPoint({ 0, 3 }));
			Assert::AreEqual(BufferPoint{ 0.0f, 2.0f }, spaceNormalizer.pixelToPoint({ -2, 0 }));
		}*/

		//TEST_METHOD(evenBufferSize)
		//{
		//	BufferSpaceNormalizer spaceNormalizer(2, 2);
		//	//by default 
		//	Assert::AreEqual(BufferPoint{ 2.0f, 0.0f }, spaceNormalizer.pixelToPoint({ 0, 4 }));

		//}

		//TEST_METHOD(zeroSizeBuffer) {
		//	BufferSpaceNormalizer spaceNormalizer(1, 2);
		//	BufferSpaceNormalizer spaceNormalizer(2, 1);
		//}

		
	};
}
