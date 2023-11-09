#ifndef ZIPLODE_WINDOWMAIN_H
#define ZIPLODE_WINDOWMAIN_H

#include <string>
#include <format>
#include <iostream>
#include <wx/wx.h>
#include <fmt/core.h>
#include <fmt/format.h>

#include "../AppInfo.h"
#include "Resources.h"

using namespace std;

class WindowMain : public wxFrame
{
    public:
        WindowMain();

    private:
        Resources *resources;
        void OnHello(wxCommandEvent& event);
        void OnExit(wxCommandEvent& event);
        void OnAbout(wxCommandEvent& event);
        static void button1Clicked();
        static void button2Clicked();
        static void button3Clicked();
};

enum MAIN_MENU_IDS
{
    MENU_HELLO = 1,
};

#endif //ZIPLODE_WINDOWMAIN_H
