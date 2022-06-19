#include "transitions-manager.h"

TransitionsManager::TransitionsManager(std::vector<std::pair<std::wstring, AnimationFrameFillerInterface&>> transitions)
{
    for (auto transitionPair : transitions) {
        this->transitionNames.push_back(transitionPair.first);
        this->transitionFillers.push_back(std::ref(transitionPair.second));
    }
}

std::vector<std::wstring> TransitionsManager::getTransitionNames() const
{
    return this->transitionNames;
}

bool TransitionsManager::transitionExists(unsigned int transitionId) const
{
    return transitionId < this->transitionFillers.size();
}

bool TransitionsManager::fillerIsEmpty(AnimationFrameFillerInterface& fillerToCheck)
{
    try {
        EmptyTransitionFiller& emptyFiller = dynamic_cast<EmptyTransitionFiller&>(fillerToCheck);
        return true;
    }
    catch (const std::bad_cast& e) {
        return false;
    }
}

AnimationFrameFillerInterface& TransitionsManager::getTransitionFiller(unsigned int transitionId)
{
    if (this->transitionExists(transitionId)) {
        return this->transitionFillers[transitionId];
    }
    else {
        return this->emptyFiller;
    }
}
