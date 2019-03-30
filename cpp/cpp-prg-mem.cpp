#include <iostream>
#include <string>
using namespace std;

string year;

class PC
{
  public:
    PC(){};
    PC(string name, string model, string type) : name(name), model(model), type(type) {}

    string getInfo() const
    {
        return this->owner + "\n-" + this->name + "\n-" + this->model + "\n-" + this->type;
    }

    void setOwner(const string &owner)
    {
        this->owner = owner;
    }

  private:
    static string pcType;
    string owner{"N/A"};
    string name{"N/A"};
    string model{"N/A"};
    string type{"N/A"};
};

string PC::pcType = "Desktop";

PC *buyDell(string &pcOwner)
{
    pcOwner = "Dell Owner:" + pcOwner;

    static PC dell1{"Dell", "T7500", "Precision Workstation"};
    dell1.setOwner("Michale Jordan");

    PC dell2{dell1};

    PC *dell3 = new PC{dell2};
    dell3->setOwner(pcOwner);

    return dell3;
}

int main()
{
    string dellOwner("Michael Dell");
    PC *dellPC = buyDell(dellOwner);
    cout << dellPC->getInfo() << endl
         << endl;

    PC applePC("Apple", "X", "Mac Desktop");
    applePC.setOwner("Tim Cook");
    cout << applePC.getInfo() << endl
         << endl;

    PC msPC;
    msPC = PC("Microsoft", "M", "Surface Laptop");
    applePC.setOwner("Satya Nadella");
    cout << msPC.getInfo() << endl
         << endl;

    return 0;
}