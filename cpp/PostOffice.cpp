#include <cstdlib>
#include <iostream>
#include <ctime>
#include <unistd.h>
#include "stack.h"

using namespace std;

int main()
{
    int total_minutes = 30,      // total number of minutes in the simulation
        print_minutes = 10,      // print results every print_minutes minutes
        max_package_weight = 10, // largest package weight in pounds (weight values randomly set from 1 to max_weight)
        add_packages = 10,       // number of packages added each minute
        total_weight = 25,       // total weight (pounds) of all packages a postal worker can handle in one minute
        postalworkers;           // number of postal workers read from user

    int minute, package, workers, timeCnt = 0;

    stack pkgBox;

    cout << "Enter number of postalworkers: ";
    cin >> postalworkers;

    for (minute = 0; minute < total_minutes; minute++)
    {
        int pkgWeight;
        srand(minute);
        for (package = 0; package < add_packages; package++)
        {
            pkgWeight = rand() % max_package_weight + 1;
            pkgBox.push(pkgWeight);
        }

        for (workers = 0; workers < postalworkers; workers++)
        {
            int sum = 0;
            while (sum <= total_weight)
            {
                if (0 == pkgBox.empty() && sum + pkgBox.peek() <= total_weight)
                    sum += pkgBox.pop();
                else
                    break;
            }
        }

        usleep(1000000);
        timeCnt++;

        if (timeCnt == print_minutes)
        {
            cout << "Time = " << print_minutes << endl;
            cout << "Weights of packages in stack" << endl;
            pkgBox.print();
            cout << "Number of elements in stack: " << pkgBox.elements() << endl;
            timeCnt = 0;
        }
    }

    return 0;
}