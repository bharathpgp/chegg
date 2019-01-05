#include <iostream>
#include <string>
#include <fstream>

using namespace std;

class Node;

typedef Node *NodePtr;

class LL;

class Node
{
    friend class LL;

  public:
    int stId;
    string stName;
    string stEmail;
    int stAge;
    NodePtr nextStudent;
};

class LL
{
  private:
    NodePtr top;
    void destroy(NodePtr &);

  public:
    LL();
    LL(const LL &source);
    ~LL();

    void insertDataFromFile();

    void print();

    bool search(int);

    void insertAfterFirst(int id, string name, string email, int age);

    void insertBeforeFirst(int id, string name, string email, int age);

    void insertAfterLast(int id, string name, string email, int age);

    void insertBeforeLast(int id, string name, string email, int age);

    void remove(int);

    void copy(NodePtr top1, NodePtr &top2);
};

//--------------------------------------------

//--------------------------------------------

// the default constructor

LL::LL()
{

    top = new Node();

    top = NULL;
}

//--------------------------------------------

//--------------------------------------------

// the copy constructor

LL::LL(const LL &source)
{

    top = new Node();

    top = NULL;

    NodePtr temp = source.top;

    while (temp != NULL)
    {

        insertAfterFirst(temp->stId, temp->stName, temp->stEmail, temp->stAge); //insert each element in list

        temp = temp->nextStudent;
    }

    top = source.top;
}

//--------------------------------------------

//--------------------------------------------

// the destructor

LL::~LL()
{

    destroy(top); //delete the list
}

//--------------------------------------------

//--------------------------------------------

// Read a transaction file and insert the data into it

// after reading a set of data you can call any of the

// insert functions to insert the node into the linked list

/* use the following data to test your program
76543 Mary mary@csusm.edu 19
98765 Kathy kathy@csusm.edu 30
16438 Flora flora@csusm.edu 25
43260 Peter peter@csusm.edu 29
87590 kim kim@csusm.edu 31
*/
void LL::insertDataFromFile()
{

    ifstream file;

    file.open("transactionFile.txt"); //open the file

    int id;

    string name;

    string email;

    int age;

    while (file)
    {

        file >> id; //read one line from file

        file >> name;

        file >> email;

        file >> age;

        if (file.eof()) break;  // haven't reached EOF because the EOF mark hasn't been read yet

        insertAfterLast(id, name, email, age); //insert the data at the end of the list
    }
}

//--------------------------------------------

//--------------------------------------------

// print the linked list

void LL::print()
{

    NodePtr temp = top; //start from top

    while (temp != NULL)
    {

        cout << temp->stId << "\t" << temp->stName << "\t" << temp->stEmail << "\t" << temp->stAge << endl;

        temp = temp->nextStudent; //iterate to next student
    }
}

//--------------------------------------------

//--------------------------------------------

// search for a particular student id in the list

bool LL::search(int id)
{

    NodePtr temp = top;

    while (temp != NULL)
    {

        if (temp->stId == id) //check if current node has same id

            return true; //return true for found

        temp = temp->nextStudent;
    }

    return false; //return false if not found
}

//--------------------------------------------

//--------------------------------------------

// creates a node and insert the node on the top of the

// linked list but after the first node. For example if the

// list constains 1 --> 20 -->13 --> 4 --> 5 --> 6

// after inserting 10, we should get:

// list constains 1 --> 10 --> 20 -->13 --> 4 --> 5 --> 6

void LL::insertAfterFirst(int id, string name, string email, int age)
{

    NodePtr temp = new Node();

    temp->stId = id; //create a new node with the parameters value

    temp->stName = name;

    temp->stEmail = email;

    temp->stAge = age;

    if (top == NULL)
    { //if the current list is empty

        top = temp;

        return;
    }

    temp->nextStudent = top->nextStudent; //insert the temp after first element

    top->nextStudent = temp;
}

//--------------------------------------------

//--------------------------------------------

// creates a node and insert the node on the top of the

// linked list before the first node. For example if the

// list constains 1 --> 20 -->13 --> 4 --> 5 --> 6

