#include "animation-generator-test.h"

void AnimationGeneratorTest::initializeUI(wxFrame* parentFrame)
{
	wxFrame* window;
	wxPanel* m_panel1;
	wxPanel* m_panel2;
	wxPanel* m_panel3;
	wxTextCtrl* m_textCtrl1;
	wxButton* m_button1;
	wxButton* m_button2;
	wxButton* m_button3;
	wxScrolledWindow* m_scrolledWindow1;
	wxStaticText* m_staticText1;

	window = new wxFrame(parentFrame, wxID_ANY, wxEmptyString, wxDefaultPosition, wxSize(530, 600), wxDEFAULT_FRAME_STYLE | wxTAB_TRAVERSAL);

	window->SetSizeHints(wxDefaultSize, wxDefaultSize);

	wxBoxSizer* bSizer1;
	bSizer1 = new wxBoxSizer(wxVERTICAL);

	wxBoxSizer* bSizer2;
	bSizer2 = new wxBoxSizer(wxHORIZONTAL);

	m_panel1 = new wxPanel(window, wxID_ANY, wxDefaultPosition, wxSize(240, 135), wxTAB_TRAVERSAL);
	bSizer2->Add(m_panel1, 0, wxALL, 5);

	m_panel2 = new wxPanel(window, wxID_ANY, wxDefaultPosition, wxSize(240, 135), wxTAB_TRAVERSAL);
	bSizer2->Add(m_panel2, 0, wxALL, 5);


	bSizer1->Add(bSizer2, 0, wxEXPAND, 5);

	m_textCtrl1 = new wxTextCtrl(window, wxID_ANY, wxEmptyString, wxDefaultPosition, wxDefaultSize, 0);
	bSizer1->Add(m_textCtrl1, 0, wxALL | wxEXPAND, 5);

	m_button1 = new wxButton(window, wxID_ANY, wxT("Generate"), wxDefaultPosition, wxDefaultSize, 0);
	bSizer1->Add(m_button1, 0, wxALL, 5);

	m_panel3 = new wxPanel(window, wxID_ANY, wxDefaultPosition, wxSize(240, 135), wxTAB_TRAVERSAL);
	m_panel3->SetBackgroundColour(wxSystemSettings::GetColour(wxSYS_COLOUR_ACTIVECAPTION));

	bSizer1->Add(m_panel3, 0, wxALL, 5);

	m_button2 = new wxButton(window, wxID_ANY, wxT("Next"), wxDefaultPosition, wxDefaultSize, 0);
	bSizer1->Add(m_button2, 0, wxALL, 5);
	m_button3 = new wxButton(window, wxID_ANY, wxT("Prev"), wxDefaultPosition, wxDefaultSize, 0);
	bSizer1->Add(m_button3, 0, wxALL, 5);

	m_staticText1 = new wxStaticText(window, wxID_ANY, wxT("frame no: i/n"), wxDefaultPosition, wxDefaultSize, 0);
	bSizer1->Add(m_staticText1, 0, wxALL, 5);

	window->SetSizer(bSizer1);
	window->Layout();

	window->Centre(wxBOTH);

	window->Show();

	wxImage::AddHandler(new wxPNGHandler());
	wxImage startKeyframe("tests/animation-generator-ui-test/startkeyframe.png");
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


	GraphicsBuffer* startKeyframeBuffer = new GraphicsBuffer(WxWidgetsBufferConverter::convertWxImageToBuffer(startKeyframe));
	GraphicsBuffer* endKeyframeBuffer = new GraphicsBuffer(WxWidgetsBufferConverter::convertWxImageToBuffer(endKeyframe));
	SimpleAnimationGenerator* animationGenerator = new SimpleAnimationGenerator();
	std::vector<wxPanel*>* outputPanels = new std::vector<wxPanel*>();

	class MockFiller : public AnimationFrameFillerInterface {
	public:
		void fillAnimationFrame(const GraphicsBuffer& startKeyframe, const GraphicsBuffer& endKeyframe, GraphicsBuffer& filledFrame, float frameNorm) override {
			filledFrame.blit(endKeyframe, { 0,0 }, { 0, 0 }, { 240, 135 });
			filledFrame.blit(startKeyframe, { 0,0 }, { 0, 0 }, { (unsigned int)(240 * frameNorm), 135 });
		}
	};
	MockFiller* mockFiller = new MockFiller();

	std::vector<GraphicsBuffer>** frames = new std::vector<GraphicsBuffer>*;
	*frames = new std::vector<GraphicsBuffer>;
	int* frameCounter = new int{};

	std::function<void()>* printFrame = new std::function<void()>{ [=]() {
		int frameNo = *frameCounter;
		GraphicsBuffer frameToPrint = (**frames)[frameNo];
		{
			wxImage frameImage = WxWidgetsBufferConverter::convertBufferToWxImage(frameToPrint);
			wxBitmap memoryBitmap2(frameImage);
			wxMemoryDC memDC2;
			memDC2.SelectObject(memoryBitmap2);
			wxClientDC dc2(m_panel3);
			dc2.Blit(0, 0, 240, 135, &memDC2, 0, 0);
		}
		std::stringstream ss;
		ss << "frame no : " << (*frameCounter) + 1 << " / " << (**frames).size();
		m_staticText1->SetLabel(ss.str());
} };

	std::function<void(wxCommandEvent&)>* prevFrame = new std::function<void(wxCommandEvent&)>{ [=](wxCommandEvent&) {
			(*frameCounter)--;
			if (*frameCounter < 0) {
				*frameCounter = (**frames).size() - 1;
			}
			(*printFrame)();
		}
	};

	std::function<void(wxCommandEvent&)>* nextFrame = new std::function<void(wxCommandEvent&)>{ [=](wxCommandEvent&) {
		(*frameCounter)++;
			if (*frameCounter >= (**frames).size()) {
				*frameCounter = 0;
			}
			(*printFrame)();
		}
	};

	std::function<void(wxCommandEvent&)>* generateFun = new std::function<void(wxCommandEvent&)>{ [=](wxCommandEvent&) {
			std::vector<float> norms;
			wxString textValue = m_textCtrl1->GetValue();
			std::string parsedText(textValue);
			std::stringstream ss(parsedText);
			while (!ss.eof()) {
				float norm;
				ss >> norm;
				norms.push_back(norm);
			}
			for (auto panel : *outputPanels) {
				delete panel;
			}
			outputPanels->erase(outputPanels->begin(), outputPanels->end());
			std::vector<GraphicsBuffer> generatedAnimation = animationGenerator->generateAnimation(
				*startKeyframeBuffer,
				*endKeyframeBuffer,
				*mockFiller,
				{240, 135},
				norms,
				nullptr
			);
			delete* frames;
			*frames = new std::vector<GraphicsBuffer>(generatedAnimation);
			*frameCounter = 0;
			(*printFrame)();
			window->Layout();
	} };
	m_button1->Bind(wxEVT_COMMAND_BUTTON_CLICKED, *generateFun);
	m_button2->Bind(wxEVT_COMMAND_BUTTON_CLICKED, *nextFrame);
	m_button3->Bind(wxEVT_COMMAND_BUTTON_CLICKED, *prevFrame);
}
