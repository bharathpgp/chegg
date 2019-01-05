// Description:
// This is the implementation file for the CScreen class.
// ============================================================================
using namespace std;
#include "cscreen.h"
#include "cmatrix.h"

// ==== CScreen::CScreen ======================================================
//
// This is the constructor for the CScreen class. It uses the parameter to open
// the configuration file and fetch the display character and sleep interval to
// initialize the object. If values cannot be read from the input file, default
// values are used. Then the random number generator is seeded with the current
// system time, and the curses library is initialized before returning.
//
// Input:
// fname [IN] -- a cstring containing the name of the configuration
// file
//
// ============================================================================

CScreen::CScreen(const char fname[])
{
    //use fname extraction operator to assign the values to the private data
    //members.Then random number generator is seeded for random pairing
    //this also calls the InitCurses function before returning back to the caller
    ifstream myFile;

    myFile.open(fname);
    if (myFile.fail())
    {
        cout << "Error with file name...\n";
    }

    //get the display character and sleep interval
    myFile.get(m_dispChar);
    myFile >> m_sleep;
    cout << m_dispChar << m_sleep << endl;
    srand(time(NULL));
    InitCurses();

} // end of "CScreen::CScreen"

// ==== CScreen::InitCurses ===================================================
//
// This function is responsible for initializing the curses library. It also
// establishes the foreground and background colors for all of the color pair
// structures.
// ====================================================================

void CScreen::InitCurses()
{
    //initialize curses library. initscr(), start_color()
    //set the foreground and background color.
    //use init_pair()
    initscr();
    start_color();
    init_pair(1, COLOR_RED, COLOR_BLUE);
    init_pair(2, COLOR_BLACK, COLOR_MAGENTA);
    init_pair(3, COLOR_WHITE, COLOR_BLUE);
    init_pair(4, COLOR_BLACK, COLOR_GREEN);
    init_pair(5, COLOR_WHITE, COLOR_CYAN);
    init_pair(6, COLOR_BLACK, COLOR_YELLOW);
    init_pair(7, COLOR_WHITE, COLOR_BLACK);

} // end of "CScreen::InitCurses"

// ==== CScreen::Scatter ======================================================
//
// This function contains an infinite loop that draws characters to random
// locations on the screen. Inside the loop, a COLOR_PAIR is activated, then a
// local CMatrix object is used to fill the screen with the display character.
// After the screen has been filled, the loop pauses for about a half-second,
// before doing it all over again and again, until the user presses Ctrl+c,
// which terminates the loop so that the function can return to the caller.
//
// ============================================================================
void CScreen::Scatter()
{

    //Will create a matix object passing in LINES and COLS as arguments. attron()
    //and color_pair() will be used in the infinite loop filling up the matrix
    //once the space is used to fill a block in the value of that block will be
    //true. If not, then false.
    //use usleep function for a pause.

    int index;
    CMatrix matrix(LINES, COLS);

    //for (index = 0; index < 7; ++index)
    while(1)
    {
        attron(COLOR_PAIR(index));
        index++;
        index %= 7;
        matrix.Fill(m_dispChar, m_sleep);
        refresh();
        usleep(500000);
    }

} // end of "CScreen::Scatter"