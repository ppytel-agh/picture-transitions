#include "sections-test.h"

void SectionsTest::initializeUI(wxFrame* parentFrame)
{
	GraphicsBuffer source({ 150, 100 });
	source.setSubpixelValues(sourcebmp);
	GraphicsBuffer expectedResult({ 87, 54 });
	expectedResult.setSubpixelValues(testcase1bmp);
	GraphicsBuffer section = source.createSection({ 17, 19 }, { 87, 54 });
	Assert::IsTrue(section == expectedResult);
}
