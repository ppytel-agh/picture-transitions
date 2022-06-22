#include "transitions-repo.h"

TransitionsRepo::TransitionsRepo()
{
	this->fillers = new std::vector<AnimationFrameFillerInterface*>{
		new SlideTransitionFiller(true, true),
		new SlideTransitionFiller(true, false),
	 new SlideTransitionFiller(false, true),
	new SlideTransitionFiller(false, false),
	new BrightnessChangeTransitionFiller(),
	new CentralScalingTransitionFiller(false),
	new CentralScalingTransitionFiller(true),
	new LetterRotationTransitionFiller(true),
 new LetterRotationTransitionFiller(false),
 new BlendTransitionFiller(),
 new BlurTransitionFiller(),
 new RingTransitionFiller()
 new WindowTransitionFiller()
	};
	this->availableTransitions = new TransitionsManager(
		{
			{L"wjazd z lewej", *(*this->fillers)[0]},
			{L"wjazd z prawej", *(*this->fillers)[1]},
			{L"wjazd z do�u", *(*this->fillers)[2]},
			{L"wjazd z g�ry", *(*this->fillers)[3]},
			{L"zmiana jasno�ci", *(*this->fillers)[4]},
			{L"boks wchodz�cy" , *(*this->fillers)[5]},
			{L"boks wychodz�cy" , *(*this->fillers)[6]},
			{L"obr�t wok� osi Y", *(*this->fillers)[7]},
			{L"obr�t wok� osi X", *(*this->fillers)[8]},
			{L"alpha blending", *(*this->fillers)[9]},
			{L"blurring", *(*this->fillers)[10]},
			{L"ring", *(*this->fillers)[11]}
			{L"okiennica", *(*this->fillers)[12]}
		}
	);
}

TransitionsRepo::~TransitionsRepo()
{
	for (AnimationFrameFillerInterface* filler : *this->fillers) {
		delete filler;
	}
	delete this->availableTransitions;
}

TransitionsManager& TransitionsRepo::getAvailableTransitions()
{
	return *this->availableTransitions;
}
