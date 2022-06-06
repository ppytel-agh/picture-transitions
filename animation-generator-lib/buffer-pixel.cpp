#include "buffer-pixel.h"

bool BufferPixel::operator==(const BufferPixel& bpx) const {
	return (bpx.i == this->i) && (bpx.j == this->j);
}

std::wstring ToString(const BufferPixel& bpx) {
	std::wstringstream ss;
	ss << "[" << bpx.i << ", " << bpx.j << "]";
	return ss.str();
}