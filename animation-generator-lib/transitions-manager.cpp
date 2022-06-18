#include "transitions-manager.h"

TransitionsManager::TransitionsManager(std::vector<std::pair<std::wstring, AnimationFrameFillerInterface*>> transitions)
{
    for (auto transitionPair : transitions) {
        this->transitionNames.push_back(transitionPair.first);
        this->transitionFillers.push_back(transitionPair.second);
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

AnimationFrameFillerInterface* TransitionsManager::getTransitionFiller(unsigned int transitionId) const
{
    if (this->transitionExists(transitionId)) {
        return this->transitionFillers[transitionId];
    }
    else {
        return nullptr;
    }
}
