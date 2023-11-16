#include "SignalManager.h"

void SignalManager::registerReceiver(SignalReceiver* receiver)
{
    this->receivers.push_back(receiver);
}

void SignalManager::sendSignal(int signalID, Signal* signal)
{
    for (int i=0; i<this->receivers.size(); i++) {
        this->receivers[i]->onSignalReceived(signalID, signal);
    }
}
