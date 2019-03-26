#include <iostream>
#include <string>
using namespace std;

void sort(string *names, int *scores, int n);
double cal_avg(int *scores, int n);

int main() {

    int *test_scores, n;
    string *names;

    cout << "Enter the number of students: ";
    cin >> n;

    //allocate memory
    test_scores = new int[n];
    names = new string[n];

    for (int i = 0; i < n; i++) {
        cout << "Name" << i + 1 << ": ";
        cin >> *(names + i);
        cout << "test_scores" << i + 1 << ": ";
        cin >> *(test_scores + i);
    }

    cout << "Test scores are: " << endl;
    for (int i = 0; i < n; i++) {
        cout << "Name: " << *(names + i) << endl;
        cout << *(test_scores + i) << endl;
    }
    sort(names, test_scores, n);

    cout << "Test scores after sorting are: " << endl;
    for (int i = 0; i < n; i++) {
        cout << "Name: " << *(names + i) << endl;
        cout << *(test_scores + i) << endl;
    }
    cout << "\nAverage test score is : " << cal_avg(test_scores, n) << endl;
    cout << "\nAverage test score after dropping the lowest test score is : " << cal_avg(test_scores + 1, n - 1) << endl;
}

void sort(string *names, int *scores, int n) {
    
    int tmp;
    string temp;

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n - i - 1; j++)
        {
            if (*(scores + j) > *(scores + j + 1))
            {
                tmp = *(scores + j + 1);
                *(scores + j + 1) = *(scores + j);
                *(scores + j) = tmp;
                temp = *(names + j + 1);
                *(names + j + 1) = *(names + j);
                *(names + j) = temp;
            }
        }
    }
}

double cal_avg(int *scores, int n)
{
    double sum = 0;
    for (int i = 0; i < n; i++)
    {
        sum += *(scores + i);
    }
    return sum / n;
}