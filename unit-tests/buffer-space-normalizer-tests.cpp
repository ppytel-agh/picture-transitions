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
			BufferSpaceNormalizer spaceNormalizer(1, 2);
			Assert::AreEqual(4.0f, spaceNormalizer.getPixelWidth());
			Assert::AreEqual(2.0f, spaceNormalizer.getPixelHeight());
			BufferSpaceNormalizer spaceNormalizer2(4, 3);
			Assert::AreEqual(0.66f, spaceNormalizer2.getPixelWidth(), 0.01f);
			Assert::AreEqual(1.0f, spaceNormalizer2.getPixelHeight());
			BufferSpaceNormalizer spaceNormalizer3(5, 6);
			Assert::AreEqual(0.5f, spaceNormalizer3.getPixelWidth());
			Assert::AreEqual(0.4f, spaceNormalizer3.getPixelHeight());
		}
		TEST_METHOD(pixelToPointSimple)
		{
			BufferSpaceNormalizer spaceNormalizer(3, 3);
			//top left
			Assert::AreEqual(BufferPoint{ -1.0f, 1.0f }, spaceNormalizer.pixelToPoint({0, 0}));
			//middle center
			Assert::AreEqual(BufferPoint{ 0.0f, 0.0f }, spaceNormalizer.pixelToPoint({1, 1}));
			//bottom center
			Assert::AreEqual(BufferPoint{ 0.0f, -1.0f }, spaceNormalizer.pixelToPoint({2, 1}));
			//middle right
			Assert::AreEqual(BufferPoint{ 1.0f, 0.0f }, spaceNormalizer.pixelToPoint({1, 2}));
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
