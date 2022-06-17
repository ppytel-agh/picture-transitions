#include "sections-test.h"

void SectionsTest::initializeUI(wxFrame* parentFrame)
{
	wxImage::AddHandler(new wxPNGHandler);
	wxImage source("tests/sections-test/testsource.png");
	wxImage expected("tests/sections-test/testcase1.png");

	GraphicsBuffer sourceBuffer({ static_cast<unsigned int>(source.GetWidth()), static_cast<unsigned int>(source.GetHeight()) });
	{
		int noSubpixels = source.GetWidth() * source.GetHeight() * 3;
		std::vector<unsigned char> subpixels(noSubpixels);
		for (int i = 0; i < noSubpixels; i++) {
			subpixels[i] = source.GetData()[i];
		}
		sourceBuffer.setSubpixelValues(subpixels);
	}

	GraphicsBuffer sectionBuffer = sourceBuffer.createSection({ 17, 19 }, { 87, 54 });
	Size bufferSize = sectionBuffer.getSize();
	wxImage section(bufferSize.width, bufferSize.height);
	{
		std::vector<unsigned char> subpixels = sectionBuffer.getSubpixelValues();
		for (int i = 0; i < subpixels.size(); i++) {
			section.GetData()[i] = subpixels[i];
		}
	}

	wxFrame* simpleFrame = new wxFrame(parentFrame, wxID_ANY, "test wycinka", wxDefaultPosition, wxSize(200, 500));

	simpleFrame->SetSizeHints(wxDefaultSize, wxDefaultSize);
	wxBoxSizer* mainSizer;
	mainSizer = new wxBoxSizer(wxVERTICAL);
	wxPanel* sourcePanel = new wxPanel(simpleFrame, wxID_ANY, wxDefaultPosition, wxSize(150, 100));
	mainSizer->Add(sourcePanel);
	wxPanel* expectedPanel = new wxPanel(simpleFrame, wxID_ANY, wxDefaultPosition, wxSize(90, 60));
	mainSizer->Add(expectedPanel);
	wxPanel* actualPanel = new wxPanel(simpleFrame, wxID_ANY, wxDefaultPosition, wxSize(90, 60));
	mainSizer->Add(actualPanel);

	simpleFrame->SetSizer(mainSizer);
	simpleFrame->Layout();
	simpleFrame->Show();

	{
		wxBitmap memoryBitmap(source);
		wxMemoryDC memDC;
		memDC.SelectObject(memoryBitmap);
		wxClientDC dc(sourcePanel);
		dc.Blit(0, 0, 150, 100, &memDC, 0, 0);
	}

	{
		wxBitmap memoryBitmap(expected);
		wxMemoryDC memDC;
		memDC.SelectObject(memoryBitmap);
		wxClientDC dc(expectedPanel);
		dc.Blit(0, 0, 87, 54, &memDC, 0, 0);
	}

	{
		wxBitmap memoryBitmap(section);
		wxMemoryDC memDC;
		memDC.SelectObject(memoryBitmap);
		wxClientDC dc(actualPanel);
		dc.Blit(0, 0, 87, 54, &memDC, 0, 0);
	}
}
