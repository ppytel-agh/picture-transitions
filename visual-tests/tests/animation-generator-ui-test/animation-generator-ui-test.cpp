#include "animation-generator-ui-test.h"

void AnimationGeneratorUITest::initializeUI(wxFrame* parentFrame)
{
	std::function<void(AnimationGeneratorUI&)> resetAction = [](AnimationGeneratorUI& ui) {
		ui.addMessage("reset");
	};
	std::function<void(AnimationGeneratorUI&, std::string)> setStartKeyframeAction = [](AnimationGeneratorUI& ui, std::string keyframePath) {
		std::stringstream ss;
		ss << "set " << keyframePath << " as start keyframe";
		ui.addMessage(ss.str());
		wxImage keyframePlaceholder("tests/animation-generator-ui-test/start-keyframe.bmp");
		ui.setStartKeyframePreview(keyframePlaceholder);
	};
	std::function<void(AnimationGeneratorUI&, std::string)> setEndKeyframeAction = [](AnimationGeneratorUI& ui, std::string keyframePath) {
		std::stringstream ss;
		ss << "set " << keyframePath << " as end keyframe";
		ui.addMessage(ss.str());
		wxImage keyframePlaceholder("tests/animation-generator-ui-test/end-keyframe.bmp");
		ui.setEndKeyframePreview(keyframePlaceholder);
	};
	std::function<void(AnimationGeneratorUI&, unsigned int, unsigned int)> generateAnimationAction = [](AnimationGeneratorUI& ui, unsigned int transitionId, unsigned int numberOfFrames) {
		std::stringstream ss;
		ss << "generated " << numberOfFrames << " frame animation of type " << transitionId;
		ui.addMessage(ss.str());
		wxImage framePlaceholder("tests/animation-generator-ui-test/inter-frame.bmp");
		ui.setAnimationFramePreview(framePlaceholder);
	};
	std::function<void(AnimationGeneratorUI&, unsigned int, unsigned int)> showPreviewAction = [](AnimationGeneratorUI& ui, unsigned int frameIndex, unsigned int numberOfFrames) {
		std::stringstream ss;
		ss << "preview of frame " << frameIndex << "/" << numberOfFrames;
		ui.addMessage(ss.str());
	};
	std::function<void(AnimationGeneratorUI&, std::string)> saveAnimationAction = [](AnimationGeneratorUI& ui, std::string outputDir) {
		std::stringstream ss;
		ss << "saving animation to dir " << outputDir;
		ui.addMessage(ss.str());
	};
	AnimationGeneratorUIActions actions{
		resetAction,
			setStartKeyframeAction,
			setEndKeyframeAction,
			generateAnimationAction,
			showPreviewAction,
			saveAnimationAction
	};
	AnimationGeneratorMainFrame* mainFrame = new AnimationGeneratorMainFrame(parentFrame, { "dupa", "dupa2" }, actions);
	mainFrame->Show();
}
