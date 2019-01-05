#include <iostream>
#include <vector>

using namespace std;

vector<class Item> items;

class Item
{
  public:
    Item()
    {
        hour = 0;
        min = 0;
        sec = 0;
    };

    Item(int hour, int min, int sec, int transID, string ItemNamme, float cstPrice, float sellPrice)
    {
        this->hour = hour;
        this->min = min;
        this->sec = sec;
        this->transID = transID;
        this->itemName = ItemNamme;
        this->cstPrice = cstPrice;
        this->sellPrice = sellPrice;
    }

    int getTransID()
    {
        return transID;
    }

    void printItems()
    {
        printf("Transaction Time: %02d:%02d:%02d\n", hour, min, sec);
        cout << "Transaction ID: " << transID << endl;
        cout << "Item Name: " << itemName << endl;
        cout << "Cost Price: " << cstPrice << endl;
        cout << "Selling Price: " << sellPrice << endl;
        cout << "Profit: " << sellPrice - cstPrice << endl;
    }

    int hour, min, sec;
    int transID;
    string itemName;
    float cstPrice, sellPrice;
};

int consoleMenu()
{
    int option;
    cout << "0. Exit" << endl;
    cout << "1. create a new transaction" << endl;
    cout << "2. void a transaction" << endl;
    cout << "3. print a summary of transactions" << endl;
    cout << "Enter option? " << endl;
    cin >> option;
    return option;
}

void createTransaction()
{
    Item item;
    cout << "Enter Transaction Details: " << endl;
    cout << "Hour? ";
    cin >> item.hour;
    cout << "Minute? ";
    cin >> item.min;
    cout << "Second? ";
    cin >> item.sec;
    cout << "Transaction ID? ";
    cin >> item.transID;
    cout << "Item Name? ";
    //getline(cin, item.itemName);
    cin >> item.itemName;
    cout << "Cost Price? ";
    cin >> item.cstPrice;
    cout << "Selling Price? ";
    cin >> item.sellPrice;
    items.push_back(item);
    cout << "Item Added" << endl;
}

void voidTransaction()
{
    int transID;
    size_t i;
    cout << "Transaction ID? ";
    cin >> transID;

    for (auto it = items.begin(); it != items.end(); ++it)
    {
        if (transID == it->getTransID())
        {
            items.erase(it);
            cout << "Transaction void" << endl;
            break;
        }
    }
}

void printSummary()
{
    cout << "Transaction Summary" << endl;
    size_t i;
    for (i = 0; i < items.size(); i++)
    {
        items[i].printItems();
    }
}

int main()
{
    Item item = Item(9, 10, 44, 1234567, "Paste", 45, 43);
    items.push_back(item);

    int option;
    do
    {
        option = consoleMenu();

        switch (option)
        {
        case 0:
            exit(1);
        case 1:
            createTransaction();
            break;
        case 2:
            voidTransaction();
            break;
        case 3:
            printSummary();
            break;
        default:
            break;
        }
    } while (0 != option);

    return 0;
}