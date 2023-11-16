#include "StateUser.h"

StateUser::StateUser(StateManager* stateManager)
{
    this->stateManager = stateManager;
    this->stateManager->getSignalManager()->registerReceiver(this);
}
