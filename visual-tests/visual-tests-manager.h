#pragma once

#include <string>
#include "abstract-visual-test.h"
#include "tests/example-test/example-test.h"
#include "visual-test-record.h"

class VisualTestsManager {
public:
	VisualTestsManager();
	VisualTestRecord* getTests();
	size_t getNumberOfTests();
private:
	size_t numberOfTests;
	VisualTestRecord* tests;
};