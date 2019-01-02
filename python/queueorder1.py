class SingleLL:

    def __init__(self, key):
        self.key = key
        self.next = None

class Queue:
    def __init__(self):
        self.front = self.rear = None

    def enQueue(self, key):
        tmp = SingleLL(key)

        if self.rear is None:
            self.front = self.rear = tmp
            return
        self.rear.next = tmp
        self.rear = tmp

    def deQueue(self):

        if self.front is None:
            return
        tmp = self.front
        self.front = tmp.next

        if self.front is None:
            self.rear = None
        return str(tmp.key)

    def printQueue(self):
        tmp = self.front
        if tmp is not None:
            print("Queue:")
        while tmp is not None:
            print(tmp.key, end=' ')
            tmp = tmp.next
        print()

if __name__ == '__main__':
    q = Queue()
    q.enQueue(1)
    q.printQueue()
    q.deQueue()
    q.enQueue(11)
    q.enQueue(22)
    q.printQueue()
    q.deQueue()
    q.printQueue()
