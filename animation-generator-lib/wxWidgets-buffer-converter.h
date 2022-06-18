#pragma once

#include <wx/wx.h>
#include <vector>
#include "graphics-buffer.h"

class WxWidgetsBufferConverter {
public:
	static GraphicsBuffer convertWxImageToBuffer(const wxImage&);
	static wxImage convertBufferToWxImage(const GraphicsBuffer&);
};