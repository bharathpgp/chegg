#ifndef CSCREEN_H
#define CSCREEN_H

#include <iostream>
#include <fstream>
#include <ncurses.h>

using namespace std;
class CScreen
{
  public:
    CScreen(const char fname[]);
    void InitCurses();
    void Scatter();

    char m_dispChar;
    int m_sleep;
};

#endif