#include "GUI/UIHandler.h"

int main (int argc, char **argv)
{
    UIHandler handler = *new UIHandler(argc, argv);
    return handler.status;
}
