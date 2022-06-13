#include "pch.h"
#include "CppUnitTest.h"
#include "../animation-generator-lib/graphics-buffer.h"
#include "buffer-tests-bitmaps/sourcebmp.h"
#include "buffer-tests-bitmaps/testcase1bmp.h"
#include "buffer-tests-bitmaps/testcase2bmp.h"
#include "buffer-tests-bitmaps/testcase3bmp.h"
#include "buffer-tests-bitmaps/testcase4bmp.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace unittests
{
	TEST_CLASS(GraphicsBufferTests)
	{
	public:
		TEST_METHOD(initialization) {
			GraphicsBuffer buffer({ 2, 1 }, { 127, 0, 68 });
			Assert::AreEqual(2, buffer.GetSize().width);
			Assert::AreEqual(1, buffer.GetSize().height);
			Assert::AreEqual({ 127, 0, 68, 127, 0, 68 }, buffer.getSubpixelValues());
		}
		TEST_METHOD(copyModification) {
			GraphicsBuffer buffer({ 2, 2 });
			GraphicsBuffer copy(buffer);
			Assert::IsTrue(buffer == copy);
			copy.setSubpixelValues({ 1, 1, 1 });
			Assert::IsFalse(buffer == copy);
		}
		TEST_METHOD(emptyBuffer) {
			{
				GraphicsBuffer buffer({ 2, 2 });
				Assert::IsFalse(buffer.IsEmpty());
			}
			{
				GraphicsBuffer buffer({ 2, 0 });
				Assert::IsTrue(buffer.IsEmpty());
			}
			{
				GraphicsBuffer buffer({ 0, 2 });
				Assert::IsTrue(buffer.IsEmpty());
			}
		}
		TEST_METHOD(moveSemantics) {
			GraphicsBuffer buffer({ 2, 2 });
			GraphicsBuffer copyOfOriginal(buffer);
			GraphicsBuffer moved = std::move(buffer);
			Assert::IsTrue(buffer.IsEmpty());
			Assert::IsFalse(copyOfOriginal == buffer);
			Assert::IsTrue(moved == copyOfOriginal);
		}
		TEST_METHOD(receivedSubpixelsCopyModification) {
			GraphicsBuffer buffer({ 2, 2 }, {0, 0, 0});
			std::vector<unsigned char> subpixels = buffer.getSubpixelValues();
			subpixels[0] = 128;
			Assert::IsFalse(subpixels == buffer.getSubpixelValues());
		}
		TEST_METHOD(puttedSubpixelsCopyModification) {
			GraphicsBuffer buffer({ 2, 1 });
			std::vector<unsigned char> subpixels{ 128, 0, 128, 128, 0, 128};
			buffer.setSubpixelValues(subpixels);
			subpixels[0] = 255;
			Assert::IsTrue(subpixels == buffer.getSubpixelValues());
		}
		TEST_METHOD(puttedSubpixelsOffset) {
			GraphicsBuffer buffer({ 2, 1 }, {128, 0, 255});
			buffer.setSubpixelValues({ 64, 20 }, 2);
			Assert::AreEqual({ 128, 0, 64, 20, 0, 255 }, buffer.getSubpixelValues());
		}
		TEST_METHOD(puttedSubpixelsOverflow) {
			GraphicsBuffer buffer({ 1, 1 });
			buffer.setSubpixelValues({ 64, 20, 5, 102, 206 }, 5);
			Assert::AreEqual({ 64, 20, 5 }, buffer.getSubpixelValues());
		}
		TEST_METHOD(comparisonTest) {
			{
				GraphicsBuffer a({ 5, 5 });
				GraphicsBuffer b({ 5, 5 });
				Assert::IsTrue(a == b);
			}
			{
				GraphicsBuffer a({ 5, 5 });
				GraphicsBuffer b({ 5, 4 });
				Assert::IsFalse(a == b);
			}
			{
				GraphicsBuffer a({ 5, 5 }, { 255, 255, 255 });
				GraphicsBuffer b({ 5, 4 }, { 255, 255, 254 });
				Assert::IsFalse(a == b);
			}
		}

		TEST_METHOD(section1Test) {
			GraphicsBuffer source({ 150, 100 });
			source.setSubpixelValues(sourcebmp);
			GraphicsBuffer expectedResult({ 150, 100 });
			source.setSubpixelValues(testcase1bmp);
			GraphicsBuffer section = source.createSection({ 17, 19 }, { 87, 54 });
			Assert::IsTrue(section == expectedResult);
		}

		TEST_METHOD(section2Test) {
			GraphicsBuffer source({ 150, 100 });
			source.setSubpixelValues(sourcebmp);
			GraphicsBuffer expectedResult({ 150, 100 });
			source.setSubpixelValues(testcase2bmp);
			GraphicsBuffer section = source.createSection({ -18, -27 }, { 95, 63 }, { 0, 255, 255 });
			Assert::IsTrue(section == expectedResult);
		}

		TEST_METHOD(blit1Test) {
			GraphicsBuffer source({ 150, 100 });
			source.setSubpixelValues(sourcebmp);
			GraphicsBuffer expectedResult({ 150, 100 });
			source.setSubpixelValues(testcase3bmp);
			source.blit(source, { -7, 7 }, { 25,44 }, { 86, 54 });
			Assert::IsTrue(source == expectedResult);
		}

		TEST_METHOD(blit2Test) {
			GraphicsBuffer source({ 150, 100 });
			source.setSubpixelValues(sourcebmp);
			GraphicsBuffer expectedResult({ 150, 100 });
			source.setSubpixelValues(testcase4bmp);
			source.blit(source, { 0,0 }, { -47, -36 }, { 150, 100 });
			Assert::IsTrue(source == expectedResult);
		}
	};
}