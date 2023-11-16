#include "PathChangedSignal.h"

PathChangedSignal::PathChangedSignal(string newPath) {
    this->path = std::move(newPath);
}

string PathChangedSignal::getPath()
{
    return this->path;
}
