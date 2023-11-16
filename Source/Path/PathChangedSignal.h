#ifndef ZIPLODE_PATHCHANGEDSIGNAL_H
#define ZIPLODE_PATHCHANGEDSIGNAL_H

#include <string>

#include "../Signal/Signal.h"

using std::string;

class PathChangedSignal : public Signal {
    public:
        PathChangedSignal(string newPath);
        string getPath();

    private:
        string path;
};


#endif //ZIPLODE_PATHCHANGEDSIGNAL_H
