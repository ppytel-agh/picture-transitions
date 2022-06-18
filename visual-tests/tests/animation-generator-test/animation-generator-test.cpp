#include "animation-generator-test.h"

void AnimationGeneratorTest::initializeUI(wxFrame* parentFrame)
{
	wxFrame* window;
	wxPanel* m_panel1;
	wxPanel* m_panel2;
	wxPanel* m_panel3;
	wxTextCtrl* m_textCtrl1;
	wxButton* m_button1;
	wxScrolledWindow* m_scrolledWindow1;

	window = new wxFrame(parentFrame, wxID_ANY, wxEmptyString, wxDefaultPosition, wxSize(530, 443), wxDEFAULT_FRAME_STYLE | wxTAB_TRAVERSAL);

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

	m_button1 = new wxButton(window, wxID_ANY, wxT("MyButton"), wxDefaultPosition, wxDefaultSize, 0);
	bSizer1->Add(m_button1, 0, wxALL, 5);

	m_panel3 = new wxPanel(window, wxID_ANY, wxDefaultPosition, wxSize(240, 135), wxTAB_TRAVERSAL);
	m_panel3->SetBackgroundColour(wxSystemSettings::GetColour(wxSYS_COLOUR_ACTIVECAPTION));

	bSizer1->Add(m_panel3, 0, wxALL, 5);


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

	std::function<void(std::vector<GraphicsBuffer>)>* generateCallback = new std::function<void(std::vector<GraphicsBuffer>)>{ [=](std::vector<GraphicsBuffer> generatedAnimation) {
		for (auto frame : generatedAnimation) {
			/*wxPanel* printPanel = new wxPanel(window, wxID_ANY, wxDefaultPosition, wxSize(240, 135), wxTAB_TRAVERSAL);
			bSizer3->Add(printPanel, 0, wxALL, 5);*/
			{
				wxImage frameImage = WxWidgetsBufferConverter::convertBufferToWxImage(frame);
				wxBitmap memoryBitmap2(frameImage);
				wxMemoryDC memDC2;
				memDC2.SelectObject(memoryBitmap2);
				wxClientDC dc2(m_panel3);
				dc2.Blit(0, 0, 240, 135, &memDC2, 0, 0);
			}
			//outputPanels->push_back(printPanel);
}
			window->Layout();
	} };

	std::function<void(wxCommandEvent&)>* generateFun = new std::function<void(wxCommandEvent&)>{ [=] (wxCommandEvent&) {
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
			animationGenerator->generateAnimation(
				*startKeyframeBuffer,
				*endKeyframeBuffer,
				*mockFiller,
				{240, 135},
				norms,
				nullptr,
				* generateCallback
			);
	} };
	m_button1->Bind(wxEVT_COMMAND_BUTTON_CLICKED, *generateFun);
	//m_textCtrl1->Bind(wxEVT_COMMAND_TEXT_UPDATED)
}
