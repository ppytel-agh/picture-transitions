#include "visual-tests-manager.h"
#include "visual-test-record.h"

#include "tests/scaler-test.h"
#include "tests/buffer-blender-tests.h"

VisualTestsManager::VisualTestsManager() {
	std::initializer_list<VisualTestRecord> testsList{
		VisualTestRecord{"przykładowy test", new ExampleTest()},
		VisualTestRecord{"test kompatybilnosci bufora gragicznego", new GraphicBufferTest()},
		VisualTestRecord{"test wycinka", new SectionsTest()},
		VisualTestRecord{"test blitowania", new BlitTests()},
		VisualTestRecord{"test konwertera", new ConverterTest()},
		VisualTestRecord{"test UI", new AnimationGeneratorUITest()},
		VisualTestRecord{"test generatora animacji", new AnimationGeneratorTest()},
		VisualTestRecord{"test generowania animacji", new GenerateAnimationTest()},
		VisualTestRecord{"test znormalizowanego blitu", new NormalizedBlitTest()},
		VisualTestRecord{"test skalowania", new ScalerTest()},
		VisualTestRecord{"test blendowania", new BufferBlenderTests()},
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