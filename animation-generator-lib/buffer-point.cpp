#include "buffer-point.h"

bool BufferPoint::operator==(const BufferPoint& bp) const {
	return (bp.x == this->x) && (bp.y == this->y);
}

std::wstring ToString(const BufferPoint& bp) {
	std::wstringstream ss;
	ss << "(" << bp.x << ", " << bp.y << ")";
	return ss.str();
}