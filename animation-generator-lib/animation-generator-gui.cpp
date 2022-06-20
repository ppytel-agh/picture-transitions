///////////////////////////////////////////////////////////////////////////
// C++ code generated with wxFormBuilder (version 3.10.1-0-g8feb16b3)
// http://www.wxformbuilder.org/
//
// PLEASE DO *NOT* EDIT THIS FILE!
///////////////////////////////////////////////////////////////////////////

#include "animation-generator-gui.h"

///////////////////////////////////////////////////////////////////////////

MainFrame::MainFrame( wxWindow* parent, wxWindowID id, const wxString& title, const wxPoint& pos, const wxSize& size, long style ) : wxFrame( parent, id, title, pos, size, style )
{
	this->SetSizeHints( wxSize( 1280,720 ), wxDefaultSize );
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

	wxBoxSizer* bSizer9;
	bSizer9 = new wxBoxSizer( wxHORIZONTAL );

	initFrameSize = new wxStaticText( this, wxID_ANY, wxT("Wymiary klatek:"), wxDefaultPosition, wxSize( -1,-1 ), 0 );
	initFrameSize->Wrap( -1 );
	initFrameSize->SetFont( wxFont( 10, wxFONTFAMILY_MODERN, wxFONTSTYLE_NORMAL, wxFONTWEIGHT_NORMAL, false, wxT("Consolas") ) );

	bSizer9->Add( initFrameSize, 1, wxALIGN_CENTER_HORIZONTAL|wxALL, 5 );

	loadedKeyframeSize = new wxStaticText( this, wxID_ANY, wxEmptyString, wxDefaultPosition, wxDefaultSize, wxALIGN_RIGHT );
	loadedKeyframeSize->Wrap( -1 );
	bSizer9->Add( loadedKeyframeSize, 1, wxALL, 5 );


	menuSizer->Add( bSizer9, 0, wxEXPAND, 5 );

	secondImgPreviewPanel = new wxPanel( this, wxID_ANY, wxPoint( -1,-1 ), wxSize( 240,135 ), wxTAB_TRAVERSAL );
	secondImgPreviewPanel->SetBackgroundColour( wxColour( 113, 184, 255 ) );
	secondImgPreviewPanel->SetMinSize( wxSize( 240,135 ) );
	secondImgPreviewPanel->SetMaxSize( wxSize( 240,135 ) );

	menuSizer->Add( secondImgPreviewPanel, 1, wxALIGN_CENTER_HORIZONTAL|wxALL, 5 );

	wxBoxSizer* logSizer;
	logSizer = new wxBoxSizer( wxHORIZONTAL );

	logScroll = new wxScrolledWindow( this, wxID_ANY, wxDefaultPosition, wxSize( -1,100 ), wxHSCROLL|wxVSCROLL );
	logScroll->SetScrollRate( 5, 5 );
	logScroll->SetBackgroundColour( wxColour( 230, 230, 230 ) );

	sbSizer1 = new wxStaticBoxSizer( new wxStaticBox( logScroll, wxID_ANY, wxT("komunikaty") ), wxVERTICAL );

	sbSizer1->SetMinSize( wxSize( -1,60 ) );
	messagesLog = new wxStaticText( sbSizer1->GetStaticBox(), wxID_ANY, wxEmptyString, wxDefaultPosition, wxDefaultSize, 0 );
	messagesLog->Wrap( -1 );
	sbSizer1->Add( messagesLog, 0, wxALL, 5 );


	logScroll->SetSizer( sbSizer1 );
	logScroll->Layout();
	logSizer->Add( logScroll, 1, wxEXPAND | wxALL, 5 );


	menuSizer->Add( logSizer, 0, wxEXPAND, 5 );

	wxBoxSizer* bSizer14;
	bSizer14 = new wxBoxSizer( wxHORIZONTAL );

	wxBoxSizer* bSizer15;
	bSizer15 = new wxBoxSizer( wxVERTICAL );

	loadInitFrameButton = new wxButton( this, wxID_ANY, wxT("Wczytaj klatke poczatkowa"), wxDefaultPosition, wxDefaultSize, 0 );
	loadInitFrameButton->SetFont( wxFont( 10, wxFONTFAMILY_MODERN, wxFONTSTYLE_NORMAL, wxFONTWEIGHT_NORMAL, false, wxT("Consolas") ) );
	loadInitFrameButton->SetBackgroundColour( wxSystemSettings::GetColour( wxSYS_COLOUR_WINDOW ) );

	bSizer15->Add( loadInitFrameButton, 0, wxALIGN_CENTER, 5 );

	loadLastFrameButton = new wxButton( this, wxID_ANY, wxT("Wczytaj klatke koncowa"), wxDefaultPosition, wxDefaultSize, 0 );
	loadLastFrameButton->SetFont( wxFont( 10, wxFONTFAMILY_MODERN, wxFONTSTYLE_NORMAL, wxFONTWEIGHT_NORMAL, false, wxT("Consolas") ) );
	loadLastFrameButton->SetBackgroundColour( wxSystemSettings::GetColour( wxSYS_COLOUR_WINDOW ) );

	bSizer15->Add( loadLastFrameButton, 0, wxALIGN_CENTER, 5 );


	bSizer14->Add( bSizer15, 1, wxEXPAND, 5 );

	resetButton = new wxButton( this, wxID_ANY, wxT("RESET"), wxDefaultPosition, wxDefaultSize, 0 );
	resetButton->SetFont( wxFont( 10, wxFONTFAMILY_MODERN, wxFONTSTYLE_NORMAL, wxFONTWEIGHT_NORMAL, false, wxT("Consolas") ) );
	resetButton->SetBackgroundColour( wxSystemSettings::GetColour( wxSYS_COLOUR_WINDOW ) );

	bSizer14->Add( resetButton, 0, wxALL, 5 );


	menuSizer->Add( bSizer14, 0, wxEXPAND, 5 );

	wxBoxSizer* textSizer;
	textSizer = new wxBoxSizer( wxHORIZONTAL );

	textSizer->SetMinSize( wxSize( -1,10 ) );
	choiceText = new wxStaticText( this, wxID_ANY, wxT("Rodzaj przejscia"), wxDefaultPosition, wxSize( -1,-1 ), 0 );
	choiceText->Wrap( -1 );
	choiceText->SetFont( wxFont( 10, wxFONTFAMILY_MODERN, wxFONTSTYLE_NORMAL, wxFONTWEIGHT_NORMAL, false, wxT("Consolas") ) );

	textSizer->Add( choiceText, 1, wxALL, 5 );

	m_staticText3 = new wxStaticText( this, wxID_ANY, wxT("Liczba klatek"), wxDefaultPosition, wxDefaultSize, wxALIGN_RIGHT );
	m_staticText3->Wrap( -1 );
	textSizer->Add( m_staticText3, 1, wxALL, 5 );


	menuSizer->Add( textSizer, 0, wxALL|wxEXPAND, 5 );

	wxBoxSizer* choiceSizer;
	choiceSizer = new wxBoxSizer( wxHORIZONTAL );

	transitionDropdownSizer = new wxBoxSizer( wxVERTICAL );

	wxString chooseTransitionChoices[] = { wxT("example") };
	int chooseTransitionNChoices = sizeof( chooseTransitionChoices ) / sizeof( wxString );
	chooseTransition = new wxChoice( this, wxID_ANY, wxDefaultPosition, wxDefaultSize, chooseTransitionNChoices, chooseTransitionChoices, 0 );
	chooseTransition->SetSelection( 0 );
	chooseTransition->SetFont( wxFont( 9, wxFONTFAMILY_MODERN, wxFONTSTYLE_NORMAL, wxFONTWEIGHT_NORMAL, false, wxT("Consolas") ) );
	chooseTransition->SetBackgroundColour( wxColour( 230, 230, 230 ) );

	transitionDropdownSizer->Add( chooseTransition, 0, wxALL, 5 );


	choiceSizer->Add( transitionDropdownSizer, 1, wxEXPAND, 5 );

	frameRate = new wxSpinCtrl( this, wxID_ANY, wxEmptyString, wxDefaultPosition, wxDefaultSize, wxSP_ARROW_KEYS, 2, 240, 3 );
	choiceSizer->Add( frameRate, 1, wxALL, 5 );


	menuSizer->Add( choiceSizer, 0, wxEXPAND, 5 );

	generateFrame = new wxButton( this, wxID_ANY, wxT("Generuj klatki posrednie"), wxDefaultPosition, wxDefaultSize, 0 );
	generateFrame->SetFont( wxFont( 10, wxFONTFAMILY_MODERN, wxFONTSTYLE_NORMAL, wxFONTWEIGHT_NORMAL, false, wxT("Consolas") ) );
	generateFrame->SetBackgroundColour( wxSystemSettings::GetColour( wxSYS_COLOUR_WINDOW ) );

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

	wxBoxSizer* bSizer12;
	bSizer12 = new wxBoxSizer( wxHORIZONTAL );

	slider = new wxSlider( this, wxID_ANY, 1, 1, 2, wxDefaultPosition, wxDefaultSize, wxSL_HORIZONTAL );
	bSizer12->Add( slider, 5, wxEXPAND, 5 );

	saveAnimation = new wxButton( this, wxID_ANY, wxT("Zapisz animacje"), wxDefaultPosition, wxDefaultSize, 0 );
	saveAnimation->SetBackgroundColour( wxSystemSettings::GetColour( wxSYS_COLOUR_WINDOW ) );

	bSizer12->Add( saveAnimation, 1, wxALIGN_RIGHT, 5 );


	sceneSizer->Add( bSizer12, 1, wxEXPAND, 5 );


	mainSizer->Add( sceneSizer, 1, wxALIGN_RIGHT|wxEXPAND, 5 );


	this->SetSizer( mainSizer );
	this->Layout();

	this->Centre( wxBOTH );

	// Connect Events
	loadInitFrameButton->Connect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( MainFrame::onLoadInitFrame ), NULL, this );
	loadLastFrameButton->Connect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( MainFrame::onLoadLastFrame ), NULL, this );
	resetButton->Connect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( MainFrame::onReset ), NULL, this );
	chooseTransition->Connect( wxEVT_COMMAND_CHOICE_SELECTED, wxCommandEventHandler( MainFrame::onTransitionChoice ), NULL, this );
	frameRate->Connect( wxEVT_COMMAND_SPINCTRL_UPDATED, wxSpinEventHandler( MainFrame::onFrameRateEnter ), NULL, this );
	generateFrame->Connect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( MainFrame::onGenerateFrame ), NULL, this );
	slider->Connect( wxEVT_SCROLL_TOP, wxScrollEventHandler( MainFrame::onScroll ), NULL, this );
	slider->Connect( wxEVT_SCROLL_BOTTOM, wxScrollEventHandler( MainFrame::onScroll ), NULL, this );
	slider->Connect( wxEVT_SCROLL_LINEUP, wxScrollEventHandler( MainFrame::onScroll ), NULL, this );
	slider->Connect( wxEVT_SCROLL_LINEDOWN, wxScrollEventHandler( MainFrame::onScroll ), NULL, this );
	slider->Connect( wxEVT_SCROLL_PAGEUP, wxScrollEventHandler( MainFrame::onScroll ), NULL, this );
	slider->Connect( wxEVT_SCROLL_PAGEDOWN, wxScrollEventHandler( MainFrame::onScroll ), NULL, this );
	slider->Connect( wxEVT_SCROLL_THUMBTRACK, wxScrollEventHandler( MainFrame::onScroll ), NULL, this );
	slider->Connect( wxEVT_SCROLL_THUMBRELEASE, wxScrollEventHandler( MainFrame::onScroll ), NULL, this );
	slider->Connect( wxEVT_SCROLL_CHANGED, wxScrollEventHandler( MainFrame::onScroll ), NULL, this );
	saveAnimation->Connect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( MainFrame::onAnimationSave ), NULL, this );
}

