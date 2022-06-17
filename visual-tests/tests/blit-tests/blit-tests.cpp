#include "blit-tests.h"

void BlitTests::initializeUI(wxFrame* parentFrame)
{
	wxImage::AddHandler(new wxPNGHandler);
	wxImage source("tests/blit-tests/testsource.png");
	wxImage expected("tests/blit-tests/testcase3.bmp");
	wxImage expected2("tests/blit-tests/blittest2.bmp");


	GraphicsBuffer sourceBuffer({ static_cast<unsigned int>(source.GetWidth()), static_cast<unsigned int>(source.GetHeight()) });
	{
		int noSubpixels = source.GetWidth() * source.GetHeight() * 3;
		std::vector<unsigned char> subpixels(noSubpixels);
		for (int i = 0; i < noSubpixels; i++) {
			subpixels[i] = source.GetData()[i];
		}
		sourceBuffer.setSubpixelValues(subpixels);
	}

	GraphicsBuffer blit1(sourceBuffer);
	blit1.blit(sourceBuffer, { -7, 7 }, { 25,44 }, { 86, 54 });
	GraphicsBuffer blit2(sourceBuffer);
	blit2.blit(sourceBuffer, { 0,0 }, { -47, -36 }, { 150, 100 });

	Size bufferSize = blit1.getSize();
	wxImage actual1(bufferSize.width, bufferSize.height);
	{
		std::vector<unsigned char> subpixels = blit1.getSubpixelValues();
		for (int i = 0; i < subpixels.size(); i++) {
			actual1.GetData()[i] = subpixels[i];
		}
	}
	Size bufferSize2 = blit2.getSize();
	wxImage actual2(bufferSize.width, bufferSize.height);
	{
		std::vector<unsigned char> subpixels = blit2.getSubpixelValues();
		for (int i = 0; i < subpixels.size(); i++) {
			actual2.GetData()[i] = subpixels[i];
		}
	}

	wxFrame* simpleFrame = new wxFrame(parentFrame, wxID_ANY, "test wycinka", wxDefaultPosition, wxSize(500, 500));

	simpleFrame->SetSizeHints(wxDefaultSize, wxDefaultSize);
	wxBoxSizer* mainSizer;
	mainSizer = new wxBoxSizer(wxVERTICAL);
	wxPanel* expectedPanel = new wxPanel(simpleFrame, wxID_ANY, wxDefaultPosition, wxSize(150, 100));
	mainSizer->Add(expectedPanel);
	wxPanel* actualPanel = new wxPanel(simpleFrame, wxID_ANY, wxDefaultPosition, wxSize(150, 100));
	mainSizer->Add(actualPanel);

	wxPanel* expectedPanel2 = new wxPanel(simpleFrame, wxID_ANY, wxDefaultPosition, wxSize(150, 100));
	mainSizer->Add(expectedPanel2);
	wxPanel* actualPanel2 = new wxPanel(simpleFrame, wxID_ANY, wxDefaultPosition, wxSize(150, 100));
	mainSizer->Add(actualPanel2);

	simpleFrame->SetSizer(mainSizer);
	simpleFrame->Layout();
	simpleFrame->Show();


	{
		wxBitmap memoryBitmap(expected);
		wxMemoryDC memDC;
		memDC.SelectObject(memoryBitmap);
		wxClientDC dc(expectedPanel);
		dc.Blit(0, 0, 150, 100, &memDC, 0, 0);
	}

	{
		wxBitmap memoryBitmap(actual1);
		wxMemoryDC memDC;
		memDC.SelectObject(memoryBitmap);
		wxClientDC dc(actualPanel);
		dc.Blit(0, 0, 150, 100, &memDC, 0, 0);
	}

	{
		wxBitmap memoryBitmap(expected2);
		wxMemoryDC memDC;
		memDC.SelectObject(memoryBitmap);
		wxClientDC dc(expectedPanel2);
		dc.Blit(0, 0, 150, 100, &memDC, 0, 0);
	}

	{
		wxBitmap memoryBitmap(actual2);
		wxMemoryDC memDC;
		memDC.SelectObject(memoryBitmap);
		wxClientDC dc(actualPanel2);
		dc.Blit(0, 0, 150, 100, &memDC, 0, 0);
	}
}
