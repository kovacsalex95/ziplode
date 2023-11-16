#ifndef ZIPLODE_SIGNALRECEIVER_H
#define ZIPLODE_SIGNALRECEIVER_H

#include <iostream>
#include <functional>

#include "Signal.h"

using std::function;

class SignalReceiver {
    public:
        virtual void onSignalReceived(int signalID, Signal* signal) = 0;
};


#endif //ZIPLODE_SIGNALRECEIVER_H
