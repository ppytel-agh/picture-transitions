#include "pch.h"
#include "CppUnitTest.h"
#include "../animation-generator-lib/transitions-manager.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace unittests
{
	TEST_CLASS(TransitionsManagerTests)
	{
	public:
		class MockTransition : public AnimationFrameFillerInterface {
		public:
			MockTransition(char t) :token(t) {};
			void fillAnimationFrame(const GraphicsBuffer& startKeyframe, const GraphicsBuffer& endKeyframe, GraphicsBuffer& filledFrame, float frameNorm) {

			}
			char getToken() {
				return this->token;
			}
		private:
			char token;
		};

		TEST_METHOD(getNames)
		{
			MockTransition transitionA('A');
			MockTransition transitionB('B');
			TransitionsManager manager({
				{L"przejœcie A", transitionA},
				{L"przejœcie B", transitionB}
				});
			std::vector < std::wstring> expected{ L"przejœcie A", L"przejœcie B" };
			Assert::IsTrue(manager.getTransitionNames() == expected);
		}

		TEST_METHOD(exists) {
			MockTransition transitionA('A');
			MockTransition transitionB('B');
			TransitionsManager manager({
				{L"przejœcie A", transitionA},
				{L"przejœcie B", transitionB}
				});
			Assert::IsTrue(manager.transitionExists(0));
			Assert::IsTrue(manager.transitionExists(1));
			Assert::IsFalse(manager.transitionExists(2));
			Assert::IsFalse(manager.transitionExists(-1));
			Assert::IsFalse(manager.transitionExists(999));
		}

		TEST_METHOD(getTransitionFiller) {
			MockTransition transitionA('A');
			MockTransition transitionB('B');
			TransitionsManager manager({
				{L"przejœcie A", transitionA},
				{L"przejœcie B", transitionB}
				});
			{
				AnimationFrameFillerInterface& fillerRef = manager.getTransitionFiller(-1);
				bool isEmpty = manager.fillerIsEmpty(fillerRef);
				Assert::AreEqual(true, isEmpty);
			}
			{
				AnimationFrameFillerInterface& fillerRef = manager.getTransitionFiller(2);
				bool isEmpty = manager.fillerIsEmpty(fillerRef);
				Assert::AreEqual(true, isEmpty);
			}
			{
				AnimationFrameFillerInterface& fillerRef = manager.getTransitionFiller(999);
				bool isEmpty = manager.fillerIsEmpty(fillerRef);
				Assert::AreEqual(true, isEmpty);
			}
			{
				MockTransition& mockFiller = dynamic_cast<MockTransition&>(manager.getTransitionFiller(0));
				bool isEmpty = manager.fillerIsEmpty(mockFiller);
				Assert::AreEqual(false, isEmpty);
				Assert::AreEqual('A', mockFiller.getToken());
			}
			MockTransition& mockFiller = dynamic_cast<MockTransition&>(manager.getTransitionFiller(1));
			bool isEmpty = manager.fillerIsEmpty(mockFiller);
			Assert::AreEqual(false, isEmpty);
			Assert::AreEqual('B', mockFiller.getToken());
		}
	};
}
