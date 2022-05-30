#include "visual-tests-frame.h"

VisualTestsFrame::VisualTestsFrame(VisualTestRecord* tests, size_t noTests):wxFrame(NULL, wxID_ANY, "testy wizualne", wxDefaultPosition, wxSize(-1, -1)) {
	wxFrame* testsParnetFrame = this;

	this->SetSizeHints(wxDefaultSize, wxDefaultSize);

	wxBoxSizer* mainSizer;
	mainSizer = new wxBoxSizer(wxVERTICAL);

	for (size_t i = 0; i < noTests; i++) {
		VisualTestRecord& test = tests[i];
		wxButton* openTestButton = new wxButton(this, wxID_ANY, test.name, wxDefaultPosition, wxDefaultSize, 0);
		openTestButton->SetFont(wxFont(10, wxFONTFAMILY_MODERN, wxFONTSTYLE_NORMAL, wxFONTWEIGHT_NORMAL, false, wxT("Consolas")));
		mainSizer->Add(openTestButton, 0, wxALL, 5);
		this->Bind(wxEVT_COMMAND_BUTTON_CLICKED, [&test, testsParnetFrame](wxCommandEvent& event) {
			test.instance->initializeUI(testsParnetFrame);
			}, openTestButton->GetId());
	}

	this->SetSizer(mainSizer);
	this->Layout();
	mainSizer->Fit(this);

	this->Centre(wxBOTH);
}