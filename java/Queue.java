
// to demonstrate queue using singly linked-list

// Linked list data struct 
class Node {
    int data;
    Node next;

    public Node(int key) {
        this.data = key;
        this.next = null;
    }
}

// Queue data structure
class Queue {
    Node front, back;

    public Queue() {
        this.front = this.back = null;
    }

    // Method to add an key to the queue.
    void enQueue(int data) {

        // new node creation
        Node temp = new Node(data);

        if (this.back == null) {
            this.front = this.back = temp;
            return;
        }

        this.back.next = temp;
        this.back = temp;
    }

    // to remove node from queue
    Node deQueue() {
        if (this.front == null)
            return null;

        Node temp = this.front;
        this.front = this.front.next;

        if (this.front == null)
            this.back = null;
        return temp;
    }
    void printQueue() {
        Node temp = this.front;

        if (temp != null) {
            System.out.println("Queue:");
            while (temp != null) {
                System.out.print(temp.data + " ");
                temp = temp.next;
            }
            System.out.println();
        }
    }
    public static void main(String[] args) {
        Queue q = new Queue();
        q.enQueue(1);
        q.printQueue();
        q.deQueue();
        q.enQueue(11);
        q.enQueue(22);
        q.printQueue();
        q.deQueue();
        q.printQueue();
    }
}