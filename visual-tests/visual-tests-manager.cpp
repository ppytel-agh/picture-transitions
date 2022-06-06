#include "visual-tests-manager.h"
#include "visual-test-record.h"

VisualTestsManager::VisualTestsManager() {
	std::initializer_list<VisualTestRecord> testsList{
		VisualTestRecord{"przyk�adowy test", new ExampleTest()},
	};

	this->numberOfTests = testsList.size();
	this->tests = new VisualTestRecord[this->numberOfTests];
	int i = 0;
	for (auto test : testsList) {
		this->tests[i++] = test;
	}
}

VisualTestRecord* VisualTestsManager::getTests() {
	return this->tests;
}

size_t VisualTestsManager::getNumberOfTests() {
	return this->numberOfTests;
}