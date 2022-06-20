#include "buffer-scaler.h"

GraphicsBuffer BufferScaler::scaleBuffer(const GraphicsBuffer& scaledBuffer, float scaleX, float scaleY)
{
    Size bufferSize = scaledBuffer.getSize();
   /* bufferSize.width *= fabs(scaleX);
    bufferSize.height *= fabs(scaleY);
    GraphicsBuffer scaledBuffer = GraphicsBuffer(bufferSize);*/
    wxImage imageForRescaling = WxWidgetsBufferConverter::convertBufferToWxImage(scaledBuffer);
    imageForRescaling.Rescale(bufferSize.width * scaleX, bufferSize.height * scaleY);
    return WxWidgetsBufferConverter::convertWxImageToBuffer(imageForRescaling);
}
