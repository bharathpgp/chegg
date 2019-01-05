#include <iostream>
using namespace std;

const int stack_size = 100;

class stack
{
  private:
    int data[stack_size]; // elements in the stack
    int top;              // index of the top element of the stack
  public:
    stack();             // constructor creates an empty stack
    void push(int item); // adds an element to the top of the stack
    int pop();           // removes and returns the top element
    bool empty();        // returns true if stack is empty
    bool full();         // returns true if stack is full
    void print();
    int elements();
    int peek();
};
// constructor creates an empty stack
stack::stack()
{
    top = -1;
}
// push adds an element, item, to the top of the stack
void stack::push(int item)
{
    // if the stack is full, print an error message
    if (full())
    {
        cout << "\n\nStack Class Error: Pushing on a full stack";
        cout << "\nElement being pushed is " << item;
    }
    else // OK to push the new element
    {
        top++;
        data[top] = item;
    }
}
// pop removes and returns the top element from the stack
int stack::pop()
{
    // if the stack is empty, print an error message
    if (empty())
    {
        cout << "\n\nStack Class Error: Popping an empty stack";
        cout << "\nReturning a ?";
        return -1;
    }
    else // OK to pop the stack
    {
        top--;
        return data[top + 1];
    }
}
// empty returns true if the stack is empty, else it returns false
bool stack::empty()
{
    return top == -1;
}
// full returns true if the stack is full, else it returns false
bool stack::full()
{
    return top == stack_size - 1;
}
// print the values in the stack from top to bottom
void stack::print()
{
    int i = top;
    while (i >= 0)
    {
        cout << data[i] << " pounds" << endl;
        i--;
    }
}
// return the number of elements in the stack
int stack::elements()
{
    return top + 1;
}
// return the top element of the stack, else return -1
int stack::peek()
{
    if (empty())
        return -1;
    else
        return data[top];
}