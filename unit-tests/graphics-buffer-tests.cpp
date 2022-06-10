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
				GraphicsBuffer a({ 5, 5 }, {255, 255, 255});
				GraphicsBuffer b({ 5, 4 }, {255, 255, 254});
				Assert::IsFalse(a == b);
			}
		}

		TEST_METHOD(section1Test) {
			GraphicsBuffer source({ 150, 100 });
			source.setSubpixelValues(sourcebmp);
			GraphicsBuffer expectedResult({ 150, 100 });
			expectedResult.setSubpixelValues(testcase1bmp);
			GraphicsBuffer section = source.createSection({17, 19}, {87, 54});
			Assert::IsTrue(section == expectedResult);
		}

		TEST_METHOD(section2Test) {
			GraphicsBuffer source({ 150, 100 });
			source.setSubpixelValues(sourcebmp);
			GraphicsBuffer expectedResult({ 150, 100 });
			expectedResult.setSubpixelValues(testcase2bmp);
			GraphicsBuffer section = source.createSection({ -18, -27 }, {95, 63}, {0, 255, 255});
			Assert::IsTrue(section == expectedResult);
		}

		TEST_METHOD(blit1Test) {
			GraphicsBuffer source({ 150, 100 }, {255, 0, 0});
			source.setSubpixelValues(sourcebmp);
			GraphicsBuffer expectedResult({ 150, 100 }, { 0, 0, 255 });
			expectedResult.setSubpixelValues(testcase3bmp);
			source.blit(source, { -7, 7 }, { 25,44 }, { 86, 54 });
			Assert::IsTrue(source == expectedResult);
		}

		TEST_METHOD(blit2Test) {
			GraphicsBuffer source({ 150, 100 }, { 255, 0, 0 });
			source.setSubpixelValues(sourcebmp);
			GraphicsBuffer expectedResult({ 150, 100 }, { 0, 0, 255 });
			expectedResult.setSubpixelValues(testcase4bmp);
			source.blit(source, { 0,0 }, { -47, -36 }, { 150, 100 });
			Assert::IsTrue(source == expectedResult);
		}
	};
}