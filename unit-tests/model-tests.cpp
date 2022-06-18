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

		TEST_METHOD(startKeyframeSize) {
			Model model;
			GraphicsBuffer startKeyframe({ 2, 1 });
			model.setStartKeyframe(std::move(startKeyframe));
			Size startKeyframeSize = model.getStartKeyframeSize();
			Assert::AreEqual((unsigned int)2, startKeyframeSize.width);
			Assert::AreEqual((unsigned int)1, startKeyframeSize.height);
		}

		TEST_METHOD(endKeyframeSize) {
			Model model;
			GraphicsBuffer endKeyframe({ 1, 2 });
			model.setEndKeyframe(std::move(endKeyframe));
			Size endKeyframeSize = model.getEndKeyframeSize();
			Assert::AreEqual((unsigned int)1, endKeyframeSize.width);
			Assert::AreEqual((unsigned int)2, endKeyframeSize.height);
		}

		TEST_METHOD(numberOfFrames) {
			Model model;
			Assert::AreEqual((unsigned int)0, model.getNumberOfAnimationFrames());
			std::vector<GraphicsBuffer> frames;
			frames.emplace_back(GraphicsBuffer({ 2, 1 }));
			frames.emplace_back(GraphicsBuffer({ 2, 1 }));
			model.setAnimationFrames(std::move(frames));
			Assert::AreEqual((unsigned int)2, model.getNumberOfAnimationFrames());
		}

		TEST_METHOD(setFrames) {
			Model model;
			std::vector<GraphicsBuffer> frames;
			frames.emplace_back(GraphicsBuffer({ 1, 1 }, { 0, 0, 1 }));
			frames.emplace_back(GraphicsBuffer({ 1, 1 }, { 0, 1, 0 }));
			model.setAnimationFrames(std::move(frames));
			Assert::IsTrue(frames.empty());
		}
		TEST_METHOD(getFrame) {
			Model model;
			std::vector<GraphicsBuffer> frames;
			frames.emplace_back(GraphicsBuffer({ 1, 1 }, {0, 0, 1}));
			frames.emplace_back(GraphicsBuffer({ 1, 1 }, {0, 1, 0}));
			model.setAnimationFrames(std::move(frames));
			std::vector<unsigned char> expectedVal1{ 0, 0, 1 };
			std::vector<unsigned char> expectedVal2{ 0, 1, 0 };
			Assert::IsTrue(model.getAnimationFrame(0).getSubpixelValues() == expectedVal1);
			Assert::IsTrue(model.getAnimationFrame(1).getSubpixelValues() == expectedVal2);
		}

		TEST_METHOD(getFrames) {
			Model model;
			Assert::IsTrue(model.getAllAnimationFrames().empty());
			std::vector<GraphicsBuffer> frames;
			frames.emplace_back(GraphicsBuffer({ 1, 1 }, { 0, 0, 1 }));
			model.setAnimationFrames(std::move(frames));
			Assert::AreEqual((size_t)1, model.getAllAnimationFrames().size());
		}
	};
}
