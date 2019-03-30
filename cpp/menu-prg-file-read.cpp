#include <cstdlib>
#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <sstream>
using namespace std;

int main()
{
    const double PI = 3.14;
    int choice = 0;
    double radius = 0, height = 0.0, width = 0.0, base = 0.0;

    //ifstream file("InFile.txt");
    fstream file("InFile.txt", ios::in);

    string line, number, tmp;
    vector<string> row;

    while (choice != 4)
    {
        cout << "Geometry Calculator" << endl;
        cout << "1. Calculate the Area of a Circle" << endl;
        cout << "2. Calculate the Area of a Rectangle" << endl;
        cout << "3. Calculate the Area of a Triangle" << endl;
        cout << "4. Quit" << endl;

        file >> tmp;
        row.clear();
        getline(file, line);
        stringstream str(line);

        while (getline(str, number, ','))
        {
            row.push_back(number);
        }

        choice = stoi(row[0]);

        cout << choice;

        switch (choice)
        {
        case 1:
            while (true)
            {
                cout << endl
                     << "Enter the circles radius" << endl;
                radius = stof(row[1]);
                if (radius < 0)
                    cout << "Radius must be a positive number!" << endl;
                else
                    break;
            }
            cout << "The Area of the Circle is = " << radius * radius * PI << endl;
            break;

        case 2:
            while (true)
            {
                cout << endl
                     << "Enter the rectangles length" << endl;
                height = stof(row[1]);
                cout << endl
                     << "Enter the rectangles Width" << endl;
                width = stof(row[2]);
                if (height < 0)
                    cout << "Length must be a positive number!" << endl;
                else if (width < 0)
                    cout << "Width must be a positive number!" << endl;
                else
                    break;
            }
            cout << "The Area of the Rectangle is = " << height * width << endl;
            break;

        case 3:
            while (true)
            {
                cout << endl
                     << "Enter the triangles Height" << endl;
                height = stof(row[1]);
                cout << endl
                     << "Enter the triangles Base" << endl;
                base = stof(row[2]);
                if (height < 0)
                    cout << "Height must be a positive number!" << endl;
                else if (base < 0)
                    cout << "Base must be a positive number!" << endl;
                else
                    break;
            }
            cout << "The Area of the Triangle is = " << base * height * .5 << endl;
            break;

        case 4:
            exit(0);
            break;

        default:
            cout << endl
                 << "Enter value between 1 to 4" << endl;
            break;
        }
    }

    return 0;
}

/*
void read_record() 
{ 

	// File pointer 
	fstream fin; 

	// Open an existing file 
	fin.open("reportcard.csv", ios::in); 

	// Get the roll number 
	// of which the data is required 
	int rollnum, roll2, count = 0; 
	cout << "Enter the roll number "
		<< "of the student to display details: "; 
	cin >> rollnum; 

	// Read the Data from the file 
	// as String Vector 
	vector<string> row; 
	string line, word, temp; 

	while (fin >> temp) { 

		row.clear(); 

		// read an entire row and 
		// store it in a string variable 'line' 
		getline(fin, line); 

		// used for breaking words 
		stringstream s(line); 

		// read every column data of a row and 
		// store it in a string variable, 'word' 
		while (getline(s, word, ', ')) { 

			// add all the column data 
			// of a row to a vector 
			row.push_back(word); 
		} 

		// convert string to integer for comparision 
		roll2 = stoi(row[0]); 

		// Compare the roll number 
		if (roll2 == rollnum) { 

			// Print the found data 
			count = 1; 
			cout << "Details of Roll " << row[0] << " : \n"; 
			cout << "Name: " << row[1] << "\n"; 
			cout << "Maths: " << row[2] << "\n"; 
			cout << "Physics: " << row[3] << "\n"; 
			cout << "Chemistry: " << row[4] << "\n"; 
			cout << "Biology: " << row[5] << "\n"; 
			break; 
		} 
	} 
	if (count == 0) 
		cout << "Record not found\n"; 
} 
s
*/