#ifndef ZIPLODE_STATEUSER_H
#define ZIPLODE_STATEUSER_H

#include "StateManager.h"

class StateUser: public SignalReceiver{
    public:
        StateUser(StateManager* stateManager);

    protected:
        StateManager* stateManager = nullptr;
};


#endif //ZIPLODE_STATEUSER_H
