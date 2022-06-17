#include "graphic-buffer-test.h"
#include "sourcebmp.h"
#include "testcase1bmp.h"

void GraphicBufferTest::initializeUI(wxFrame* parentFrame)
{
	wxFrame* simpleFrame = new wxFrame(parentFrame, wxID_ANY, "przykladowy test", wxDefaultPosition, wxSize(200, 600));

	simpleFrame->SetSizeHints(wxDefaultSize, wxDefaultSize);
	wxBoxSizer* mainSizer;
	mainSizer = new wxBoxSizer(wxVERTICAL);
	wxPanel* panel = new wxPanel(simpleFrame, wxID_ANY, wxDefaultPosition, wxSize(150, 100));
	mainSizer->Add(panel);
	wxPanel* panel2 = new wxPanel(simpleFrame, wxID_ANY, wxDefaultPosition, wxSize(90, 60));
	mainSizer->Add(panel2);
	simpleFrame->SetSizer(mainSizer);
	simpleFrame->Layout();
	simpleFrame->Show();

	{
		wxImage image(150, 100 , sourcebmp.data(), true);
		wxBitmap memoryBitmap(image);
		wxMemoryDC memDC;
		memDC.SelectObject(memoryBitmap);
		wxClientDC dc(panel);
		dc.Blit(0, 0, 150, 100, &memDC, 0, 0);
	}
	{
		wxImage image(87, 54, testcase1bmp.data(), true);
		wxBitmap memoryBitmap(image);
		wxMemoryDC memDC;
		memDC.SelectObject(memoryBitmap);
		wxClientDC dc(panel2);
		dc.Blit(0, 0, 87, 54, &memDC, 0, 0);
	}
}
