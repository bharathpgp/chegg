#include "cscreen.h"
// ==== main ==================================================================
int main()
{
    // create a screen object
    CScreen screen("config.dat");
    // have the object fill the screen at random locations with colored
    // characters
    screen.Scatter();
    return 0;
} // end of "main"