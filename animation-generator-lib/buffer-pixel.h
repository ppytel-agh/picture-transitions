#pragma once

#include <string>
#include <sstream>

class BufferPixel {
public:
	/**
	* row offset from top
	*/
	int i;
	/**
	* column offset from left
	*/
	int j;
	bool operator==(const BufferPixel& bpx) const;
};

std::wstring ToString(const BufferPixel& bpx);