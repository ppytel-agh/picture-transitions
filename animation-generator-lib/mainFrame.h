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
#include <wx/button.h>
#include <wx/bitmap.h>
#include <wx/image.h>
#include <wx/icon.h>
#include <wx/choice.h>
#include <wx/textctrl.h>
#include <wx/slider.h>
#include <wx/frame.h>

///////////////////////////////////////////////////////////////////////////


///////////////////////////////////////////////////////////////////////////////
/// Class mainFrame
///////////////////////////////////////////////////////////////////////////////
class mainFrame : public wxFrame
{
	private:

	protected:
		wxPanel* separator1;
		wxPanel* firstImgPreviewPanel;
		wxStaticText* initFrameSize;
		wxPanel* secondImgPreviewPanel;
		wxPanel* separator2;
		wxPanel* log;
		wxButton* resetButton;
		wxPanel* separator3;
		wxButton* loadInitFrameButton;
		wxPanel* separator4;
		wxButton* loadLastFrameButton;
		wxPanel* separator5;
		wxStaticText* choiceText;
		wxChoice* chooseTransition;
		wxTextCtrl* frameRate;
		wxPanel* separator6;
		wxButton* generateFrame;
		wxPanel* scenePanel;
		wxPanel* separator7;
		wxSlider* slider;
		wxButton* saveAnimation;

		// Virtual event handlers, override them in your derived class
		virtual void onReset( wxCommandEvent& event ) { event.Skip(); }
		virtual void onLoadInitFrame( wxCommandEvent& event ) { event.Skip(); }
		virtual void onLoadLastFrame( wxCommandEvent& event ) { event.Skip(); }
		virtual void onTransitionChoice( wxCommandEvent& event ) { event.Skip(); }
		virtual void onFrameRateEnter( wxCommandEvent& event ) { event.Skip(); }
		virtual void onGenerateFrame( wxCommandEvent& event ) { event.Skip(); }
		virtual void onScroll( wxScrollEvent& event ) { event.Skip(); }
		virtual void onAnimationSave( wxCommandEvent& event ) { event.Skip(); }


	public:

		mainFrame( wxWindow* parent, wxWindowID id = wxID_ANY, const wxString& title = wxEmptyString, const wxPoint& pos = wxDefaultPosition, const wxSize& size = wxSize( 1280,720 ), long style = wxDEFAULT_FRAME_STYLE|wxTAB_TRAVERSAL );

		~mainFrame();

};

