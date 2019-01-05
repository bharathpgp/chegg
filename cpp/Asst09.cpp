#include <iostream>
#include <fstream>
using namespace std;

#define MAX_STUDENTS 25
#define AMOUNT_OF_HW 10
#define AMOUNT_OF_TESTS 3

void outputStudentInfo(string firstName, string lastName, char grade, int hw[], int exams[])
{
    int i;
    cout << lastName << ", " << firstName << endl;
    cout << "Assignment grades" << endl;
    for (i = 0; i < 10; i++)
        cout << hw[i] << " ";
    cout << "\nExam grades" << endl;
    for (i = 0; i < 3; i++)
        cout << exams[i] << " ";
    cout << "\nLetter grade" << endl;
    cout << grade << endl;
}

string format(string name)
{
}

char computeGrade(int hw[], int exams[])
{
    int i;
    char grade;

    int assAvg, assTot = 0;

    for (i = 0; i < 10; i++)
        assTot += hw[i];

    for (i = 0; i < 3; i++)
        assTot += exams[i];

    assAvg = assTot / 13;

    if (assAvg > 90)
        grade = 'A';
    else if (assAvg > 80)
        grade = 'B';
    else if (assAvg > 70)
        grade = 'C';
    else if (assAvg > 60)
        grade = 'D';
    else
        grade = 'F';

    return grade;
}

int readFile(string names[][2], int hw[][AMOUNT_OF_HW], int exams[][AMOUNT_OF_TESTS])
{
    int studCnt = 0, i;
    string fileName;
    char grade;
    cout << "Enter student file: ";
    cin >> fileName;

    ifstream fp;
    fp.open(fileName);

    while (!fp.eof())
    {
        fp >> names[studCnt][0];
        fp >> names[studCnt][1];

        if (names[studCnt][0].empty() || names[studCnt][1].empty())
            break;

        for (i = 0; i < 10; i++)
            fp >> hw[studCnt][i];

        for (i = 0; i < 3; i++)
            fp >> exams[studCnt][i];

        studCnt++;
    }

    return studCnt;
}

int findStudent(string names[][2], int studCnt, string lastName)
{
    int i;
    for (i = 0; i < studCnt; i++)
        if (0 == names[i][1].compare(lastName))
            return i;

    return -1;
}

int main()
{
    string names[MAX_STUDENTS][2];
    char grade[MAX_STUDENTS];
    int hw[MAX_STUDENTS][AMOUNT_OF_HW];
    int exams[MAX_STUDENTS][AMOUNT_OF_TESTS];
    int studCnt, studIdx, i;

    studCnt = readFile(names, hw, exams);

    for (i = 0; i < studCnt; i++)
        grade[i] = computeGrade(hw[i], exams[i]);

    string name;
    while (1)
    {
        cout << "\nEnter a student's last name or enter quit: ";
        cin >> name;
        if (0 == name.compare("quit"))
            break;

        studIdx = findStudent(names, studCnt, name);

        if (-1 != studIdx)
            outputStudentInfo(names[studIdx][0], names[studIdx][1], grade[studIdx], hw[studIdx], exams[studIdx]);
        else
            cout << "\nStudent not found\n";
    }

    return 0;
}