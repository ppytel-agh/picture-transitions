#include "converter-test.h"

void ConverterTest::initializeUI(wxFrame* parentFrame)
{
	wxImage::AddHandler(new wxPNGHandler);
	wxImage jeziorkoImage("tests/converter-test/jeziorko.png");
	GraphicsBuffer jeziorkoBuffer = WxWidgetsBufferConverter::convertWxImageToBuffer(jeziorkoImage);
	wxImage jeziorkoImageProcessed = WxWidgetsBufferConverter::convertBufferToWxImage(jeziorkoBuffer);

	wxFrame* simpleFrame = new wxFrame(parentFrame, wxID_ANY, "przykladowy test", wxDefaultPosition, wxSize(1400, 900));
	simpleFrame->Show();

	{
		wxBitmap memoryBitmap(jeziorkoImageProcessed);
		wxMemoryDC memDC;
		memDC.SelectObject(memoryBitmap);
		wxClientDC dc(simpleFrame);
		dc.Blit(50, 50, 1280, 720, &memDC, 0, 0);
	}
}
