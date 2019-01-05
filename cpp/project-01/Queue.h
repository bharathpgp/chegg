#ifndef __QUEUE_H__
#define __QUEUE_H__

#include "container.h"
#include "managed_array.h"

class Queue : public Container
{
  public:
    Queue(int size);
    void dequeue();
    void enqueue(int x);
    int peek();
    int size();
    bool isEmpty();
    bool isFull();
    void insert(int x);
    int remove();
    bool empty();

  private:
    ManagedArray *array;
    int front, rear, capacity, count;
};
#endif /* __QUEUE_H__ */