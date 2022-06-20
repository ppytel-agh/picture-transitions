#include "buffer-blender-tests.h"

#include <functional>
#include <buffer-blender.h>
#include <sstream>
#include <wx/filedlg.h>

void scaleToFit2(wxImage& image, unsigned short width, unsigned short height) {
	float destinationRatio = float(width) / float(height);
	int imageWidth = image.GetWidth();
	int imageHeight = image.GetHeight();
	float imageRatio = float(imageWidth) / float(imageHeight);
	int newWidth = width;
	int newHeight = height;
	if (imageRatio > destinationRatio) {
		float scaleRatio = float(width) / float(imageWidth);
		newHeight = imageHeight * scaleRatio;
	}
	else if (imageRatio < destinationRatio) {
		float scaleRatio = float(height) / float(imageHeight);
		newWidth = imageWidth * scaleRatio;
	}
	image.Rescale(newWidth, newHeight);
}

void drawInCenterOfPanel2(wxWindow* panel, const wxImage& scaledImage, int panelWidth, int panelHeight) {
	int imageWidth = scaledImage.GetWidth();
	int imageHeight = scaledImage.GetHeight();
	int xOffset = 0;
	int yOffset = 0;
	if (imageWidth < panelWidth) {
		xOffset = (panelWidth - imageWidth) / 2;
	}
	if (imageHeight < panelHeight) {
		yOffset = (panelHeight - imageHeight) / 2;
	}
	wxBitmap memoryBitmap(scaledImage);
	wxMemoryDC memDC;
	memDC.SelectObject(memoryBitmap);
	wxClientDC dc(panel);
	dc.Blit(xOffset, yOffset, imageWidth, imageHeight, &memDC, 0, 0);
}

BufferBlenderTests::BufferBlenderTests() : destinationBuffer(nullptr), sourceBufferOriginal(nullptr), sourceBufferScaled(nullptr), blendBuffer(nullptr), destinationProportionVal(1.0f), scaleVal(1.0f), blender({})
{
}

void BufferBlenderTests::initializeUI(wxFrame* parentFrame)
{
	wxImage::AddHandler(new wxPNGHandler());
	wxImage::AddHandler(new wxJPEGHandler());

	wxFrame* frame = new wxFrame(parentFrame, wxID_ANY, wxEmptyString, wxDefaultPosition, wxSize(490, 550), wxDEFAULT_FRAME_STYLE | wxTAB_TRAVERSAL);

	frame->SetSizeHints(wxDefaultSize, wxDefaultSize);

	wxBoxSizer* bSizer1;
	bSizer1 = new wxBoxSizer(wxVERTICAL);

	wxBoxSizer* bSizer2;
	bSizer2 = new wxBoxSizer(wxHORIZONTAL);

	wxBoxSizer* bSizer5;
	bSizer5 = new wxBoxSizer(wxVERTICAL);

	m_button1 = new wxButton(frame, wxID_ANY, wxT("load destination"), wxDefaultPosition, wxDefaultSize, 0);
	bSizer5->Add(m_button1, 0, wxALL, 5);

	m_panel1 = new wxPanel(frame, wxID_ANY, wxDefaultPosition, wxSize(240, 135), wxTAB_TRAVERSAL);
	bSizer5->Add(m_panel1, 0, wxALIGN_CENTER | wxALL, 5);


	bSizer2->Add(bSizer5, 1, wxEXPAND, 5);

	wxBoxSizer* bSizer6;
	bSizer6 = new wxBoxSizer(wxVERTICAL);

	m_button2 = new wxButton(frame, wxID_ANY, wxT("load source"), wxDefaultPosition, wxDefaultSize, 0);
	bSizer6->Add(m_button2, 0, wxALL, 5);

	m_panel2 = new wxPanel(frame, wxID_ANY, wxDefaultPosition, wxSize(240, 135), wxTAB_TRAVERSAL);
	bSizer6->Add(m_panel2, 0, wxALIGN_CENTER | wxALL, 5);


	bSizer2->Add(bSizer6, 1, wxEXPAND, 5);


	bSizer1->Add(bSizer2, 0, wxEXPAND, 5);

	wxBoxSizer* bSizer3;
	bSizer3 = new wxBoxSizer(wxHORIZONTAL);

	sourceScale = new wxSlider(frame, wxID_ANY, 100, -200, 200, wxDefaultPosition, wxDefaultSize, wxSL_HORIZONTAL);
	bSizer3->Add(sourceScale, 1, wxALL | wxEXPAND, 5);

	sourceScaleTxt = new wxStaticText(frame, wxID_ANY, wxT("sourceScale: 1.0"), wxDefaultPosition, wxDefaultSize, 0);
	sourceScaleTxt->Wrap(-1);
	bSizer3->Add(sourceScaleTxt, 0, wxALL, 5);


	bSizer1->Add(bSizer3, 0, wxEXPAND, 5);

	wxBoxSizer* bSizer4;
	bSizer4 = new wxBoxSizer(wxHORIZONTAL);

	destinationProportion = new wxSlider(frame, wxID_ANY, 100, 0, 100, wxDefaultPosition, wxDefaultSize, wxSL_HORIZONTAL);
	bSizer4->Add(destinationProportion, 1, wxALL, 5);

	destinationProportionTxt = new wxStaticText(frame, wxID_ANY, wxT("destinationProportion: 1.0"), wxDefaultPosition, wxDefaultSize, 0);
	destinationProportionTxt->Wrap(-1);
	bSizer4->Add(destinationProportionTxt, 0, wxALL, 5);


	bSizer1->Add(bSizer4, 0, wxEXPAND, 5);

	m_panel3 = new wxPanel(frame, wxID_ANY, wxDefaultPosition, wxSize(360, 240), wxTAB_TRAVERSAL);
	bSizer1->Add(m_panel3, 0, wxALIGN_CENTER | wxALL, 5);


	frame->SetSizer(bSizer1);
	frame->Layout();

	frame->Centre(wxBOTH);

	frame->Show();

	// Connect Events
	m_button1->Connect(wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler(BufferBlenderTests::loadDest), NULL, this);
	m_button2->Connect(wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler(BufferBlenderTests::loadSrc), NULL, this);
	sourceScale->Connect(wxEVT_SCROLL_CHANGED, wxScrollEventHandler(BufferBlenderTests::scaleSource), NULL, this);
	destinationProportion->Connect(wxEVT_SCROLL_CHANGED, wxScrollEventHandler(BufferBlenderTests::bump), NULL, this);
}

