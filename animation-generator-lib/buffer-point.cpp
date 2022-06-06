#include "buffer-point.h"

#define EPSILON 0.000001f

bool BufferPoint::operator==(const BufferPoint& bp) const {
	float diffX = fabs(bp.x - this->x);
	float diffY = fabs(bp.y - this->y);
	return (diffX < EPSILON) && (diffY < EPSILON);
}

std::wstring ToString(const BufferPoint& bp) {
	std::wstringstream ss;
	ss << "(" << bp.x << ", " << bp.y << ")";
	return ss.str();
}