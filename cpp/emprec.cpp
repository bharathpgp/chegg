#include <iostream>
#include <fstream>
#include <iomanip>

using namespace std;

void writeToDataFile(void)
{
    char ch;
    int counter = 0;
    ofstream outfile;

    char empID[10];
    char lastName[30], firstName[30];
    float hrsWorked, payHrly;
    float taxFed, taxStat;
    string tmp;

    outfile.open("data.txt", ios::app);

    do
    {
        cin.ignore();
        cout << "#1 of 7 - Enter Employee Worker ID Code(i.e. AF123): ";
        cin.getline(empID, sizeof empID);
        cout << "#2 of 7 - Enter Employee LAST Name: ";
        cin.getline(lastName, sizeof lastName);
        cout << "#3 of 7 - Enter Employee FIRST Name: ";
        cin.getline(firstName, sizeof firstName);
        cout << "#4 of 7 - Enter Total Hours Worked: ";
        getline(cin, tmp);
        hrsWorked = stof(tmp);
        cout << "#5 of 7 - Enter Hourly Pay: ";
        getline(cin, tmp);
        payHrly = stof(tmp);
        cout << "#6 of 7 - Enter FEDERAL Tax Rate: ";
        getline(cin, tmp);
        taxFed = stof(tmp);
        cout << "#7 of 7 - Enter STATE Tax Rate: ";
        getline(cin, tmp);
        taxStat = stof(tmp);

        outfile << empID << " " << lastName << " " << firstName << " " << hrsWorked << " " << payHrly << " " << taxFed << " " << taxStat << endl;
        counter++;

        cout << "Enter ANOTHER Personnel record?(Y/N): ";
        cin >> ch;

    } while (ch == 'y' || ch == 'Y');

    cout << counter << " records written to the data file." << endl;
    outfile.close();
}

void readFromDataFile(void)
{
    ifstream input;

    char empID[10];
    char lastName[30], firstName[30];
    float hrsWorked, payHrly;
    float taxFed, taxStat;

    int counter = 1;

    input.open("data.txt", ios::in);

    while (true)
    {
        input >> empID >> lastName >> firstName >> hrsWorked >> payHrly >> taxFed >> taxStat;
        if (input.eof())
            break;
        cout << "\tRecord #" << counter << endl;
        cout << "Employee ID: " << empID << endl;
        cout << "Last Name: " << lastName << " First Name: " << firstName << endl;
        float grossPay = hrsWorked * payHrly;
        cout << "Hours Worked: " << hrsWorked << " Pay Per Hour: $" << payHrly << " Gross Pay: $" << grossPay << endl;
        float fedTaxes = grossPay * taxFed / 100.00;
        float stateTaxes = grossPay * taxStat / 100.00;
        float netPay = grossPay - fedTaxes - stateTaxes;
        cout << "Federal Taxes: $" << fedTaxes << " State Taxes: $" << stateTaxes << " Net Pay: $" << netPay << endl;
        cout << "Employee Federal Tax Rate: " << taxFed << "%"
             << " Employee State Tax Rate: " << taxStat << "%";
        counter++;
        cout << endl;
    }
    input.close();
}

void displayLessHoursWorkedEmployees(void)
{
    ifstream input;

    char empID[10];
    char lastName[30], firstName[30];
    float hrsWorked, payHrly;
    float taxFed, taxStat;
    float hrs;

    int counter = 1;

    cout << "Enter Hours: ";
    cin >> hrs;

    input.open("data.txt", ios::in);

    while (true)
    {
        input >> empID >> lastName >> firstName >> hrsWorked >> payHrly >> taxFed >> taxStat;

        if (input.eof())
            break;

        if (hrsWorked < hrs)
        {
            cout << "\tRecord #" << counter << endl;
            cout << "Employee ID: " << empID << endl;
            cout << "Last Name: " << lastName << " First Name: " << firstName << endl;
            float grossPay = hrsWorked * payHrly;
            cout << "Hours Worked: " << hrsWorked << " Pay Per Hour: $" << payHrly << " Gross Pay: $" << grossPay << endl;
            float fedTaxes = grossPay * taxFed / 100.00;
            float stateTaxes = grossPay * taxStat / 100.00;
            float netPay = grossPay - fedTaxes - stateTaxes;
            cout << "Federal Taxes: $" << fedTaxes << " State Taxes: $" << stateTaxes << " Net Pay: $" << netPay << endl;
            cout << "Employee Federal Tax Rate: " << taxFed << "%"
                 << " Employee State Tax Rate: " << taxStat << "%";
            counter++;
            cout << endl;
        }
    }
    input.close();
}

int displayMenu()
{
    int choice;
    cout << endl;
    cout << "\tEnter an Option\n";
    cout << "1 - Write new Records to the Data file\n";
    cout << "2 - Display Records From the Data file to the Screen\n";
    cout << "3 - Find ALL Employees with Work Hours LESS than \"N\" Hours (User enters Hours value)\n";
    cout << "4 - QUIT\n";
    cout << "Enter Your option: ";
    cin >> choice;
    return choice;
}

int main()
{
    int choice;
    char ch;

    do
    {
        choice = displayMenu();

        switch (choice)
        {
        case 1:
            writeToDataFile();
            break;
        case 2:
            readFromDataFile();
            break;
        case 3:
            displayLessHoursWorkedEmployees();
            break;
        case 4:
            exit(1);
        default:
            cout << "\tInvalid entry!" << endl;
            continue;
        }
    } while (true);

    return 0;
}