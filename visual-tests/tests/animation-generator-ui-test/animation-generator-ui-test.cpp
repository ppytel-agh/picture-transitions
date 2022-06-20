#include "animation-generator-ui-test.h"

#include <functional>

void AnimationGeneratorUITest::initializeUI(wxFrame* parentFrame)
{
	wxImage::AddHandler(new wxPNGHandler());
	
	std::function<void(AnimationGeneratorUI&)>* resetAction = new std::function<void(AnimationGeneratorUI&)>{
		 [](AnimationGeneratorUI& ui) {
			ui.addMessage("reset");
		}
	};
	std::function<void(AnimationGeneratorUI&, std::string)>* setStartKeyframeAction = new std::function<void(AnimationGeneratorUI&, std::string)>{
	 [](AnimationGeneratorUI& ui, std::string keyframePath) {
		std::stringstream ss;
		ss << "set " << keyframePath << " as start keyframe";
		ui.addMessage(ss.str());
		wxImage keyframePlaceholder("./tests/animation-generator-ui-test/startkeyframe.png");
		ui.setStartKeyframePreview(keyframePlaceholder);
		ui.setKeyframesSize(240, 135);
	}
	};
	std::function<void(AnimationGeneratorUI&, std::string)>* setEndKeyframeAction = new std::function<void(AnimationGeneratorUI&, std::string)>{
			[](AnimationGeneratorUI& ui, std::string keyframePath) {
		std::stringstream ss;
		ss << "set " << keyframePath << " as end keyframe";
		ui.addMessage(ss.str());
		wxImage keyframePlaceholder("tests/animation-generator-ui-test/endkeyframe.png");
		ui.setEndKeyframePreview(keyframePlaceholder);
		ui.setKeyframesSize(240, 135);
	}
	};
	std::function<void(AnimationGeneratorUI&, unsigned int, unsigned int)>* generateAnimationAction = new std::function<void(AnimationGeneratorUI&, unsigned int, unsigned int)>{
		[](AnimationGeneratorUI& ui, unsigned int transitionId, unsigned int numberOfFrames) {
		std::stringstream ss;
		ss << "generated " << numberOfFrames << " frame animation of type " << transitionId;
		ui.addMessage(ss.str());
		wxImage framePlaceholder("tests/animation-generator-ui-test/interframe.png");
		ui.setAnimationFramePreview(framePlaceholder);
		ui.setAnimationFrameCountSlider(numberOfFrames);
	}
	};
	std::function<void(AnimationGeneratorUI&, unsigned int, unsigned int)>* previewFrameAction = new std::function<void(AnimationGeneratorUI&, unsigned int, unsigned int)>{
		[](AnimationGeneratorUI& ui, unsigned int frameIndex, unsigned int numberOfFrames) {
		std::stringstream ss;
		ss << "preview of frame " << frameIndex << "/" << numberOfFrames;
		ui.addMessage(ss.str());
	}
	};
	std::function<void(AnimationGeneratorUI&, std::string)>* saveAnimationAction = new std::function<void(AnimationGeneratorUI&, std::string)>{
		[](AnimationGeneratorUI& ui, std::string outputDir) {
			std::stringstream ss;
			ss << "saving animation to dir " << outputDir;
			ui.addMessage(ss.str());
		}
	};
	AnimationGeneratorUIActions* testActions = new AnimationGeneratorUIActions{};
	testActions->resetAction = *resetAction;
	testActions->setStartKeyframeAction = *setStartKeyframeAction;
	testActions->setEndKeyframeAction = *setEndKeyframeAction;
	testActions->generateAnimationAction = *generateAnimationAction;
	testActions->showPreviewAction = *previewFrameAction;
	testActions->saveAnimationAction = *saveAnimationAction;
	AnimationGeneratorMainFrame* mainFrame = new AnimationGeneratorMainFrame(parentFrame, { L"test1", L"test2", L"abc¹êŸ¿æ" }, *testActions);
	mainFrame->Show();
}
