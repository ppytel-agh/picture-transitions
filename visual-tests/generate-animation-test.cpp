#include "generate-animation-test.h"

#include <slide-transition-filler.h>
#include <brightness-change-transition-filler.h>
#include <central-scaling-transition-filler.h>
#include <letter-rotation-transition-filler.h>
#include <blend-transition-filler.h>

#include <load-start-keyframe-action.h>
#include <load-end-keyframe-action.h>

#include <save-animation-action.h>

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
	CentralScalingTransitionFiller* boxIn = new CentralScalingTransitionFiller(false);
	CentralScalingTransitionFiller* boxOut = new CentralScalingTransitionFiller(true);
	LetterRotationTransitionFiller* verticalAxisRotation = new LetterRotationTransitionFiller(true);
	LetterRotationTransitionFiller* horizontalAxisRotation = new LetterRotationTransitionFiller(false);
	BlendTransitionFiller* blendingTransition = new BlendTransitionFiller();
	TransitionsManager* transitionsManager = new TransitionsManager(
		{
			{L"przejœcie A", *mockFiller1},
			{L"przejœcie B", *mockFiller2},
			{L"przejœcie C", *mockFiller3},
			{L"wjazd z lewej", *ltr},
			{L"wjazd z prawej", *rtl},
			{L"wjazd z do³u", *btt},
			{L"wjazd z góry", *ttb},
			{L"zmiana jasnoœci", *brightnessChangeTransition},
			{L"boks wchodz¹cy" , *boxIn},
			{L"boks wychodz¹cy" , *boxOut},
			{L"obrót wokó³ osi Y", *verticalAxisRotation},
			{L"obrót wokó³ osi X", *horizontalAxisRotation},
			{L"alpha blending", *blendingTransition}
		}
	);
	GenerateAnimationSimple* generateAnimation = new GenerateAnimationSimple(*animationGenerator, *model, *transitionsManager);
	FramePreviewAction* framePreview = new FramePreviewAction(*model);
	//LoadStartKeyframeAction* loadStartKeyframe = new LoadStartKeyframeAction(*model);
	//LoadEndKeyframeAction* loadEndKeyframe = new LoadEndKeyframeAction(*model);
	SaveAnimationAction* saveAction = new SaveAnimationAction(*model);
	AnimationGeneratorUIActions* testActions = new AnimationGeneratorUIActions{};
	testActions->generateAnimationAction = *generateAnimation;
	testActions->showPreviewAction = *framePreview;
	//testActions->setStartKeyframeAction = *loadStartKeyframe;
	//testActions->setEndKeyframeAction = *loadEndKeyframe;
	testActions->saveAnimationAction = *saveAction;

	AnimationGeneratorMainFrame* mainFrame = new AnimationGeneratorMainFrame(parentFrame, transitionsManager->getTransitionNames(), *testActions);
	mainFrame->Show();

	mainFrame->getUI()->setStartKeyframePreview(startKeyframe);
	mainFrame->getUI()->setEndKeyframePreview(endKeyframe);
}
