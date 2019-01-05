
#include <iostream>

using namespace std;

#define ARRAY_SIZE 5

// to generate lottery array using random numbers
void generateLotteryArray(int *lotteryArray)
{
    int i;
    for (i = 0; i < ARRAY_SIZE; i++)
        lotteryArray[i] = rand() % 9;
}

// to get user picking numbers
void getUserPick(int *userArray)
{
    int i;
    for (i = 0; i < ARRAY_SIZE; i++)
    {
        cout << "User pick between(0-9): ";
        cin >> userArray[i];
    }
}

// matching between lottery and user array
int matchLotteryAndUserArray(int *lotteryArray, int *userArray)
{
    int i, count = 0;
    for (i = 0; i < ARRAY_SIZE; i++)
        if (userArray[i] == lotteryArray[i])
            count++;
    return count;
}

// to display given array
void displayArray(int *array)
{
    int i;
    for (i = 0; i < ARRAY_SIZE; i++)
        cout << array[i] << "\t";
    cout << "\n";
}

// main program to demonstrate lottery application
int main() {
    int lotteryArray[ARRAY_SIZE];
    int userArray[ARRAY_SIZE];
    int matchingCount;
    generateLotteryArray(lotteryArray);
    getUserPick(userArray);
    cout << "Lottery Array:" << endl;
    displayArray(lotteryArray);
    cout << "User Array:" << endl;
    displayArray(userArray);
    matchingCount = matchLotteryAndUserArray(lotteryArray, userArray);
    if (ARRAY_SIZE == matchingCount)
        cout << "You won the grand prize!!!";
    else
        cout << "Number of Matches : " << matchingCount;
    return 0;
}