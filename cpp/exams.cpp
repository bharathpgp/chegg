#include <iostream>
#include <fstream>
#include <cstring>
using namespace std;

const int NO_OF_QUESTIONS = 20;
char examGrade(int score);

int main() {
    char keyString[NO_OF_QUESTIONS + 1], answerString[NO_OF_QUESTIONS + 1];
    char ID[9], ch;
    int score, len, i;
    ifstream infile;

    infile.open("exams.txt");
    if (!infile) {
        cout << "Cannot open the input file. Program terminates!" << endl;
        return 1;
    }

    cout << "Processing Data" << endl;
    infile.get(keyString, 21);
    cout << "Key: " << keyString << endl;

    infile >> ID;
    infile.get(ch);
    infile.get(answerString, 21);

    while (infile) {
        len = strlen(answerString);
        
        for (i = len; i < 20; i++)
            answerString[i] = ' ';
        answerString[20] = '\0';

        score = 0;

        for (i = 0; i < 20; i++)
            if (answerString[i] != ' ')
                if (answerString[i] == keyString[i])
                    score = score + 2;
                else
                    score = score - 1;

        cout << ID << " " << answerString << " " << score << " " << examGrade(score) << endl;

        infile >> ID;
        infile.get(ch);
        infile.get(answerString, 21);
    }
    cout << endl;
    infile.close();
    return 0;
}

char examGrade(int score)
{
    float a = (score / 40.0) * 100;

    if (a >= 90 && a <= 100)
        return 'A';
    else if (a >= 80 && a <= 89.99)
        return 'B';
    else if (a >= 70 && a <= 79.99)
        return 'C';
    else if (a >= 60 && a <= 69.99)
        return 'D';
    else if (a >= 0 && a <= 59.99)
        return 'F';
}