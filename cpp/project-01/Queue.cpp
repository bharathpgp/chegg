#include <iostream>

#include "Queue.h"

Queue::Queue(int size)
{
    array = new ManagedArray(size);
    capacity = size;
    front = 0;
    rear = -1;
    count = 0;
}

void Queue::dequeue()
{
    // check for queue underflow
    if (isEmpty())
    {
        exit(EXIT_FAILURE);
    }

    array->remove(front);
    front = (front + 1) % capacity;
    count--;
}

// Utility function to add an item to the queue
void Queue::enqueue(int item)
{
    // check for queue overflow
    if (isFull())
    {
        exit(EXIT_FAILURE);
    }

    rear = (rear + 1) % capacity;
    array->insert(rear, item);
    count++;
}

// Utility function to return front element in the queue
int Queue::peek()
{
    if (isEmpty())
    {
        exit(EXIT_FAILURE);
    }
    return array->read(front);
}

// Utility function to return the size of the queue
int Queue::size()
{
    return count;
}

// Utility function to check if the queue is empty or not
bool Queue::isEmpty()
{
    return (size() == 0);
}

// Utility function to check if the queue is full or not
bool Queue::isFull()
{
    return (size() == capacity);
}

void Queue::insert(int x)
{
    enqueue(x);
}

int Queue::remove()
{
    dequeue();
}

bool Queue::empty()
{
    return isEmpty();
}