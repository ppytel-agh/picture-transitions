#include "pch.h"
#include "CppUnitTest.h"
#include "../animation-generator-lib/model.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace unittests
{
	TEST_CLASS(ModelTests)
	{
	public:
		TEST_METHOD(startKeyframeSet) {
			Model model;
			GraphicsBuffer startKeyframe({ 2, 1 }, {0, 255, 0});
			model.setStartKeyframe(std::move(startKeyframe));
			Assert::IsTrue(startKeyframe.isEmpty());
			std::vector<unsigned char> subpixels = model.getStartKeyframe().getSubpixelValues();
			std::vector<unsigned char> expected{ 0, 255, 0, 0, 255, 0 };
			Assert::IsTrue(expected == subpixels);
		}

		TEST_METHOD(endKeyframeSet) {
			Model model;
			GraphicsBuffer endKeyframe({ 2, 1 }, {0, 0, 255});
			model.setEndKeyframe(std::move(endKeyframe));
			Assert::IsTrue(endKeyframe.isEmpty());
			std::vector<unsigned char> subpixels = model.getEndKeyframe().getSubpixelValues();
			std::vector<unsigned char> expected{ 0, 0, 255, 0, 0, 255 };
			Assert::IsTrue(expected == subpixels);
		}

		TEST_METHOD(keyframeSize) {
			Model model;
			GraphicsBuffer endKeyframe({ 2, 1 });
			model.setStartKeyframe(std::move(endKeyframe));
			Size startKeyframeSize = model.getStartKeyframeSize();
			Assert::AreEqual((unsigned int)2, startKeyframeSize.width);
			Assert::AreEqual((unsigned int)1, startKeyframeSize.height);
		}
	};
}