void BufferBlenderTests::createScaledSource()
{
	if (this->sourceBufferOriginal != nullptr) {
		GraphicsBuffer scaledSource = this->scaler.scaleBuffer(*this->sourceBufferOriginal, this->scaleVal, this->scaleVal);
		if (this->sourceBufferScaled != nullptr) {
			delete this->sourceBufferScaled;
		}
		this->sourceBufferScaled = new GraphicsBuffer(scaledSource);
	}
}

void BufferBlenderTests::render()
{
	if (this->destinationBuffer != nullptr && this->sourceBufferScaled != nullptr) {
		if (this->blendBuffer != nullptr) {
			delete this->blendBuffer;
		}
		GraphicsBuffer blendBuffer(*this->destinationBuffer);
		this->blender.blendIntoBuffer(blendBuffer, *this->sourceBufferScaled, this->destinationProportionVal);
		wxImage blendImage = WxWidgetsBufferConverter::convertBufferToWxImage(blendBuffer);

		scaleToFit2(blendImage, 360, 240);
		drawInCenterOfPanel2(m_panel3, blendImage, 360, 240);
	}
}

void BufferBlenderTests::loadDest(wxCommandEvent& event)
{
	wxFileDialog* WxOpenFirstFrameDialog(new wxFileDialog(this->frame, _("Wybierz klatke poczatkowa"), _(" "), _(""), _("JPEG files (*.jpg)|*.jpg|PNG files (*.png)|*.png|Bitmap (*.bmp)|*.bmp"), wxFD_OPEN | wxFD_FILE_MUST_EXIST));

	if (WxOpenFirstFrameDialog->ShowModal() == wxID_OK)
	{
		std::string filePath = WxOpenFirstFrameDialog->GetPath();
		wxImage destinationImage(filePath);
		if (this->destinationBuffer != nullptr) {
			delete this->destinationBuffer;
		}
		this->destinationBuffer = new GraphicsBuffer(WxWidgetsBufferConverter::convertWxImageToBuffer(destinationImage));

		wxImage destImage = WxWidgetsBufferConverter::convertBufferToWxImage(*this->destinationBuffer);
		scaleToFit2(destImage, 240, 135);
		drawInCenterOfPanel2(m_panel1, destImage, 240, 135);
		this->render();
	}
}

void BufferBlenderTests::loadSrc(wxCommandEvent& event)
{
	wxFileDialog* WxOpenFirstFrameDialog(new wxFileDialog(this->frame, _("Wybierz klatke poczatkowa"), _(" "), _(""), _("JPEG files (*.jpg)|*.jpg|PNG files (*.png)|*.png|Bitmap (*.bmp)|*.bmp"), wxFD_OPEN | wxFD_FILE_MUST_EXIST));

	if (WxOpenFirstFrameDialog->ShowModal() == wxID_OK)
	{
		std::string filePath = WxOpenFirstFrameDialog->GetPath();
		wxImage destinationImage(filePath);
		if (this->sourceBufferOriginal != nullptr) {
			delete this->sourceBufferOriginal;
		}
		this->sourceBufferOriginal = new GraphicsBuffer(WxWidgetsBufferConverter::convertWxImageToBuffer(destinationImage));
		wxImage srcImg = WxWidgetsBufferConverter::convertBufferToWxImage(*this->sourceBufferOriginal);
		scaleToFit2(srcImg, 240, 135);
		drawInCenterOfPanel2(m_panel2, srcImg, 240, 135);
		this->createScaledSource();
		this->render();
	}
}

void BufferBlenderTests::scaleSource(wxScrollEvent& event)
{
	int sliderValue = this->sourceScale->GetValue();
	float scale = float(sliderValue) / 100.0f;
	std::stringstream ss;
	ss << "sourceScale: " << scale;
	this->sourceScaleTxt->SetLabel(ss.str());

	this->scaleVal = scale;

	this->createScaledSource();
	this->render();
}

void BufferBlenderTests::bump(wxScrollEvent& event)
{
	int sliderValue = this->destinationProportion->GetValue();
	float destinationProportion = float(sliderValue) / 100.0f;
	this->destinationProportionVal = destinationProportion;

	std::stringstream ss;
	ss << "destinationProportion: " << destinationProportion;
	this->destinationProportionTxt->SetLabel(ss.str());

	this->render();
}
