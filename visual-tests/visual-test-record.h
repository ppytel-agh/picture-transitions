#pragma once

#include <string>
#include "abstract-visual-test.h"

class VisualTestRecord {
public:
	std::string name;
	AbstractVisualTest* instance;
};
