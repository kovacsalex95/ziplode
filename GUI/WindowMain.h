#ifndef ZIPLODE_WINDOWMAIN_H
#define ZIPLODE_WINDOWMAIN_H

#include <string>
#include <iostream>
#include "FileList.h"
#include "FileListTab.h"
#include "TabView.h"

using namespace std;

class WindowMain
{
    public:
        WindowMain();
        static void open();

    private:
        static void button1Clicked();
        static void button2Clicked();
        static void button3Clicked();
};


#endif //ZIPLODE_WINDOWMAIN_H
