#ifndef CMATRIX_H
#define CMATRIX_H

#include <cstdlib>
#include <ctime>
#include <fstream>
#include <ncurses.h>
#include <unistd.h>

class CMatrix
{
  public:
    CMatrix(int numRows, int numCols);
    void Fill(char dispChar, int msecs);

    int m_numRows;
    int m_numCols;
};
#endif