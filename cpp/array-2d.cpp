#include <iostream>

using namespace std;

const int ROW = 4;
const int COL = 3;

void fill2dArray(int arr2D[ROW][COL]);
void print2dArray(int arr2D[ROW][COL]);
void getColumn(int arr2D[ROW][COL], int col, int result[ROW]);
void printArray(int result[ROW]);

// main function to demonstrate 2D array
int main()
{
    int arr2D[ROW][COL];
    int result[ROW];
    int i;

    fill2dArray(arr2D);
    print2dArray(arr2D);

    for (i = 0; i < COL; i++)
    {
        getColumn(arr2D, i, result);
        printArray(result);
    }
    return 0;
}

// fill 2D array with random numbers between 0 and 9 inclusive
void fill2dArray(int arr2D[ROW][COL])
{
    int i, j;
    for (i = 0; i < ROW; i++)
        for (j = 0; j < COL; j++)
            arr2D[i][j] = rand() % 10;
}

// print 2D array in matrix form
void print2dArray(int arr2D[ROW][COL])
{
    int i, j;
    for (i = 0; i < ROW; i++)
    {
        for (j = 0; j < COL; j++)
        {
            cout << arr2D[i][j] << "\t";
        }
        cout << "\n";
    }
    cout << "\n";
}

// get the column from 2D array
void getColumn(int arr2D[ROW][COL], int col, int result[ROW])
{
    int i;
    for (i = 0; i < ROW; i++)
        result[i] = arr2D[i][col];
}

// print given array
void printArray(int result[ROW])
{
    int i;
    for (i = 0; i < ROW; i++)
    {
        cout << result[i] << "\t";
    }
    cout << "\n";
}