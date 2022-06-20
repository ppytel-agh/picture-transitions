#include "scaler-test.h"

#include <buffer-scaler.h>
#include <functional>

void ScalerTest::initializeUI(wxFrame* parentFrame)
{
	wxPanel* m_panel1;
	wxSlider* xSlider;
	wxStaticText* xPos;
	wxSlider* ySlider;
	wxStaticText* yPos;
	wxPanel* m_panel3;

	wxFrame* frame = new wxFrame(parentFrame, wxID_ANY, wxEmptyString, wxDefaultPosition, wxSize(490, 800), wxDEFAULT_FRAME_STYLE | wxTAB_TRAVERSAL);
	frame->SetSizeHints(wxDefaultSize, wxDefaultSize);

	wxBoxSizer* bSizer1;
	bSizer1 = new wxBoxSizer(wxVERTICAL);

	wxBoxSizer* bSizer2;
	bSizer2 = new wxBoxSizer(wxHORIZONTAL);

	m_panel1 = new wxPanel(frame, wxID_ANY, wxDefaultPosition, wxSize(240, 135), wxTAB_TRAVERSAL);
	bSizer2->Add(m_panel1, 0, wxALIGN_CENTER | wxALL, 5);

	bSizer1->Add(bSizer2, 0, wxEXPAND, 5);

	wxBoxSizer* bSizer3;
	bSizer3 = new wxBoxSizer(wxHORIZONTAL);

	xSlider = new wxSlider(frame, wxID_ANY, 100, -200, 200, wxDefaultPosition, wxDefaultSize, wxSL_HORIZONTAL);
	bSizer3->Add(xSlider, 1, wxALL | wxEXPAND, 5);

	xPos = new wxStaticText(frame, wxID_ANY, wxT("scaleX: 1.0"), wxDefaultPosition, wxDefaultSize, 0);
	xPos->Wrap(-1);
	bSizer3->Add(xPos, 0, wxALL, 5);

	bSizer1->Add(bSizer3, 0, wxEXPAND, 5);

	wxBoxSizer* bSizer4;
	bSizer4 = new wxBoxSizer(wxHORIZONTAL);

	ySlider = new wxSlider(frame, wxID_ANY, 100, -200, 200, wxDefaultPosition, wxDefaultSize, wxSL_HORIZONTAL);
	bSizer4->Add(ySlider, 1, wxALL, 5);

	yPos = new wxStaticText(frame, wxID_ANY, wxT("scaleY: 1.0f"), wxDefaultPosition, wxDefaultSize, 0);
	yPos->Wrap(-1);
	bSizer4->Add(yPos, 0, wxALL, 5);


	bSizer1->Add(bSizer4, 0, wxEXPAND, 5);

	m_panel3 = new wxPanel(frame, wxID_ANY, wxDefaultPosition, wxSize(480, 270), wxTAB_TRAVERSAL);
	bSizer1->Add(m_panel3, 0, wxALIGN_CENTER | wxALL, 5);


	frame->SetSizer(bSizer1);
	frame->Layout();

	frame->Centre(wxBOTH);

	frame->Show();

	wxImage::AddHandler(new wxPNGHandler());
	wxImage startKeyframe("tests/animation-generator-ui-test/startkeyframe.png");
	GraphicsBuffer* sourceBuffer = new GraphicsBuffer(WxWidgetsBufferConverter::convertWxImageToBuffer(startKeyframe));
	{
		wxBitmap memoryBitmap(startKeyframe);
		wxMemoryDC memDC;
		memDC.SelectObject(memoryBitmap);
		wxClientDC dc(m_panel1);
		dc.Blit(0, 0, 240, 135, &memDC, 0, 0);
	}

	float* scaleX = new float{ 1.0f };
	float* scaleY = new float{ 1.0f };

	std::function<void()>* rescaleAndDraw = new std::function<void()>{
		[=]() {
			BufferScaler scaler;
			GraphicsBuffer scaledBuffer = scaler.scaleBuffer(*sourceBuffer, *scaleX, *scaleY);
			if (!scaledBuffer.isEmpty()) {
				wxImage scaledBufferImage = WxWidgetsBufferConverter::convertBufferToWxImage(scaledBuffer);
				m_panel3->ClearBackground();
				wxBitmap memoryBitmap(scaledBufferImage);
				wxMemoryDC memDC;
				memDC.SelectObject(memoryBitmap);
				wxClientDC dc(m_panel3);
				dc.Blit(0, 0, 480, 270, &memDC, 0, 0);
			}
		}
	};
	std::function<void(wxScrollEvent&)>* xScrollFunction = new std::function<void(wxScrollEvent&)>{
		[=](wxScrollEvent&) {
			int sliderVal = xSlider->GetValue();
			*scaleX = float(sliderVal) / 100.0f;
			std::stringstream newLabel;
			newLabel << "scale: " << *scaleX;
			xPos->SetLabel(newLabel.str());
			(*rescaleAndDraw)();
		}
	};
	std::function<void(wxScrollEvent&)>* yScrollFunction = new std::function<void(wxScrollEvent&)>{
		[=](wxScrollEvent&) {
			int sliderVal = ySlider->GetValue();
			*scaleY = float(sliderVal) / 100.0f;
			std::stringstream newLabel;
			newLabel << "scale: " << *scaleY;
			yPos->SetLabel(newLabel.str());
			(*rescaleAndDraw)();
		}
	};
	// Connect Events
	xSlider->Bind(wxEVT_SCROLL_CHANGED, *xScrollFunction);
	ySlider->Bind(wxEVT_SCROLL_CHANGED, *yScrollFunction);
}
