#include "buffer-scaler.h"

GraphicsBuffer BufferScaler::scaleBuffer(const GraphicsBuffer& scaledBuffer, float scaleX, float scaleY)
{
    Size scaling = scaledBuffer.getSize();
    scaling.width *= fabs(scaleX);
    scaling.height *= fabs(scaleY);
    if (scaling.width < 1 || scaling.height < 1) {
        return GraphicsBuffer({});
    }
    wxImage imageForRescaling = WxWidgetsBufferConverter::convertBufferToWxImage(scaledBuffer);
    if (scaleX < 0.0f) {
        imageForRescaling = imageForRescaling.Mirror(true);
    }
    if (scaleY < 0.0f) {
        imageForRescaling = imageForRescaling.Mirror(false);
    }
    imageForRescaling.Rescale(scaling.width, scaling.height);
    return WxWidgetsBufferConverter::convertWxImageToBuffer(imageForRescaling);
}
