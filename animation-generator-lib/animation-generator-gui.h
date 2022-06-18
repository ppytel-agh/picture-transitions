///////////////////////////////////////////////////////////////////////////
// C++ code generated with wxFormBuilder (version 3.10.1-0-g8feb16b3)
// http://www.wxformbuilder.org/
//
// PLEASE DO *NOT* EDIT THIS FILE!
///////////////////////////////////////////////////////////////////////////

#pragma once

#include <wx/artprov.h>
#include <wx/xrc/xmlres.h>
#include <wx/sizer.h>
#include <wx/gdicmn.h>
#include <wx/panel.h>
#include <wx/font.h>
#include <wx/colour.h>
#include <wx/settings.h>
#include <wx/string.h>
#include <wx/stattext.h>
#include <wx/statbox.h>
#include <wx/scrolwin.h>
#include <wx/button.h>
#include <wx/bitmap.h>
#include <wx/image.h>
#include <wx/icon.h>
#include <wx/choice.h>
#include <wx/spinctrl.h>
#include <wx/slider.h>
#include <wx/frame.h>

///////////////////////////////////////////////////////////////////////////


///////////////////////////////////////////////////////////////////////////////
/// Class MainFrame
///////////////////////////////////////////////////////////////////////////////
class MainFrame : public wxFrame
{
	private:

	protected:
		wxPanel* separator1;
		wxStaticText* initFrameSize;
		wxButton* loadInitFrameButton;
		wxButton* loadLastFrameButton;
		wxButton* resetButton;
		wxStaticText* choiceText;
		wxStaticText* m_staticText3;
		wxChoice* chooseTransition;
		wxSpinCtrl* frameRate;
		wxButton* generateFrame;
		wxPanel* separator7;
		wxButton* saveAnimation;

		// Virtual event handlers, override them in your derived class
		virtual void onLoadInitFrame( wxCommandEvent& event ) { event.Skip(); }
		virtual void onLoadLastFrame( wxCommandEvent& event ) { event.Skip(); }
		virtual void onReset( wxCommandEvent& event ) { event.Skip(); }
		virtual void onTransitionChoice( wxCommandEvent& event ) { event.Skip(); }
		virtual void onFrameRateEnter( wxSpinEvent& event ) { event.Skip(); }
		virtual void onGenerateFrame( wxCommandEvent& event ) { event.Skip(); }
		virtual void onScroll( wxScrollEvent& event ) { event.Skip(); }
		virtual void onAnimationSave( wxCommandEvent& event ) { event.Skip(); }


	public:
		wxPanel* firstImgPreviewPanel;
		wxStaticText* loadedKeyframeSize;
		wxPanel* secondImgPreviewPanel;
		wxScrolledWindow* logScroll;
		wxStaticBoxSizer* sbSizer1;
		wxStaticText* messagesLog;
		wxBoxSizer* transitionDropdownSizer;
		wxPanel* scenePanel;
		wxSlider* slider;

		MainFrame( wxWindow* parent, wxWindowID id = wxID_ANY, const wxString& title = wxEmptyString, const wxPoint& pos = wxDefaultPosition, const wxSize& size = wxSize( 1280,720 ), long style = wxCAPTION|wxCLOSE_BOX|wxMINIMIZE_BOX|wxSYSTEM_MENU|wxTAB_TRAVERSAL );

		~MainFrame();

};