MainFrame::~MainFrame()
{
	// Disconnect Events
	loadInitFrameButton->Disconnect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( MainFrame::onLoadInitFrame ), NULL, this );
	loadLastFrameButton->Disconnect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( MainFrame::onLoadLastFrame ), NULL, this );
	resetButton->Disconnect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( MainFrame::onReset ), NULL, this );
	chooseTransition->Disconnect( wxEVT_COMMAND_CHOICE_SELECTED, wxCommandEventHandler( MainFrame::onTransitionChoice ), NULL, this );
	frameRate->Disconnect( wxEVT_COMMAND_SPINCTRL_UPDATED, wxSpinEventHandler( MainFrame::onFrameRateEnter ), NULL, this );
	generateFrame->Disconnect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( MainFrame::onGenerateFrame ), NULL, this );
	slider->Disconnect( wxEVT_SCROLL_TOP, wxScrollEventHandler( MainFrame::onScroll ), NULL, this );
	slider->Disconnect( wxEVT_SCROLL_BOTTOM, wxScrollEventHandler( MainFrame::onScroll ), NULL, this );
	slider->Disconnect( wxEVT_SCROLL_LINEUP, wxScrollEventHandler( MainFrame::onScroll ), NULL, this );
	slider->Disconnect( wxEVT_SCROLL_LINEDOWN, wxScrollEventHandler( MainFrame::onScroll ), NULL, this );
	slider->Disconnect( wxEVT_SCROLL_PAGEUP, wxScrollEventHandler( MainFrame::onScroll ), NULL, this );
	slider->Disconnect( wxEVT_SCROLL_PAGEDOWN, wxScrollEventHandler( MainFrame::onScroll ), NULL, this );
	slider->Disconnect( wxEVT_SCROLL_THUMBTRACK, wxScrollEventHandler( MainFrame::onScroll ), NULL, this );
	slider->Disconnect( wxEVT_SCROLL_THUMBRELEASE, wxScrollEventHandler( MainFrame::onScroll ), NULL, this );
	slider->Disconnect( wxEVT_SCROLL_CHANGED, wxScrollEventHandler( MainFrame::onScroll ), NULL, this );
	saveAnimation->Disconnect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( MainFrame::onAnimationSave ), NULL, this );

}
