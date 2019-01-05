#include <iostream>

using namespace std;

const int M = 3;
const int N = 3;

// display 2D array in matrix form
void displayArray(int arr[M][N])
{
    int i, j;
    for (i = 0; i < M; i++)
    {
        for (j = 0; j < N; j++)
        {
            printf("%d\t", arr[i][j]);
        }
        printf("\n");
    }
}

// compute 2D array sum of all elements
int getTotal(int arr[M][N])
{
    int i, j, sum = 0;
    for (i = 0; i < M; i++)
        for (j = 0; j < N; j++)
            sum += arr[i][j];
    return sum;
}

// compute average of 2D array
float getAverage(int arr[M][N])
{
    int i, j, sum = 0;
    for (i = 0; i < M; i++)
        for (j = 0; j < N; j++)
            sum += arr[i][j];
    return sum / (M * N);
}

// get value at given row, col
int getValue(int arr[M][N], int row, int col)
{
    return arr[row][col];
}

// compute sum of given row
int getRowTotal(int arr[M][N], int row)
{
    int i, tot = 0;
    for (i = 0; i < N; i++)
        tot += arr[row][i];
    return tot;
}

// compute sum of given column
int getColumnTotal(int arr[M][N], int col)
{
    int i, tot = 0;
    for (i = 0; i < M; i++)
        tot += arr[i][col];
    return tot;
}

// get the position of given value
void getPosition(int arr[M][N], int val, int *row, int *col)
{
    int i, j;
    for (i = 0; i < M; i++)
        for (j = 0; j < N; j++)
            if (arr[i][j] == val)
            {
                *row = i + 1;
                *col = j + 1;
                return;
            }
}

// get the highest value of given row
int getHighestInRow(int arr[M][N], int row)
{
    int i, highest = arr[row][0];
    for (i = 1; i < N; i++)
        if (highest < arr[row][i])
            highest = arr[row][i];
    return highest;
}

// get the lowest value of given row
int getLowestInRow(int arr[M][N], int row)
{
    int i, lowest = arr[row][0];
    for (i = 1; i < N; i++)
        if (lowest > arr[row][i])
            lowest = arr[row][i];
    return lowest;
}

// main function to demonstrate 2D array
int main()
{
    int arr[][N] = {{1, 2, 3}, {4, 5, 6}, {7, 8, 9}};
    int row, col;
    displayArray(arr);
    printf("Total = %d\n", getTotal(arr));
    printf("Average = %0.2f\n", getAverage(arr));
    printf("Value at(%d, %d) = %d\n", 3, 3, getValue(arr, 2, 2));
    printf("Row Total = %d\n", getRowTotal(arr, 1));
    printf("Column Total = %d\n", getColumnTotal(arr, 1));
    getPosition(arr, 5, &row, &col);
    printf("Position of value = %d is (%d, %d)\n", 5, row, col);
    printf("Row Highest Value = %d\n", getHighestInRow(arr, 1));
    printf("Row Lowest Value = %d\n", getLowestInRow(arr, 1));
    return 0;
}