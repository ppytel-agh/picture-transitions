///////////////////////////////////////////////////////////////////////////
// C++ code generated with wxFormBuilder (version 3.10.1-0-g8feb16b3)
// http://www.wxformbuilder.org/
//
// PLEASE DO *NOT* EDIT THIS FILE!
///////////////////////////////////////////////////////////////////////////

#include "mainFrame.h"

///////////////////////////////////////////////////////////////////////////

mainFrame::mainFrame( wxWindow* parent, wxWindowID id, const wxString& title, const wxPoint& pos, const wxSize& size, long style ) : wxFrame( parent, id, title, pos, size, style )
{
	this->SetSizeHints( wxDefaultSize, wxDefaultSize );
	this->SetBackgroundColour( wxColour( 255, 255, 255 ) );

	wxBoxSizer* mainSizer;
	mainSizer = new wxBoxSizer( wxHORIZONTAL );

	wxBoxSizer* menuSizer;
	menuSizer = new wxBoxSizer( wxVERTICAL );

	wxBoxSizer* previewSizer;
	previewSizer = new wxBoxSizer( wxVERTICAL );


	menuSizer->Add( previewSizer, 1, wxEXPAND, 5 );

	separator1 = new wxPanel( this, wxID_ANY, wxDefaultPosition, wxSize( -1,5 ), wxTAB_TRAVERSAL );
	separator1->SetBackgroundColour( wxColour( 255, 255, 255 ) );
	separator1->SetMinSize( wxSize( -1,5 ) );
	separator1->SetMaxSize( wxSize( -1,5 ) );

	menuSizer->Add( separator1, 1, wxEXPAND | wxALL, 5 );

	firstImgPreviewPanel = new wxPanel( this, wxID_ANY, wxDefaultPosition, wxSize( 240,135 ), wxTAB_TRAVERSAL );
	firstImgPreviewPanel->SetBackgroundColour( wxColour( 113, 184, 255 ) );
	firstImgPreviewPanel->SetMinSize( wxSize( 240,135 ) );
	firstImgPreviewPanel->SetMaxSize( wxSize( 240,135 ) );

	menuSizer->Add( firstImgPreviewPanel, 1, wxALIGN_CENTER_HORIZONTAL|wxALL, 5 );

	initFrameSize = new wxStaticText( this, wxID_ANY, wxT("Wymiary klatek:"), wxDefaultPosition, wxSize( 240,-1 ), 0 );
	initFrameSize->Wrap( -1 );
	initFrameSize->SetFont( wxFont( 10, wxFONTFAMILY_MODERN, wxFONTSTYLE_NORMAL, wxFONTWEIGHT_NORMAL, false, wxT("Consolas") ) );
	initFrameSize->SetMinSize( wxSize( 240,-1 ) );

	menuSizer->Add( initFrameSize, 0, wxALIGN_CENTER_HORIZONTAL|wxALL, 5 );

	secondImgPreviewPanel = new wxPanel( this, wxID_ANY, wxPoint( -1,-1 ), wxSize( 240,135 ), wxTAB_TRAVERSAL );
	secondImgPreviewPanel->SetBackgroundColour( wxColour( 113, 184, 255 ) );
	secondImgPreviewPanel->SetMinSize( wxSize( 240,135 ) );
	secondImgPreviewPanel->SetMaxSize( wxSize( 240,135 ) );

	menuSizer->Add( secondImgPreviewPanel, 1, wxALIGN_CENTER_HORIZONTAL|wxALL, 5 );

	separator2 = new wxPanel( this, wxID_ANY, wxDefaultPosition, wxSize( -1,15 ), wxTAB_TRAVERSAL );
	separator2->SetBackgroundColour( wxColour( 255, 255, 255 ) );
	separator2->SetMinSize( wxSize( -1,15 ) );
	separator2->SetMaxSize( wxSize( -1,15 ) );

	menuSizer->Add( separator2, 1, wxEXPAND | wxALL, 5 );

	wxBoxSizer* logSizer;
	logSizer = new wxBoxSizer( wxHORIZONTAL );

	log = new wxPanel( this, wxID_ANY, wxDefaultPosition, wxSize( -1,70 ), wxTAB_TRAVERSAL );
	log->SetBackgroundColour( wxColour( 230, 230, 230 ) );
	log->SetMinSize( wxSize( -1,70 ) );
	log->SetMaxSize( wxSize( -1,70 ) );

	logSizer->Add( log, 1, wxALL, 5 );

	resetButton = new wxButton( this, wxID_ANY, wxT("RESET"), wxDefaultPosition, wxDefaultSize, 0 );
	resetButton->SetFont( wxFont( 10, wxFONTFAMILY_MODERN, wxFONTSTYLE_NORMAL, wxFONTWEIGHT_NORMAL, false, wxT("Consolas") ) );
	resetButton->SetBackgroundColour( wxColour( 179, 83, 219 ) );

	logSizer->Add( resetButton, 0, wxALL, 5 );


	menuSizer->Add( logSizer, 1, wxEXPAND, 5 );

	separator3 = new wxPanel( this, wxID_ANY, wxDefaultPosition, wxSize( -1,10 ), wxTAB_TRAVERSAL );
	separator3->SetMinSize( wxSize( -1,10 ) );
	separator3->SetMaxSize( wxSize( -1,10 ) );

	menuSizer->Add( separator3, 1, wxEXPAND | wxALL, 5 );

	loadInitFrameButton = new wxButton( this, wxID_ANY, wxT("Wczytaj klatkê pocz¹tkow¹"), wxDefaultPosition, wxDefaultSize, 0 );
	loadInitFrameButton->SetFont( wxFont( 10, wxFONTFAMILY_MODERN, wxFONTSTYLE_NORMAL, wxFONTWEIGHT_NORMAL, false, wxT("Consolas") ) );
	loadInitFrameButton->SetBackgroundColour( wxColour( 179, 83, 219 ) );

	menuSizer->Add( loadInitFrameButton, 0, wxALIGN_CENTER, 5 );

	separator4 = new wxPanel( this, wxID_ANY, wxDefaultPosition, wxSize( -1,3 ), wxTAB_TRAVERSAL );
	separator4->SetMinSize( wxSize( -1,3 ) );
	separator4->SetMaxSize( wxSize( -1,3 ) );

	menuSizer->Add( separator4, 1, wxEXPAND | wxALL, 5 );

	loadLastFrameButton = new wxButton( this, wxID_ANY, wxT("Wczytaj klatkê koñcow¹"), wxDefaultPosition, wxDefaultSize, 0 );
	loadLastFrameButton->SetFont( wxFont( 10, wxFONTFAMILY_MODERN, wxFONTSTYLE_NORMAL, wxFONTWEIGHT_NORMAL, false, wxT("Consolas") ) );
	loadLastFrameButton->SetBackgroundColour( wxColour( 179, 83, 219 ) );

	menuSizer->Add( loadLastFrameButton, 0, wxALIGN_CENTER, 5 );

	separator5 = new wxPanel( this, wxID_ANY, wxDefaultPosition, wxSize( -1,10 ), wxTAB_TRAVERSAL );
	separator5->SetMinSize( wxSize( -1,10 ) );
	separator5->SetMaxSize( wxSize( -1,10 ) );

	menuSizer->Add( separator5, 1, wxEXPAND | wxALL, 5 );

	wxBoxSizer* textSizer;
	textSizer = new wxBoxSizer( wxHORIZONTAL );

	textSizer->SetMinSize( wxSize( -1,10 ) );
	choiceText = new wxStaticText( this, wxID_ANY, wxT("Rodzaj przejscia                 Liczba klatek\n"), wxDefaultPosition, wxSize( -1,15 ), 0 );
	choiceText->Wrap( -1 );
	choiceText->SetFont( wxFont( 10, wxFONTFAMILY_MODERN, wxFONTSTYLE_NORMAL, wxFONTWEIGHT_NORMAL, false, wxT("Consolas") ) );

	textSizer->Add( choiceText, 0, wxALL, 5 );


	menuSizer->Add( textSizer, 1, wxALL|wxEXPAND, 5 );

	wxBoxSizer* choiceSizer;
	choiceSizer = new wxBoxSizer( wxHORIZONTAL );

	wxString chooseTransitionChoices[] = { wxT("Wjazd obrazu z lewej strony"), wxT("Wjazd obrazu z prawej strony"), wxT("Wjazd obrazu z góry"), wxT("Wjazd obrazu z do³u"), wxT("Box wchodz¹cy"), wxT("Box wychodz¹cy"), wxT("Œciemnienie / Rozjaœnienie"), wxT("Zmiana wartoœci kana³u alfa"), wxT("Obrót kartki w pionie"), wxT("Obrót kartki w poziomie"), wxT("Okiennica"), wxEmptyString };
	int chooseTransitionNChoices = sizeof( chooseTransitionChoices ) / sizeof( wxString );
	chooseTransition = new wxChoice( this, wxID_ANY, wxDefaultPosition, wxDefaultSize, chooseTransitionNChoices, chooseTransitionChoices, 0 );
	chooseTransition->SetSelection( 11 );
	chooseTransition->SetFont( wxFont( 9, wxFONTFAMILY_MODERN, wxFONTSTYLE_NORMAL, wxFONTWEIGHT_NORMAL, false, wxT("Consolas") ) );
	chooseTransition->SetBackgroundColour( wxColour( 230, 230, 230 ) );

	choiceSizer->Add( chooseTransition, 0, wxALL, 5 );

	frameRate = new wxTextCtrl( this, wxID_ANY, wxT("3"), wxDefaultPosition, wxDefaultSize, 0 );
	frameRate->SetBackgroundColour( wxColour( 230, 230, 230 ) );

	choiceSizer->Add( frameRate, 0, wxALL, 5 );


	menuSizer->Add( choiceSizer, 1, wxEXPAND, 5 );

	separator6 = new wxPanel( this, wxID_ANY, wxDefaultPosition, wxSize( -1,10 ), wxTAB_TRAVERSAL );
	separator6->SetMinSize( wxSize( -1,10 ) );
	separator6->SetMaxSize( wxSize( -1,10 ) );

	menuSizer->Add( separator6, 1, wxEXPAND | wxALL, 5 );

	generateFrame = new wxButton( this, wxID_ANY, wxT("Generuj klatki poœrednie"), wxDefaultPosition, wxDefaultSize, 0 );
	generateFrame->SetFont( wxFont( 10, wxFONTFAMILY_MODERN, wxFONTSTYLE_NORMAL, wxFONTWEIGHT_NORMAL, false, wxT("Consolas") ) );
	generateFrame->SetBackgroundColour( wxColour( 179, 83, 219 ) );

	menuSizer->Add( generateFrame, 0, wxALIGN_CENTER, 5 );


	mainSizer->Add( menuSizer, 1, wxALIGN_LEFT|wxEXPAND, 5 );

	wxBoxSizer* sceneSizer;
	sceneSizer = new wxBoxSizer( wxVERTICAL );

	sceneSizer->SetMinSize( wxSize( 960,540 ) );
	scenePanel = new wxPanel( this, wxID_ANY, wxDefaultPosition, wxSize( 960,540 ), wxTAB_TRAVERSAL );
	scenePanel->SetBackgroundColour( wxColour( 113, 184, 255 ) );
	scenePanel->SetMinSize( wxSize( 960,540 ) );
	scenePanel->SetMaxSize( wxSize( 960,540 ) );

	sceneSizer->Add( scenePanel, 1, wxALL, 5 );

	separator7 = new wxPanel( this, wxID_ANY, wxDefaultPosition, wxSize( -1,40 ), wxTAB_TRAVERSAL );
	separator7->SetMinSize( wxSize( -1,40 ) );
	separator7->SetMaxSize( wxSize( -1,40 ) );

	sceneSizer->Add( separator7, 1, wxEXPAND | wxALL, 5 );

	slider = new wxSlider( this, wxID_ANY, 50, 0, 100, wxDefaultPosition, wxDefaultSize, wxSL_HORIZONTAL );
	sceneSizer->Add( slider, 0, wxEXPAND, 5 );

	saveAnimation = new wxButton( this, wxID_ANY, wxT("Zapisz animacjê"), wxDefaultPosition, wxDefaultSize, 0 );
	saveAnimation->SetBackgroundColour( wxColour( 179, 83, 219 ) );

	sceneSizer->Add( saveAnimation, 0, 0, 5 );


	mainSizer->Add( sceneSizer, 1, wxEXPAND, 5 );


	this->SetSizer( mainSizer );
	this->Layout();

	this->Centre( wxBOTH );

	// Connect Events
	resetButton->Connect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( mainFrame::onReset ), NULL, this );
	loadInitFrameButton->Connect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( mainFrame::onLoadInitFrame ), NULL, this );
	loadLastFrameButton->Connect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( mainFrame::onLoadLastFrame ), NULL, this );
	chooseTransition->Connect( wxEVT_COMMAND_CHOICE_SELECTED, wxCommandEventHandler( mainFrame::onTransitionChoice ), NULL, this );
	frameRate->Connect(wxTE_PROCESS_ENTER||wxEVT_COMMAND_TEXT_ENTER, wxCommandEventHandler( mainFrame::onFrameRateEnter ), NULL, this );
	generateFrame->Connect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( mainFrame::onGenerateFrame ), NULL, this );
	slider->Connect( wxEVT_SCROLL_TOP, wxScrollEventHandler( mainFrame::onScroll ), NULL, this );
	slider->Connect( wxEVT_SCROLL_BOTTOM, wxScrollEventHandler( mainFrame::onScroll ), NULL, this );
	slider->Connect( wxEVT_SCROLL_LINEUP, wxScrollEventHandler( mainFrame::onScroll ), NULL, this );
	slider->Connect( wxEVT_SCROLL_LINEDOWN, wxScrollEventHandler( mainFrame::onScroll ), NULL, this );
	slider->Connect( wxEVT_SCROLL_PAGEUP, wxScrollEventHandler( mainFrame::onScroll ), NULL, this );
	slider->Connect( wxEVT_SCROLL_PAGEDOWN, wxScrollEventHandler( mainFrame::onScroll ), NULL, this );
	slider->Connect( wxEVT_SCROLL_THUMBTRACK, wxScrollEventHandler( mainFrame::onScroll ), NULL, this );
	slider->Connect( wxEVT_SCROLL_THUMBRELEASE, wxScrollEventHandler( mainFrame::onScroll ), NULL, this );
	slider->Connect( wxEVT_SCROLL_CHANGED, wxScrollEventHandler( mainFrame::onScroll ), NULL, this );
	saveAnimation->Connect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( mainFrame::onAnimationSave ), NULL, this );
}

