#pragma once

#include "../abstract-visual-test.h"
#include <buffer-scaler.h>
#include <buffer-blender.h>

class BufferBlenderTests : public AbstractVisualTest, public wxEvtHandler {
public:
	BufferBlenderTests();
	// Inherited via AbstractVisualTest
	virtual void initializeUI(wxFrame* parentFrame) override;
	void createScaledSource();
	void render();
	void loadDest(wxCommandEvent& event);
	void loadSrc(wxCommandEvent& event);
	void scaleSource(wxScrollEvent& event);
	void bump(wxScrollEvent& event);

private:
	GraphicsBuffer* destinationBuffer;
	GraphicsBuffer* sourceBufferOriginal;
	GraphicsBuffer* sourceBufferScaled;
	GraphicsBuffer* blendBuffer;
	float scaleVal;
	float destinationProportionVal;
	///
	BufferScaler scaler;
	BufferBlender blender;
	//
	wxButton* m_button1;
	wxPanel* m_panel1;
	wxButton* m_button2;
	wxPanel* m_panel2;
	wxSlider* sourceScale;
	wxStaticText* sourceScaleTxt;
	wxSlider* destinationProportion;
	wxStaticText* destinationProportionTxt;
	wxPanel* m_panel3;
	wxFrame* frame;
};