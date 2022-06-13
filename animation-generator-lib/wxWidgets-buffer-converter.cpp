#include "wxWidgets-buffer-converter.h"

GraphicsBuffer WxWidgetsBufferConverter::convertWxImageToBuffer(const wxImage& wxIm)
{
    GraphicsBuffer buffer(wxIm.GetWidth(), wxIm.GetHeight());
    int noSubpixels = wxIm.GetWidth() * wxIm.GetHeight() * 3;
    std::vector<unsigned char> subpixels(noSubpixels);
    for (int i = 0; i < noSubpixels; i++) {
        subpixels[i] = wxIm.GetData()[i];
    }
    return buffer;
}

wxImage WxWidgetsBufferConverter::convertBufferToWxImage(const GraphicsBuffer& buffer)
{
    Size bufferSize = buffer.GetSize();
    wxImage wxIm(bufferSize.width, bufferSize.height);
    std::vector<unsigned char> subpixels = buffer.getSubpixels();
    for (int i = 0; i < subpixels.size(); i++) {
        wxIm.GetData()[i] = subpixels[i];
    }
    return wxIm;
}
