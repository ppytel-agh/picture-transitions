#pragma once

#include <string>
#include <sstream>

class BufferPoint {
public:
	/**
	* horizontal position relative to center
	*/
	float x;
	/**
	* vertical position relative to center
	*/
	float y;
	bool operator==(const BufferPoint& bp) const;
};

std::wstring ToString(const BufferPoint& bp);