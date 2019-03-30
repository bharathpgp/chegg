#include <cstdlib>
#include <iostream>
using namespace std;

int main()
{
    const double PI = 3.14;
    int choice = 0;
    double radius = 0, height = 0.0, width = 0.0, base = 0.0;

    while (choice != 4)
    {
        cout << "Geometry Calculator" << endl;
        cout << "1. Calculate the Area of a Circle" << endl;
        cout << "2. Calculate the Area of a Rectangle" << endl;
        cout << "3. Calculate the Area of a Triangle" << endl;
        cout << "4. Quit" << endl;

        cin >> choice;

        switch (choice)
        {
        case 1:
            while (true)
            {
                cout << endl
                     << "Enter the circles radius" << endl;
                cin >> radius;
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
                cin >> height;
                cout << endl
                     << "Enter the rectangles Width" << endl;
                cin >> width;
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
                cin >> height;
                cout << endl
                     << "Enter the triangles Base" << endl;
                cin >> base;
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
            break;

        default:
            cout << endl
                 << "Enter value between 1 to 4" << endl;
            break;
        }
    }
    return 0;
}