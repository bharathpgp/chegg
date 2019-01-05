
// include necessary headers
#include <iostream>
#include <string>

using namespace std;

// Class fortune cookie
class fortuneCookie
{
    int luckyNum;
    string phrase;

  public:
    void fillCookieData();
    int getLuckyNum();
    string getInfo();
};

// Main function
int main()
{
    fortuneCookie thisCookie;
    thisCookie.fillCookieData();
    cout << thisCookie.getInfo() << endl;
    cout << "Your Lucky Number is : " << thisCookie.getLuckyNum() << endl;
    return 0;
}


// get data from user
void fortuneCookie::fillCookieData()
{
    cout << "Enter phrase: ";
    getline(cin, phrase);
    cout << "Enter Lucky Number: ";
    cin >> luckyNum;
}

// return lucky number
int fortuneCookie::getLuckyNum()
{
    return luckyNum;
}

// return phrase user entered
string fortuneCookie::getInfo()
{
    return phrase;
}