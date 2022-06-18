#include "animation-generator-ui-test.h"

void AnimationGeneratorUITest::initializeUI(wxFrame* parentFrame)
{
	wxImage::AddHandler(new wxPNGHandler());
	AnimationGeneratorUIActions* testActions = new AnimationGeneratorUIActions{
		 [](AnimationGeneratorUI& ui) {
			ui.addMessage("reset");
		},
	 [](AnimationGeneratorUI& ui, std::string keyframePath) {
		std::stringstream ss;
		ss << "set " << keyframePath << " as start keyframe";
		ui.addMessage(ss.str());
		wxImage keyframePlaceholder("./tests/animation-generator-ui-test/startkeyframe.png");
		ui.setStartKeyframePreview(keyframePlaceholder);
		ui.setKeyframesSize(240, 135);
	},
			[](AnimationGeneratorUI& ui, std::string keyframePath) {
		std::stringstream ss;
		ss << "set " << keyframePath << " as end keyframe";
		ui.addMessage(ss.str());
		wxImage keyframePlaceholder("tests/animation-generator-ui-test/endkeyframe.png");
		ui.setEndKeyframePreview(keyframePlaceholder);
		ui.setKeyframesSize(240, 135);
	},
		[](AnimationGeneratorUI& ui, unsigned int transitionId, unsigned int numberOfFrames) {
		std::stringstream ss;
		ss << "generated " << numberOfFrames << " frame animation of type " << transitionId;
		ui.addMessage(ss.str());
		wxImage framePlaceholder("tests/animation-generator-ui-test/interframe.png");
		ui.setAnimationFramePreview(framePlaceholder);
		ui.setAnimationFrameCountSlider(numberOfFrames);
	},
		[](AnimationGeneratorUI& ui, unsigned int frameIndex, unsigned int numberOfFrames) {
		std::stringstream ss;
		ss << "preview of frame " << frameIndex << "/" << numberOfFrames;
		ui.addMessage(ss.str());
	}, [](AnimationGeneratorUI& ui, std::string outputDir) {
		std::stringstream ss;
		ss << "saving animation to dir " << outputDir;
		ui.addMessage(ss.str());
	}
	};
	AnimationGeneratorMainFrame* mainFrame = new AnimationGeneratorMainFrame(parentFrame, { L"test1", L"test2", L"abc¹êŸ¿æ" }, *testActions);
	mainFrame->Show();
}
