#pragma once

#include <wx/wx.h>
#include <vector>
#include "graphics-buffer.h"

class WxWidgetsBufferConverter {
public:
	static GraphicsBuffer convertWxImageToBuffer(const wxImage&);
	/**
	* If provided buffer is empty then function returns image with single fully transparent black pixel
	*/
	static wxImage convertBufferToWxImage(const GraphicsBuffer&);
};