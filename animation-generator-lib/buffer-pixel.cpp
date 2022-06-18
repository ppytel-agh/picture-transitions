#include "buffer-pixel.h"

bool BufferPixel::operator==(const BufferPixel& bpx) const {
	return (bpx.i == this->i) && (bpx.j == this->j);
}

BufferPixel BufferPixel::operator+(BufferPixel& r) const
{
	return BufferPixel({ this->i + r.i, this->j + r.j });
}

std::wstring ToString(const BufferPixel& bpx) {
	std::wstringstream ss;
	ss << "[" << bpx.i << ", " << bpx.j << "]";
	return ss.str();
}