mainFrame::~mainFrame()
{
	// Disconnect Events
	resetButton->Disconnect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( mainFrame::onReset ), NULL, this );
	loadInitFrameButton->Disconnect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( mainFrame::onLoadInitFrame ), NULL, this );
	loadLastFrameButton->Disconnect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( mainFrame::onLoadLastFrame ), NULL, this );
	chooseTransition->Disconnect( wxEVT_COMMAND_CHOICE_SELECTED, wxCommandEventHandler( mainFrame::onTransitionChoice ), NULL, this );
	frameRate->Disconnect( wxEVT_COMMAND_TEXT_ENTER, wxCommandEventHandler( mainFrame::onFrameRateEnter ), NULL, this );
	generateFrame->Disconnect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( mainFrame::onGenerateFrame ), NULL, this );
	slider->Disconnect( wxEVT_SCROLL_TOP, wxScrollEventHandler( mainFrame::onScroll ), NULL, this );
	slider->Disconnect( wxEVT_SCROLL_BOTTOM, wxScrollEventHandler( mainFrame::onScroll ), NULL, this );
	slider->Disconnect( wxEVT_SCROLL_LINEUP, wxScrollEventHandler( mainFrame::onScroll ), NULL, this );
	slider->Disconnect( wxEVT_SCROLL_LINEDOWN, wxScrollEventHandler( mainFrame::onScroll ), NULL, this );
	slider->Disconnect( wxEVT_SCROLL_PAGEUP, wxScrollEventHandler( mainFrame::onScroll ), NULL, this );
	slider->Disconnect( wxEVT_SCROLL_PAGEDOWN, wxScrollEventHandler( mainFrame::onScroll ), NULL, this );
	slider->Disconnect( wxEVT_SCROLL_THUMBTRACK, wxScrollEventHandler( mainFrame::onScroll ), NULL, this );
	slider->Disconnect( wxEVT_SCROLL_THUMBRELEASE, wxScrollEventHandler( mainFrame::onScroll ), NULL, this );
	slider->Disconnect( wxEVT_SCROLL_CHANGED, wxScrollEventHandler( mainFrame::onScroll ), NULL, this );
	saveAnimation->Disconnect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( mainFrame::onAnimationSave ), NULL, this );

}
