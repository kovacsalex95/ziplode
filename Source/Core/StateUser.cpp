#include "StateUser.h"

StateUser::StateUser(StateManager* stateManager)
{
    std::cout << "Signal receiver initiated" << std::endl;
    this->stateManager = stateManager;
    this->stateManager->getSignalManager()->registerReceiver(this);
}
