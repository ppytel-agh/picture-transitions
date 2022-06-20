#include "generate-animation-test.h"

#include <slide-transition-filler.h>
#include <brightness-change-transition-filler.h>

void GenerateAnimationTest::initializeUI(wxFrame* parentFrame)
{
	class MockFiller : public AnimationFrameFillerInterface {
	public:
		MockFiller(int off) :offset(off) {}
		void fillAnimationFrame(const GraphicsBuffer& startKeyframe, const GraphicsBuffer& endKeyframe, GraphicsBuffer& filledFrame, float frameNorm) override {
			filledFrame.blit(endKeyframe, { 0,0 }, { 0, 0 }, { 240, 135 });
			filledFrame.blit(startKeyframe, { 0,0 }, { 0, 0 }, { (unsigned int)(240 * frameNorm) + this->offset, 135 });
		}
	private:
		int offset;
	};

	wxImage::AddHandler(new wxPNGHandler());
	wxImage startKeyframe("./tests/animation-generator-ui-test/startkeyframe.png");
	wxImage endKeyframe("./tests/animation-generator-ui-test/endkeyframe.png");

	Model* model = new Model();
	model->setStartKeyframe(WxWidgetsBufferConverter::convertWxImageToBuffer(startKeyframe));
	model->setEndKeyframe(WxWidgetsBufferConverter::convertWxImageToBuffer(endKeyframe));

	SimpleAnimationGenerator* animationGenerator = new SimpleAnimationGenerator();
	MockFiller* mockFiller1 = new MockFiller(0);
	MockFiller* mockFiller2 = new MockFiller(-50);
	MockFiller* mockFiller3 = new MockFiller(25);
	SlideTransitionFiller* ltr = new SlideTransitionFiller(true, true);
	SlideTransitionFiller* rtl = new SlideTransitionFiller(true, false);
	SlideTransitionFiller* btt = new SlideTransitionFiller(false, true);
	SlideTransitionFiller* ttb = new SlideTransitionFiller(false, false);
	BrightnessChangeTransitionFiller* brightnessChangeTransition = new BrightnessChangeTransitionFiller();
	TransitionsManager* transitionsManager = new TransitionsManager(
		{
			{L"przej�cie A", *mockFiller1},
			{L"przej�cie B", *mockFiller2},
			{L"przej�cie C", *mockFiller3},
			{L"wjazd z lewej", *ltr},
			{L"wjazd z prawej", *rtl},
			{L"wjazd z do�u", *btt},
			{L"wjazd z g�ry", *ttb},
		{L"zmiana jasno�ci", *brightnessChangeTransition}
		}
	);
	GenerateAnimationSimple* generateAnimation = new GenerateAnimationSimple(*animationGenerator, *model, *transitionsManager);
	FramePreviewAction* framePreview = new FramePreviewAction(*model);
	AnimationGeneratorUIActions* testActions = new AnimationGeneratorUIActions{};
	testActions->generateAnimationAction = *generateAnimation;
	testActions->showPreviewAction = *framePreview;

	AnimationGeneratorMainFrame* mainFrame = new AnimationGeneratorMainFrame(parentFrame, transitionsManager->getTransitionNames(), *testActions);
	mainFrame->Show();

	mainFrame->getUI()->setStartKeyframePreview(startKeyframe);
	mainFrame->getUI()->setEndKeyframePreview(endKeyframe);
}
