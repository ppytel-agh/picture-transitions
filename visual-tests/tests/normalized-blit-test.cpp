#include "normalized-blit-test.h"

#include <functional>
#include <wxWidgets-buffer-converter.h>
#include <normalized-blit.h>
#include <sstream>

void NormalizedBlitTest::initializeUI(wxFrame* parentFrame)
{
	wxPanel* m_panel1;
	wxPanel* m_panel2;
	wxSlider* xSlider;
	wxStaticText* xPos;
	wxSlider* ySlider;
	wxStaticText* yPos;
	wxPanel* m_panel3;

	wxFrame* frame = new wxFrame(parentFrame, wxID_ANY, wxEmptyString, wxDefaultPosition, wxSize(490, 400), wxDEFAULT_FRAME_STYLE | wxTAB_TRAVERSAL);
	frame->SetSizeHints(wxDefaultSize, wxDefaultSize);

	wxBoxSizer* bSizer1;
	bSizer1 = new wxBoxSizer(wxVERTICAL);

	wxBoxSizer* bSizer2;
	bSizer2 = new wxBoxSizer(wxHORIZONTAL);

	m_panel1 = new wxPanel(frame, wxID_ANY, wxDefaultPosition, wxSize(240, 135), wxTAB_TRAVERSAL);
	bSizer2->Add(m_panel1, 0, wxALIGN_CENTER | wxALL, 5);

	m_panel2 = new wxPanel(frame, wxID_ANY, wxDefaultPosition, wxSize(240, 135), wxTAB_TRAVERSAL);
	bSizer2->Add(m_panel2, 0, wxALIGN_CENTER | wxALL, 5);


	bSizer1->Add(bSizer2, 0, wxEXPAND, 5);

	wxBoxSizer* bSizer3;
	bSizer3 = new wxBoxSizer(wxHORIZONTAL);

	xSlider = new wxSlider(frame, wxID_ANY, 0, -200, 200, wxDefaultPosition, wxDefaultSize, wxSL_HORIZONTAL);
	bSizer3->Add(xSlider, 1, wxALL | wxEXPAND, 5);

	xPos = new wxStaticText(frame, wxID_ANY, wxT("xPos: 0.5"), wxDefaultPosition, wxDefaultSize, 0);
	xPos->Wrap(-1);
	bSizer3->Add(xPos, 0, wxALL, 5);


	bSizer1->Add(bSizer3, 0, wxEXPAND, 5);

	wxBoxSizer* bSizer4;
	bSizer4 = new wxBoxSizer(wxHORIZONTAL);

	ySlider = new wxSlider(frame, wxID_ANY, 0, -200, 200, wxDefaultPosition, wxDefaultSize, wxSL_HORIZONTAL);
	bSizer4->Add(ySlider, 1, wxALL, 5);

	yPos = new wxStaticText(frame, wxID_ANY, wxT("yPos: 0.5"), wxDefaultPosition, wxDefaultSize, 0);
	yPos->Wrap(-1);
	bSizer4->Add(yPos, 0, wxALL, 5);


	bSizer1->Add(bSizer4, 0, wxEXPAND, 5);

	m_panel3 = new wxPanel(frame, wxID_ANY, wxDefaultPosition, wxSize(240, 135), wxTAB_TRAVERSAL);
	bSizer1->Add(m_panel3, 0, wxALIGN_CENTER | wxALL, 5);


	frame->SetSizer(bSizer1);
	frame->Layout();

	frame->Centre(wxBOTH);

	frame->Show();

	wxImage::AddHandler(new wxPNGHandler());
	wxImage startKeyframe("tests/animation-generator-ui-test/startkeyframe.png");
	GraphicsBuffer* sourceBuffer = new GraphicsBuffer(WxWidgetsBufferConverter::convertWxImageToBuffer(startKeyframe));
	sourceBuffer->blit(GraphicsBuffer({ 2, 2 }, { 255, 0, 0 }), { 0, 0 }, { 67, 120 }, { 2, 2 });//red 
	startKeyframe = WxWidgetsBufferConverter::convertBufferToWxImage(*sourceBuffer);
	wxImage endKeyframe("tests/animation-generator-ui-test/endkeyframe.png");
	{
		wxBitmap memoryBitmap(startKeyframe);
		wxMemoryDC memDC;
		memDC.SelectObject(memoryBitmap);
		wxClientDC dc(m_panel1);
		dc.Blit(0, 0, 240, 135, &memDC, 0, 0);
	}
	{
		wxBitmap memoryBitmap(endKeyframe);
		wxMemoryDC memDC;
		memDC.SelectObject(memoryBitmap);
		wxClientDC dc(m_panel2);
		dc.Blit(0, 0, 240, 135, &memDC, 0, 0);
	}

	GraphicsBuffer* endFrameBuffer = new GraphicsBuffer(WxWidgetsBufferConverter::convertWxImageToBuffer(endKeyframe));
	BufferPoint* position = new BufferPoint{ 0.0f, 0.0f };

	std::function<void()>* blitFun = new std::function<void()>{
		[=]() {
			NormalizedBlit blitOp;
			GraphicsBuffer destination(*endFrameBuffer);
			blitOp.blitTo(*sourceBuffer, destination, *position);
			wxImage productIage = WxWidgetsBufferConverter::convertBufferToWxImage(destination);
			wxBitmap memoryBitmap(productIage);
			wxMemoryDC memDC;
			memDC.SelectObject(memoryBitmap);
			wxClientDC dc(m_panel3);
			dc.Blit(0, 0, 240, 135, &memDC, 0, 0);
		}
	};
	std::function<void(wxScrollEvent&)>* xScrollFunction = new std::function<void(wxScrollEvent&)>{
		[=](wxScrollEvent&) {
			int sliderVal = xSlider->GetValue();
			float newX = float(sliderVal) / 100.0f;
			position->x = newX;
			std::stringstream newLabel;
			newLabel << "xPos: " << newX;
			xPos->SetLabel(newLabel.str());
			(* blitFun)();
		}
	};
	std::function<void(wxScrollEvent&)>* yScrollFunction = new std::function<void(wxScrollEvent&)>{
		[=](wxScrollEvent&) {
			int sliderVal = ySlider->GetValue();
			float newY = float(sliderVal) / 100.0f;
			position->y = newY;
			std::stringstream newLabel;
			newLabel << "yPos: " << newY;
			yPos->SetLabel(newLabel.str());
			(*blitFun)();
		}
	};
	// Connect Events
	xSlider->Bind(wxEVT_SCROLL_CHANGED, *xScrollFunction);
	ySlider->Bind(wxEVT_SCROLL_CHANGED, *yScrollFunction);
}
