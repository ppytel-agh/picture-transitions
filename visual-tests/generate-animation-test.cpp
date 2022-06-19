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
	SimpleAnimationGenerator* animationGenerator = new SimpleAnimationGenerator();
	Model* model = new Model();
	TransitionsManager* transitionsManager = new TransitionsManager(
		{
			{L"przejœcie A", new MockFiller(0)},
			{L"przejœcie B", new MockFiller(-50)},
			{L"przejœcie C", new MockFiller(25)}
		}
	);
	GenerateAnimationSimple* generateAnimation = new GenerateAnimationSimple(std::ref( * animationGenerator), std::ref(*model), std::ref(*transitionsManager));
	AnimationGeneratorUIActions* testActions = new AnimationGeneratorUIActions{};
	testActions->generateAnimationAction = *generateAnimation;

}
