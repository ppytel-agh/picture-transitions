#include "generate-animation-test.h"

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
	TransitionsManager* transitionsManager = new TransitionsManager(
		{
			{L"przejœcie A", *mockFiller1},
			{L"przejœcie B", *mockFiller2},
			{L"przejœcie C", *mockFiller3}
		}
	);
	GenerateAnimationSimple* generateAnimation = new GenerateAnimationSimple(*animationGenerator, *model, * transitionsManager);
	FramePreviewAction* framePreview = new FramePreviewAction(*model);
	AnimationGeneratorUIActions* testActions = new AnimationGeneratorUIActions{};
	testActions->generateAnimationAction = *generateAnimation;
	testActions->showPreviewAction = *framePreview;

	AnimationGeneratorMainFrame* mainFrame = new AnimationGeneratorMainFrame(parentFrame, transitionsManager->getTransitionNames(), *testActions);
	mainFrame->Show();

	mainFrame->getUI()->setStartKeyframePreview(startKeyframe);
	mainFrame->getUI()->setEndKeyframePreview(endKeyframe);
}
