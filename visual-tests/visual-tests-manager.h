#pragma once

#include <string>
#include "abstract-visual-test.h"
#include "tests/example-test/example-test.h"
#include "visual-test-record.h"
#include "tests/graphic-buffer/graphic-buffer-test.h"
#include "tests/sections-test/sections-test.h"
#include "tests/blit-tests/blit-tests.h"
#include "tests/converter-test/converter-test.h"

class VisualTestsManager {
public:
	VisualTestsManager();
	VisualTestRecord* getTests();
	size_t getNumberOfTests();
private:
	size_t numberOfTests;
	VisualTestRecord* tests;
};