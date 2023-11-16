#ifndef ZIPLODE_SIGNALMANAGER_H
#define ZIPLODE_SIGNALMANAGER_H

#include <vector>
#include <map>

#include "SignalReceiver.h"
#include "Signal.h"

using std::vector;
using std::map;

class SignalManager {
    public:
        void registerReceiver(SignalReceiver* receiver);
        void sendSignal(int signalID, Signal* signal = new Signal());

    private:
        vector<SignalReceiver*> receivers;
};


#endif //ZIPLODE_SIGNALMANAGER_H
