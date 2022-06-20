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
			Assert::AreEqual((unsigned char)0, imageFromEmpty.GetRed(0, 0));
			Assert::AreEqual((unsigned char)0, imageFromEmpty.GetGreen(0, 0));
			Assert::AreEqual((unsigned char)0, imageFromEmpty.GetBlue(0, 0));
			Assert::AreEqual((unsigned char)0, imageFromEmpty.GetAlpha(0, 0));
		}

		TEST_METHOD(nonemptyBuffer) {
			GraphicsBuffer nonemptyBuffer({ 2, 3 });
			wxImage imageFromEmpty = WxWidgetsBufferConverter::convertBufferToWxImage(nonemptyBuffer);
			Assert::AreEqual(2, imageFromEmpty.GetWidth());
			Assert::AreEqual(3, imageFromEmpty.GetHeight());
		}

		TEST_METHOD(emptyImage)
		{
			{
				wxImage emptyImage(0, 0);
				GraphicsBuffer buffer = WxWidgetsBufferConverter::convertWxImageToBuffer(emptyImage);
				Assert::IsTrue(buffer.isEmpty());
			}
			{
				wxImage emptyImage(0, 1);
				GraphicsBuffer buffer = WxWidgetsBufferConverter::convertWxImageToBuffer(emptyImage);
				Assert::IsTrue(buffer.isEmpty());
			}
			{
				wxImage emptyImage(1, 0);
				GraphicsBuffer buffer = WxWidgetsBufferConverter::convertWxImageToBuffer(emptyImage);
				Assert::IsTrue(buffer.isEmpty());
			}
			{
				wxImage emptyImage(1, 1);
				GraphicsBuffer buffer = WxWidgetsBufferConverter::convertWxImageToBuffer(emptyImage);
				Assert::IsFalse(buffer.isEmpty());
			}
		}
	};
}
