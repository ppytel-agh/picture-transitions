#include "wxWidgets-buffer-converter.h"

GraphicsBuffer WxWidgetsBufferConverter::convertWxImageToBuffer(const wxImage& wxIm)
{
	if (!wxIm.IsOk()) {
		return GraphicsBuffer({});
	}
	Size bufferSize{ wxIm.GetWidth(), wxIm.GetHeight() };
	GraphicsBuffer buffer(bufferSize);
	int noSubpixels = wxIm.GetWidth() * wxIm.GetHeight() * 3;
	std::vector<unsigned char> subpixels(noSubpixels);
	for (int i = 0; i < noSubpixels; i++) {
		subpixels[i] = wxIm.GetData()[i];
	}
	buffer.setSubpixelValues(subpixels);
	return buffer;
}

wxImage WxWidgetsBufferConverter::convertBufferToWxImage(const GraphicsBuffer& buffer)
{
	if (buffer.isEmpty()) {
		wxImage returnedImage(1, 1);
		returnedImage.InitAlpha();
		returnedImage.SetAlpha(0, 0, 0);
		return returnedImage;
	}
	Size bufferSize = buffer.getSize();
	wxImage wxIm(bufferSize.width, bufferSize.height);
	std::vector<unsigned char> subpixels = buffer.getSubpixelValues();
	for (int i = 0; i < subpixels.size(); i++) {
		wxIm.GetData()[i] = subpixels[i];
	}
	return wxIm;
}
