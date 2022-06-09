#include "graphic-buffer-test.h"
#include "sourcebmp.h"

void GraphicBufferTest::initializeUI(wxFrame* parentFrame)
{
	wxFrame* simpleFrame = new wxFrame(parentFrame, wxID_ANY, "przykladowy test");

	unsigned char* subpixels = reinterpret_cast<unsigned char*>(sourcebmp);
	simpleFrame->SetSizeHints(wxDefaultSize, wxDefaultSize);
	wxBoxSizer* mainSizer;
	mainSizer = new wxBoxSizer(wxHORIZONTAL);
	wxPanel* panel = new wxPanel(simpleFrame, wxID_ANY, wxDefaultPosition, wxSize(150, 100));
	mainSizer->Add(panel);
	simpleFrame->SetSizer(mainSizer);
	simpleFrame->Layout();
	simpleFrame->Show();

	wxImage image(150, 100 , subpixels);
	wxBitmap memoryBitmap(image);
	wxMemoryDC memDC;
	memDC.SelectObject(memoryBitmap);
	wxClientDC dc(panel);
	dc.Blit(0, 0, 150, 100, &memDC, 0, 0);
}
