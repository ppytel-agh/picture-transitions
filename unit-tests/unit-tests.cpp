#include "pch.h"
#include "CppUnitTest.h"
#include "../animation-generator-lib/misc.h"
#include "../animation-generator-lib/animation-generator-app.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace unittests
{
	TEST_CLASS(unittests)
	{
	public:
		
		TEST_METHOD(TestMethod1)
		{
			Misc misc;
			Assert::AreEqual(1, misc.action());
		}

		TEST_METHOD(AppBuild)
		{
			AnimationGeneratorApp app;
		}
	};
}
