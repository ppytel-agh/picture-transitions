#include "visual-tests-manager.h"
#include "visual-test-record.h"

VisualTestsManager::VisualTestsManager() {
	std::initializer_list<VisualTestRecord> testsList{
		VisualTestRecord{"przyk³adowy test", new ExampleTest()},
		VisualTestRecord{"test kompatybilnosci bufora gragicznego", new GraphicBufferTest()},
		VisualTestRecord{"test wycinka", new SectionsTest()},
		VisualTestRecord{"test blitowania", new BlitTests()},
		VisualTestRecord{"test UI", new AnimationGeneratorUITest()},
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