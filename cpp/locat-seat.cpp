#include <iostream>
#include <iomanip>
#include <fstream>
using namespace std;

int phase_3(int plan_count,int count, int array_name[99],char path_name[200]) {

   int row, col, i = 0, k, j, x, y, m, n,e=0;
   int plan;
   char choice='n';
   int seat = 1;
   int valid_input=0,valid_choice=0;
   ifstream path;
   string numbers[200];
   string str;
   string locate_seat;
   char command;
   int search;
   path.open(path_name);
   while (getline(path, str))
   {
       if (str != " " && str != "" && str != "\n")
       {
           numbers[i] = str;
           i++;
       }
       else
       {
           numbers[i] = "(vacant)";
       }
   }

    for (int j = i; j < 200; j++)
    {
        numbers[j] = "(vacant)";
    }
  
    if (plan_count == 1) {
        for (row = 3; row < count; row++)
        {
            for (col = 3; col < count; col++)
            {
                if (row*col == count) {
                    break;
                }
            }
            if (row*col == count)
                break;
        }
        cout << "Plan (" << row << " rows x " << col << " columns)" << endl;
        for (n = 0; n < row; n++)
        {
            if (plan_count < 1)
                break;
            for (m = 0; m < col; m++)
            {
                cout << "seat #" << setw(2) << setfill('0') << seat << " ";
                seat++;
            }
            cout << endl;
            for (m = 0; m < col; m++)
            {
                cout << numbers[e] << " ";
                e++;
            }
            cout << "\n";
        }
    }
    if (plan_count > 1) {
        do {
            do
            {
                cout << "Input your choice of plan (1-" << plan_count << "):" << endl;
                cin >> plan;
                if (plan <= plan_count && plan > 0)
                    valid_input = 1;

                else {
                    valid_input = 0;
                }

            } while (valid_input == 0);

            k = plan - 1;
            y = array_name[k];
            x = count / y;
            cout << "Plan (" << y << " rows x " << x << " columns)" << endl;
            for (i = 0; i < y; i++)
            {
                if (plan_count < 1)
                    break;
                for (j = 0; j < x; j++)
                {
                    cout << "seat #" << setw(2) << setfill('0') << seat << " ";
                    seat++;
                }
                cout << "\n";
                for (j = 0; j < x; j++)
                {
                    cout << numbers[e] << " ";
                    e++;
                }
                cout << "\n";
            }


            do {
                cout << "Change to another plan? Your choice [y/n]:" << endl;
                cin >> choice;
            } while (choice != 'y' && choice != 'n');


            if (choice == 'y') {
                seat = 1;
                e = 0;
            }
        } while (choice == 'y');
    }
    cout << "[D] Enquire or change seats" << endl;
    cout << "===========================" << endl;
    do {
        cout << "Locate student, Change seat(s), Display the plan, or Quit [L/C/D/Q]:" << endl;
        cin >> command >> locate_seat;

        if (command == 'L') {

            for (int i = 0; i < y; i++) {

                for (int j = 0; j < x; j++) {

            //        if (numbers[i][j] == locate_seat ) {
            //        cout << endl;


            //    }
            }
        }
        }
    } while (command != 'Q');
  
   return i;
}

int main(){
    int arr[100];
    phase_3(2,3,arr,"seat.txt");
    return 0;
}