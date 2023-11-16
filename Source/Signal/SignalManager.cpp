#include "SignalManager.h"

void SignalManager::registerReceiver(SignalReceiver* receiver)
{
    this->receivers.push_back(receiver);
}

void SignalManager::sendSignal(int signalID, Signal* signal)
{
    for (SignalReceiver* receiver : this->receivers) {
        receiver->onSignalReceived(signalID, signal);
    }
}