// after inserting 10, we should get:

// list constains 10 --> 1 --> 20 -->13 --> 4 --> 5 --> 6

void LL::insertBeforeFirst(int id, string name, string email, int age)
{

    NodePtr temp = new Node();

    temp->stId = id;

    temp->stName = name;

    temp->stEmail = email;

    temp->stAge = age;

    if (top == NULL)
    { //if the list is empty

        top = temp;

        return;
    }

    temp->nextStudent = top; //insert the node at the first position

    top = temp; //change first
}

//--------------------------------------------

//--------------------------------------------

// creates a node and insert the node on the bottom of the

// linked list after the last node. For example if the

// list constains 1 --> 20 -->13 --> 4 --> 5 --> 6

// after inserting 10, we should get:

// list constains 1 --> 20 -->13 --> 4 --> 5 --> 6 --> 10

void LL::insertAfterLast(int id, string name, string email, int age)
{

    NodePtr temp = new Node();

    temp->stId = id;

    temp->stName = name;

    temp->stEmail = email;

    temp->stAge = age;

    if (top == NULL)
    { //if the list is empty

        top = temp;

        return;
    }

    NodePtr itr = top;

    while (itr->nextStudent != NULL)
    { //find the last node

        itr = itr->nextStudent;
    }

    itr->nextStudent = temp; //insert the node after last

    temp->nextStudent = NULL; //set next for last as NULL
}

//--------------------------------------------

//--------------------------------------------

// creates a node and insert the node on the bottom of the

// linked list before the last node. For example if the

// list constains 1 --> 20 -->13 --> 4 --> 5 --> 6

// after inserting 10, we should get:

// list constains 1 --> 20 -->13 --> 4 --> 5 --> 10 --> 6

void LL::insertBeforeLast(int id, string name, string email, int age)
{

    NodePtr temp = new Node();

    temp->stId = id;

    temp->stName = name;

    temp->stEmail = email;

    temp->stAge = age;

    if (top == NULL)
    { //if the list is empty

        top = temp;

        return;
    }

    NodePtr itr = top;

    while (itr->nextStudent->nextStudent != NULL)
    { //find second last node in list

        itr = itr->nextStudent;
    }

    temp->nextStudent = itr->nextStudent; //insert the node between second last node and last node

    itr->nextStudent = temp;
}

//--------------------------------------------

//--------------------------------------------

// removes a node from the list based on the given student id

void LL::remove(int id)
{

    if (!search(id))
    { //if id is not present in list

        return;
    }

    NodePtr temp = top;

    while (temp->nextStudent->stId != id)
    { //find the node before the node which needs to be removed

        temp = temp->nextStudent;
    }

    NodePtr del = temp->nextStudent; //del is the node which needs to be deleted

    temp->nextStudent = del->nextStudent; //update the before node to the next node

    del->nextStudent = NULL;

    delete del; //delete node
}

//--------------------------------------------

//--------------------------------------------

// copies one list into another

void LL::copy(NodePtr atop, NodePtr &btop)
{

    btop = atop; //copy top of one list to another top
}

//--------------------------------------------

// deallocate the nodes in a linked list

void LL::destroy(NodePtr &top)
{
    if (top == NULL)
    {
        return;
    }
    NodePtr priorNode;
    while (top != NULL)
    {
        priorNode = top;
        top = top->nextStudent;
        delete priorNode;
    }
}

//--------------------------------------------
int main()
{
    LL list1;

    list1.insertDataFromFile();
    list1.print();

    list1.insertAfterFirst(54321, "Jim", "jim@csusm.edu", 25);
    list1.insertBeforeFirst(54123, "Joe", "joe@csusm.edu", 35);
    list1.insertAfterLast(63421, "Adam", "adam@csusm.edu", 20);
    list1.insertBeforeLast(66641, "Nancy", "nancy@csusm.edu", 27);
    list1.print();

    bool found = list1.search(12321);
    if (found)
        cout << "the record was found" << endl;
    else
        cout << "the record was not found" << endl;

    list1.remove(54321);
    list1.print();

    LL list2(list1);
    list2.print();

    return 0;
}
