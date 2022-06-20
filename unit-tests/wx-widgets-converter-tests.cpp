#include "pch.h"
#include "CppUnitTest.h"
#include "../animation-generator-lib/wxWidgets-buffer-converter.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace unittests
{
	TEST_CLASS(WxWidgetsConverter)
	{
	public:

		TEST_METHOD(emptyBuffer)
		{
			GraphicsBuffer emptyBuffer({});
			Assert::IsTrue(emptyBuffer.isEmpty());
			wxImage imageFromEmpty = WxWidgetsBufferConverter::convertBufferToWxImage(emptyBuffer);
			Assert::AreEqual(1, imageFromEmpty.GetWidth());
			Assert::AreEqual(1, imageFromEmpty.GetHeight());
			Assert::AreEqual((unsigned char)0, imageFromEmpty.GetData()[0]);
			Assert::AreEqual((unsigned char)0, imageFromEmpty.GetData()[1]);
			Assert::AreEqual((unsigned char)0, imageFromEmpty.GetData()[2]);
		}
	};
}
